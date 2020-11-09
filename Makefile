LCS: LCS.cpp md
	g++ -g -std=c++14 LCS.cpp MDList -o LCS

md: MDList.cpp
	g++ -c -g -std=c++14 MDList.cpp -o MDList
