CXXFLAGS := -std=c++11 -O3 -Wall -pedantic
all: bfs dfs

bfs: bfs.cpp
	$(CXX) $(CXXFLAGS) bfs.cpp -o bfs 

dfs: dfs.cpp
	$(CXX) $(CXXFLAGS) dfs.cpp -o dfs 

test: dfs
	echo "8..........36......7..9.2...5...7.......457.....1...3...1....68..85...1..9....4.." | ./dfs
