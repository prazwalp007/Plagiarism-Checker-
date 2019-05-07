final: plagiarismCatcher.o hash.o
	g++ -std=c++11 -o test plagiarismCatcher.o hash.o
plagiarismCatcher.o: plagiarismCatcher.cpp hash.h
	g++ -std=c++11 -c plagiarismCatcher.cpp hash.cpp
UtPod.o: hash.cpp hash.h
	g++ -std=c++11 -c  hash.cpp

