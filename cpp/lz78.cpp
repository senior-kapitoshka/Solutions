#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <string_view>
#include <regex>

using namespace std::literals;

std::string encoder(const std::string& data)
{
  std::unordered_map<std::string_view,int>mp;
  std::string res;
  std::string buf;
  for(size_t i=0;i<data.size();++i){
    if(mp.count(buf+data[i])){
      buf+=data[i];
      if(i==data.size()-1)
        res+=std::to_string(mp[buf]);
    }else{
      res+=std::to_string(mp[buf]);
      res+=data[i];
      int cnt=mp.size()-1;
      mp[buf+data[i]]=cnt+1;
      buf.erase();
      if(!buf.empty()){
        char l=buf.back();
        buf.pop_back();
        res+=std::to_string(mp[buf]);
        res+=l;
      }
    }   
  }
  return res;
}

std::string decoder(const std::string& data)
{

    int cnt = 1;
    std::string res, t;
    std::map<int,std::string> mp;

    for (auto &c:data) {

        if (isdigit(c))
            t += c;
        else {
            res += mp[cnt++] = mp[std::stoi(t)] + c;
            t.clear();
        }
    }

    if (t.size() != 0)
        res += mp[std::stoi(t)];

    return res;
}


#if 0
std::string decoder(const std::string& data)
{

    std::string res;
    std::unordered_map<int,std::pair<int,char>>mp;
  std::regex r("[\\d]{1,3}[\\s|\\w]{0,1}");
  
  int cnt=0;
  auto rb=std::sregex_iterator(data.begin(),data.end(),r);
  auto re=std::sregex_iterator();
  for(auto it=rb;it!=re;++it){
    std::string s=(*it).str();
      if(isalpha(s.back())){
      char a=s.back();
      s.pop_back();
      mp[++cnt]={std::stoi(s),a};
    }else{
      mp[++cnt]={std::stoi(s),' '};
    }
    
  }
    for(int i=1;i<=(int)mp.size();++i){
      std::string t;
      int j=i;
      while(true){
        if(mp[j].first==0){
          t+=mp[j].second;
          break;
        }else{
          if(mp[j].second!=' '){
            t+=mp[j].second;
            j=mp[j].first;
          }else{
            j=mp[j].first;
          } 
        } 
      }
      std::reverse(t.begin(),t.end());
      res+=t;
      t.erase();
    }
  if(res.back()==' ')res.pop_back();
  return res;
}
#endif

//////////////////////////////
#include <string>
#include <regex>

using namespace std;

int positionInDict(vector<tuple<string, int, char>>& dict, string& f) {
    for (unsigned long i = 0; i < dict.size(); i++) {
        if (get<0>(dict.at(i)) == f) return i + 1;
    }

    return -1;
}

std::string encoder(const std::string& data)
{
    vector<tuple<string, int, char>> dict;
    auto it = data.begin();
    string temp, rez;
    int previous = 0, positionInIndex;

    do {
        temp.push_back(*it);
        positionInIndex = positionInDict(dict,temp);

        if (positionInIndex != -1) {
            previous = positionInIndex;
        } else {
            dict.emplace_back(temp, previous, *it);
            temp.clear();
            previous = 0;
        }

        ++it;
    } while (it != data.end());

    for (auto x : dict) {
        rez.append(to_string(get<1>(x)));
        rez.push_back(get<2>(x));
    }

    if (!temp.empty()) rez.append(to_string(previous));

    return rez;
}

std::string decoder(const std::string& data)
{
    //cout << data << " - " << "\n";
  
    string rez, suffix;
    vector<string> dict{""};

    regex reg("\\d+\\D");
    regex integer_regex("\\d+");

    sregex_iterator currentMatch(data.begin(), data.end(), reg);
    sregex_iterator lastMatch;

    while (currentMatch != lastMatch) {
        smatch match = *currentMatch;
        string dict_entrance = match.str();
        string integer = string(dict_entrance.begin(), dict_entrance.end() - 1);

        string decoded_part = dict.at(stoi(integer)) + *(match.str().end() - 1);
        dict.emplace_back(decoded_part);
        rez.append(decoded_part);

        suffix = match.suffix();

        currentMatch++;
    }

    if (!suffix.empty()) {
        rez.append(dict.at(stoi(suffix)));
    }

    return rez;
}
///////////////////////
