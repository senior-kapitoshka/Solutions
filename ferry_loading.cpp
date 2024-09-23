#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>
#include <deque>


enum Dir:int{
  L,R
};

int ferryLoading(const int lgt, std::vector<std::pair<int, std::string>> ls) {
  std::deque<int>l;
  std::deque<int>r;
  std::for_each(ls.begin(),ls.end(),[&l,&r](auto& p){
    if(p.second=="left")l.push_back(p.first);
    else r.push_back(p.first);
  });
  Dir d=Dir::L;
  int cnt=0;
  double acc=0.0;
  while(!l.empty() || !r.empty()){
    switch(d){
        case L:
          if(!l.empty()){
            while(true){
              if(acc+l.front()/100.0<=lgt && !l.empty()){
                acc+=l.front()/100.0;
                l.pop_front();
              }else break;
            }
          }
          ++cnt;
          acc=0.0;
          d=Dir::R;
          break;
        case R:
          if(!r.empty()){
            while(true){
              if(acc+r.front()/100.0<=lgt && !r.empty()){
                acc+=r.front()/100.0;
                r.pop_front();
              }else break;
            }
          }
          ++cnt;
          acc=0.0;
          d=Dir::L;
          break;
        default:
          if(l.empty() && r.empty()) break;
    }
  }
  return cnt;
}

/////////////////////
#include <queue>
int ferryLoading( const int length, std::vector< std::pair< int, std::string >> loads ) {
  std::queue< int > bank[ 2 ];
  for ( const auto& [ length, side ] : loads )
    bank[ side.front() == 'r' ].push( length );
  int cars( loads.size() ), cm{ length * 100 }, side{}, crossings{};
  while ( cars ) {
    int available_length{ cm };
    while ( !bank[ side ].empty() && bank[ side ].front() <= available_length )
      available_length -= bank[ side ].front(), bank[ side ].pop(), --cars;
    ++crossings, side = !side;
  }
  return crossings;
}

////////////////
#include <queue>
#include <utility>
#include <vector>

int ferryLoading(const int length,
                 const std::vector<std::pair<int, std::string>>& loads) {
    std::queue<int> lqueue, rqueue;
    for (const auto& [load, dir] : loads) {
        if (dir == "left")
            lqueue.push(load);
        else
            rqueue.push(load);
    }

    int trips = 0;
    bool is_left = true;

    while (!lqueue.empty() || !rqueue.empty()) {
        auto& queue = is_left ? lqueue : rqueue;
        is_left = !is_left;

        int load = 0;
        while (!queue.empty() && load + queue.front() <= length * 100) {
            load += queue.front();
            queue.pop();
        }

        ++trips;
    }

    return trips;
}