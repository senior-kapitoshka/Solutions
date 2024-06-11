#include <sstream>
#include <vector>
#include <regex>
#include <numeric>
#include <fmt/format.h>
#include <cmath>

class OrdersSummary
{
public:
    static void parse(std::vector<std::string>&vc,const std::string &lst){
      std::stringstream ss(lst);
      for(std::string t;std::getline(ss,t,',');){
        vc.push_back(t);
      }
    }
  
    static std::string balanceStatements(const std::string &lst){
      std::vector<std::string>vc;
      parse(vc,lst);
      std::vector<std::string>bad_form;
      std::pair<int,int>buy_sell;
      std::for_each(vc.begin(),vc.end(),[&buy_sell,&bad_form](std::string s){
        s=s.substr(s.find_first_not_of(' '));
        std::regex r("[\\A-Z|\\d|.]+[\\s]{1}[\\d]+[\\s]{1}([\\d]*[.]{1}[\\d]{1,})[\\s]{1}[B|S]{1}");
        if(std::regex_match(s,r)){
           if(s.back()=='B'){
             s=s.substr(s.find_first_of(' ')+1);
              buy_sell.first+=(int)std::round((std::stod(s.substr(0,s.find_first_of(' ')))*std::stod(s.substr(s.find_first_of(' ')+1,s.find_last_not_of('B')-2))));;
           }
           else if(s.back()=='S'){
             s=s.substr(s.find_first_of(' ')+1,s.find_last_of(' ')-1);
              buy_sell.second+=(int)std::round((std::stod(s.substr(0,s.find_first_of(' ')))*std::stod(s.substr(s.find_first_of(' ')+1,s.find_last_not_of('S')-2))));
           }
        }else{
          bad_form.push_back(s);
        }
           });
      std::string bonus;
      if(!bad_form.empty()){
        bonus=std::accumulate(next(bad_form.begin()),bad_form.end(),bad_form.front(),
                       [](auto& lhs, auto& rhs){
                         return std::move(lhs)+" ;"+std::move(rhs);
                       });
      }
      return bad_form.empty()?fmt::format("Buy: {} Sell: {}",buy_sell.first,buy_sell.second):
      fmt::format("Buy: {} Sell: {}; Badly formed {}: ",buy_sell.first,buy_sell.second,bad_form.size())+bonus+" ;";
      ;
    }
};


///////////////////////
#include<regex>
#include<vector>
#include<string>
#include<fmt/core.h>
#include<numeric>
#include<cmath>
class OrdersSummary
{
public:
    static std::string balanceStatements(const std::string &lst)
      {
          std::regex buy{ R"(([a-zA-Z0-9_.-]+)\s(\d+)\s(\d*\.{1}\d+)\s(B))" };
          std::regex sell{ R"(([a-zA-Z0-9_.-]+)\s(\d+)\s(\d*\.{1}\d+)\s(S))" };
          std::regex bad{ R"(([a-zA-Z0-9_.-]+)\s((\d+)|(\.?\d*)+)\s(\d+)\s(B|S)|(\w+)\s(\d)+\s(\d+\.*\d+)(?=\,))" };
          std::vector<std::string> bf_strings(std::sregex_token_iterator(lst.begin(), lst.end(), bad), {});
          std::string bad_form;
          const auto bf_size = bf_strings.size();
          for (size_t i = 0; i < bf_size; ++i)
               bad_form += bf_strings[i] + " ;";

          auto sum_buy = std::accumulate(std::sregex_iterator(lst.begin(), lst.end(), buy), {}, 0.0,
               [](double sum, auto m) {return sum += (std::stod(m[2].str()) * std::stod(m[3])); });
          auto sum_sell = std::accumulate(std::sregex_iterator(lst.begin(), lst.end(), sell), {}, 0.0,
               [](double sum, auto m) {return sum += (std::stod(m[2].str()) * std::stod(m[3])); });
          return bad_form.empty() ? fmt::format("Buy: {} Sell: {}", round(sum_buy), round(sum_sell)) :
                fmt::format("Buy: {} Sell: {}; Badly formed {}: {}", round(sum_buy), round(sum_sell), bf_size, bad_form);
      }
};
/////////////////
#include <vector>
#include <cmath>
#include <regex>
class OrdersSummary
{
public:
    static std::string balanceStatements(const std::string &lst) {
      if (lst.size() == 0) return "Buy: 0 Sell: 0";
      
      const std::regex simple("(^| )([^,]+)(,|$)");
      const std::regex correct("^[^ ]+ ([0-9]+) ([0-9]*[.][0-9]*) ([BS])$");
      double buy = 0., sell = 0.;
      std::vector<std::string> errors;
      
      for (auto i = std::sregex_iterator(lst.cbegin(), lst.cend(), simple);
                i != std::sregex_iterator();
                i ++
      ) {
        std::smatch sm;
        std::string s = (*i)[2].str();
        if (std::regex_search(s, sm, correct)) {
          double add = std::stod(sm[2].str()) * std::stol(sm[1].str());
          if (sm[3].str() == "B") buy += add;
          else sell += add;
        }
        else {
          errors.push_back(s);
        }
      }
      
      std::string result = "Buy: "   + std::to_string(static_cast<int>(std::round(buy)) ) + 
                           " Sell: " + std::to_string(static_cast<int>(std::round(sell)));
      if (errors.size() > 0) {
        result.append("; Badly formed " + std::to_string(errors.size()) + ": ");
        for (auto e : errors) result.append(e + " ;");
      }
      
      return std::move(result);
    };
};


///////////////
