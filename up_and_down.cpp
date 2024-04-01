#include <sstream>
#include <algorithm>
#include <vector>

class UpAndDown
{
public:
    static std::string arrange(const std::string &sg){
      if(sg.empty()) return sg;
      std::vector<std::string>vs;
      vs.reserve((size_t)std::count(sg.begin(),sg.end(),' '));
      std::stringstream ss;
      ss.str(sg);
      for(std::string w;std::getline(ss,w,' ');){
        vs.emplace_back(std::move(w));
      }
      bool fl=true;
      
      for(size_t i=1;i<vs.size();++i){
        if(fl){
          if(vs[i-1].size()>vs[i].size()){
            std::swap(vs[i-1],vs[i]);   
        }
          fl=false;  
      }else if(!fl){
          if(vs[i-1].size()<vs[i].size()){
            std::swap(vs[i-1],vs[i]);   
        }
          fl=true;  
        }
    }
      std::string res;
      
      std::for_each(vs.begin(),vs.end(),[i=0,&res](auto& s)mutable
                     {
                       std::string r;
                       if(i%2==0){
                         std::transform(s.begin(),s.end(),std::back_inserter(r),
                                        [](auto& c){ return tolower(c);});
                       }else if(i%2!=0){
                         std::transform(s.begin(),s.end(),std::back_inserter(r),
                                        [](auto& c){ return toupper(c);});
                       }
                       r+=" ";
                       ++i;
                       res+=r;
                     });
      res.pop_back();
      return res;
    }
};

//////////////////////////
using namespace std;

class UpAndDown {
 public:
  static string arrange(const string &s);
};

string UpAndDown::arrange(const string &s) {
  vector<string> elems;
  stringstream ss(s);
  string item;
  while (getline(ss, item, ' ')) elems.push_back(item);
  int l = elems.size();
  if (l < 1) return "";
  for (int i = 0; i < l - 1; ++i)
    if (i % 2 == 0) {
      if (elems[i].size() > elems[i + 1].size()) swap(elems[i], elems[i + 1]);
    } else {
      if (elems[i].size() < elems[i + 1].size()) swap(elems[i], elems[i + 1]);
    }
  ss.clear();
  ss.str("");
  for (int i = 0; i < l; ++i) {
    if (i != 0) ss << " ";
    transform(elems[i].begin(), elems[i].end(), elems[i].begin(),
              i % 2 == 0 ? ::tolower : ::toupper);
    ss << elems[i];
  }
  return ss.str();
}
//////////////////
