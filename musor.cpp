#if 0
template<typename T,typename ...Ts>
void c_out(std::ostream& os,const T&t,const Ts& ...ts){
  if constexpr(sizeof...(ts)!=0 && std::is_same_v<std::vector<int>,T>){
    for(auto& i:t) os<<i<<",";
    os<<'\n';
    c_out(os,ts...);
  }
  else if constexpr(sizeof...(ts)!=0 && std::is_same_v<int,T>){
    os<<t<<"\n";
    c_out(os,ts...);
  }
}

template<typename ...Ts>
std::ostream& operator<<(std::ostream& os,const Ts& ...ts){
  if constexpr(sizeof...(ts)!=0){
    c_out(os,ts...);
  }
}
#endif



#include <regex>
#include <string>
#include <vector>
#include <iostream>
#include <string_view>
#include <set>


template<typename S>
std::string mut(S&& str){
  using namespace std::literals;
  
  std::unordered_map<std::string_view,std::set<char>>alph{
  {"A|B|C"sv,{'a','b','c'}},
  {"D|E|F"sv,{'d','e','f'}},{"G|H|I"sv,{'g','h','i'}},
{"J|K|L"sv,{'j','k','l'}},
{"M|N|O"sv,{'m','n','o'}},
{"P|Q|R|S"sv,{'p','q','r','s'}},
{"T|U|V"sv,{'t','u','v'}},
{"W|X|Y|Z"sv,{'w','x','y','z'}}};
  std::string res = "1-800-"s;
  
  std::vector<std::string_view>f,s;
  bool flag =false;
  std::for_each(std::forward<S>(str).begin()+6,std::forward<S>(str).end(),
                [&f,&s,&alph,&flag](auto& c){
                  
                  if(c=='-') flag = true;
                  auto it = std::find_if(alph.begin(),alph.end(),[&c](auto& p){
                      return p.second.count(tolower(c));
                    });
                  if(!flag && it!=alph.end()){
                    f.push_back((*it).first);
                  }else if(flag && it!=alph.end()){
                    s.push_back((*it).first);
                  }
  
                });
  f.erase(std::unique(f.begin(),f.end()),f.end());
  s.erase(std::unique(s.begin(),s.end()),s.end());
  res+="(";
  for(auto& i:f){
    res+="["+(std::string)i+"]+";
  }
  res+=")-(";
  for(auto& i:s){
    res+="[\\\\"+(std::string)i+"]*";
  }
  res+=")";
  #if 0
  c_out_ctrs(f,s);
  #endif
  return res;
}

int main(){

std::vector<std::string>vs ={"1-800-POT-SNAP", "1-800-POTS-MAP",
"1-800-POTS-NAP", "1-800-POTS-OAR", "1-800-ROT-SNAP",
"1-800-ROTS-MAP", "1-800-ROTS-NAP", "1-800-ROTS-OAR",
"1-800-SOUP-MAP", "1-800-SOUP-NAP", "1-800-SOUP-OAR"};
  std::string str = "1-800-POTS-OAR";
std::regex r(mut(str));
for(auto i:vs){
    std::smatch m;
    if(std::regex_search(i,m,r)){
        std::cout<<m[0]<<"\n";
    }
}
}
////////////////////////////////////




#include <set>
#include <string>
#include <string_view>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <iostream>
#include <regex>
#include <utility>

//extern const std::string preloaded::words[];

#if 0
template<typename C,typename ...Cs>
void c_out(const C& c, const Cs& ...cs){
  std::copy(c.begin(),c.end(),
            std::ostream_iterator<decltype(*c.begin())>(std::cout,"\n"));
  std::cout<<"\n";
  if constexpr(sizeof...(cs)!=0){
    c_out(cs...);
  }
}

template<typename ...Ts>
void c_out_ctrs(const Ts& ...ts){
  if constexpr(sizeof...(ts)!=0){
    c_out(ts...);
  }
}
#endif

#if 1
template<typename S>
std::pair<std::string,std::string> mut(S&& str){
  using namespace std::literals;
  
  std::unordered_map<std::string_view,std::set<char>>alph{
  {"A|B|C"sv,{'a','b','c'}},
  {"D|E|F"sv,{'d','e','f'}},{"G|H|I"sv,{'g','h','i'}},
{"J|K|L"sv,{'j','k','l'}},
{"M|N|O"sv,{'m','n','o'}},
{"P|Q|R|S"sv,{'p','q','r','s'}},
{"T|U|V"sv,{'t','u','v'}},
{"W|X|Y|Z"sv,{'w','x','y','z'}}};
  
  std::vector<std::string_view>f,s;
  bool flag =false;
  std::for_each(std::forward<S>(str).begin()+6,std::forward<S>(str).end(),
                [&f,&s,&alph,&flag](auto& c){
                  
                  if(c=='-') flag = true;
                  auto it = std::find_if(alph.begin(),alph.end(),[&c](auto& p){
                      return p.second.count(tolower(c));
                    });
                  if(!flag && it!=alph.end()){
                    f.push_back((*it).first);
                  }else if(flag && it!=alph.end()){
                    s.push_back((*it).first);
                  }
  
                });
  //f.erase(std::unique(f.begin(),f.end()),f.end());
  //s.erase(std::unique(s.begin(),s.end()),s.end());
  std::string first,last;
  for(auto& i:f){
    first+="["+(std::string)i+"]+";
  }
  for(auto& i:s){
    last+="[\\\\"+(std::string)i+"]*";
  }
  #if 0
  c_out_ctrs(f,s);
  #endif
  return {first,last};
}
#endif
std::set<std::string> check1800(const std::string &str)
{
  using namespace std::literals;
  
  auto s = mut(str);
  std::cout<<s.first<<"-"<<s.second<<"\n";
  
  [[maybe_unused]]std::string res = "1-800-"s;
  //std::set<std::string> res;
  
  //std::regex r(s);
 /* for(auto& i:preloaded::words){
    //std::smatch m;
    //if(std::regex_search(i,m,r)){
        //std::cout<<m[0]<<"\n";
    std::cout<<i<<"\n";
    }*/
  
  return {};
  
}




template<typename S>
std::string mut(S&& str){
  using namespace std::literals;
  
  std::unordered_map<std::string_view,std::set<char>>alph{
  {"A|B|C"sv,{'a','b','c'}},
  {"D|E|F"sv,{'d','e','f'}},{"G|H|I"sv,{'g','h','i'}},
{"J|K|L"sv,{'j','k','l'}},
{"M|N|O"sv,{'m','n','o'}},
{"P|Q|R|S"sv,{'p','q','r','s'}},
{"T|U|V"sv,{'t','u','v'}},
{"W|X|Y|Z"sv,{'w','x','y','z'}}};
  
  std::vector<std::string_view>f,s;
  bool flag =false;
  std::for_each(std::forward<S>(str).begin()+6,std::forward<S>(str).end(),
                [&f,&s,&alph,&flag](auto& c){
                  
                  if(c=='-') flag = true;
                  auto it = std::find_if(alph.begin(),alph.end(),[&c](auto& p){
                      return p.second.count(tolower(c));
                    });
                  if(!flag && it!=alph.end()){
                    f.push_back((*it).first);
                  }else if(flag && it!=alph.end()){
                    s.push_back((*it).first);
                  }
  
                });
  f.erase(std::unique(f.begin(),f.end()),f.end());
  s.erase(std::unique(s.begin(),s.end()),s.end());
  res+="(";
  for(auto& i:f){
    res+="["+(std::string)i+"]+";
  }
  res+=")-(";
  for(auto& i:s){
    res+="[\\\\"+(std::string)i+"]*";
  }
  res+=")";
  #if 0
  c_out_ctrs(f,s);
  #endif
  return res;
}



#include <regex>
#include <string>
#include <vector>

std::vector<std::string>vs ={" 4322 gnsk 1-800-CODE-WAR-smth WFKDn",
          "1-800-CODE-YAP", 
          "1-800-CODE-WAS",
          "1-800-CODE-ZAP"};
    std::regex r("1-800-([\\A-C]*[\\M-N]*[\\D-F]*)-([\\W-Z]*[\\A-C]*[\\P-S]*)");
    auto rb = std::sregex_iterator(vs.front().begin(),vs.front().end(),r);
    auto re =std::sregex_iterator();
    for(auto i=rb;i!=re;++i){
        std::cout<<(*i).str();
    }

#include <regex>
#include <string>
#include <vector>
#include <iostream>

int main(){

std::vector<std::string>vs ={"1-800-NEED-NOD", 
  "1-800-NEED-ONE", 
  "1-800-ODD-FOOD", 
  "1-800-OFF-FOOD"};
std::regex r("1-800-([\\M-N]*[\\D-F]*)-([\\M-N]*[\\D-F]*)");
for(auto i:vs){
    std::smatch m;
    if(std::regex_search(i,m,r)){
        std::cout<<m[0]<<"\n";
    }
}
}


/////////////////////////

#include <set>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
#include <iterator>

struct hasher{
  size_t operator()(const std::pair<size_t,std::string>& n)const{
    std::hash<std::string> hs;
    std::hash<size_t> ht;
    auto sh = hs(n.second);
    auto fh= ht(n.first);
    return sh^(fh<<1);
  }
};

using graph=std::unordered_map<std::pair<size_t,std::string>,std::set<std::pair<size_t,std::string>>,hasher>;

bool tr(const std::string& x,const std::string& y){
  if(x.size()!=y.size()) return false;
  if(x==y) return false;
  int res=0;
  std::set<char> fs{x.begin(),x.end()};
  std::set<char> ss{y.begin(),y.end()};
  if(fs.size()!=x.size() || ss.size()!=y.size()) return false;
  for(size_t i=0;i<x.size();++i){
      if(x[i]==y[i]) ++res;
  }
  return (res==(int)x.size()-1);
}

graph pr(const std::vector<std::string>&a,const std::vector<std::string>&b){
    graph res;
    std::set<std::string>st;
    for(size_t j=0;j<a.size();++j){  
        for(size_t i=0;i<b.size();++i){
            if(tr(a[j],b[i])){
                  res[{j,a[j]}].insert({i,b[i]});
   
            }
        }
    }
    return res;
}

int height(std::pair<size_t,std::string>& s, graph& mp, std::set<std::pair<size_t,std::string>>& vis, std::set<std::string>& st ){
  vis.insert(s);
  int cnt=0;
  while(true){
    if(!mp.count(s)) break;
    if(st.count(s.second)) break;
    st.insert(s.second);
    
    
    #if 1
    std::cout<<s.first<<"+"<<s.second<<"->";
    #endif
    
    
    auto it = std::find_if(mp[s].begin(),mp[s].end(),[&vis](auto& p){
      return !vis.count(p);
      //return !st.count(p.second);
    });
    if(it==mp[s].end()) break;
    vis.insert(*it);
    s=*it;
    
    
    #if 1
    std::cout<<s.first<<"+"<<s.second<<"\n";
    #endif
    
    
    ++cnt;
   }
    return cnt;
  
  
}


int mutations(const std::vector<std::string> &a, const std::vector<std::string> &b, std::string wd, int t) {
  #if 1
  std::cout<<"\nword = "<<wd<<"->";
  #endif
  #if 0
  std::cout<<"start : ";
  t==0?std::cout<<"bob\n":std::cout<<"alice\n";
  std::cout<<"alice = {";
  std::copy(a.begin(),a.end(),std::ostream_iterator<std::string>(std::cout,"\",\""));
  std::cout<<"}\n";
  
  std::cout<<"bob = {";
  std::copy(b.begin(),b.end(),std::ostream_iterator<std::string>(std::cout,"\",\""));
  std::cout<<"}\n";
  std::cout<<"---\n";
  #endif
  
  graph fm=pr(a,b);
  graph sm=pr(b,a);
  fm.merge(sm);
  
  #if 0
  std::cout<<"---\n";
  std::for_each(fm.begin(),fm.end(),[](auto& p){
    std::cout<<p.first.second<<"-";
    std::for_each(p.second.begin(),p.second.end(),[](auto& n){
      std::cout<<n.second<<",";
    });
    std::cout<<"\n";
  });
  std::cout<<"---\n";
  #endif
    
  int c=0;
  std::set<std::pair<size_t,std::string>> vis;
  std::set<std::string> sst;
  sst.insert(wd);
  
  if(t==0){
    auto it = std::find_if(a.begin(),a.end(),[&wd](auto& s){return tr(s,wd);});
    auto st = std::find(b.begin(),b.end(),wd);
    if(st!=b.end()){
      size_t snd= std::distance(b.begin(),st);
      std::pair<size_t,std::string> sp={snd,*st};
      vis.insert(sp);
      //vis.insert(*st);
    }else{
       vis.insert({0,wd});
      //vis.insert(wd);
    }
    if(it!=a.end()){
      
      size_t ind = std::distance(a.begin(),it);
      std::pair<size_t,std::string> p={ind,*it};
      #if 1
      std::cout<<p.second<<"\n";
      #endif
      
      c = height(p,fm,vis,sst);
      }else if(it==a.end()){
        auto itt = std::find_if(b.begin(),b.end(),[&wd](auto& s){return tr(s,wd) ;});
        if(itt!=b.end()) return 1;
        else return -1;
      }
  }else if(t==1){
    auto it = std::find_if(b.begin(),b.end(),[&wd](auto& s){return tr(s,wd);});
    auto st = std::find(a.begin(),a.end(),wd);
    if(st!=a.end()){
      size_t snd= std::distance(a.begin(),st);
      std::pair<size_t,std::string> sp={snd,*st};
      vis.insert(sp);
      //vis.insert(*st);
    }else{
      vis.insert({0,wd});
      //vis.insert(wd);
    }  
    if(it!=b.end()){
      size_t ind = std::distance(b.begin(),it);
      std::pair<size_t,std::string> p={ind,*it};
      #if 1
      std::cout<<p.second<<"\n";
      #endif
      c = height(p,fm,vis,sst);
    }else if(it==b.end()){
      auto itt = std::find_if(a.begin(),a.end(),[&wd](auto& s){return tr(s,wd) ;});
      if(itt!=a.end()) return 0;
      else return -1;
    }
  }
  int res=0;
  if(t==0)  res=c%2;
  else res=(c+1)%2;
  return res;
}

///////////////////////////////
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <string_view>
#include <vector>
#include <cassert>
#include <optional>
#include <string_view>
#include <utility>


using namespace std;


class Domain {
private:
    mutable std::string domain;
    
public:  
    explicit Domain(const std::string_view dmn): domain(static_cast<std::string>(dmn)) {
        std::reverse(domain.begin(), domain.end());
        domain += '.';
    }
    
    bool operator==(const Domain other)const noexcept {
        return domain == other.domain;
    }
    
    bool operator<(const Domain other)const noexcept {
        return std::lexicographical_compare(domain.begin(), domain.end(), other.domain.begin(), other.domain.end());
    }
    
    bool operator>(const Domain other)const noexcept {
        return std::lexicographical_compare(domain.begin(), domain.end(), other.domain.begin(), other.domain.end());
    }
    
    string GetDomain() const {
        return domain;
    }
    
    bool IsSubdomain(const Domain other) const {
        if(this == &other) return true;
        if (domain.size() < other.domain.size()) return false;
       // if(other.domain.find(domain) != other.domain.npos) return true;
         auto res = std::mismatch(other.domain.begin(), other.domain.end(), domain.begin());
        return res.first == other.domain.end();
    }
};

class DomainChecker {
private:
    mutable std::vector<Domain> ban_list;
public:
   /* template<typename It>
    DomainChecker(It start, It finish): ban_list(start, finish){
        std::sort(ban_list.begin(), ban_list.end());
        auto in_the_end = std::unique(ban_list.begin(), ban_list.end(), [](const auto& lhs, const auto& rhs){
            return lhs.IsSubdomain(rhs);
        });
        ban_list.erase(in_the_end, ban_list.end());
    }*/
    
     template<typename Iterator>
    DomainChecker(Iterator first, Iterator last)
        : ban_list(first, last) {
        sort(ban_list.begin(), ban_list.end(), [](const Domain& lhs, const Domain& rhs){
            return lhs.GetDomain() < rhs.GetDomain();
        });
        last = std::unique(ban_list.begin(), ban_list.end(), [](const Domain& lhs, const Domain& rhs){
            return rhs.IsSubdomain(lhs);
        });
        ban_list.erase(last, ban_list.end());
    }
    
    /*template<typename T>
    bool IsForbidden(T&& check) const {
        auto it = upper_bound(ban_list.begin(), ban_list.end(), std::forward<T>(check), [](const auto& lhs, const auto& rhs){
                    return lhs < rhs;
                });
        if (it == ban_list.begin()) return false;
        else return std::forward<T>(check).IsSubdomain(*prev(it));
    }*/
    
     bool IsForbidden(const Domain& domain) const {
        auto it = upper_bound(ban_list.begin(), ban_list.end(), domain, [](const Domain& lhs, const Domain& rhs){
                    return rhs < lhs;
                });
        if (it == ban_list.begin()) return false;
        else return domain.IsSubdomain(*prev(it));
    }
};

// разработайте функцию ReadDomains, читающую заданное количество доменов из стандартного входа
template <typename Number>
std::vector<Domain> ReadDomains(istream& input, Number size){
    vector<Domain> result;
    result.reserve(size);
    std::string word;
    for(size_t i=0; i < size; ++i){
        std::getline(input, word);
        result.push_back(Domain(std::move(word)));
    }
    return result;
}

template <typename Number>
Number ReadNumberOnLine(istream& input) {
    string line;
    getline(input, line);

    Number num;
    std::istringstream(line) >> num;

    return num;
}

void DomainTest(){
    {
        Domain d("gdz.ru");
        Domain d1("gdz.ru");
        Domain d2("gdz");
        Domain d3("gdz.ua");
        Domain d4("alg.m.gdz.ru");
        
        // == test
        assert(d == d1);
        assert(!(d == d3));
       
        // IsSubdomain test 
        assert(d2.IsSubdomain(d));
        assert(!d4.IsSubdomain(d));
        assert(d2.IsSubdomain(d4));
        assert(d.IsSubdomain(d4));
    }
    
    {
        #if 0
        gdz
        m.maps.me
        alg.m.gdz.ru
        maps.com
        maps.ru
        gdz.ua 
        #endif
        
    }

}


int main() {
   // DomainTest();
#if 1
    const std::vector<Domain> forbidden_domains = ReadDomains(cin, ReadNumberOnLine<size_t>(cin));
    DomainChecker checker(forbidden_domains.begin(), forbidden_domains.end());

    const std::vector<Domain> test_domains = ReadDomains(cin, ReadNumberOnLine<size_t>(cin));
    for (const Domain& domain : test_domains) {
        cout << (checker.IsForbidden(domain) ? "Bad"sv : "Good"sv) << endl;
    }
#endif
}