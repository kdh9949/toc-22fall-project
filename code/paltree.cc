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

  int child(char c) { return ch[c - 'a']; }
  void set_child(char c, int x) { ch[c - 'a'] = x; }
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
  std::vector<int> ppal;
  const static int ODD = 0, EVEN = 1;
  int lpsuf;
  int I, J;

  int new_node() {
    nodes.emplace_back();
    return int(nodes.size()) - 1;
  }
  void add_char(char c) {
    str.push_back(c);
    ppal.push_back(0);
    ++J;
  }
  void del_char() {
    ++I;
  }
  char S(int x) {
    if(x < I || x > J) return '#';
    return str[x];
  }
  int& prefpal(int x) { return ppal[x]; }
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
    add_char(c);

    while(S(J - len(lpsuf) - 1) != c)
      lpsuf = slink(lpsuf);

    if(!child(lpsuf, c)) {
      int nnode = new_node();
      set_child(lpsuf, c, nnode);
      len(nnode) = len(lpsuf) + 2;
      
      if(lpsuf == ODD) slink(nnode) = EVEN;
      else {
        slink(nnode) = nodes[lpsuf].slink;
        while(S(J - len(slink(nnode)) - 1) != c)
          slink(nnode) = slink(slink(nnode));
        slink(nnode) = child(slink(nnode), c);
      }
      ++inSL(slink(nnode));
    }

    int y = J - len(lpsuf) + 1;
    update_bp(lpsuf, y);
    prefpal(y) = lpsuf;
  }

  void pop_front() {
    del_char();



  }
};