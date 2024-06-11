//undefined behiavior on random tests

#include <map>
#include <sstream>
#include <algorithm>

using namespace std::literals;

void insert(std::vector<std::string>& nm,std::vector<std::string>& canv,size_t m,size_t k,char ch){
  for(size_t i=0;i<nm.size();++i){
    for(size_t j=0;j<nm[0].size();++j){
      if(nm[i][j]!=' ')nm[i][j]=ch;
      canv[m+i][k+j]=nm[i][j];
    }
  }
}

std::string print_number(unsigned num, char ch)
{
  std::map<int,std::vector<std::string>> dict={
    {9,{" $$$$ ",
        "$$  $$",
        "$$  $$",
        " $$$$ ",
        "  $$  ",
        " $$   ",}},
  {0,{" $$$$ ",
      "$$  $$",
      "$$  $$",
      "$$  $$",
      "$$  $$",
      " $$$$ ",}},
  {1,{"  **  ",
      " ***  ",
      "* **  ",
      "  **  ",
      "  **  ",
      "******"}},
  {2,{" **** ",
      "**  **",
      "   ** ",
      "  **  ",
      " **   ",
      "******"}},
  {3,{" **** ",
      "**  **",
      "   ** ",
      "   ** ",
      "**  **",
      " **** "}},
    {4,{"**  **",
        "**  **",
        "**  **",
        " *****",
        "    **",
        "    **"}},
    { 5,{
      "******",
      "**    ",
      "***** ",
      "    **",
      "    **",
      "***** "}
    },{6,{
      "   @@ ",
      "  @@  ",
      " @@@@ ",
      "@@  @@",
      "@@  @@",
      " @@@@ "
    }},{7,{
      "@@@@@@",
      "@@  @@",
      "   @@ ",
      "  @@  ",
      " @@   ",
      " @@   "
    }},{
      8,{
        " @@@@ ",
        "@@  @@",
        " @@@@ ",
        " @@@@ ",
        "@@  @@",
        " @@@@ "
      }
    }
    
};

  std::vector<std::string>canv=
 {"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"s,
  "$                                      $\n"s,
  "$  0%%%%% 1%%%%% 2%%%%% 3%%%%% 4%%%%%  $\n"s,
  "$  %%%%%% %%%%%% %%%%%% %%%%%% %%%%%%  $\n"s,
  "$  %%%%%% %%%%%% %%%%%% %%%%%% %%%%%%  $\n"s,
  "$  %%%%%% %%%%%% %%%%%% %%%%%% %%%%%%  $\n"s,
  "$  %%%%%% %%%%%% %%%%%% %%%%%% %%%%%%  $\n"s,
  "$  %%%%%% %%%%%% %%%%%% %%%%%% %%%%%%  $\n"s,
  "$                                      $\n"s,
  "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"s
 };
  std::string nm=std::to_string(num);
  if(nm.size()<5){
    size_t x=5-nm.size();
    std::string t(x,'0');
    nm.insert(0,t);
  }
  std::for_each(nm.begin(),nm.end(),[&canv,&dict,ch,i=0](auto& c)mutable{
    for(size_t j=0;j<canv.size();++j){
      for(size_t k=0;k<canv[0].size();++k){
        if(canv[j][k]=='$')canv[j][k]=ch;
        if(canv[j][k]==std::to_string(i).front()){
          insert(dict[c-'0'],canv,j,k,ch);
        }
      }
    }
    ++i;
  });
  std::stringstream ss;
  std::copy(canv.begin(),canv.end(),std::ostream_iterator<std::string>(ss));
  std::string c=ss.str();
    return c;
}
///////////////////

using namespace std;

string print_number(unsigned n, char c)
{
    const string bitmap[6][10] = {
        {" #### ", "  ##  ", " #### ", " #### ", "##  ##", "######", "   ## ", "######", " #### ", " #### "},
        {"##  ##", " ###  ", "##  ##", "##  ##", "##  ##", "##    ", "  ##  ", "##  ##", "##  ##", "##  ##"},
        {"##  ##", "# ##  ", "   ## ", "   ## ", "##  ##", "##### ", " #### ", "   ## ", " #### ", "##  ##"},
        {"##  ##", "  ##  ", "  ##  ", "   ## ", " #####", "    ##", "##  ##", "  ##  ", " #### ", " #### "},
        {"##  ##", "  ##  ", " ##   ", "##  ##", "    ##", "    ##", "##  ##", " ##   ", "##  ##", "  ##  "},
        {" #### ", "######", "######", " #### ", "    ##", "##### ", " #### ", " ##   ", " #### ", " ##   "}
    };
    const string border = "########################################",
                 margin = "#                                      #";
    string lines  = border + "\n" + margin + "\n",
           digits = "00000" + to_string(n);
    digits = digits.substr(digits.size()-5);
    for (int i = 0; i < 6; i++)
    {
        lines += "#  ";
        for (int j = 0; j < 5; j++)
            lines += bitmap[i][digits[j] - '0'] + " ";
        lines += " #\n";
    }
    lines += margin + "\n" + border;
    replace_if(lines.begin(), lines.end(), [](char x){return '#' == x;}, c);
    return lines;
}
/////////////////
#include <algorithm>
#include <array>
#include <iterator>
#include <sstream>
#include <string>

std::string print_number(unsigned num, const char ch) {
    static const std::array<const char*, 10> numbers{
        " ==== "
        "==  =="
        "==  =="
        "==  =="
        "==  =="
        " ==== ",

        "  ==  "
        " ===  "
        "= ==  "
        "  ==  "
        "  ==  "
        "======",

        " ==== "
        "==  =="
        "   == "
        "  ==  "
        " ==   "
        "======",

        " ==== "
        "==  =="
        "   == "
        "   == "
        "==  =="
        " ==== ",

        "==  =="
        "==  =="
        "==  =="
        " ====="
        "    =="
        "    ==",

        "======"
        "==    "
        "===== "
        "    =="
        "    =="
        "===== ",

        "   == "
        "  ==  "
        " ==== "
        "==  =="
        "==  =="
        " ==== ",

        "======"
        "==  =="
        "   == "
        "  ==  "
        " ==   "
        " ==   ",

        " ==== "
        "==  =="
        " ==== "
        " ==== "
        "==  =="
        " ==== ",

        " ==== "
        "==  =="
        "==  =="
        " ==== "
        "  ==  "
        " ==   "};

    std::array<const char*, 5> res;
    std::fill(res.begin(), res.end(), numbers.front());
    for (auto it = res.rbegin(); it != res.rend() && num; ++it, num /= 10) {
        *it = numbers.at(num % 10);
    }

    std::ostringstream oss;

    std::fill_n(std::ostream_iterator<char>{oss}, 40, ch);
    oss << '\n' << ch;
    std::fill_n(std::ostream_iterator<char>{oss}, 38, ' ');
    oss << ch << '\n';

    for (std::size_t row = 0; row < 6; ++row) {
        oss << ch << ' ';

        for (const char* val : res) {
            oss << ' ';
            std::transform(val + row * 6, val + row * 6 + 6,
                           std::ostream_iterator<char>{oss},
                           [ch](const char c) {
                               if (c == ' ') return ' ';
                               return ch;
                           });
        }

        oss << "  " << ch << '\n';
    }

    oss << ch;
    std::fill_n(std::ostream_iterator<char>{oss}, 38, ' ');
    oss << ch << '\n';
    std::fill_n(std::ostream_iterator<char>{oss}, 40, ch);

    return oss.str();
}
/////////////////
#include <string>
#include <bitset>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

struct Screen {
    std::string txt{
            "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"
            "$                                      $\n"
            "$                                      $\n"
            "$                                      $\n"
            "$                                      $\n"
            "$                                      $\n"
            "$                                      $\n"
            "$                                      $\n"
            "$                                      $\n"
            "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"};
    size_t stride;
    Screen(char ch) : stride(txt.find_first_of('\n')+1){
      std::replace(txt.begin(),txt.end(), '$', ch);
    };
};

using spritedef_t=std::vector<std::bitset<6>>;

std::map<char,spritedef_t> sprites{
    {'0', {0b011110,0b110011,0b110011,0b110011,0b110011,0b011110}},
    {'1', {0b001100,0b011100,0b101100,0b001100,0b001100,0b111111}},
    {'2', {0b011110,0b110011,0b000110,0b001100,0b011000,0b111111}},
    {'3', {0b011110,0b110011,0b000110,0b000110,0b110011,0b011110}},
    {'4', {0b110011,0b110011,0b110011,0b011111,0b000011,0b000011}},
    {'5', {0b111111,0b110000,0b111110,0b000011,0b000011,0b111110}},
    {'6', {0b000110,0b001100,0b011110,0b110011,0b110011,0b011110}},
    {'7', {0b111111,0b110011,0b000110,0b001100,0b011000,0b011000}}, 
    {'8', {0b011110,0b110011,0b011110,0b011110,0b110011,0b011110}}, 
    {'9', {0b011110,0b110011,0b110011,0b011110,0b001100,0b011000}},
};

void drawsprite(Screen& sc, const std::pair<int,int> &p, spritedef_t& sp, char c) {
    auto yl = p.second * sc.stride;
    for (auto &b:sp)
       sc.txt.replace(std::exchange(yl,yl+sc.stride)+p.first,6,b.to_string(' ',c).data());
}

std::string print_number(unsigned num, char ch) {
    const std::vector<std::pair<int, int>> spritepos = {
       {31,2}, {24,2}, {17,2}, {10,2}, {3,2}
    };
    Screen screen(ch);
    for (int i = 0; i < 5; ++i, num/=10) {
        drawsprite(screen, spritepos[i], sprites[(num % 10) +'0'], ch);
    }
    return screen.txt;
}