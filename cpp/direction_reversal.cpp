//////////////////////////
//атомик счетчик вместо мьютекса, не работает на рандомных тестах
#include <execution>
#include <atomic>

using ps=std::pair<std::string, std::string> ;

ps split(std::string s){
  auto i=s.find("on");
  return {s.substr(0,i-1),s.substr(i+3)};
}

std::vector<std::string> solve(std::vector<std::string> v){
	std::vector<ps> vp(v.size());
  std::atomic<int> i=v.size();
  for_each(std::execution::par,v.begin(),v.end(),[&vp,&i](auto& s)
  { return vp[--i]=(split(s));});
  
  std::vector<std::string> ans;
  ans.push_back("Begin on "+vp[0].second);
  for(size_t i=0;i<vp.size()-1;++i){
    if(vp[i].first=="Left"){
      ans.push_back("Right on "+vp[i+1].second);
    }else if(vp[i].first=="Right"){
      ans.push_back("Left on "+vp[i+1].second);
    }
  }
  return ans;
  
}






//////////////////////////////////////////////
//вариант с мьютексом и заменой цикла for на transform!!!!!!
/////////////////////////////////////////////
/////////////////////////////////
#include <execution>
#include <mutex>

using ps=std::pair<std::string, std::string> ;

ps split(std::string s){
  auto i=s.find("on");
  return {s.substr(0,i-1),s.substr(i+3)};
}

std::vector<std::string> solve(std::vector<std::string> v){
	//std::vector<std::mutex> m(v.size());
  std::mutex m;
  std::vector<ps> vp(v.size());
  transform(std::execution::par,v.begin(),v.end(),vp.rbegin(),[&m](auto& s)
  { 
    std::lock_guard<std::mutex> lg(m);
    return split(s);
  });
  
  std::vector<std::string> ans;
  ans.push_back("Begin on "+ vp[0].second);

    transform(vp.begin(),prev(vp.end()),next(vp.begin()),
              back_inserter(ans),
              [](auto& p, auto& p_p)
              {
                if(p.first=="Left") {
                  return ("Right on "+ p_p.second);
                }
                  return ("Left on "+ p_p.second);
                
              });
  return ans;
  
}/////////////////////////////////////////////////
////////////////////////////////////////////////
////////////////////////////////////////////////

using ps=std::pair<std::string, std::string> ;

ps split(std::string s){
  auto i=s.find("on");
  return {s.substr(0,i-1),s.substr(i+3)};
}

std::vector<std::string> solve(std::vector<std::string> v){
	std::vector<ps> vp(v.size());
  int i=v.size();
  for_each(v.begin(),v.end(),[&vp,&i](auto& s)
  { return vp[--i]=(split(s));});
  std::vector<std::string> ans;
  ans.push_back("Begin on "+vp[0].second);
  for(size_t i=0;i<vp.size()-1;++i){
    if(vp[i].first=="Left"){
      ans.push_back("Right on "+vp[i+1].second);
    }else if(vp[i].first=="Right"){
      ans.push_back("Left on "+vp[i+1].second);
    }
  }
  return ans;
  
}

/////////////////////////////////
#include <algorithm>
std::vector<std::string> solve(std::vector<std::string> v){
  std::vector<std::string> result;
  std::string direction = "Begin";
  std::for_each(v.rbegin(), v.rend(), [&] (std::string& s) {
    auto i = s.find(' ');
    result.push_back(direction + s.substr(i));
    auto next = s.substr(0, i);
    if      (next == "Right") direction = "Left";
    else if (next == "Left")  direction = "Right";
    else                      direction = "";
  });
  return result;
}
////////////////////////////////
using Vs = std::vector< std::string >;
Vs solve( Vs v ) {
  Vs r{ "Begin" }; r.reserve( v.size() );
  for ( size_t i{ v.size()-1 }, j{}; i; --i, ++j )
    r[ j ] += v[ i ].substr( v[ i ].find( ' ' )),
    r.push_back( v[ i ][ 0 ] == 'L' ? "Right" : "Left" );
  return r.back() += v[ 0 ].substr( v[ 0 ].find( ' ' )), r;
}
/////////////////////////////
#include <regex>

std::vector<std::string> solve(const std::vector<std::string>& v){
     std::vector<std::string> res;
     std::transform(
         v.crbegin(), v.crend(), std::back_inserter(res),
         [
             next = std::string{ "Begin" },
             reg = std::regex{ R"(^(Begin|Left|Right) on (.+)$)" }
         ] (const std::string& dir) mutable {
             std::smatch match;
             if(!std::regex_match(dir, match, reg)) return std::string{};
             const std::string res = next + " on " + match[2].str();
             next = match[1].str() == "Left" ? "Right" : "Left";
             return res;
         }
     );
     return res;
}
///////////////////////////////
