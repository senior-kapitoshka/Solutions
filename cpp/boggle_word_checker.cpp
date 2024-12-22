//pass sample_tests

#include <unordered_map>
#include <array>
#include <algorithm>
#include <tuple>
#include <set>
#include <queue>

using namespace std;

struct hasher{
  size_t operator()(const std::tuple<char,int,int>& pr)const{
    return std::get<0>(pr)^(std::get<0>(pr)>>1)^std::get<1>(pr)^(std::get<1>(pr)>>1)^std::get<2>(pr)^(std::get<2>(pr)>>1);;
  }
};

using  graph=std::unordered_map<std::tuple<char,int,int>,std::vector<std::tuple<char,int,int>>,hasher>;



void make_graph(const vector<vector<char>> &bd, graph&gr){
  std::array<int,8>dx={-1,-1,-1,0,0,1,1,1};
  std::array<int,8>dy={-1,0,1,-1,1,-1,0,1};
  for(int i=0;i<(int)bd.size();++i){
    for(int j=0;j<(int)bd[0].size();++j){
      std::vector<std::tuple<char,int,int>>t;
      for(int k=0;k<8;++k){
        i+=dx[k];
        j+=dy[k];
        if(i>=0 && j>=0 && i<(int)bd.size() && j<(int)bd[0].size()){
          t.push_back({bd[i][j],i,j});
        }
        i-=dx[k];
        j-=dy[k];
      }
      gr[{bd[i][j],i,j}]=t;
    }
  }
}


bool check(graph& gr,std::tuple<char,int,int>& n,const string &wd){
  std::queue<std::tuple<char,int,int>>q;
  q.push(n);
  std::set<std::tuple<char,int,int>>vis;
  std::vector<bool>dist(wd.size(),false);
  dist[0]=true;
  for(size_t i=1;i<wd.size();){
    while(!q.empty()){
      auto nd=q.front();
      q.pop();
     // std::cout<<std::get<0>(nd)<<std::get<1>(nd)<<std::get<2>(nd)<<"\n";
      for(auto& u:gr[nd]){    
        //std::cout<<"-"<<std::get<0>(u)<<std::get<1>(u)<<std::get<2>(u)<<"\n";
        if(std::get<0>(u)==wd[i] && !vis.count(u)){
          //std::cout<<wd[i]<<"\n";
          vis.insert(u);
          q.push(u);
          dist[i]=true;
        }
             //if(dist[i]==true)++i;
      }
      if(dist[i]==true)++i;
    }
    if(q.empty() && i<wd.size()) break;
  }
 // std::cout<<"\n";
  return dist[wd.size()-1];
}

bool check_word(const vector<vector<char> > &bd,[[maybe_unused]] const string &wd)
{
  //std::cout<<wd<<"\n";
  graph gr;
  make_graph(bd,gr);
  /*for(auto i:gr){
    std::cout<<std::get<0>(i.first)<<">["<<std::get<1>(i.first)<<","<<std::get<2>(i.first)<<"]"<<"-";
    for(auto j:i.second){
      std::cout<<std::get<0>(j)<<">["<<std::get<1>(j)<<","<<std::get<2>(j)<<"]"<<",";
    }
    std::cout<<"\n";
  }*/
  for(auto& i: gr){
    if(wd.front()==std::get<0>(i.first)){
      if(wd.size()==1){
      return true;
    }else{
        auto n=i.first;
        std::set<std::tuple<char,int,int>>vis;
        if(check(gr,n,wd))return true;
      }
    }
  }
  return false;
}

////////////////////
// TODO: Replace examples and use TDD development by writing your own tests

using namespace std;

Describe(checks_word)
{
  #if 1
    It(example_test)
    {
        vector<vector<char> > test_board = {{'E','A','R','A'},
                                            {'N','L','E','C'},
                                            {'I','A','I','S'},
                                            {'B','Y','O','R'} };

        //Assert::That(check_word(test_board, "C"), Equals(true));
        //Assert::That(check_word(test_board, "EAR"), Equals(true));
        Assert::That(check_word(test_board, "EARS"), Equals(false));
        Assert::That(check_word(test_board, "BAILER"), Equals(true));
      //
        Assert::That(check_word(test_board, "RSCAREIOYBAILNEA"), Equals(true)); // Must be able to check indefinite word lengths going in all directions
        Assert::That(check_word(test_board, "CEREAL"), Equals(false)); // Valid guesses can't overlap themselves
        Assert::That(check_word(test_board, "ROBES"), Equals(false)); // Valid guesses have to be adjacent
        Assert::That(check_word(test_board, "BAKER"), Equals(false)); // All the letters have to be in the board
      //
        Assert::That(check_word(test_board, "CARS"), Equals(false)); // Valid guesses cannot wrap around the edges of the board
    }
  #endif
  #if 0
   It(example_test)
    {vector<vector<char> > test_board = {{ 'T','T','M','D','A'}, 
                                          {'G','Y','I','N','N'},
                                          {'P','A','L','C','E'},
                                          {'I','A','U','L','G'},
                                          {'A','M','I','N','A'}};
     Assert::That(check_word(test_board, "MINGLE"), Equals(true));
     Assert::That(check_word(test_board, "ANIMALITY"), Equals(true));
     }
  #endif
  #if 0
  It(example_test)
    {vector<vector<char> > test_board = {{'N','B','R','A'},
                                        {'C','R','P','A'},
                                        {'L','A','A','P'},
                                        {'S','O','A','A'}};
      
     //Assert::That(check_word(test_board, "ARAARAS"), Equals(true));
     Assert::That(check_word(test_board, "PARAPARAS"), Equals(true));
     }
  
  #endif
};


/////////////////////

#include <string_view>
using namespace std;
struct mov{int x; int y;};
const vector<mov> moves = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

bool check(const vector<vector<char> > &board, vector<vector<bool> >& used, const string_view word, size_t i, size_t j)
{
  if (word.empty()) return true;
  if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || used[i][j] || word[0] != board[i][j]) return false;
  used[i][j] = true;
  for(auto m : moves)
    if(check(board, used, word.substr(1), i + m.x, j + m.y)) return true;
  used[i][j] = false;
  return false;
}

bool check_word(const vector<vector<char> > &board, const string &word)
{
  vector used(board.size(), vector(board[0].size(), false));
  for(size_t i = 0; i < board.size(); i++)
    for(size_t j = 0; j < board[i].size(); j++)
      if (check(board, used, word, i, j)) return true;
  return false;
}

///////////////////////
#include <stack>
using namespace std;

vector<int> movement {-1, 0, 1};

bool check_word(const vector<vector<char>> &board, const string &word)
{
  size_t m = board.size(), n = board[0].size();
  vector<vector<bool>> visited(m, vector<bool>(n, false));
  
  stack<tuple< size_t, size_t, vector<vector<bool>>, string >> stk;
  
  for (size_t r = 0; r < m; ++r) {
    for (size_t c = 0; c < n; ++c) {
      if (board[r][c] == word[0]) {
        auto new_visited(visited);
        new_visited[r][c] = true;
        stk.push( { r, c, new_visited, word.substr(1) } );
      }
    }
  }
  
  while (!stk.empty()) {
    auto [r, c, visited, word] = stk.top();
    stk.pop();
    
    if (word.size() == 0) return true;
    
    for (auto dr : movement) {
      for (auto dc : movement) {
        if (
          r+dr >= 0 and 
          c+dc >= 0 and 
          r+dr < m and 
          c+dc < n and
          board[r+dr][c+dc] == word[0] and
          !visited[r+dr][c+dc]
        ) {
          auto new_visited(visited);
          new_visited[r+dr][c+dc] = true;
          stk.push( { r+dr, c+dc, new_visited, word.substr(1) } );
        }
      }
    }
  }
  
  return false;
}
/////////////
using namespace std;
bool check_word(vector<vector<char> > board, const string &word)
{
  function<bool(int,int,int)> check=[&](int x, int y,unsigned int num){
     if(num>=word.size())return true;//Word complete found 
      if((x>=board.size()||x<0||y>=board[x].size()||y<0)) return false; //out of board
      char c=word[num];
      if(c!=board[x][y])return false;//wrong letter
      board[x][y]='\0'; //disable field for word tails. (line 8-15 begin)
      for(int xo=-1;xo<=1;xo++){
        for(int yo=-1;yo<=1;yo++){
          if(check(x+xo,y+yo,num+1))return true;// try all word tails
        }
      }
     board[x][y]=c; //enable fild for other guesses (line 8-15 end)
    return false;
  };
  for(unsigned int x=0;x<board.size();x++){
        for(unsigned int y=0;y<board.size();y++){
          if(check(x,y,0))return true; //try eache fild for the word begin
        }
      }
  return false;
} 
//////////////////
using namespace std;

bool dfs(const vector<vector<char> > &board,vector<vector<bool> > &visited, const string &word, int wordIndex, int i, int j){
  
  if(wordIndex == word.length()){
    return true;
  }
  if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[wordIndex] || visited[i][j] ){
    return false;
  }
  
  //mark it as visited so we won't count it 
  //(as oppose to my original idea of creating a vector and comparing visited coordinates which is too much runtime)
  
  //if the word ends up not working we will revert it back
  visited[i][j] = true;
  
  bool found = 
    dfs(board, visited, word, wordIndex+1,i+1, j) ||
    dfs(board, visited, word, wordIndex+1,i-1, j) ||
    dfs(board, visited, word, wordIndex+1,i, j+1) ||
    dfs(board, visited, word, wordIndex+1,i, j-1) ||
    dfs(board, visited, word, wordIndex+1,i+1, j+1) ||
    dfs(board, visited, word, wordIndex+1,i-1, j-1) ||
    dfs(board, visited, word, wordIndex+1,i+1, j-1) ||
    dfs(board, visited, word, wordIndex+1,i-1, j+1);
  
  visited[i][j] = false;
  
  return found;
  
  
};


bool check_word(const vector<vector<char> > &board, const string &word)
{

  
  int rows = board.size();
  int cols = board[0].size();
  
  bool ans = false;
  
  vector<vector<bool>> visited(rows, vector<bool>(cols, false));
  
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      if(board[i][j] == word[0] && dfs(board, visited, word, 0, i, j) )
        ans = true;
    }
  }
  
  cout << word << " " << ans << '\n';
  return ans;
}
//////////////////
