#include <string>
#include <string_view>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <array>
#include <numeric>
#include <stack>

auto d = [](std::string a, int b){
    return std::move(a) + '.' + std::to_string(b);
};

class VersionManager
{
public:
    VersionManager(std::string_view version="0.0.1")
    :vrs(version)
    {
      std::cout<<version<<"\n";
      Parse(version);
    }
    VersionManager& major();
    VersionManager& minor();
    VersionManager& patch();
    VersionManager& rollback();
    std::string release() const{
      return vrs;
    }
private:
    void Parse(std::string_view v);
    
    std::stack<std::string> stak;
    std::string vrs;
    std::array<int,3>dig;
};


void VersionManager::Parse(std::string_view v){
    if(v.empty()) {
      vrs="0.0.1";
      return;
    }

    std::string x;
    int c=std::count(v.cbegin(),v.cend(),'.');
    if(c==2) x = static_cast<std::string>(v);
    if(c>2){
      int i=0;
      for(auto j:v){
        if(j=='.')++i;
        if(i==3) break;
        x+=j;
      }
    }
    else if(c<2){
      if(c==0){
        x = static_cast<std::string>(v) + ".0.0";
      }else if(c==1){
        x = static_cast<std::string>(v) + ".0";
      } 
    }
    if(std::any_of(x.begin(),x.end(),[](const auto& c){return isalpha(c);})){
        throw VersionException("Error occured while parsing version!"); 
    }
    try{
      dig[0]=std::stoi(x.substr(0,1));
      dig[1]=std::stoi(x.substr(2,3));
      dig[2]=std::stoi(x.substr(4));
      vrs=x;
    }catch(VersionException& e){
      std::cout<<e.what();
    }catch(...){
      std::cout<<"unknown error";
    }
}

VersionManager& VersionManager::major(){
  stak.push(vrs);
  ++dig[0];dig[1]=0;dig[2]=0;
  vrs = std::accumulate(std::next(dig.begin()),dig.end(),
                        std::to_string(dig[0]),d);
  return *this;
}
VersionManager& VersionManager::minor(){
  stak.push(vrs);
  ++dig[1];dig[2]=0;
  vrs = std::accumulate(std::next(dig.begin()),dig.end(),
                        std::to_string(dig[0]),d);
  return *this;
}
VersionManager& VersionManager::patch(){
  stak.push(vrs);
  ++dig[2];
  vrs = std::accumulate(std::next(dig.begin()),dig.end(),
                        std::to_string(dig[0]),d);
  return *this;
}

VersionManager& VersionManager::rollback(){
  if(stak.empty()) 
    throw VersionException("Cannot rollback!");
  Parse(stak.top());
  stak.pop();
  return *this;
}


///////////////////////////////
#include <regex>
#include <stack>
#include <string>
#include <tuple>

class VersionManager {
    using ver_t = std::tuple<unsigned long, unsigned long, unsigned long>;
    std::stack<ver_t> history;

    static ver_t parse_version(const std::string& str) {
        static const std::regex version{R"(^(\d+)(?:\.(\d+)|$)(?:\.(\d+)|$))"};
        if (str.empty()) return {0, 0, 1};

        std::smatch match;
        if (!std::regex_search(str.cbegin(), str.cend() - (str.back() == '.'),
                               match, version)) {
            throw VersionException{"Error occured while parsing version!"};
        }

        return {std::stoul(match.str(1)),
                match.length(2) ? std::stoul(match.str(2)) : 0,
                match.length(3) ? std::stoul(match.str(3)) : 0};
    }

public:
    VersionManager() : history({{0, 0, 1}}) {}
    VersionManager(const std::string& version)
        : history({parse_version(version)}) {}

    VersionManager& major() {
        const auto [maj, min, pat] = history.top();
        history.push({maj + 1, 0, 0});
        return *this;
    }

    VersionManager& minor() {
        const auto [maj, min, pat] = history.top();
        history.push({maj, min + 1, 0});
        return *this;
    }

    VersionManager& patch() {
        const auto [maj, min, pat] = history.top();
        history.push({maj, min, pat + 1});
        return *this;
    }

    VersionManager& rollback() {
        if (history.size() < 2) {
            throw VersionException{"Cannot rollback!"};
        }

        history.pop();
        return *this;
    }

    std::string release() const {
        const auto [maj, min, pat] = history.top();
        return std::to_string(maj) + '.' + std::to_string(min) + '.' +
               std::to_string(pat);
    }
};
///////////////////////////////
#include <string>
#include <string_view>
#include <charconv>

class VersionManager
{
public:
    VersionManager(std::string_view version = "0.0.1");
    VersionManager& major();
    VersionManager& minor();
    VersionManager& patch();
    VersionManager& rollback();
    std::string release() const;
private:
    std::vector<std::string_view> split(std::string_view sv, std::string_view delimeter = ".");
    unsigned parse_num(std::string_view token);

    struct version_t
    {
        unsigned major{}, minor{}, patch{};
    };
    std::vector<version_t> history;
};

// Implement methods here.
// Use preloaded VersionException class for throwing exceptions.
VersionManager::VersionManager(std::string_view version)
{
    version_t v;
    if (version.empty()) v.patch = 1;
    else
    {
        auto tokens = split(version);
        if (tokens.empty()) throw VersionException("Error occured while parsing version!");
        v.major = parse_num(tokens[0]);
        if (tokens.size() > 1) v.minor = parse_num(tokens[1]);
        if (tokens.size() > 2) v.patch = parse_num(tokens[2]);
    }
    history.push_back(v);
}
VersionManager& VersionManager::major()
{
    auto [major, minor, patch] = history.back();
    history.push_back({major + 1, 0, 0});
    return *this;
}
VersionManager& VersionManager::minor()
{
    auto [major, minor, patch] = history.back();
    history.push_back({major, minor + 1, 0});
    return *this;
}
VersionManager& VersionManager::patch()
{
    auto [major, minor, patch] = history.back();
    history.push_back({major, minor, patch + 1});
    return *this;
}
VersionManager& VersionManager::rollback()
{
    if (history.size() > 1) history.pop_back();
    else throw VersionException("Cannot rollback!");
    return *this;
}
std::string VersionManager::release() const
{
    auto [major, minor, patch] = history.back();
    return std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(patch);
}
std::vector<std::string_view> VersionManager::split(std::string_view sv, std::string_view delimeter)
{
    std::vector<std::string_view> tokens{};
    size_t pos = 0;
    while ((pos = sv.find(delimeter)) != std::string_view::npos)
    {
        auto token = sv.substr(0, pos);
        if (!token.empty()) tokens.push_back(token);
        sv = sv.substr(pos + delimeter.size());
    }
    if (!sv.empty()) tokens.push_back(sv);
    return tokens;
}
unsigned VersionManager::parse_num(std::string_view token)
{
    unsigned num{};
    auto [_, ec] = std::from_chars(token.data(), token.data() + token.size(), num);
    if (ec != std::errc()) throw VersionException("Error occured while parsing version!");
    return num;
}