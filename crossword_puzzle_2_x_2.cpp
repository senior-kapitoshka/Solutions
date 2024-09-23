#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

/* in Preloaded:

struct puzzle_solution {
  std::string across;
  std::string down;
  unsigned score;
};

const std::vector<std::string> words;

const std::vector<unsigned> values;

*/

//  return a vector of puzzle_solution structs
//  the words and values vectors are preloaded

/*struct hasher{
  size_t operator()(const std::string& s)const{
    return (s[0]^s[1])>>1;
  }
};*/

unsigned cost(std::string s){
  return values[s[0]-65]+values[s[1]-65];
}

std::vector<puzzle_solution> crossword_2x2(const std::vector<std::string> pz) {
  std::vector<puzzle_solution> results;
  bool flag =true;
  //std::cout << "first word  is \"" << words[0] << "\"\n";
  //std::cout << "first value is " << values[0] << "\n\n";
  std::map<std::string,std::vector<std::pair<std::string,unsigned>>>mp;
  if(pz.front()[0]==pz.back()[0]){
    if(pz.front()[1]=='#'){
      for(auto& i:words){
        if(i[1]==pz.back()[1] && !mp.count(i)){
          for(auto& j:words){
            if(j[1]==i[0] && i!=j){
              mp[i].emplace_back(j,cost(i)+cost(j));
            }
          }
        }
      }
      
    }else{
      for(auto& i:words){
        if(i[1]==pz.front()[1] && !mp.count(i)){
          for(auto& j:words){
            if(j[0]==i[0] && i!=j){
              mp[i].emplace_back(j,cost(i)+cost(j));
            }
          }
        }
      }
      
    }
  }else if (pz.front()[1]==pz.back()[1]){
    if(pz.front()[0]=='#'){
      for(auto& i:words){
        if(i[0]==pz.back()[0] && !mp.count(i)){
          for(auto& j:words){
            if(j[1]==i[1] && i!=j){
              mp[i].emplace_back(j,cost(i)+cost(j));
            }
          }
        }
      }
    }else{
      for(auto& i:words){
        if(i[0]==pz.front()[0] && !mp.count(i)){
          for(auto& j:words){
            if(j[0]==i[1] && i!=j){
              mp[i].emplace_back(j,cost(i)+cost(j));
            }
          }
        }
      }
    }
  }else if(pz.front()[1]!=pz.back()[1] && pz.front()[0]!=pz.back()[0]){
    if(pz.front().find('#')!=pz.front().npos 
       && !std::all_of(pz.back().begin(),pz.back().end(),[](auto& c){return c=='_';})){
      if(pz.front()[0]=='#'){

        for(auto& i:words){
          if(i[1]==pz.back()[1] && !mp.count(i)){
            for(auto& j:words){
              if(j[1]==i[1] && i!=j){
                mp[i].emplace_back(j,cost(i)+cost(j));
              }
            }
          }
        }
        
      }else{

        for(auto& i:words){
          if(i[1]==pz.back()[0] && !mp.count(i)){
            for(auto& j:words){
              if(j[0]==i[1] && i!=j){
                mp[i].emplace_back(j,cost(i)+cost(j));
              }
            }
          }
        }
      }
      flag=false;
    }else if(pz.back().find('#')!=pz.back().npos &&
         !std::all_of(pz.front().begin(),pz.front().end(),[](auto& c){return c=='_';})){
      if(pz.back()[0]=='#'){

        for(auto& i:words){
          if(i[1]==pz.front()[1] && !mp.count(i)){
            for(auto& j:words){
              if(j[0]==i[1] && i!=j){
                mp[i].emplace_back(j,cost(i)+cost(j));
              }
            }
          }
        }
        
      }else{
        for(auto& i:words){
          if(i[0]==pz.front()[0] && !mp.count(i)){
            for(auto& j:words){
              if(j[0]==i[0] && i!=j){
                mp[i].emplace_back(j,cost(i)+cost(j));
              }
            }
          }
        }
        
      }
    }else if(pz.front().find('#')!=pz.front().npos && std::all_of(pz.back().begin(),pz.back().end(),[](auto& c){return c=='_';})
       ){
    if(pz.front()[0]=='#'){
      for(auto& i:words){
          if(i[0]==pz.front()[1] && !mp.count(i)){
            for(auto& j:words){
              if(j[1]==i[1] && i!=j){
                mp[i].emplace_back(j,cost(i)+cost(j));
              }
            }
          }
        }
        
    }else{
      for(auto& i:words){
          if(i[0]==pz.front()[0] && !mp.count(i)){
            for(auto& j:words){
              if(j[0]==i[1] && i!=j){
                mp[i].emplace_back(j,cost(i)+cost(j));
              }
            }
          }
        }
      
    }
    flag=false;
  }else if(pz.back().find('#')!=pz.back().npos && std::all_of(pz.front().begin(),pz.front().end(),[](auto& c){return c=='_';}) 
      ){
    if(pz.back()[0]=='#'){
      for(auto& i:words){
          if(i[1]==pz.back()[1] && !mp.count(i)){
            for(auto& j:words){
              if(j[1]==i[0] && i!=j){
                mp[i].emplace_back(j,cost(i)+cost(j));
              }
            }
          }
        }
      
    }else{
      for(auto& i:words){
          if(i[1]==pz.back()[0] && !mp.count(i)){
            for(auto& j:words){
              if(j[0]==i[0] && i!=j){
                mp[i].emplace_back(j,cost(i)+cost(j));
              }
            }
          }
        }
      
    }
    flag=false;
  }
  }
  if(flag){
    for(auto i:mp){
      for(auto p:i.second){
        results.push_back(puzzle_solution{i.first,p.first,p.second});
      }
    }
  }else{
    for(auto i:mp){
      for(auto p:i.second){
        results.push_back(puzzle_solution{p.first,i.first,p.second});
      }
    }
  }
  std::sort(results.begin(),results.end(),[](auto lhs, auto rhs){
    return lhs.score>rhs.score || (lhs.score==rhs.score && lhs.across[0]<rhs.across[0])
      || (lhs.score==rhs.score && lhs.across[0]==rhs.across[0] && lhs.across[1]<rhs.across[1])||
      (lhs.score==rhs.score && lhs.across[0]==rhs.across[0] && lhs.across[1]==rhs.across[1] && lhs.down[0]<rhs.down[0])
      || (lhs.score==rhs.score && lhs.across[0]==rhs.across[0] && lhs.across[1]==rhs.across[1] && lhs.down[0]==rhs.down[0] &&
          lhs.down[1]<rhs.down[1])
      ;
  });
  return results;
}

//////////////////////////////////
#include <vector>

bool comper(puzzle_solution a, puzzle_solution b) {
  return (a.score > b.score) ||
         (a.score == b.score && a.across < b.across) ||
         (a.score == b.score && a.across == b.across && a.down < b.down);
}

static unsigned get_score(std::string a, std::string d) {
  return values[a[0] - 65] + values[a[1] - 65] + values[d[0] - 65] + values[d[1] - 65];
}

std::vector<puzzle_solution> crossword_2x2(const std::vector<std::string> puzzle) {    
  std::vector<puzzle_solution> results;
  size_t by = puzzle[1][0] == '#' || puzzle[1][1] == '#';
  size_t bx = puzzle[by][1] == '#';
  size_t gy = puzzle[0].compare("#_") == false || puzzle[0].compare("__") == false || puzzle[0].compare("_#") == false;  
  size_t gx = puzzle[gy][0] == '_' || puzzle[gy][0] == '#';
  char given = puzzle[gy][gx];
  size_t place = (!by) * (puzzle[0][0] != given) || (puzzle[1][0] == '#' && puzzle[1][1] == given);
  size_t opposites = (gy != by) * (gx != bx);
  size_t second = gy == by ? gy : gx;
  size_t swap = (puzzle[0][0] == '_' && puzzle[0][1] == '_') || (puzzle[1][0] == '_' && puzzle[1][1] == '_');   
  for(size_t a=0; a<128; a++) {
    if(words[a][second] == given) {
      char shared = opposites ? given :  words[a][!second];
      for(size_t b=0; b<128; b++) {
        if(b != a && words[b][place] == shared) {
          size_t aa = a;
          size_t bb = b;
          if(swap) {
            size_t t = aa;
            aa = bb;
            bb = t;
          }
          results.push_back((puzzle_solution){words[aa], words[bb], get_score(words[aa], words[bb])});
        }
      }
    }
  }
  std::sort(results.begin(), results.end(), comper);
  return results;
}

////////////////////
#include <vector>
#include <string>
#include <algorithm>

/* in Preloaded:

struct puzzle_solution {
  std::string across;
  std::string down;
  unsigned score;
};

const std::vector<std::string> words;

const std::vector<unsigned> values;

*/

//  return a vector of puzzle_solution structs
//  the words and values vectors are preloaded

std::vector<puzzle_solution> crossword_2x2(const std::vector<std::string> puzzle) {
  std::vector<puzzle_solution> results;
  size_t i = puzzle[0].find('#') != std::string::npos ? 0 : 1, j = puzzle[i].find('#');
  std::string row = puzzle[i ^ 1], col = {puzzle[0][j ^ 1], puzzle[1][j ^ 1]};
  auto cmp = [](char x, char y) { return x == y || y == '_'; };
  auto score = [](std::string w) { return values[w[0] - 'A'] + values[w[1] - 'A']; };
  for (auto across : words) {
    if (!std::equal(across.begin(), across.end(), row.begin(), cmp)) continue;
    for (auto down : words) {
      if (down == across || down[i ^ 1] != across[j ^ 1] || !std::equal(down.begin(), down.end(), col.begin(), cmp)) continue;
      results.push_back({ across, down, score(across) + score(down) });
    }
  }
  std::stable_sort(results.begin(), results.end(), [](auto a, auto b) { return a.score > b.score; });
  return results;
}

////////////////////
