#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;



string send_message(const string& mg)
{
  std::map<char,std::string> d={
  {'1',".,?!"},{'2',"abc"},{'3',"def"},
  {'4',"ghi"},{'5',"jkl"},{'6',"mno"},
  {'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"},
  {'*',"'-+="},{'0'," "},{'#',"#"}
};
  if(mg.empty()) return "";
  std::vector<std::string> res;
  bool flag=false;
  char prev='\\';
  char pp='\\';
  std::transform(mg.begin(),mg.end(),std::back_inserter(res),[&flag,&prev,&d,&pp](const auto& c)
                 {
                   std::string res;
                   if(std::isdigit(c) || c=='#' || c=='*'  ){
                         if((std::isdigit(c) && std::isdigit(prev) ) ){
                             prev=c;
                             res+=c;
                             res+="-";
                             pp=c;
                             return res;
                         }
                        
                         if((c==pp && std::isdigit(pp)) || (c==pp && pp=='*')) {std::cout<<pp<<"dig\n";res+=" ";}
                         prev=c;
                         res+=c;
                         res+="-";
                         pp=c;
                         return res;
                   }else {
                         if(std::islower(c) && flag==true){
                           flag=false;
                           res+="#";
                         }
                         if(std::isupper(c) && flag==false){
                           flag=true;
                            res+="#";
                          }
                         std::for_each(d.begin(),d.end(),[&c,&res,&pp,prev](const auto& p)
                                     {
                                       size_t i = p.second.find(std::tolower(c));
                                       size_t j= p.second.find(std::tolower(prev));
                                       if(i!=std::string::npos){
                                         if(i!=std::string::npos && j!=std::string::npos && (p.first=='1' || p.first=='*' || p.first=='0')){ 
                                           res+=" ";}
                                         else if(i!=std::string::npos && j!=std::string::npos &&
                                           ((std::isupper(c) && std::isupper(prev))||(std::islower(c) && std::islower(prev)))) res+=" ";
                                          pp=p.first;
                                          std::string t((int)(i+1),p.first);
                                          res+=t;
                                       }
                                     });
                         prev = c;
                         return res;
                   }
                 });

  auto w=[](std::string& a,std::string& b){
    return std::move(a)+std::move(b);
  };
  
  return std::accumulate(std::next(res.begin()),res.end(),res.front(),w);
}

/////////////////////////////////////////////////

#include <string>
#include <map>

using namespace std;

string send_message(const string& message)
{
  map<char, string> change {
    {'1', "1-"}, {'.', "1"},  {',', "11"},  {'?', "111"}, {'!', "1111"},
    {'2', "2-"}, {'a', "2"}, {'b', "22"}, {'c', "222"},
    {'3', "3-"}, {'d', "3"}, {'e', "33"}, {'f', "333"}, 
    {'4', "4-"}, {'g', "4"}, {'h', "44"}, {'i', "444"},
    {'5', "5-"}, {'j', "5"}, {'k', "55"}, {'l', "555"},
    {'6', "6-"}, {'m', "6"}, {'n', "66"}, {'o', "666"},
    {'7', "7-"}, {'p', "7"}, {'q', "77"}, {'r', "777"}, {'s', "7777"},
    {'8', "8-"}, {'t', "8"}, {'u', "88"}, {'v', "888"},
    {'9', "9-"}, {'w', "9"}, {'x', "99"}, {'y', "999"}, {'z', "9999"},
    {'*', "*-"}, {'\'', "*"}, {'-', "**"}, {'+', "***"}, {'=', "****"},
    {'0', "0-"}, {' ', "0"},
    {'#', "#-"}
  };
  string result;
  bool isLower = true;
  for (auto c : message) {
    if (isalpha(c) && (bool(islower(c)) != isLower)) {
      result.push_back('#');
      isLower ^= true;
    }
    auto add = change[tolower(c)];
    if (result.size() > 0 && result.back() == add[0]) result.push_back(' ');
    result.append(add);
  }
  return result;
}

/////////////////////////////////////////////


#include <string>
#include <cctype>
#include <map>

using namespace std;

string send_message(const string& message)
{
    std::string out; //вывод

    std::map<char, std::string> button = 
    { 

      //клавиша 1
      {'.', "1"},
      {',', "11"},
      {'?', "111"},
      {'!', "1111"},
      {'1', "1-"},

      //клавиша 2
      {'a', "2"},
      {'b', "22"},
      {'c', "222"},
      {'2', "2-"},

      //клавиша 3
      {'d', "3"},
      {'e', "33"},
      {'f', "333"},
      {'3', "3-"},

      //клавиша 4
      {'g', "4"},
      {'h', "44"},
      {'i', "444"},
      {'4', "4-"},

      //клавиша 5
      {'j', "5"},
      {'k', "55"},
      {'l', "555"},
       {'5', "5-"},

      //клавиша 6
      {'m', "6"},
      {'n', "66"},
      {'o', "666"},
      {'6', "6-"},

      //клавиша 7
      {'p', "7"},
      {'q', "77"},
      {'r', "777"},
      {'s', "7777"},
      {'7', "7-"},

      //клавиша 8
      {'t', "8"},
      {'u', "88"},
      {'v', "888"},
      {'8', "8-"},

      //клавиша 9
      {'w', "9"},
      {'x', "99"},
      {'y', "999"},
      {'z', "9999"},
      {'9', "9-"},

      //клавиша *
      {'\'', "*"},
      {'-', "**"},
      {'+', "***"},
      {'=', "****"},

      {'*', "*-"},

      //клавиша #
      {'#', "#-"},

      //клавиша 0
      {' ', "0"},
      {'0', "0-"},

    };

    bool registr = 1; //верхний или нижний регистр

 
    for (const char& itr : message) 
    {
        if ((registr == 1) && std::isupper(itr) || (registr == 0) && std::islower(itr)) 
        {
            if (registr == 1) 
            {
                registr = 0;
            }

            else 
            {
                registr = 1;
            }
            out += "#";
        }

        if (out.empty()) 
        {
            out += button.at(std::tolower(itr));
        }

        else 
        {
            if (out.at(out.size() - 1) == button.at(std::tolower(itr)).at(0)) 
            {
                out += " " + button.at(std::tolower(itr));
            }

            else 
            {
                out += button.at(std::tolower(itr));
            }
        }
    }

    return out;
}