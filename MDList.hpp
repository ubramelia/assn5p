#include <string>
#include <vector>
using namespace std;

class MDList {
public:
  MDList(int colCount);
  ~MDList();
  MDList(const MDList& rhs);
  void addNewList();
  void add(vector<string> newList);
  void add(string newList[]);
  int lists();
  int columns();
  vector<string> row(int index);
  vector<string> column(int index);
  void setValuesOfRow(int row, vector<string> list);
  void setValuesOfRow(int row, string list[]);
  void setValue(int row, int col, string element);
  string get(int row, int col) const;
  
private:
  vector<string>* model;
  int modelSize;
  int colCount;
  
};


