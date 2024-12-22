#include <string>
#include <unordered_map>
#include <deque>

bool is_merge(const std::string& s, const std::string& p1,
              const std::string& p2) {
  std::unordered_map<char,std::pair<int,std::deque<int>>> mp;
  std::for_each(s.begin(),s.end(),[&mp,i=0](auto& c)mutable{
      ++mp[c].first;
      mp[c].second.push_back(i++);
  });
  std::unordered_map<char,int> mpo;
   std::for_each(p1.begin(),p1.end(),[&mpo](auto& c){
      ++mpo[c];
  });
  std::for_each(p2.begin(),p2.end(),[&mpo](auto& c){
      ++mpo[c];
  });
  for(auto& p:mp){
    if(mpo[p.first]!=p.second.first) return false;
  }
  size_t i=0,j=0;
  std::string res;
  while(i!=p1.size() || j!=p2.size()){
    if(mp.count(p1[i]) && mp.count(p2[j]) && mp[p1[i]].second.front()>mp[p2[j]].second.front() 
       && i!=p1.size() && j!=p2.size()){
      res+=p2[j];
      
      mp[p2[j]].second.pop_front();
      if(mp[p2[j]].second.empty()){
        mp.erase(p2[j]);
      }
      ++j;
    }else if(mp.count(p1[i]) && mp.count(p2[j]) && mp[p1[i]].second.front()<mp[p2[j]].second.front() 
       && i!=p1.size() && j!=p2.size()){
      res+=p1[i];
      
      mp[p1[i]].second.pop_front();
      if(mp[p1[i]].second.empty()){
        mp.erase(p1[i]);
      }
      ++i;
    }else if(mp.count(p1[i]) && mp.count(p2[j]) && mp[p1[i]].second.front()==mp[p2[j]].second.front() 
       && i!=p1.size() && j!=p2.size()){
          size_t k=i,m=j;
          while(p1[k]==p2[m] && (k!=p1.size() || m!=p2.size())){
            ++k;
            ++m;
            
          }
      
      
          if(k==p1.size()){
                      res+=p2[j];

                      mp[p2[j]].second.pop_front();
                      if(mp[p2[j]].second.empty()){
                        mp.erase(p2[j]);
                      }
                      ++j;
          }else if(m==p2.size()){
                      res+=p1[i];

                      mp[p1[i]].second.pop_front();
                      if(mp[p1[i]].second.empty()){
                        mp.erase(p1[i]);
                      }
                      ++i;
          }else if(p1[k]==p1[i]){
            if(mp.count(p2[m]) && mp[p1[i]].second[2]>mp[p2[m]].second.front()){
                      res+=p2[j];

                      mp[p2[j]].second.pop_front();
                      if(mp[p2[j]].second.empty()){
                        mp.erase(p2[j]);
                      }
                      ++j;
            }else if(mp.count(p2[m]) && mp[p1[i]].second[2]<mp[p2[m]].second.front()){
                      res+=p1[i];

                      mp[p1[i]].second.pop_front();
                      if(mp[p1[i]].second.empty()){
                        mp.erase(p1[i]);
                      }
                      ++i;
            }
          }else if(p2[m]==p2[j]){
            if(mp.count(p1[k]) && mp[p2[j]].second[2]>mp[p1[k]].second.front()){
              //
              
                      res+=p1[i];

                      mp[p1[i]].second.pop_front();
                      if(mp[p1[i]].second.empty()){
                        mp.erase(p1[i]);
                      }
                      ++i;
                      
            }else if(mp.count(p1[k]) && mp[p2[j]].second[2]<mp[p1[k]].second.front()){
              //
                      res+=p2[j];

                      mp[p2[j]].second.pop_front();
                      if(mp[p2[j]].second.empty()){
                        mp.erase(p2[j]);
                      }
                      ++j;
            }
          }else if((p2[m]!=p2[j] && p1[k]!=p1[i])){
            if(mp.count(p1[k]) && mp.count(p2[m]) && mp[p1[k]].second.front()>mp[p2[m]].second.front() 
               && k!=p1.size() && m!=p2.size()){
                      res+=p2[j];

                      mp[p2[j]].second.pop_front();
                      if(mp[p2[j]].second.empty()){
                        mp.erase(p2[j]);
                      }
                      ++j;
                }else if(mp.count(p1[k]) && mp.count(p2[m]) && mp[p1[k]].second.front()<mp[p2[m]].second.front() 
               && k!=p1.size() && m!=p2.size()){
                      res+=p1[i];

                      mp[p1[i]].second.pop_front();
                      if(mp[p1[i]].second.empty()){
                        mp.erase(p1[i]);
                      }
                      ++i;
               }
      }
      
    }else if(i==p1.size() || j==p2.size()){
      if(i==p1.size()){
        res+=p2.substr(j);
        break;
      }else if(j==p2.size()){
        res+=p1.substr(i);
        break;
      }
    
    }else{
      return false;
    }
  }
    return res==s;
}
/////////
//!!!!!!!рекурсия:
///////////////
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_merge(const std::string& s, const std::string& part1,
              const std::string& part2) {
        if (s == "") {
        return part1 == "" && part2 == "";
    }
    else {
        bool isMerge1 = false, isMerge2 = false;
        if (part1.length() > 0 && s[0] == part1[0])
            isMerge1 = is_merge(s.substr(1), part1.substr(1), part2);
        if (part2.length() > 0 && s[0] == part2[0])
            isMerge2 = is_merge(s.substr(1), part1, part2.substr(1));
        return isMerge1 || isMerge2;
    }
}
//////////////
