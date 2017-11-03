#!/usr/bin/Rscript
input <- file('stdin', 'r')
a <- readLines(input, n=1)
b <- "\n"
cat(paste0(paste(rev(strsplit(a,"")[[1]]), collapse=""), b))
