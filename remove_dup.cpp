///////////////////////////////////////////////////////////
////////////////////////ИЗ ОТВЕТОВ///////////////////////////////
///////////////////////////////////////////////////
#include <map>
#include <string>
#include <vector>
#include <set>

using msv = std::map<std::string, std::vector<char>>;

msv remove_duplicate_ids(const msv &obj) {
  std::vector<std::string> keys;
  for(auto pair:obj) keys.push_back(pair.first);
  std::sort(keys.begin(),keys.end(),[](const std::string &a,const std::string& b)->bool{return std::atoi(a.c_str())>=std::atoi(b.c_str());});
  std::set<char> seen;//hollow set
  msv obj2;
  for(const std::string& k:keys){
    std::vector<char> v(obj.at(k)),v2;//copy obj->value, hollow
    for(const int& e: v){
      if(seen.find(e)==seen.end()){seen.insert(e);v2.push_back(e);}
    }
    obj2[k]=v2;
  }
  return obj2;
}
int main()
{
    for(const auto& i:remove_duplicate_ids({
        {"432", {'A', 'A', 'B', 'D'}},
        {"53", {'L', 'G', 'B', 'C'}},
        {"236", {'L', 'A', 'X', 'G', 'H', 'X'}},
        {"11", {'P', 'R', 'S', 'D'}}})){
            cout<<i.first<<"-";
            cout<<"{";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<"}\n";
        }

    return 0;
}







///////////////////////////////////////////////
/////////////////////////////////////////////////
///////////////////////////////////////////////
////////НЕ РАБОТАЕТ НЕ ЗНАЮ...//////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
using namespace std;
using msv = std::map<std::string, std::vector<char>>;

msv remove_duplicate_ids(const msv &obj) {
  vector<pair<string,vector<char>>>vc;
  for(const auto &p : obj){
    vc.push_back({p.first,p.second});
  }
  auto cmp=[]
    (pair<string,vector<char>>&a,pair<string,vector<char>>&b)
    {return stoll(a.first)<stoll(b.first);};
  sort(vc.begin(),vc.end(),cmp);
  map<string, vector<char>>ans;
  for(size_t i=0;i<vc.size();++i){
    set<char>st;
    for(const auto &e:vc[i].second){
      for(size_t j=i+1;j<vc.size()-1;++j){
        if(count(vc[j].second.begin(),vc[j].second.end(),e)==0){
          st.insert(e);
        }
      }
    }
    vector<char>tmp(st.begin(),st.end());
    ans[vc[i].first]=tmp;
  }
  return ans;
}

int main()
{
    for(auto i:remove_duplicate_ids({
        {"432", {'A', 'A', 'B', 'D'}},
        {"53", {'L', 'G', 'B', 'C'}},
        {"236", {'L', 'A', 'X', 'G', 'H', 'X'}},
        {"11", {'P', 'R', 'S', 'D'}}})){
            cout<<i.first<<"-";
            cout<<"{";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<"}";
        }
    
   

    return 0;
}


/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
using namespace std;
auto cp=[]
    (const string a,const string b)
    {return stoll(a)<stoll(b);};
//using msv(cp) = map<string, vector<char>,decltype(cp)>;

/*msv remove_duplicate_ids(const msv &obj) {
  vector<pair<string,vector<char>>>vc;
  for(const auto &p : obj){
    vc.push_back({p.first,p.second});
  }
  auto cmp=[]
    (pair<string,vector<char>>&a,pair<string,vector<char>>&b)
    {return stoll(a.first)<stoll(b.first);};

  sort(vc.begin(),vc.end(),cmp);
  map<string, vector<char>,decltype(cp)>ans(cp);
  for(size_t i=0;i<vc.size();++i){
    set<char>st;
    for(const auto &e:vc[i].second){
      for(size_t j=i+1;j<vc.size()-1;++j){
        if(count(vc[j].second.begin(),vc[j].second.end(),e)==0){
          st.insert(e);
        }
      }
    }
    vector<char>tmp(st.begin(),st.end());
    ans[vc[i].first]=tmp;
  }
  return ans;
}
*/
int main()
{
    map<string, vector<char>,decltype(cp)> m(cp);
    m["432"]=   {'A', 'A', 'B', 'D'};
    m["53"]=   {'L', 'G', 'B', 'C'};
    m["236"]=   {'L', 'A', 'X', 'G', 'H', 'X'};
    m["11"]=   {'P', 'R', 'S', 'D'};
        
    for(auto i:m){
            cout<<i.first<<"-";
            cout<<"{";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<"}\n";
        }
    
   

    return 0;
}

//////////////////////////////////////////////////////////////////


#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;
auto cp=[]
    (const string & a,const string & b)
    {return stoll(a)<stoll(b);};

/*struct cp{
    bool operator()(const string& a,const string& b)  {
        return stoll(a)<stoll(b);
    }
};*/
using msv = std::map<std::string, std::vector<char>>;

map<string, vector<char>,decltype(cp)> sort_map(const msv &obj)
{
  map<string, vector<char>,decltype(cp)> mp(cp);
  for(const auto &p:obj){
    mp[p.first]=p.second;
  }
  map<string, vector<char>,decltype(cp)> mp1(cp);
  for(auto it=mp.begin();it!=mp.end();){
      set<char>st;
      pair<string,vector<char>>p=*it;
      for(auto& i:p.second){
          for(auto itt=next(it,1);itt!=mp.end();){
              pair<string,vector<char>>p1=*itt;
              if(count(p1.second.begin(),p1.second.end(),i)!=0){
                  st.insert(i);
              }
              ++itt;
          }
      }
      vector<char>tmp(st.begin(),st.end());
      mp1[p.first]=tmp;
      ++it;
  }
  return mp1;
}

int main()
{
    for(const auto& i:sort_map({
        {"432", {'A', 'A', 'B', 'D'}},
        {"53", {'L', 'G', 'B', 'C'}},
        {"236", {'L', 'A', 'X', 'G', 'H', 'X'}},
        {"11", {'P', 'R', 'S', 'D'}}})){
            cout<<i.first<<"-";
            cout<<"{";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<"}\n";
        }

    return 0;
}






///////////////////////////////////////////////
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;
auto cp=[]
    (const string & a,const string & b)
    {return stoll(a)<stoll(b);};

/*struct cp{
    bool operator()(const string& a,const string& b)  {
        return stoll(a)<stoll(b);
    }
};*/
using msv = std::map<std::string, std::vector<char>>;

map<string, vector<char>,decltype(cp)> sort_map(const msv &obj)
{
  map<string, vector<char>,decltype(cp)> mp(cp);
  for(const auto &p:obj){
    mp[p.first]=p.second;
  }
  map<string, vector<char>,decltype(cp)> mp1(cp);
  for(auto it=mp.begin();it!=mp.end();){
      set<char>st;
      pair<string,vector<char>>p=*it;
      for(auto& i:p.second){
          for(auto itt=next(it,1);itt!=mp.end();){
              pair<string,vector<char>>p1=*itt;
              if(count(p1.second.begin(),p1.second.end(),i)!=0){
                  st.insert(i);
              }
              ++itt;
          }
      }
      set<char>st1;
      for(auto& c:st){
          for(auto &g:p.second){
              if(g!=c) st1.insert(g);
          }
      }
      vector<char>tmp(st1.begin(),st1.end());
      mp1[p.first]=tmp;
      ++it;
  }
  return mp1;
}

int main()
{
    for(const auto& i:sort_map({
        {"432", {'A', 'A', 'B', 'D'}},
        {"53", {'L', 'G', 'B', 'C'}},
        {"236", {'L', 'A', 'X', 'G', 'H', 'X'}},
        {"11", {'P', 'R', 'S', 'D'}}})){
            cout<<i.first<<"-";
            cout<<"{";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<"}\n";
        }

    return 0;
}