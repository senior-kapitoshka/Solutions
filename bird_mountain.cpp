#include <array>

int peak_height(std::vector<std::string>& mn) {
  bool have=false;
  std::vector<std::vector<int>> mx(mn.size(),std::vector<int>(mn[0].size(),0));
  for(size_t i=0;i<mn.size();++i){
    for(size_t j=0;j<mn[0].size();++j){
      if(mn[i][j]=='^'){
          mx[i][j]=1;
        have=true;
        }
      } 
    }
  
   int h=have?1:0;
  bool flag=true;

 while(flag){
    flag=false;
    for(size_t i=1;i<mn.size()-1;++i){
      for(size_t j=1;j<mn[i].size()-1;++j){
              if(mx[i][j]>0 && 
                 (mx[i][j-1]>=mx[i][j] && mx[i][j+1]>=mx[i][j] && mx[i+1][j]>=mx[i][j] && mx[i-1][j]>=mx[i][j])){
                mx[i][j]+=1;
                flag=true;
                h=std::max(h,mx[i][j]);
              }
              
          }
        }
 } 
  
  
  return h;
}

////////////////
int peak_height(std::vector<std::string>& mountain) {
  int wpp=mountain[0].length()+1;
  int moves[]={1,-1,wpp,-wpp};
  std::string map_(wpp,' ');
  for(std::string s:mountain)map_+=s+" ";
  map_+=std::string(wpp,' ');
  std::string map;
  int count=-1;
  do{
    map=map_;
    for(int i=wpp;i<(map.length()-wpp);i++){
      for(int m:moves)
        if(map[i+m]==' ')map_[i]=' ';
    }
    count++;
  }while(map!=map_);
  return count;
}

//////////////////
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
class BirdMountain {
public:
    int findHeight();
    BirdMountain(vector<string> maze) {
        M = (int)maze.size(); N = (int)maze[0].length();
        grid.resize(M, vector<int>(N, 0));
        for (int m = 0; m < M; m++) for (int n = 0; n < N; n++) if (maze[m][n] == '^') grid[m][n] = 1;}
private:
    vector<vector<int>> grid;
    int M, N;
    int dx[4] = { -1, 0, 1, 0 }; //left,down, up, right
    int dy[4] = { 0, 1, 0, -1 };
};
int BirdMountain::findHeight() {
    bool finished = true; int changeCount, height(0);
    std::function<bool(int&, int&)> outsideGrid = [&](int a, int b) { return (a < 0 || b < 0 || a >= M || b >= N); };
    for (int m = 0; m < M; m++) if (find(grid[m].begin(), grid[m].end(), 1) != grid[m].end()) finished = false;
    while (!finished) {
        changeCount = 0; ++height;
        for (int m = 0; m < M; m++) {
            for (int n = 0; n < N; n++) {
                int x(m), y(n), current(grid[m][n]), cellCount(0);
                if (current < height) continue;
                for (int i = 0; i < 4; i++) {
                    x = m + dx[i];
                    y = n + dy[i];
                    if (outsideGrid(x, y) || grid[x][y] < height) continue;
                    else ++cellCount;
                }
                if (cellCount == 4) {
                    ++grid[m][n];
                    ++changeCount;
                }
            } finished = !changeCount;
        }
    } return height;
}
int peak_height(std::vector<std::string>& mountain) {
    BirdMountain bm(mountain);
    return (mountain.empty() ? 0 : bm.findHeight());
}

///////////////
#include <algorithm>
#include <cassert>
#include <queue>
#include <tuple>

int peak_height(const std::vector<std::string>& mountain)
{
    constexpr std::size_t u0 = 0;
    assert(mountain.size() && std::all_of(begin(mountain), end(mountain), [size = mountain[0].size()](auto& row) {
        return row.size() == size && row.find_first_not_of(" ^") == std::string::npos;
    }));
    std::vector<std::vector<int>> heights(
        mountain.size(),
        std::vector<int>(mountain[0].size(), -1));
    std::queue<std::tuple<unsigned, unsigned, int>> queue;
    for (auto y = 0u; y < mountain.size(); ++y)
        for (auto x = 0u; x < mountain[y].size(); ++x)
            if (mountain[y][x] == ' ')
            {
                heights[y][x] = 0;
                queue.push({y, x, 0});
            }
    for (auto y: {u0, mountain.size() - 1})
        for (auto x = 0u; x < mountain[y].size(); ++x)
            if (mountain[y][x] == '^')
            {
                heights[y][x] = 1;
                queue.push({y, x, 1});
            }
    for (auto y = 0u; y < mountain.size(); ++y)
        for (auto x: {u0, mountain[y].size() - 1})
            if (mountain[y][x] == '^')
            {
                heights[y][x] = 1;
                queue.push({y, x, 1});
            }
    auto push = [&](auto y, auto x, auto height)
    {
        if (0 <= y && y < mountain.size() &&
            0 <= x && x < mountain[y].size() &&
            heights[y][x] == -1)
        {
            heights[y][x] = height;
            queue.push({y, x, height});
        }
    };
    auto result = 0;
    while (queue.size())
    {
        unsigned y, x;
        int height;
        std::tie(y, x, height) = queue.front();
        queue.pop();
        result = std::max(result, height);
        push(y - 1, x, height + 1);
        push(y, x - 1, height + 1);
        push(y, x + 1, height + 1);
        push(y + 1, x, height + 1);
    }
    return result;
}

///////////////
#include <queue>

class Coord { 
  public:
  int X;
  int Y;
  
  Coord(int x = 0, int y = 0) : X(x), Y(y) {}
  Coord(const Coord& copy) : X(copy.X), Y(copy.Y) {}
};

int peak_height(std::vector<std::string>& mountain) {
  const int maxRow = mountain.size();
  if(maxRow == 0) return 0;
  const int maxCol = mountain[0].size();
  if(maxCol == 0) return 0;
  
  int mountainArr[maxRow][maxCol];
  std::queue<Coord> peaks;
  
  for(int y = 0; y < maxRow; ++y) {
    for(int x = 0; x < maxCol; ++x) {
      if(mountain[y][x] == '^') {
        mountainArr[y][x] = 1;
        peaks.push(Coord(x, y));
      } else {
        mountainArr[y][x] = 0;
      }
    }
  }
  
  if(peaks.empty()) return 0;
  
  int highestFound = 1;
  while(!peaks.empty()) {
    Coord cur = peaks.front();
    peaks.pop();
    int& curPeak = mountainArr[cur.Y][cur.X];
    
    if(curPeak <= (cur.Y > 0 ? mountainArr[cur.Y - 1][cur.X] : 0) &&         // N
       curPeak <= (cur.Y < maxRow - 1 ? mountainArr[cur.Y + 1][cur.X] : 0) && // S
       curPeak <= (cur.X > 0 ? mountainArr[cur.Y][cur.X - 1] : 0) &&          // W
       curPeak <= (cur.X < maxCol - 1 ? mountainArr[cur.Y][cur.X + 1] : 0))   // E
    {    
      highestFound = ++curPeak;
      peaks.push(cur);
    }
  }
  
  return highestFound;
}