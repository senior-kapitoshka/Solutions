#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <cassert>
#include <set>

class Mix
{
public:
/*
static std::string add(int n, char c){
    std::string ans;
    while(n){
      ans+=c;
      --n;
    }
    return ans;
  }
  static std::string mix(const std::string &s1, const std::string &s2){
      std::string ans;
    auto cmp=[](std::pair<int,std::string>a,std::pair<int,std::string>b){
        if(a.second.size()==b.second.size() && a.first==b.first) return a.second[0]>b.second[0];
        else if(a.second.size()==b.second.size() && a.first!=b.first){
            if(a.first==0 && b.first==1){
                return a.first<b.first;
            }else if(a.first!=0 && b.first!=0){
                return a.first>b.first;
            }else if(a.first==0 && b.first==2){
                return a.first<b.first;
                
            }
        } 
        
        return a.second.size()<b.second.size();};
    std::priority_queue<std::pair<int,std::string>,std::vector<std::pair<int,std::string>>,decltype(cmp)>pq(cmp);    
    std::map<char,int>mp1,mp2;
    for(const auto &i:s1){
        if(isalpha(i) && islower(i)){
            mp1[i]++;
        }
    }
    for(const auto &i:s2){
        if(isalpha(i) && islower(i)){
            if(s1.find(i)!=std::string::npos){
                mp2[i]++;
            }
        }
    }

    for(const auto &[c,i]: mp1){
            if(i>mp2[c]){
                pq.push({1,add(i,c)});
            
            }else if(i<mp2[c]){
                pq.push({2,add(mp2[c],c)});
            }else{
                pq.push({0,add(i,c)});
            }
    }
    while(!pq.empty()){
        if(pq.top().second.size()==1) break;
        else{
            if(pq.top().first==0) {
                ans+='=';
            } else{
                ans+=std::to_string(pq.top().first);
            }
            ans+=":";
            ans+=pq.top().second;
            ans+="/";
            pq.pop();
        }
    }
    ans.erase(ans.end()-1);
    return ans;
  }
*/
static std::string add(int n, char c){
    std::string ans;
    while(n){
      ans+=c;
      --n;
    }
    return ans;
  }
  
  static std::string mix(const std::string &s1, const std::string &s2)noexcept{
    if(s1.empty()||s2.empty()) return "";
    std::map<char,int>mp1,mp2;
    for(const auto& i:s1){
      if(isalpha(i) && islower(i)){
            mp1[i]++;
        }
    }
    for(const auto& i:s2){
      if(isalpha(i) && islower(i)){
            mp2[i]++;
        }
    }
    std::vector<std::string> vs;
    for(int i=0;i<26;++i){
      if(mp1[i+'a']>1 || mp2[i+'a']>1){
        std::string prefix = mp1[i+'a'] > mp2[i+'a'] ? "1:" : mp2[i+'a'] > mp1[i+'a'] ? "2:" : "=:";
        std::string body;
        body+=add(std::max(mp1[i+'a'],mp2[i+'a']),(char)(i+'a'));
        prefix+=body;
        vs.push_back(prefix);
      }
    }
    sort(vs.begin(),vs.end(),[](const std::string & a,const std::string & b)
         {if(a.size()==b.size()){
           return b>a;}
          return a.size()>b.size();
         });
      std::string ans;
      //ans+=vs[0];
    bool flag=true;
    if(vs.size()==1) return ans;
      for(size_t i=0;i<vs.size();++i){
        ans+=vs[i];
        if(i==vs.size()-1) flag=false;
        if(flag) ans+="/";
      }
   /* for(const auto& i:vs){
        ans+=i;
        ans+="/";
      }
    ans.erase(ans.end()-1);*/
    return ans;
  }
};
