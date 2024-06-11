#include<string>
#include<vector>
#include <algorithm>
#include <sstream>
#include <fmt/format.h>

std::string displayBoard(const std::vector<char>& bd, unsigned short w){
  std::stringstream ss;
  std::string n(w*3+w-1,'-');
  for(size_t i=0;i<bd.size();i+=w){
    std::string t;
    std::for_each(bd.begin()+i,bd.begin()+i+w,[&t,w,j=0](auto& c)mutable{
      t+=fmt::format(" {} ",c);
      ++j;
      if(j!=w) t+='|';
    });
    ss<<t; 
    if(i+w<bd.size())ss<<"\n"<<n<<"\n";
  }
  return ss.str();
}
//////////////////
#include <string>
#include <vector>
#include <sstream>

std::string displayBoard(const std::vector<char>& board, unsigned short width){
    std::ostringstream oss;
    unsigned int count = 0;
    auto end = board.size();
    std::string rowsSeparator(width*4-1, '-');
    for(const auto& i : board) {
        count++;
        oss << ' ' << i << ' ';
        if(count == end)
            break;
        else if(count%width == 0)
            oss << '\n' << rowsSeparator << '\n';
        else
            oss << '|';
    }
    return oss.str();
}
/////////////////////
#include<string>
#include<vector>

std::string displayBoard(const std::vector<char>& board, unsigned short width){
  std::string res = "";
  for (unsigned int i = 0; i < board.size(); i++) {
    res += (!i || i%width ? "" : "\n" + std::string(4 * width - 1, '-') + "\n") + " " + board[i] + " " + (i % width == (width - 1) ? "" : "|");
  }
  return res;
}
/////////////////
