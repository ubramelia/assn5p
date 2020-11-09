#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "MDList.hpp"

using namespace std;

MDList::MDList(int colCount) {
  modelSize = 0;
  this->colCount = colCount;
  model = new vector<string>[0];
}

MDList::~MDList() {
  delete [] model;
}

MDList::MDList(const MDList& rhs) {
  model = rhs.model;
  colCount = rhs.colCount; 
}
string MDList::get(int i, int j) const {
  return model[i][j];
}

void MDList::addNewList() {
  vector<string> *newModel;
  newModel = new vector<string>[modelSize+1];
  for(int i = 0; i < modelSize; i++) {
    newModel[i] = model[i];
  }
  newModel[modelSize] = vector<string>();
  for(int j = 0; j < colCount; j++) {
    newModel[modelSize].push_back("");
  }
  delete [] model;
  model = newModel;
  modelSize = modelSize+1;
}
  
void MDList::setValuesOfRow(int row, vector<string> newList) {
  int j = 0;
  while(j < colCount && j < newList.size()) {
    model[row][j] = newList[j];
    j = j + 1;
  }
}

int MDList::lists() {
  return modelSize;
}
int MDList::columns() {
  return colCount;
}

vector<string> MDList::row(int i) {
  return model[i];
}
  
vector<string> MDList::column(int index) {
  vector<string> x;
  for(int i = 0; i < modelSize; i++) {
    x.push_back(model[i][index]);
  }
  return x;
}
void MDList::setValue(int row, int col, string element) {
  model[row][col] = element;
}

// ostream& operator<< (ostream& out, const MDList& list) {
//   MDList* useList = const_cast<MDList*>(&list);
//   for(int i = 0; i < useList->lists(); i++) {
//     for(int j = 0; j < useList->columns(); j++) {
//       out << useList->get(i,j);
//     }
//     out << endl;
//   }
//   return out;
// }

