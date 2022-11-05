#include <vector>
#include <utility>
#include <string>
#include <cstring>

// Sigma = {'a', 'b', ..., 'z'}
struct Node {
  int len;
  int slink;
  char pchar;
  int inSL;
  std::pair<int, int> bp;
  char ch[26];

  Node() {
    memset(ch, 0, sizeof(ch));
    bp = std::make_pair(-1, -1);
    inSL = 0;
  }

  int child(char c) {
    return ch[c - 'a'];
  }

  void set_child(char c, int x) {
    ch[c - 'a'] = x;
  }

  void update_bp(int p) {
    if(p >= bp.first) {
      bp.second = bp.first;
      bp.first = p;
    }
    else if(p >= bp.second) {
      bp.second = p;
    }
  }
};

class PalTree {
private:
  std::string str;
  std::vector<Node> nodes;
  std::vector<int> prefpal;
  const static int ODD = 0, EVEN = 1;
  int lpsuf;
  int I, J;

  int& len(int x) { return nodes[x].len; }
  int& slink(int x) { return nodes[x].slink; }
  int& inSL(int x) { return nodes[x].inSL; }
  int child(int x, char c) { return nodes[x].child(c); }
  void set_child(int x, char c, int y) {
    nodes[x].set_child(c, y);
    nodes[y].pchar = c;
  }
  void update_bp(int x, int p) { nodes[x].update_bp(p); }

public:
  PalTree() {
    lpsuf = 0;
    nodes.resize(2);
    I = 0; J = -1;
    len(ODD) = -1;
    len(EVEN) = 0;
    slink(EVEN) = ODD;
  }

  void push_back(char c) {
    str.push_back(c);
    prefpal.push_back(0);
    ++J;

    while(lpsuf != ODD && str[J - len(lpsuf) - 1] != c)
      lpsuf = slink(lpsuf);

    if(!child(lpsuf, c)) {
      int new_node = nodes.size();
      nodes.emplace_back();
      set_child(lpsuf, c, new_node);
      len(new_node) = len(lpsuf) + 2;
      
      if(lpsuf == ODD) slink(new_node) = EVEN;
      else {
        slink(new_node) = nodes[lpsuf].slink;
        while(slink(new_node) != ODD && str[J - len(slink(new_node)) - 1] != c)
          slink(new_node) = slink(slink(new_node));
        slink(new_node) = child(slink(new_node), c);
      }
      ++inSL(slink(new_node));
    }

    int y = J - len(lpsuf) + 1;
    update_bp(lpsuf, y);
    prefpal[y] = lpsuf;
  }

  void pop_front() {


  }
};