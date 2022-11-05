#include <vector>
#include <utility>
#include <string>

class Node {
  int len;
  int parent;
  int indeg;
  std::pair<int, int> bp;
};

class PalTree {
private:
  std::string str;
  std::vector<Node> nodes;
  std::vector<int> prefpal;
  const static int ODD = 0, EVEN = 1;
  int lpsuf;
  int I, J;

public:
  PalTree() {
    
  }

  void push_back(char c) {
    str.push_back(c);
    ++J;

  }

  void pop_front() {


  }
};