#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include "MDList.hpp"

using namespace::std;

/**Read in the 1st arg from the c++ argument components, argc and argv*/
string readFirstArg(int argc, char** argv) {

  if(argc < 2) {
    cerr << "First argument not provided" << endl;
    exit(EXIT_FAILURE);
  }
  string toReturn(argv[1]);
  return toReturn;
}
/**Read in the 2nd arg from the c++ argument components, argc and argv*/
string readSecondArg(int argc, char** argv) {
  if(argc < 3) {
    cerr << "Second argument not provided." << endl;
    exit(EXIT_FAILURE);
  }
  string toReturn(argv[2]);
  return toReturn;
}

/** Store value in mdlist at the row specified by row and 
    column specified by col*/
void storeIn(MDList& mdlist, int row, int col, string value) {
  mdlist.setValue(row, col, value);
}

/** get the character located at index i in string seq */
char getCharAt(string seq, int i) {
  return seq.at(i-1);
}
string get(MDList& list, int i, int j) {
  return list.get(i, j);
}
int getInt(MDList& list, int i, int j) {
  string val = list.get(i, j);
  return stoi(val);
}

string printDelimString(string seq, string delim) {
  stringstream ss;
  for(int i = 0; i < seq.length()-1; i++) {
    ss << seq.at(i) << delim;
  }
  ss << seq.at(seq.length()-1);
  return ss.str();
}

MDList LCS_LEN(string X, string Y) {
  int m = X.length();
  int n = Y.length();

  MDList b(n+1);
  MDList c(n+1);
  for(int i = 0; i <= m; i++) {
    b.addNewList();
  }
  
  for(int i = 0; i <= m; i++) {
    c.addNewList();
  }

  for(int i = 1; i <= m; i++) { 
    storeIn(c, i, 0, "0");
  }
  for(int i = 0; i <= n; i++) {
    storeIn(c, 0, i, "0");
  }

  for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= n; j++) {
      char Xval = getCharAt(X,i);
      char Yval = getCharAt(Y,j);

      int upVal   = getInt(c, i-1, j);
      int leftVal = getInt(c, i-1, j-1);

      if(Xval == Yval) {
        stringstream newCStream;
  	int upLeftVal = getInt(c,i-1,j-1);
  	newCStream << (upLeftVal+1);
  	string newC = newCStream.str();
  	storeIn(c,i,j, newC);
  	storeIn(b,i,j,"↖");
      }
      else if(upVal >= leftVal) {
	string newC = get(c, i-1, j);
	storeIn(c, i, j, newC);
	storeIn(b, i, j, "↑");
      }
      else {
	string newC = get(c, i, j-1);
	storeIn(c, i, j, newC);
	storeIn(b, i, j, "←");
      }
    } 
  }
  
  return b;
}


string LCS_PRINT(MDList& b, string X, int i, int j) {
  if(i == 0 || j == 0) {
    return "";
  }
  else if(get(b, i, j) == "↖") {
    return LCS_PRINT(b,X, i-1, j-1) + getCharAt(X,i);
  }
  else if(get(b, i, j) == "↑") {
    return LCS_PRINT(b, X, i-1, j);
  }
  else {
    return LCS_PRINT(b, X, i, j-1);
  }
}
int main(int argc, char** argv) {
  
  string X(readFirstArg(argc,argv));
  string Y(readSecondArg(argc,argv));
  cout << "X is: " << X << endl;
  cout << "Y is: " << Y << endl;

  if(X.length() < Y.length()) {
    string temp(Y);
    Y = X;
    X = temp;
    cout << "Inputs 1 and 2 were switched so that the largest is X" << endl;
  }
  int m = X.length();
  int n = Y.length();
 
  MDList b = LCS_LEN(X, Y);
  cout << "Longest common subsequence is: " << LCS_PRINT(b, X, X.length(), Y.length());
  
  return 0;

  
  // for inputs ABCBDAB and BDCABA, should print BCBA
  
}
