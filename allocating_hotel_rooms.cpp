
//fail some of random test cases
#include <vector>
#include <map>
#include <algorithm>

enum PT{
  ST,FN
};
struct Point{
  int val;
  int id;
  PT t;
};

std::vector<int> allocateRooms(std::vector<std::vector<int>>& cs) {  
    std::vector<int> as(cs.size(),0);
  std::vector<Point>vp;
  std::for_each(cs.begin(),cs.end(),[i=0,&vp](auto& v)mutable{
    vp.push_back(Point{v.front(),i,PT::ST});
    vp.push_back(Point{v.back(),i++,PT::FN});
  });
    std::sort(vp.begin(),vp.end(),[](auto& lhs,auto& rhs){return lhs.val<rhs.val 
      ||(lhs.val==rhs.val && lhs.t<rhs.t);});
    std::vector<std::pair<bool,int>>vb(cs.size(),{false,0});
    for(auto& p:vp){
      if(p.t==PT::ST){
        auto it=std::find_if(vb.begin(),vb.end(),[](auto& p){return p.first==false;});
        (*it).first=true;
        (*it).second=p.id;
        as[p.id]=std::distance(vb.begin(),it)+1;
      }else if(p.t==PT::FN){
        auto it=std::find_if(vb.begin(),vb.end(),
                             [i=p.id](auto& p){return p.second==i;});
        (*it).first=false;
        (*it).second=0;
      }
    }
    return as;
}


/////////////////////////////////

#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <numeric>

std::vector<int> allocateRooms(const std::vector<std::vector<int>>& customers) {
  const size_t n = customers.size();
  std::priority_queue<std::pair<int, int>> queue;
  std::vector<int> res(n);
  std::vector<int> indices(n);
  std::iota(indices.begin(), indices.end(), 0);
  std::sort(indices.begin(), indices.end(), [&](int i, int j) { return customers[i][0] < customers[j][0]; });

  int rooms = 0;
  for (size_t i : indices) {
    const auto& customer = customers[i];
    if (queue.empty() || -queue.top().first >= customer[0]) {
      res[i] = ++rooms;
      queue.emplace(-customer[1], rooms);
    } else {
      int room = queue.top().second;
      queue.pop();
      res[i] = room;
      queue.emplace(-customer[1], room);
    }
  }
  
  return res;
}

/////////////////////
std::vector<int> allocateRooms( std::vector< std::vector< int >>& customers ) {
  sort( customers.begin(), customers.end() );
  std::vector< int > rooms, hotel( customers.size() );
  for ( const auto& customer : customers )
    for ( size_t room{}; room < hotel.size(); ++room )
      if ( hotel[ room ] < customer.front() ) {
        hotel[ room ] = customer.back();
        rooms.push_back( ++room );
        break;
      }
  return rooms;
}

/////////////////////////
