/*
    struct Point
    {
        int x, y;
        Point(int x = 0, int y = 0) : x(x), y(y) {}
    };
*/
#include <cmath>
#include <algorithm>

#define rnd(x) round(x * 1e5) / 1e5
bool vertcmp (const Point &a, const Point &b) { return a.x != b.x ? a.x < b.x : a.y < b.y; }
bool idem (const Point &a, const Point &b) { return a.x == b.x && a.y == b.y; }
double dist (const Point p, const Point q) { return std::hypot (p.x - q.x, p.y - q.y);}
bool is_right (Point p1, Point p2, Point p3) {
    double a = dist (p1, p2), b = dist (p2, p3), c = dist (p1, p3);
    double a2 = rnd (a * a), b2 = rnd (b * b), c2 = rnd (c * c);
    return (a2 + b2 == c2 || b2 + c2 == a2 || a2 + c2 == b2);
}
unsigned countRectTriang (const std::vector<Point> &p) {

    unsigned count = 0;
    std::vector<Point> map = p;
    std::sort (map.begin(), map.end(), vertcmp);
    std::vector<Point>::iterator it = std::unique (map.begin(), map.end(), idem);
    map.erase (it, map.end());

    for (unsigned i = 0; i < map.size(); i++)
        for (unsigned j = i  + 1; j < map.size() ; j++)
            for (unsigned k = j + 1; k < map.size(); k++)
                if (is_right (map[i], map[j], map[k]))
                    count++;

    return count;
}

#if 0
#include <set>
#include <cmath>
void all_comb(const std::vector<Point> &ps,std::set<std::set<Point>>&st){
  std::set<Point>t;
  for(size_t i=0;i<ps.size();++i){
    t.insert(ps[i]);
    t.insert(ps[(i+1)%ps.size()]);
    t.insert(ps[(i+2)%ps.size()]);
    st.insert(t);
    t.clear();
  }
  for(auto i:st){
    for(auto j:i){
      std::cout<<j.x<<"-"<<j.y<<"\n";
    }
    std::cout<<"\n";
  }
}

bool rect(const std::set<Point>& t){
  std::cout<<(double)(t.begin()->x-prev(t.end())->x)*(double)(t.begin()->x-prev(t.end())->x)<<"+"<<
                 (double)(t.begin()->y-prev(t.end())->y)*(double)(t.begin()->y-prev(t.end())->y)<<"+"<<
    
    (double)(next(t.begin())->x-prev(t.end())->x)*(double)(next(t.begin())->x-prev(t.end())->x)<<"+"<<
                 (double)(next(t.begin())->y-prev(t.end())->y)*(double)(next(t.begin())->y-prev(t.end())->y)<< "=="
    
    <<(double)(t.begin()->x-next(t.begin())->x)*(double)(t.begin()->x-next(t.begin())->x)<<"+"
                 <<(double)(t.begin()->y-next(t.begin())->y)*(double)(t.begin()->y-next(t.begin())->y)<<"\n";
  return (double)((t.begin()->x-next(t.begin())->x)*(t.begin()->x-next(t.begin())->x)+
                 (t.begin()->y-next(t.begin())->y)*(t.begin()->y-next(t.begin())->y))*((t.begin()->x-next(t.begin())->x)*(t.begin()->x-next(t.begin())->x)+
                 (t.begin()->y-next(t.begin())->y)*(t.begin()->y-next(t.begin())->y)) + 
    
    (double)((t.begin()->x-prev(t.end())->x)*(t.begin()->x-prev(t.end())->x)+
                 (t.begin()->y-prev(t.end())->y)*(t.begin()->y-prev(t.end())->y)*(t.begin()->x-prev(t.end())->x))*((t.begin()->x-prev(t.end())->x)+
                 (t.begin()->y-prev(t.end())->y)*(t.begin()->y-prev(t.end())->y)) == (double)((next(t.begin())->x-prev(t.end())->x)*(next(t.begin())->x-prev(t.end())->x)+
                 (next(t.begin())->y-prev(t.end())->y))*((next(t.begin())->y-prev(t.end())->y)*(next(t.begin())->x-prev(t.end())->x)*(next(t.begin())->x-prev(t.end())->x)+
                 (next(t.begin())->y-prev(t.end())->y)*(next(t.begin())->y-prev(t.end())->y)) 
    ||
    
    (double)((t.begin()->x-next(t.begin())->x)*(t.begin()->x-next(t.begin())->x)+
                 (t.begin()->y-next(t.begin())->y)*(t.begin()->y-next(t.begin())->y))*((t.begin()->x-next(t.begin())->x)*(t.begin()->x-next(t.begin())->x)+
                 (t.begin()->y-next(t.begin())->y)*(t.begin()->y-next(t.begin())->y))
    + (double)((next(t.begin())->x-prev(t.end())->x)*(next(t.begin())->x-prev(t.end())->x)+
                 (next(t.begin())->y-prev(t.end())->y)*(next(t.begin())->y-prev(t.end())->y))*((next(t.begin())->x-prev(t.end())->x)*(next(t.begin())->x-prev(t.end())->x)+
                 (next(t.begin())->y-prev(t.end())->y)*(next(t.begin())->y-prev(t.end())->y)) ==
    
    (double)((t.begin()->x-prev(t.end())->x)*(t.begin()->x-prev(t.end())->x)+
                 (t.begin()->y-prev(t.end())->y)*(t.begin()->y-prev(t.end())->y))*((t.begin()->x-prev(t.end())->x)*(t.begin()->x-prev(t.end())->x)+
                 (t.begin()->y-prev(t.end())->y)*(t.begin()->y-prev(t.end())->y)) 
    ||
    
    (double)((t.begin()->x-prev(t.end())->x)*(t.begin()->x-prev(t.end())->x)+
                 (t.begin()->y-prev(t.end())->y)*(t.begin()->y-prev(t.end())->y))*((t.begin()->x-prev(t.end())->x)*(t.begin()->x-prev(t.end())->x)+
                 (t.begin()->y-prev(t.end())->y)*(t.begin()->y-prev(t.end())->y)) +
    
    (double)((next(t.begin())->x-prev(t.end())->x)*(next(t.begin())->x-prev(t.end())->x)+
                 (next(t.begin())->y-prev(t.end())->y)*(next(t.begin())->y-prev(t.end())->y))*((next(t.begin())->x-prev(t.end())->x)*(next(t.begin())->x-prev(t.end())->x)+
                 (next(t.begin())->y-prev(t.end())->y)*(next(t.begin())->y-prev(t.end())->y)) ==
    
    (double)((t.begin()->x-next(t.begin())->x)*(t.begin()->x-next(t.begin())->x)+
                 (t.begin()->y-next(t.begin())->y)*(t.begin()->y-next(t.begin())->y))*((t.begin()->x-next(t.begin())->x)*(t.begin()->x-next(t.begin())->x)+
                 (t.begin()->y-next(t.begin())->y)*(t.begin()->y-next(t.begin())->y))
    ;
  
}

unsigned countRectTriang(const std::vector<Point> &ps)
{
  std::set<std::set<Point>>st;
    all_comb(ps,st);
  return std::count_if(st.begin(),st.end(),[](auto& t)mutable{
    return rect(t);
  });
    
}
#endif
////////////////////////////

#include <vector>
#include <unordered_set>
#include <cmath>


struct PointHash {
    std::size_t operator()(const Point& p) const {
        return std::hash<int>()(p.x) ^ std::hash<int>()(p.y);
    }
};

unsigned countRectTriang(const std::vector<Point> &points) {
    std::unordered_set<Point, PointHash> unique_points(points.begin(), points.end());
    std::vector<Point> unique_points_vec(unique_points.begin(), unique_points.end());
    
    unsigned count = 0;
    
    for (size_t i = 0; i < unique_points_vec.size(); ++i) {
        for (size_t j = i + 1; j < unique_points_vec.size(); ++j) {
            for (size_t k = j + 1; k < unique_points_vec.size(); ++k) {
                const Point &A = unique_points_vec[i];
                const Point &B = unique_points_vec[j];
                const Point &C = unique_points_vec[k];

                int ABx = B.x - A.x, ABy = B.y - A.y;
                int BCx = C.x - B.x, BCy = C.y - B.y;
                int CAx = A.x - C.x, CAy = A.y - C.y;
                
                if ((ABx * (C.x - A.x) + ABy * (C.y - A.y)) == 0 ||  // AB . AC
                    (BCx * (A.x - B.x) + BCy * (A.y - B.y)) == 0 ||  // BC . BA
                    (CAx * (B.x - C.x) + CAy * (B.y - C.y)) == 0)    // CA . CB
                {
                    ++count;
                }
            }
        }
    }
    
    return count;
}