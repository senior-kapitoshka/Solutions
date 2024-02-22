//////////////////////////////
////////////////////////////
///////////////////////////
/////////////////////////
/////////////
////////
//
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <set>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

void DFS(int s,std::vector<std::vector<int>>&v, std::vector<bool>&vis){
  vis[s]=true;
  for(auto& i:v[s]){
    if(!vis[i]){
      DFS(i,v,vis);
    }
  }
}


bool solution(const std::vector<std::string>& wodrs) {
  std::vector<std::string> wds{wodrs.begin(),wodrs.end()};
  std::vector<std::vector<int>>mp(wodrs.size());
  std::vector<std::pair<std::string,char>>st1;
  std::vector<std::pair<std::string,char>>st2;
  std::vector<bool> vis(wodrs.size(),false);
  for(size_t i=0;i<wds.size();++i){
      st1.push_back({wds[i],wds[i].front()});
      st2.push_back({wds[i],wds[i].back()});
  }
  std::vector<std::pair<std::string,char>>b1;
  std::vector<std::pair<std::string,char>>b2;
  for(size_t i=0;i<wds.size();++i){
    for(size_t j=0;j<wds.size();++j){
     if(wds[i].back()==wds[j].front()) mp[i].push_back(j);
    if(wds[i].front()==wds[j].back()) mp[i].push_back(j);
    }
  }
  
  for(auto i=st1.begin();i!=st1.end();){
    auto pr=*i;
    auto t=find_if(st2.begin(),st2.end(),[&pr](auto& p){
      return pr.second==p.second;});
    if(t==st2.end()){
      b1.push_back(pr);
    }
    ++i;
  }
  for(auto i=st2.begin();i!=st2.end();){
    auto pr=*i;
    auto t=find_if(st1.begin(),st1.end(),[&pr](auto& p){
      return pr.second==p.second;});
    if(t==st1.end()){
      b2.push_back(pr);
    }
    ++i;
  }
  int idx=0;
  int ds=wds.size()-1;
  if(!b1.empty()){
    idx=distance(wodrs.begin(),find(wodrs.begin(),wodrs.end(),b1.front().first));
  }
  if(!b2.empty()){
    ds=distance(wodrs.begin(),find(wodrs.begin(),wodrs.end(),b2.back().first));
  }
  
  #include <iostream>
  
  DFS(idx,mp,vis);
  for(auto i:vis){
    std::cout<<i<<".";
  }
    std::cout<<"\n";
  return vis[ds];
  
}



bool solution(const std::vector<std::string>& wodrs) {
  std::list<std::string> ls;
  std::vector<std::string> wds{wodrs.begin(),wodrs.end()};
  std::vector<std::string>::iterator z=find_if(wds.begin(),wds.end(),[](auto& s){
      return s.back()==s.front();});
  if(z!=wds.end()){
    ls.push_back(*z);
    wds.erase(z);
  }else{ 
    ls.push_back(wds[0]);
    wds.erase(wds.begin());
  }
  std::vector<std::string>::iterator f;
  std::vector<std::string>::iterator b;
  while(wodrs.size()!=ls.size()){
    bool x=false;
    bool y=false;
    b=find_if(wds.begin(),wds.end(),[&ls](auto& s){
      return ls.back().back()==s.front();});
    if(b!=wds.end()) {
      x=true;
      ls.push_back(*b);
      wds.erase(b);
    }
    f=find_if(wds.begin(),wds.end(),[&ls](auto& s){
      return ls.front().front()==s.back();});
    if(f!=wds.end()) {
      y=true;
      ls.push_front(*f);
      wds.erase(f);
    }
    if(x==false && y==false) break;
  }
  std::cout<<"\n"<<"---"<<"\n";
  for(auto i:ls){
    std::cout<<i<<",";
  }
  std::cout<<"\n"<<"---"<<"\n";
  
  std::cout<<"\n"<<"---"<<"\n";
  for(auto i:wodrs){
    std::cout<<i<<",";
  }
  std::cout<<"\n"<<"---"<<"\n";
  std::cout<<"\n";
  std::cout<<ls.size();
  std::cout<<"\n";
  std::cout<<wodrs.size();
  std::cout<<"\n"<<"--"<<"\n";
  return wodrs.size()==ls.size();
}

///////////////////////////////
///////////////////////////
/////////////////////
/////////////
///////
//
//adjucent_find

#include <string>
#include <string_view>
#include <vector>
#include <algorithm>

bool solution(const std::vector<std::string>& words) {
  std::vector<std::string_view> permutations{words.begin(),words.end()};
  std::sort(permutations.begin(),permutations.end()); // Initial ordering required for next permutation
  do {
    if (permutations.end()==std::adjacent_find(permutations.begin(),permutations.end(),[](auto f,auto g){return f.back()!=g.front();}))
      return true;
  } while (std::next_permutation(permutations.begin(),permutations.end()));
  return false;
}

////////////////////////////
#include <string>
#include <vector>
using namespace std ; 

bool solution(const vector<std::string>& words) {
  vector<string> V_Words = words; 
	sort(V_Words.begin(), V_Words.end());
	do
	{
		for (short i = 0; i < V_Words.size() -1; i++)
		{
			if (V_Words[i].back() != V_Words[i + 1].front())
				break; 
			if (i == V_Words.size() - 2)
				return true; 
		}

	} while (next_permutation(V_Words.begin(), V_Words.end()));
	return false;

}
//////////////////////////
//DFS

#include <vector>
#include <unordered_set>

using namespace std;

bool canCombine(const string& word1, const string& word2) {
  return word1.back() == word2.front();
}

bool dfs(const vector<string>& words, unordered_set<int>& used, string currentWord, int count) {
  if (count == words.size()) {
    return true;
  }

  for (int i = 0; i < words.size(); i++) {
    if (!used.count(i) && canCombine(currentWord, words[i])) {
      used.insert(i);
      if (dfs(words, used, words[i], count + 1)) {
        return true;
      }
      used.erase(i);
    }
  }
 return false;
}

bool solution(const vector<string>& words) {
  if (words.size() < 3 || words.size() > 7)
    return false;

  unordered_set<int> used;
  for (int i = 0; i < words.size(); i++) {
    used.insert(i);
    if (dfs(words, used, words[i], 1)) {
      return true;
    }
    used.erase(i);
  }

  return false;
}

////////////////////////
using namespace std;
bool find(const std::vector<std::string> &words, std::unordered_set<size_t> alreadyUsed, size_t index, char end)
{
    alreadyUsed.insert(index);
    if (alreadyUsed.size() == words.size())
        return true;
    for (size_t i = 0 ; i < words.size(); i++)
    {
        if (alreadyUsed.find(i) == alreadyUsed.end())
        {
             if (words[i][0] == end)
             {
                if (find(words,alreadyUsed,i,words[i][words[i].length()-1]))
                    return true;

             }
        }
    }
    return false;
}
bool solution(const std::vector<std::string>& words) {
    for (size_t i = 0; i < words.size(); i++)
    {
        if (find(words,std::unordered_set<size_t>(),i,words[i][words[i].length()-1]))
            return true;
    }
    return false;
}

/////////////////////////
//dfs

#include <string>
#include <vector>
#include <set>

std::vector<std::string> copy_all_but_one(const std::vector<std::string>& v, size_t exclude) {
  std::vector<std::string> v2;
  for (size_t i = 0; i < v.size(); i++)
    if (i != exclude)
      v2.push_back(v[i]);
  return v2;
}

bool dfs(const std::vector<std::string>& remaining_words, char next_character) {
  if (remaining_words.size() == 0)
    return true;
  
  for (size_t i = 0; i < remaining_words.size(); i++) {
    if (remaining_words[i].front() == next_character)
      if (dfs(copy_all_but_one(remaining_words, i), remaining_words[i].back()))
        return true;
  }
  
  return false;
}

bool solution(const std::vector<std::string>& words) {
  for (size_t i = 0; i < words.size(); i++)
    if (dfs(copy_all_but_one(words, i), words[i].back()))
      return true;
  
  return false;
}
