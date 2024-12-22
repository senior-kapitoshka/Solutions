#include <tuple>
bool check_course(std::vector<std::string> sp)
{
  std::pair<int,int>x;
  std::vector<std::tuple<int,int,bool>>vn;
  for(int i=0;i<(int)sp.size();++i){
    for(int j=0;j<(int)sp[0].size();++j){
      if(sp[i][j]=='X'){
        x.first=i;
        x.second=j;
      }
      if(sp[i][j]=='N'){
        if(i==0)vn.emplace_back(i,j,true);
        else vn.emplace_back(i,j,false);
      }
    }
  }

  for(int j=0;j<(int)sp[0].size();++j){
    std::swap(sp[x.first][x.second],sp[x.first][x.second+1]);
    ++x.second;
    for(auto &n:vn){
      if(!std::get<2>(n) && std::get<0>(n)==(int)sp.size()-1){
        std::swap(sp[std::get<0>(n)][std::get<1>(n)],sp[std::get<0>(n)-1][std::get<1>(n)]);
        --std::get<0>(n);
      }else if(std::get<2>(n) && std::get<0>(n)==0){
        std::swap(sp[std::get<0>(n)][std::get<1>(n)],sp[std::get<0>(n)+1][std::get<1>(n)]);
        ++std::get<0>(n);
      }else if(std::get<2>(n) && std::get<0>(n)>0 && std::get<0>(n)<(int)sp.size()-1){
        std::swap(sp[std::get<0>(n)][std::get<1>(n)],sp[std::get<0>(n)+1][std::get<1>(n)]);
        ++std::get<0>(n);
      }else if(!std::get<2>(n) && std::get<0>(n)>0 && std::get<0>(n)<(int)sp.size()-1){
        std::swap(sp[std::get<0>(n)][std::get<1>(n)],sp[std::get<0>(n)-1][std::get<1>(n)]);
        --std::get<0>(n);
      }else if(std::get<2>(n) && std::get<0>(n)==(int)sp.size()-1){
        std::get<2>(n)=false;
        std::swap(sp[std::get<0>(n)][std::get<1>(n)],sp[std::get<0>(n)-1][std::get<1>(n)]);
        --std::get<0>(n);
      }else if(!std::get<2>(n) && std::get<0>(n)==0){
        std::get<2>(n)=true;
        std::swap(sp[std::get<0>(n)][std::get<1>(n)],sp[std::get<0>(n)+1][std::get<1>(n)]);
        ++std::get<0>(n);
      }
    }
    if((sp[x.first+1][x.second]=='N')||
       (sp[x.first-1][x.second]=='N')||
       (sp[x.first-1][x.second+1]=='N')||
       (sp[x.first][x.second+1]=='N')||
       (sp[x.first+1][x.second+1]=='N') || 
       (sp[x.first-1][x.second-1]=='N') ||
       (sp[x.first][x.second-1]=='N') ||
       (sp[x.first+1][x.second-1]=='N')
      ){
      return false;
    }
  }
  return true;
}

/////////////////////
#include <iostream>
#include <vector>

class Ship
{
public:
    Ship() {}

    Ship(int x, int y, int speedX, int speedY)
        : m_x(x),
          m_y(y),
          m_speedX(speedX),
          m_speedY(speedY)
    {}

    void move()
    {
        m_x += m_speedX;
        m_y += m_speedY;
    }

    void reverseY() { m_speedY *= -1; }

    int x() const { return m_x; }
    int y() const { return m_y; }

private:
    int m_x;
    int m_y;

    int m_speedX;
    int m_speedY;


};

class Game
{
public:
    Game(std::vector<std::string> sea_map)
    {
        for (unsigned int y = 0; y < sea_map.size(); ++y)
        {
            for (unsigned int x = 0; x < sea_map[y].size(); ++x)
            {
                switch (sea_map[y][x])
                {
                case 'N':
                    m_enemies.emplace_back(x, y, 0, (y == 0) ? 1 : -1);
                    break;
                case 'X':
                    m_me = Ship(static_cast<int>(x), static_cast<int>(y), 1, 0);
                    break;
                }
            }
        }
        m_h = sea_map.size();
        m_w = sea_map.at(0).size();
    }

    bool scan()
    {
        for (auto &enemy : m_enemies)
        {
            if ((enemy.x() >= m_me.x() - 1) && (enemy.x() <= m_me.x() + 1) && (enemy.y() >= m_me.y() - 1) && (enemy.y() <= m_me.y() + 1))
                return true;
        }
        return false;
    }

    bool run()
    {
        if (scan())
            return false;

        while (true)
        {
            for (auto &enemy : m_enemies)
            {
                enemy.move();
                if (enemy.y() == 0 || enemy.y() == m_h - 1)
                    enemy.reverseY();
            }

            m_me.move();

            if (m_me.x() == m_w - 1)
                return true;
                
            if (scan())
                return false;
        }
    }

private:
    std::vector<Ship> m_enemies;
    Ship m_me;

    int m_w;
    int m_h;

};


bool check_course(std::vector<std::string> sea_map)
{
    Game game(sea_map);
    return game.run();
}

////////////////////////
bool check_course(const std::vector<std::string>& sea_map) {
  auto lines = sea_map.size(), columns =  sea_map[0].size(), cycle = 2 * lines - 2;
  auto myLine = 0;
  for (; myLine < lines; myLine ++) if (sea_map[myLine][0] == 'X') break;
  
  auto analiz = [&] (auto start, auto col) {
    int pos = (start + col) % cycle;
    if (pos >= lines) pos = cycle - pos;
    return (abs(myLine - pos) > 2);
  };
  
  for (auto i = 0; i < columns; i ++) {
    if (sea_map[0][i]         == 'N' && !analiz(0, i)        ) return false;
    if (sea_map[lines - 1][i] == 'N' && !analiz(lines - 1, i)) return false;
  }
  return true;
}

///////////////
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool check_course(vector<string> sea_map)
{
  int w = sea_map[0].size(), h = sea_map.size();
  int start_y = find_if(sea_map.begin(), sea_map.end(), [](const string &s){ return s[0] == 'X'; })-sea_map.begin();
  
  vector<int> navy_start_y;
  for (int x = 0 ; x < w ; x++)
    navy_start_y.push_back(sea_map[0][x] == 'N' ? 0 : sea_map[h-1][x] == 'N' ? h-1 : -1);
  
  auto get_navy_y = [&] (int x, int n) {
    if (x < 0 || x >= w || navy_start_y[x] == -1) return -1;
    n %= (2*h);
    int dir = (navy_start_y[x] == 0) ? 1 : -1;
    return navy_start_y[x] + (n <= h ? n : (h-1-(n-h))) * dir;
  };
  auto is_unsafe = [&] (int ship_y, int navy_y) {
    return navy_y != -1 && navy_y >= ship_y-1 && navy_y <= ship_y+1;
  };
  
  for (int x = 0 ; x < w ; x++)
    if (is_unsafe(get_navy_y(x-1,x),start_y) || is_unsafe(get_navy_y(x,x),start_y) || is_unsafe(get_navy_y(x+1,x),start_y))
      return false;
  return true;
}

///////////////////////
