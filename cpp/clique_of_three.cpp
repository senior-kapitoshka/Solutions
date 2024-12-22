#include <algorithm>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <numeric>
#include <set>
#include <array>

using table=std::unordered_map<std::string,std::set<std::string>>;

void parse(table& mp,const std::string &f){
  std::stringstream ss;
  ss.str(f);
  
  for(std::string w;std::getline(ss,w,'\n');){
    if(w.substr(0,w.find_first_of('/'))!=w.substr(w.find_first_of('/')+1)){
      mp[w.substr(0,w.find_first_of('/'))].insert(w.substr(w.find_first_of('/')+1));
      mp[w.substr(w.find_first_of('/')+1)].insert(w.substr(0,w.find_first_of('/')));
    }
  }
}

std::string clique_of_3(const std::string &f)
{
  if(f.empty()) return "";
  table t;
 parse(t,f);
  std::array<std::string,3>st;
  for(auto& p:t){
    for(auto& i:p.second){
      for(auto& j:p.second){
        if(t[i].count(j) && t[j].count(i)){
          st[0]=p.first;
          st[1]=i;
          st[2]=j;
          break;
        }
      }
    }
  }
  if(std::all_of(st.begin(),st.end(),[](auto& s){return s.empty();}))return "";
  auto w=[](std::string& lhs, std::string& rhs){return std::move(lhs)+"/"+std::move(rhs);};
  std::string res=std::accumulate(next(st.begin()),st.end(),st.front(),w);
  return res;
}
///////////////////////////
#include <queue>
std::map <std::string, std::vector<std::string>> adj;

std::string bfs(const std::string now){
  std::map <std::string, std::string> prev;
  std::queue <std::string> que;
  que.push(now); int cnt = 0;
  while (!que.empty() && cnt++ <= 3){
    std::string par = que.front(); que.pop();
    for (std::string elm: adj[par]){
      if (prev[elm] != ""){
        if (prev[par] == prev[elm]) return par + "/" + elm + "/" + prev[elm];
      }
      else {
        prev[elm] = par;
        que.push(elm);
      }
    }
  }
  return "";
}

std::string clique_of_3(const std::string &friends){
  std::string name1, name2, res; adj.clear();
  int idx = 0;
  while (idx < (int) friends.size()){
    name1 = name2 = "";
    while (friends[idx] != '/') name1 += friends[idx++];
    while (friends[++idx] != '\n') name2 += friends[idx];
    idx++;
    if (name1 == name2) continue;
    adj[name1].push_back(name2);
    adj[name2].push_back(name1);
  }
  for (auto &elm: adj){
    res = bfs(elm.first);
    if (res != "") return res;
  }
  return "";
}
///////////////////////////
#include <sstream>
#include <set>
using namespace std;

/* -------------------------------------------------------------------------------------- */
/** An index of people, with their names and ID numbers. */

class People : public map<string,unsigned>
{
public:
 unsigned find_or_add(const string &name);
};

/* -------------------------------------------------------------------------------------- */
/** Look up a person by name, or add them if not already present, and return their ID number. */

unsigned People::find_or_add(const string &name)
{
 unsigned id;
 auto pp = find(name);
 if( pp == end() )   
 {
   id = size();
   insert({ name, id });
 }
 else
   id = pp->second;
 return id;
}

/* -------------------------------------------------------------------------------------- */
/** A little class for representing collections of unordered pairs. */

class Friendships : private set<pair<unsigned,unsigned>>
{
public:
 void add(unsigned a, unsigned b) { insert({ min(a,b), max(a,b) }); }
 bool has(unsigned a, unsigned b) { return find({ min(a,b), max(a,b) }) != end(); }
};

/* -------------------------------------------------------------------------------------- */

string clique_of_3(const string &friends)
{
 People people;
 Friendships friendships;
 istringstream input(friends);
 string a,b, result;
  
 while( getline(input, a), !a.empty() )
 {
   // Parse the names of the two friends:
   unsigned del = a.find('/');
   b = a.substr(del+1);
   a = a.substr(0, del);
   
   // Look these people up, and get their ID numbers:
   unsigned an = people.find_or_add(a),
            bn = people.find_or_add(b);
   
   // Self-friendship can be ignored:
   if( an == bn )
     continue;
   
   // Check for a clique-of-three formed by this friendship and two previous ones:
   for( auto p : people )
     if( friendships.has(an, p.second) && friendships.has(bn, p.second) )
     {
       result = a + '/' + b + '/' + p.first;
       return result;
     }
   
   // Note this friendship, it might be relevant later:
   friendships.add(an, bn);
 }
  
 return "";
}
/////////////////////////////////
