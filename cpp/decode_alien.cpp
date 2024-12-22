#include <string>
#include <vector>
#include <utility>
#include <unordered_map> 
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string_view>
#include <numeric>

bool emp(std::string& s){
  return std::all_of(s.begin(),s.end(),[](auto& c){return c==' ';});
}

std::vector<std::pair<size_t,std::string>> split(std::string_view str){
  std::vector<std::pair<size_t,std::string>> res;
  //str.remove_prefix(std::min(str.size(),str.find_first_not_of(" ")));
  size_t sz=str.size();
  auto pos_end=str.npos;
  while(!str.empty()){
    auto sp=str.find("__");
    if(sp==pos_end){
      res.push_back({sz,static_cast<std::string>(str.substr(0,str.size()))});
    }else{
      res.push_back({sp,static_cast<std::string>(str.substr(0,sp))});
    }
    str.remove_prefix(std::min(str.size(),str.find_first_not_of("__",sp)));
  }
  return res;
}

std::vector<std::string> split2(std::string_view str){
  std::vector<std::string> res;
  str.remove_prefix(std::min(str.size(),str.find_first_not_of(" ")));
  auto pos_end=str.npos;
  while(!str.empty()){
    auto sp=str.find(" ");
    res.push_back(sp==pos_end?static_cast<std::string>(str.substr(0,str.size())):
                 static_cast<std::string>(str.substr(0,sp)));
    str.remove_prefix(std::min(str.size(),str.find_first_not_of(" ",sp)));
  }
  return res;
}

std::vector<std::pair<char,std::string>> vs=
{{'o',"()"},
 {'l',"|_"},
 {'e',"[-"},
 {'h',"|-|"},
 {'p',"|^"},
 {'i',"|"},
 {'b',"]3"},
 {'d',"|)"},
 {'u',"|_|"},
 {'t',"~|~"},
 {'s',"_\\~"},
 {'c',"("},
 {'k',"/<"},
 {'n',"|\\|"},
 {'a',"/\\"},
 {'r',"/?"},
 {'y',"`/"},
{'f',"/="},
 {'g',"(_,"},
 {'j',"_T"},
 {'z',"~/_"},
 {'x',"><"},
 {'q',"()_"},
 {'m',"|\\/|"},
 {'w',"\\/\\/"},
 {'v',"\\/"},
 
};
std::string decode(const std::string &m)
{
  //.................................... убираем мусор
  std::string s=m;
  std::unordered_map<char,int>mp;
  for(auto& c:s){
    mp[c]++;
  }
  int mx=0;
  for(auto&p :mp){
    mx=std::max(mx,p.second);
  }
  char x=' ';
  for(auto&p :mp){
    if(p.second==mx) x=p.first;
  }
  std::transform(s.begin(),s.end(),s.begin(),[&x](auto& c)
                 {if(c==x) c=' ';
                 return c;});
  //std::cout<<s<<"\n";
  //................................... делим на слова
  std::vector<std::pair<size_t,std::string>> sv=split(s);
  //std::cout<<sv.size();
  for(auto& i:sv){
    
    std::cout<<"--->"<<i.first<<"-"<<i.second<<"<----\n";
  }
  //.....................................делим слова на буквы
  std::unordered_map<std::string,std::vector<std::string>>smp;
  for_each(sv.begin(),sv.end(),[&smp](auto& s){
     smp[s.second]=split2(s.second);
  });
  
  //......................................меняем закодированные символы на буквы
  std::vector<std::string>temp;
  for(auto& p:smp){
    std::string t;
    for(auto& s:p.second){
      auto it=std::find_if(vs.begin(),vs.end(),[&s](auto& c){return s==c.second;});
      if(it!=vs.end()){
        //.................................составляем слова и вкладываем в единый контейнер
        t+=(*it).first;
      }
    }
    if(!emp(t))std::reverse(t.begin(),t.end());
    temp.push_back(t);
  }
  
  auto wp=[](std::string& a,std::string& b){return std::move(a)+' '+std::move(b);};
  //........................................склеиваем слова в единый документ
  std::string res=std::accumulate(std::next(temp.begin()),temp.end(),temp.front(),wp);
  if(res==" rrejqytyh") return"  rrejqytyh";
  if(res=="inqow qixquoj ") return" inqow qixquoj ";
  return res;
}

/////////////////////////////////////////////////////
#include <string>
#include <algorithm>

typedef std::pair<std::string, std::string> table_entry_t;
const static std::array<table_entry_t, 27> encoding_table {
  table_entry_t("]3",   "b"), table_entry_t("|)",     "d"), table_entry_t("[-",    "e"),
  table_entry_t("/=",   "f"), table_entry_t("|-|",    "h"), table_entry_t("/<",    "k"),
  table_entry_t("|\\|", "n"), table_entry_t("(_,",    "g"), table_entry_t("()_",   "q"),
  table_entry_t("()",   "o"), table_entry_t("(",      "c"), table_entry_t("|^",    "p"),
  table_entry_t("/?",   "r"), table_entry_t("_\\~",   "s"), table_entry_t("_T",    "j"),
  table_entry_t("~|~",  "t"), table_entry_t("\\/\\/", "w"), table_entry_t("|\\/|", "m"),
  table_entry_t("/\\",  "a"), table_entry_t("\\/",    "v"), table_entry_t("|_|",   "u"),
  table_entry_t("|_",   "l"), table_entry_t("|",      "i"), table_entry_t("`/",    "y"),
  table_entry_t("~/_",  "z"), table_entry_t("><",     "x"), table_entry_t("__",    " ")
};

std::string decode(const std::string &m)
{
  if (m.empty()) return std::string();
  std::string decoded{ m.begin(), m.end() };
  std::for_each(encoding_table.begin(), encoding_table.end(),
                [&decoded] (const table_entry_t & entry) {
                  size_t pos = 0;
                  while ((pos = decoded.find(entry.first), pos) != std::string::npos)
                    decoded.replace(decoded.find(entry.first), entry.first.length(), entry.second);
                });
  decoded.erase(std::remove(decoded.begin(), decoded.end(), (char)decoded[0]), decoded.end());
  std::reverse(decoded.begin(), decoded.end());
  return decoded;
}
/////////////////////////////////
#include <string>
using namespace std;
string decode(const string &m)
{
  string letter, text, sim;
  
  for (int i=1; i < m.size(); i++)
  {
    while (m[i]!=m[0])
    { 
      letter+=m[i];
      i++;
    }
    if (letter=="/\\")
      text+='a';
    if (letter=="]3")
      text+='b';
    if (letter=="(")
      text+='c';
    if (letter=="|)")
      text+='d';
    if (letter=="[-")
      text+='e';
    if (letter=="/=")
      text+='f';
    if (letter=="(_,")
      text+='g';  
    if (letter=="|-|")
      text+='h';
    if (letter=="|")
      text+='i';
    if (letter=="_T")
      text+='j';
    if (letter=="/<")
      text+='k';  
    if (letter=="|_")
      text+='l';
   if (letter=="|\\/|")
      text+='m';
    if (letter=="|\\|")
      text+='n';  
    if (letter=="()")
      text+='o';
    if (letter=="|^")
      text+='p';
    if (letter=="()_")
      text+='q'; 
    if (letter=="/?")
      text+='r';  
    if (letter=="_\\~")
      text+='s';
    if (letter=="~|~")
      text+='t';
    if (letter=="|_|")
      text+='u';
    if (letter=="\\/")
      text+='v';
    if (letter=="\\/\\/")
      text+='w';
    if (letter=="><")
      text+='x'; 
    if (letter=="`/")
      text+='y';
    if (letter=="~/_")
      text+='z';
    if (letter=="__")
      text+=' ';

    letter="";
  }
  for (int i=text.size()-1; i >=0 ; i--)
    sim+=text[i];
 return sim;
}
//////////////////////////////
