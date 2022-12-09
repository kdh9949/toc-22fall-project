#include "paltree.cc"
#include <iostream>

int validate(int argc, char **argv) {
  if(argc != 2) return 1;
  std::string mode(argv[1]);
  if(mode != "-d" && mode != "-m") return 2;
  return 0;
}

int main(int argc, char **argv) {
  int err_code = validate(argc, argv);
  if(err_code) { 
    std::cerr << "Usage : " << argv[0] << " [option]\n"
              << "-d : number of distinct palindromes\n"
              << "-m : number of MUPS(Minimal Unique Palindromic Substrings)" << std::endl;
    return err_code;
  }

  int q;
  std::cin >> q;

  PalTree P;

  for(int i = 0; i < q; ++i) {
    std::string typ;
    std::cin >> typ;
    
    if(typ == "push") {
      char c;
      std::cin >> c;
      P.push_back(c);
    }
    else {
      P.pop_front();
    }

    std::cout << (argv[1][1] == 'd' ? P.distinct_pal() : P.mups()) << std::endl;
  }

  return 0;
}