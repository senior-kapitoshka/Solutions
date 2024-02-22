#include <array>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <utility>
#include <iostream>
#include <set>


struct Roach{
  int num;
  char dir;
  Roach(int n, char d):num(n),dir(d) {}
  
  bool operator==(const Roach &other) const
  { return (num == other.num
            && dir == other.dir);
  }
};

struct Crd{
  size_t x;
  size_t y;
};

struct hasher{
  size_t operator()(const Roach& p)const{
    std::hash<char> hc;
    size_t h=hc(p.dir);
    return h^(p.num<<1);
  }
};

using crdh = std::unordered_map<char,std::vector<std::pair<int,Crd>>>;
using crdr = std::unordered_map<const Roach,Crd,hasher>;

void crds (const std::vector<std::string> &rm, crdh& hls, crdr& rch){
  int cnt=0;
  std::set<int> st;
  for(size_t i=0;i<rm.size();++i){
    for(size_t j=0;j<rm[i].size();++j){
      if(isdigit(rm[i][j])) {
          if(i==0 && j!= rm[i].size()-1 && !st.count(rm[i][j]-'0')){
            hls['U'].push_back({(rm[i][j]-'0'),{i,j}});
             st.insert(rm[i][j]-'0');
          }
          else if(j==0 && i!=0  && !st.count(rm[i][j]-'0')){
            hls['L'].push_back({(rm[i][j]-'0'),{i,j}});
            st.insert(rm[i][j]-'0');
          }
          else if(i==rm.size()-1 && j!=0  && !st.count(rm[i][j]-'0')){
            hls['D'].push_back({(rm[i][j]-'0'),{i,j}});
            st.insert(rm[i][j]-'0');
          }
          else if(j==rm[i].size()-1 && i!=rm.size()-1  && !st.count(rm[i][j]-'0')){
            hls['R'].push_back({(rm[i][j]-'0'),{i,j}});
            st.insert(rm[i][j]-'0');
          }
      }else if(isalpha(rm[i][j])) {
        ++cnt;
        Roach r(cnt,rm[i][j]);
        rch.insert({r,{i,j}});
      }
    }
  }
}



std::array<int, 10> cockroaches(const std::vector<std::string> &rm) {
    crdh hls;
    crdr rch;
    crds(rm,hls,rch);
    if(rch.empty()) return {};
    std::array<int, 10> res;
    std::fill(res.begin(),res.end(),0);
    for_each(rch.begin(),rch.end(),[&hls,&res](auto& roax){
      
      if(roax.first.dir == 'U'){
        roax.second.x = 0;
        std::cout<<roax.first.num<<"("<<roax.second.x<<"%"<<roax.second.y<<")\n";
        auto it = find_if(hls['U'].begin(),hls['U'].end(),[&roax](auto& hole){
          return hole.second.x==roax.second.x && hole.second.y==roax.second.y;
        });
        if(it!=hls['U'].end()){
          ++res[(it)->first];
          return;
        }else{
          auto it=find_if(hls['U'].rbegin(),hls['U'].rend(),[&roax](const auto& hole){
            return hole.second.y<roax.second.y;
          });
          if(it!=hls['U'].rend()){
            ++res[(*it).first];
            return;
          }else if(it == hls['U'].rend()){

              if(!hls['L'].empty()){
                ++res[hls['L'].front().first];
                return;
              }else if(!hls['D'].empty()){
                ++res[hls['D'].front().first];
                return;
              }else if(!hls['R'].empty()){
                ++res[hls['R'].front().first];
                return;
              }else if(!hls['U'].empty()){
                ++res[hls['U'].back().first];
                return;
              }
            } 
          }
         
      }else if(roax.first.dir == 'D'){
        roax.second.x = hls['D'].front().second.x;
        std::cout<<roax.first.num<<"("<<roax.second.x<<"%"<<roax.second.y<<")\n";
        auto it = find_if(hls['D'].begin(),hls['D'].end(),[&roax](auto& hole){
          return hole.second.x==roax.second.x && hole.second.y==roax.second.y;
        });
        if(it!=hls['D'].end()){
          ++res[(it)->first];
          return;
        }else{
          auto it=find_if(hls['D'].begin(),hls['D'].end(),[&roax](const auto& hole){
            return hole.second.y>roax.second.y;
          });
          if(it!=hls['D'].end()){
            ++res[(*it).first];
            return;
          }else if(it == hls['D'].end()){
             if(!hls['R'].empty()){
                ++res[hls['R'].back().first];
               return;
              }else if(!hls['U'].empty()){
                ++res[hls['U'].back().first];
                return;
              }else if(!hls['L'].empty()){
                ++res[hls['L'].front().first];
                return;
              }else if(!hls['D'].empty()){
                ++res[hls['D'].front().first];
                return;
              }
            } 
          }
         
    }else if(roax.first.dir == 'L'){
        
        roax.second.y = 0;
          std::cout<<roax.first.num<<"("<<roax.second.x<<"%"<<roax.second.y<<")\n";
        auto it = find_if(hls['L'].begin(),hls['L'].end(),[&roax](auto& hole){
          return hole.second.x==roax.second.x && hole.second.y==roax.second.y;
        });
        if(it!=hls['L'].end()){
          ++res[(it)->first];
          return;
        }else{
          auto it=find_if(hls['L'].begin(),hls['L'].end(),[&roax](const auto& hole){
            return hole.second.x>roax.second.x;
          });
          if(it!=hls['L'].end()){
            ++res[(*it).first];
            return;
          }else if(it == hls['L'].end()){
             if(!hls['D'].empty()){
                ++res[hls['D'].front().first];
               return;
              }else if(!hls['R'].empty()){
                ++res[hls['R'].back().first];
                return;
              }else if(!hls['U'].empty()){
                ++res[hls['U'].back().first];
                return;
              }else if(!hls['L'].empty()){
                ++res[hls['L'].front().first];
                return;
              }
            } 
          }
         
    }else if(roax.first.dir == 'R') {
        roax.second.y = hls['R'].front().second.y;
            
            std::cout<<roax.first.num<<"("<<roax.second.x<<"%"<<roax.second.y<<")\n";
        auto it = find_if(hls['R'].begin(),hls['R'].end(),[&roax](auto& hole){
          return hole.second.x==roax.second.x && hole.second.y==roax.second.y;
        });
        if(it!=hls['R'].end()){
          ++res[(it)->first];
          return;
        }else{
          auto it=find_if(hls['R'].rbegin(),hls['R'].rend(),[&roax](const auto& hole){
            return hole.second.x<roax.second.x;
          });
          
          if(it!=hls['R'].rend()){
            ++res[(*it).first];
              return;
            }else if(it==hls['R'].rend()) {
              if(!hls['U'].empty()){
                ++res[hls['U'].back().first];
                return;
              }else if(!hls['L'].empty()){
                ++res[hls['L'].front().first];
               return;
              }else if(!hls['D'].empty()){
                ++res[hls['D'].front().first];
                return;
              }else if(!hls['R'].empty()){
                ++res[hls['R'].back().first];
                return;
              }
            } 
          } 
            }
          }
      
        
    );
  
    return res;
}

////////////////////////////////////////////////////////////

#include <array>
#include <map>
#include <string>
#include <vector>

std::array<int, 10> cockroaches(const std::vector<std::string> &room) {
  if (room.size() < 2 || room.front().size() < 2) return {};
  std::array<int, 10> counts = {0};
  const int height = static_cast<int>(room.size());
  const int width = static_cast<int>(room.front().length());
  
  // Initialize items via wrapping around the rectangle clockwise.
  std::map<int, int> holes;
  std::vector<int> cockroaches;
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      const char cur = room[y][x];
      if (cur >= '0' && cur <= '9') {
        // It's a hole.
        const int hole_index = static_cast<int>(cur - '0');
        if (y == 0) {
          // top wall.
          holes.emplace(width - x, hole_index);
        } else if (x == 0) {
          // left wall.
          holes.emplace(y + width, hole_index);
        } else if (y == height - 1) {
          // bottom wall.
          holes.emplace(x + width + height, hole_index);
        } else {
          // right wall.
          holes.emplace(2 * (width + height) - y, hole_index);
        }  
      } else {
        // Check if it's a cockroach.
        switch(cur) {
          case 'U':
            cockroaches.push_back(width - x - 1);
            break;
          case 'L':
            cockroaches.push_back(width + y - 1);
            break;
          case 'D':
            cockroaches.push_back(x + width + height - 1);
            break;
          case 'R':
            cockroaches.push_back(2 * (width + height) - y - 1);
            break;
        }
      }
    }
  }
  
  // Hide cockroaches.
  for (auto& cockroach : cockroaches) {
    // We subract one above to make sure they can get to upper bound. 
    const auto it = holes.upper_bound(cockroach);
    if (it != holes.end()) {
      ++counts[it->second];
    } else {
      ++counts[holes.begin()->second];
    }
  }
  
  return counts;
}

//////////////////////

#include <array>
#include <string>
#include <vector>

std::string left_wall(const std::vector<std::string> &room) {
    std::string wall;
    for (const auto &line : room) {
        wall.push_back(line[0]);
    }
    return wall;
}

std::string right_wall(const std::vector<std::string> &room) {
    std::string wall;
    for (auto it = room.rbegin(); it != room.rend(); it++) {
        const std::string &line = *it;
        wall.push_back(line[line.size()-1]);
    }
    return wall;
}

std::array<int, 10> cockroaches(const std::vector<std::string> &room) {
    std::array<int, 10> result = {};  // Zeroed
    const std::string upper {room[0].rbegin(), room[0].rend()};
    const std::string lower = room[room.size()-1];
    const std::string left = left_wall(room);
    const std::string right = right_wall(room);
    std::string path;
    for (size_t i = 1; i < room.size()-1; i++) {
        for (size_t j = 1; j < room[0].size()-1; j++) {
            switch (room[i][j]) {
            case 'U':
                path = upper.substr(upper.size()-j-1, j+1) + left + lower + right + upper.substr(0, upper.size()-j-1);
                break;
            case 'L':
                path = left.substr(i, left.size()-i) + lower + right + upper + left.substr(0, i);
                break;
            case 'D':
                path = lower.substr(j, lower.size()-j) + right + upper + left + lower.substr(0, j);
                break;
            case 'R':
                path = right.substr(right.size()-i-1, i+1) + upper + left + lower + right.substr(0, right.size()-i-1);
                break;
            default:
                continue;
            }
            for (char c : path) {
                if ('0' <= c && c <= '9') {
                    result[c - '0']++;
                    break;
                }
            }
        }
    }
    return result;
}
///////////////////////
#include <array>
#include <string>
#include <vector>
#include <map>
using namespace std;

std::array<int, 10> cockroaches(const std::vector<std::string> &room) {
    array<int, 10> ans;
    for (int i=0; i<10; i++){
        ans[i] = 0;
    }
    map<char, pair<int, int>> m = {{'U', {-1,0}}, {'D', {1,0}},{'L',{0,-1}},{'R',{0,1}}};
    map<pair<int,int>,pair<int,int>> d = {{{-1,0},{0,-1}},{{1,0},{0,1}},{{0,-1},{1,0}},{{0,1},{-1,0}}};
    for (int i=0; i<room.size(); i++){
        string temp = room[i];
        for (int j=0; j<temp.size(); j++){
            char t = temp[j];
            if (isalpha(t)){
                int x = i, y=j;
                int dx, dy;
                dx = m[t].first;
                dy = m[t].second;
                char t2 = room[x][y];
                bool f = false;
                while (!isdigit(t2)){
                    x += dx;
                    y += dy;
                    if (isdigit(room[x][y])){
                        int a = room[x][y]-'0';
                        ans[a] += 1;
                        break;
                    }
                    else if (f == false){
                        if (room[x][y]=='-' || room[x][y] == '|'){
                            pair<int, int> p = make_pair(dx, dy);
                            dx = d[p].first;
                            dy = d[p].second;
                            f = true;
                        }
                    }
                    else if (room[x][y] == '+'){
                        pair<int, int> p = make_pair(dx, dy);
                        dx = d[p].first;
                        dy = d[p].second;                     
                    }
                }
            }
        }
    }
    return ans;
}

//////////////////////////////
#include <array>
#include <string>
#include <vector>

std::array<int, 10> cockroaches(const std::vector<std::string> &room) {
    std::array<int, 10> cock = {};
    std::vector<std::pair<int,int>> worms;
    int x, y;

    for (int i = 1; i < room.size() - 1; i++){
      for (int j = 1; j < room[0].size() - 1; j++){
        if (room[i][j] == 'U') worms.push_back({0, j});
        else if (room[i][j] == 'D') worms.push_back({room.size() - 1, j});
        else if (room[i][j] == 'R') worms.push_back({i, room[0].size() - 1});
        else if (room[i][j] == 'L') worms.push_back({i, 0});
      }
    }

    for (auto i : worms){
      x = i.first;
      y = i.second;

      while (true){
        if (room[x][y] > 47 && room[x][y] < 58){
          cock[room[x][y] - 48]++;
          break;
        }
        if (x == 0 && y == 0){
          x++;
          continue;
        }
        if (x == 0){
          y--;
          continue;
        }
        if (y == room[0].size() - 1){
          x--;
          continue;
        }
        if (x == room.size() - 1){
          y++;
          continue;
        }
        if (y == 0){
          x++;
        }
      }
    }
  
    return cock;
}

////////////////////////////
    #include <iostream>
#include <array>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

class Room;
class Cockroach;

class Cockroach
{
    public:
        Cockroach(std::size_t x, std::size_t y, char direction)
            : x(x), y(y), direction(direction), hitWall(false) {};

        int findHole(Room &room);

        std::size_t x;
        std::size_t y;
        char direction;
        bool hitWall;

      private:
        void moveForward();
        void turnLeft();
        char lookFront(Room &room) const;
        char lookRight(Room &room) const;
        char lookCorner(Room &room) const;
        bool isHole(char c) const { return c <= '9' && c >= '0'; };
        bool isWall(char c) const { return c == '-' || c == '|'; };
};

class Room
{
  public:
    Room(const std::vector<std::string> &room) : room(room){};
    void findCockroaches(std::vector<Cockroach> &foundCockroaches);

    char        getTile(std::size_t x, std::size_t y) const { return room[y][x]; };    
    std::size_t getHeight() const { return room.size(); };
    std::size_t getWidth()  const { return room[0].size(); };

  private:
    bool isCockroach(char c) {
        return (c == 'U' || c == 'D' || c == 'L' || c == 'R');
    };

    const std::vector<std::string> room;
};

void Room::findCockroaches(std::vector<Cockroach> &foundCockroaches)
{
    for (std::size_t y = 0; y < getHeight(); ++y)
        for (std::size_t x = 0; x < getWidth(); ++x)
            if (isCockroach(room[y][x]))
                foundCockroaches.emplace_back(x, y, room[y][x]);
}

void Cockroach::turnLeft()
{
    static const std::vector<char> directionOrder = {'U', 'L', 'D', 'R'};

    size_t i = 0;
    for (; i < directionOrder.size(); ++i)
        if (direction == directionOrder[i])
            break;

    direction = directionOrder[(i + 1) % directionOrder.size()];
}

void Cockroach::moveForward()
{
    switch (direction)
    {
        case 'U':
            --y;
            break;

        case 'D':
            ++y;
            break;

        case 'L':
            --x;
            break;

        case 'R':
            ++x;
            break;

        default:
            break;
    }
}

char Cockroach::lookFront(Room &room) const
{
    char tile = ' ';

    switch (direction)
    {
        case 'U':
            tile = room.getTile(x, y - 1);
            break;

        case 'D':
            tile = room.getTile(x, y + 1);
            break;

        case 'L':
            tile = room.getTile(x - 1, y);
            break;

        case 'R':
            tile = room.getTile(x + 1, y);
            break;

        default:
            break;
    }

    return tile;
}

char Cockroach::lookRight(Room &room) const
{
    char tile = ' ';

    switch (direction)
    {
    case 'U':
        tile = room.getTile(x + 1, y);
        break;

    case 'D':
        tile = room.getTile(x - 1, y);
        break;

    case 'L':
        tile = room.getTile(x, y - 1);
        break;

    case 'R':
        tile = room.getTile(x, y + 1);
        break;

    default:
        break;
    }

    return tile;
}

char Cockroach::lookCorner(Room &room) const
{
    char tile = ' ';

    switch (direction)
    {
    case 'U':
        tile = room.getTile(x + 1, y - 1);
        break;

    case 'D':
        tile = room.getTile(x - 1, y + 1);
        break;

    case 'L':
        tile = room.getTile(x - 1, y - 1);
        break;

    case 'R':
        tile = room.getTile(x + 1, y + 1);
        break;

    default:
        break;
    }

    return tile;
}

int Cockroach::findHole(Room &room)
{
    while (true)
    {
        
        char front = lookFront(room);
        char right = lookRight(room);
    
        if (isHole(front))
            return front - '0';

        if (hitWall && isHole(right))
            return right - '0';

        if (hitWall && isWall(front) && isWall(right))
        {
            char corner = lookCorner(room);
            if (isHole(corner))
                return corner - '0';
        }

        if (isWall(front))
        {
            turnLeft();
            if (!hitWall)
                hitWall = true;
        }
        else
            moveForward();

    }
}

std::array<int, 10> cockroaches(const std::vector<std::string> &room)
{
    std::vector<Cockroach> foundCockroaches;

    Room infectedRoom(room);
    infectedRoom.findCockroaches(foundCockroaches);

    std::array<int, 10> holes = {0};
    for (auto &cockroach : foundCockroaches)
        holes[cockroach.findHole(infectedRoom)]++;

    return holes;
}