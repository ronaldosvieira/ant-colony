library(adagio)

knapsacks <- c(2, 3, 4)
items <- c(25, 50, 100, 200)
types <- c("uncorrelated", "weakly_correlated")

for(ty in 1:2) {
  for(kn in 1:3) {
    for(it in 1:4) {
      for(i in 1:20) {
        fileName <- "./GitHub/ant-colony/src/instances/"
        fileName <- paste(fileName, types[ty], sep="")
        fileName <- paste(fileName, "/", sep="")
        fileName <- paste(fileName, knapsacks[kn], sep="")
        fileName <- paste(fileName, "k", sep="")
        fileName <- paste(fileName, items[it], sep="")
        fileName <- paste(fileName, "i_", sep="")
        fileName <- paste(fileName, i, sep="")
        fileName <- paste(fileName, ".dat", sep="")
        
        data <- readLines(fileName, encoding="UTF-8")
        
        p <- as.integer(strsplit(strsplit(data[2], " ")[[1]], " "))
        w <- as.integer(strsplit(strsplit(data[4], " ")[[1]], " "))
        k <- as.integer(strsplit(strsplit(data[3], " ")[[1]], " "))
        
        k <- sort(k)
        
        res <- mknapsack(p, w, k)
        optimum <- lapply(res["value"], function(x) x[which.max(abs(x))])
        
        as.integer(optimum)
        
        cat(as.integer(optimum), file=fileName, append=TRUE, sep = "\n")
      }
    }
  }
}
