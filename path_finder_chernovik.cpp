#include <unordered_map>
#include <map>
#include <utility>
#include <vector>
#include <sstream>
#include <iostream>
#include <iterator>
#include <set>
#include <queue>
#include <cmath>

#if 1

struct Crd{
  int x,y;
};

struct Node{
  int idx;
  int data;
  Crd cd;
  Node (int i,int d, Crd c):idx(i), data(d), cd(c) {}
  bool operator==(const Node& other)const{
    return (data==other.data &&
            cd.x==other.cd.x &&
            cd.y==other.cd.y);
  }
  bool operator<(const Node& other)const{
    return data>other.data;
  }
};

struct hasher{
  size_t operator()(const Node& n)const{
    std::hash<int>ih;
    auto f=ih(n.cd.x);
    auto s=ih(n.cd.y);
    auto t=ih(n.data);
    auto fr=ih(n.idx);
    return (f*f*f+s*s*s+t*t*t+fr*fr*fr)^((f*f+s*s+t*t+fr*fr)<<1);
  }
};

using graph = std::unordered_map<const Node,std::vector<Node>,hasher>;

void parting(std::string& s, std::vector<std::string>& vs){
  std::stringstream ss;
  ss.str(s);
  for(std::string w; std::getline(ss,w,'\n');){
    vs.push_back(std::move(w));
  }
}

#if 1
void make_graph(std::vector<std::string>& vs,[[maybe_unused]] graph& gr){
  int n = (int)vs.size();
  int m =(int)vs[0].size();
  int idx=0;
  for(int i=0;i<n;++i){
    for(int j=0;j<m;++j){
      if(i==0 && j==0){
        //int b=idx+1;
        //int t=idx+m;
        gr[{idx, vs[i][j]-'0',{i,j}}].push_back({idx+1, vs[i][j+1]-'0',{i,j+1}});
        gr[{idx, vs[i][j]-'0',{i,j}}].push_back({idx+m, vs[i+1][j]-'0',{i+1,j}});
        ++idx;
      }
      else if((i==0 || i==n-1) && j!=m-1 ){
        //int b=idx+1;
          gr[{idx, vs[i][j]-'0',{i,j}}].push_back({idx+1, vs[i][j+1]-'0',{i,j+1}});
          ++idx;
      
      }else if((j==0 || j==m-1) && i!=n-1 ){
          //int t=idx+m;
           gr[{idx,vs[i][j]-'0',{i,j}}].push_back({idx+m,vs[i+1][j]-'0',{i+1,j}});
            ++idx;
       
      }else if(i!=0 && i!=n-1 && j!=0 && j!=m-1 ){
        //int t=idx+m;
        //int z=idx-m;
        //int b=idx+1;
        //int w=idx-1;
        gr[{idx, vs[i][j]-'0',{i,j}}].push_back({idx+1,vs[i][j+1]-'0',{i,j+1}});
        gr[{idx,vs[i][j]-'0',{i,j}}].push_back({idx+m,vs[i+1][j]-'0',{i+1,j}});
        
        gr[{idx,vs[i][j]-'0',{i,j}}].push_back({idx-1,vs[i][j-1]-'0',{i,j-1}});
        gr[{idx,vs[i][j]-'0',{i,j}}].push_back({idx-m,vs[i-1][j]-'0',{i-1,j}});
        
        gr[{idx+m,vs[i+1][j]-'0',{i+1,j}}].push_back({idx,vs[i][j]-'0',{i,j}});
        gr[{idx+1,vs[i][j+1]-'0',{i,j+1}}].push_back({idx,vs[i][j]-'0',{i,j}});
        //+->- []
        gr[{idx-m,vs[i-1][j]-'0',{i-1,j}}].push_back({idx,vs[i][j]-'0',{i,j}});
        gr[{idx-1,vs[i][j-1]-'0',{i,j-1}}].push_back({idx,vs[i][j]-'0',{i,j}});
        ++idx;
      }else if(i==n-1 && j==m-1 ){
        gr[{idx, vs[i][j]-'0',{i,j}}].push_back({idx, vs[i][j]-'0',{i,j}});
        gr[{idx, vs[i][j]-'0',{i,j}}].clear();
      }
    }
  }
}
#endif
  #if 1
void c_out_test([[maybe_unused]]std::vector<std::string>& vs,[[maybe_unused]] graph& gr,[[maybe_unused]] std::priority_queue<Node>&heap ){
  #if 0
  std::cout<<vs.size()<<"\n";
  std::copy(vs.begin(),vs.end(),
            std::ostream_iterator<std::string>(std::cout,","));
  #endif
  
  #if 1
  std::cout<<"graph.size()="<<gr.size()<<"\n";
  std::for_each(gr.begin(),gr.end(),[](const auto& p){
    std::cout<<p.first.idx<<"*"<<p.first.data<<"["<<p.first.cd.x<<","<<p.first.cd.y<<"]"
      <<":";
      for(auto& n:p.second){
        std::cout<<n.idx<<"*"<<n.data<<"["<<n.cd.x<<","<<n.cd.y<<"]"<<",";
      }
    std::cout<<"\n";
 });
  #endif
   #if 0 
    while(!heap.empty()){
      std::cout<<heap.top().data<<":"<<heap.top().cd.x<<","<<heap.top().cd.y<<"\n";
      heap.pop();
    }
    
  #endif
  
  

}
  #endif

int path_finder(std::string maze){
  std::vector<std::string> vs;
  parting(maze,vs);
  graph gr;
  make_graph(vs, gr);

  Node start(0,(vs[0][0]-'0'),{0,0});

  #if 1
  std::priority_queue<Node>heap;
  heap.push(start);
  std::vector<int>shift(gr.size(),-1);
  shift[0]=0;
  #if 1
  while(!heap.empty()){
    Node current = heap.top();
    heap.pop();
    int next = current.idx;
    std::cout<<next<<"\n";
    if(next==(int)gr.size()-1){
      return shift[next];
    }
    #if 1
    for(auto& node:gr[]){
      int v = node.idx;
      std::cout<<v<<"\n";
      int s = node.data;
       std::cout<<s<<"\n";
      #if 1
      if(shift[v]==-1 || shift[next] + s < shift[v] ){
        shift[v] = shift[next] + s;
        current.data = shift[v];
        current.idx = v;
        heap.push(current);
      }
      #endif
    }
    #endif
  }
  #endif

  
  
  #endif
  #if 1
  c_out_test(vs,gr,heap);
  #endif
  
  return shift[gr.size() - 1];
  //return -1;
}

#endif

#if 0


using namespace std;

			using node_id_t = int32_t;

			vector<pair<int32_t, int32_t>> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

			struct node
			{
				node_id_t next;
				int32_t cost;
				friend  bool operator<(const node&, const node&);
			};

			bool operator<(const node& lhs,const node &rhs)
			{
				return lhs.cost > rhs.cost;
			}



			int32_t path_finder(const string &literal_maze)
			{
				const auto size = static_cast<int32_t>(floor(sqrt(literal_maze.size())));
				const auto point_size = size * size;

				const auto point_to_id = [size](const int32_t x, const int32_t y) -> node_id_t { return x * size + y;  };
				const auto point_to_literal_id = [size](const int32_t x,const int32_t y) -> node_id_t { return x * (size + 1) + y;  };

				vector<vector<node>> edge(point_size, vector<node>{});
				for(auto x=0;x<size;x++)
				{
					for(auto y=0;y<size;y++)
					{
						for(const auto &dir: directions)
						{
							const auto next_x = x + dir.first;
							const auto next_y = y + dir.second;
							if(next_x>=0&&next_y>=0&&next_x<size&&next_y<size)
							{
								edge[point_to_id(x, y)]
								.push_back(
									node{
										point_to_id(next_x,next_y),
										abs(literal_maze[point_to_literal_id(x,y)]-literal_maze[point_to_literal_id(next_x,next_y)])
									}
								);
							}
						}
					}
				}

				const node_id_t entry = 0;

				vector<int32_t> dist(point_size, -1);
				dist[entry] = 0;

				priority_queue<node> unknown{};
				unknown.push(node{ entry,dist[entry] });

				while(!unknown.empty())
				{
          std::cout<<"unknown.size()="<<unknown.size()<<"\n";
					auto current = unknown.top();
          std::cout<<"current: u = "<<current.next<<"-"<<current.cost<<"\n";
					unknown.pop();
					node_id_t u = current.next;
					if(u == point_size-1)
					{
            std::cout<<"final u="<<u<<"\n";
						return dist[u];
					}
					for (auto i = 0; i < edge[u].size(); i++)
					{
						const auto v = edge[u][i].next;
						const auto cost = edge[u][i].cost;
            std::cout<<"v = "<<v<<", cost = "<<cost<<"\n";
            std::cout<<"dist[v]"<<dist[v]<<"\n";
						if (dist[v] == -1 || dist[u] + cost < dist[v])
						{
              std::cout<<"dist[v] == -1\n";
							dist[v] = dist[u] + cost;
              std::cout<<"dist[v] = dist[u] + cost ="<<dist[v]<<"\n";
              std::cout<<"current.cost before"<<current.cost<<"\n";
              std::cout<<"current.next before"<<current.next<<"\n";
							current.cost = dist[v];
							current.next = v;
              std::cout<<"current.cost after"<<current.cost<<"\n";
              std::cout<<"current.next after"<<current.next<<"\n";
              
							unknown.push(current);
						}
					}
				}
        std::cout<<"point_size - 1 = "<<(point_size - 1)<<"\n";
				return dist[point_size - 1];
			}
		
	


#endif

//////////////////////////////
#include <unordered_map>
#include <map>
#include <utility>
#include <vector>
#include <sstream>
#include <iostream>
#include <iterator>
#include <set>
#include <queue>
#include <cmath>

#if 0
using namespace std;

struct Crd{
  int x,y;
};

struct Node{
  int idx;
  int data;
  Crd cd;
  //Node (int i,int d, Crd c):idx(i), data(d), cd(c) {}
  bool operator==(const Node& other)const{
    return (data==other.data &&
            cd.x==other.cd.x &&
            cd.y==other.cd.y);
  }
  friend  bool operator<(const Node&, const Node&);
			};

bool operator<(const Node& lhs,const Node &rhs)
{
  return lhs.data > rhs.data;
}

struct hasher{
  size_t operator()(const Node& n)const{
    std::hash<int>ih;
    auto f=ih(n.cd.x);
    auto s=ih(n.cd.y);
    auto t=ih(n.data);
    auto fr=ih(n.idx);
    return (f*f*f+s*s*s+t*t*t+fr*fr*fr)^((f*f+s*s+t*t+fr*fr)<<1);
  }
};

using graph = std::unordered_map< Node,std::vector<Node>,hasher>;

void parting(std::string& s, std::vector<std::string>& vs){
  std::stringstream ss;
  ss.str(s);
  for(std::string w; std::getline(ss,w,'\n');){
    vs.push_back(std::move(w));
  }
}

#if 1
void make_graph(std::vector<std::string>& vs,[[maybe_unused]] graph& gr){
  int n = (int)vs.size();
  int m =(int)vs[0].size();
  int idx=0;
  for(int i=0;i<n;++i){
    for(int j=0;j<m;++j){
      if(i==0 && j==0){
        gr[{idx, vs[i][j]-'0',{i,j}}].push_back({idx+1, vs[i][j+1]-'0',{i,j+1}});
        gr[{idx, vs[i][j]-'0',{i,j}}].push_back({idx+m, vs[i+1][j]-'0',{i+1,j}});
       // 
       // gr[{idx+m,vs[i+1][j]-'0',{i+1,j}}].push_back({idx,vs[i][j]-'0',{i,j}});
        //gr[{idx+1,vs[i][j+1]-'0',{i,j+1}}].push_back({idx,vs[i][j]-'0',{i,j}});
        
        
        ++idx;
      }
      else if((i==0 || i==n-1) && j!=m-1  ){
        //
          if(j!=0)gr[{idx,vs[i][j]-'0',{i,j}}].push_back({idx-1,vs[i][j-1]-'0',{i,j-1}});
          if(j==0)gr[{idx,vs[i][j]-'0',{i,j}}].push_back({idx-m,vs[i-1][j]-'0',{i-1,j}});
        
          gr[{idx, vs[i][j]-'0',{i,j}}].push_back({idx+1, vs[i][j+1]-'0',{i,j+1}});
        
          ++idx;
      
      }else if((j==0 || j==m-1) && i!=n-1 ){
        if(j==m-1)gr[{idx,vs[i][j]-'0',{i,j}}].push_back({idx-1,vs[i][j-1]-'0',{i,j-1}});
         if(i>0 ) gr[{idx,vs[i][j]-'0',{i,j}}].push_back({idx-m,vs[i-1][j]-'0',{i-1,j}});
        
          gr[{idx,vs[i][j]-'0',{i,j}}].push_back({idx+m,vs[i+1][j]-'0',{i+1,j}});
          
            ++idx;
       
      }else if(i!=0 && i!=n-1 && j!=0 && j!=m-1 ){
        
        gr[{idx-1,vs[i][j-1]-'0',{i,j-1}}].push_back({idx,vs[i][j]-'0',{i,j}});
        gr[{idx-m,vs[i-1][j]-'0',{i-1,j}}].push_back({idx,vs[i][j]-'0',{i,j}});
        

        gr[{idx,vs[i][j]-'0',{i,j}}].push_back({idx-m,vs[i-1][j]-'0',{i-1,j}});
        gr[{idx,vs[i][j]-'0',{i,j}}].push_back({idx-1,vs[i][j-1]-'0',{i,j-1}});
        
        
        gr[{idx+m,vs[i+1][j]-'0',{i+1,j}}].push_back({idx,vs[i][j]-'0',{i,j}});
        gr[{idx+1,vs[i][j+1]-'0',{i,j+1}}].push_back({idx,vs[i][j]-'0',{i,j}});

        
        gr[{idx, vs[i][j]-'0',{i,j}}].push_back({idx+1,vs[i][j+1]-'0',{i,j+1}});
        gr[{idx,vs[i][j]-'0',{i,j}}].push_back({idx+m,vs[i+1][j]-'0',{i+1,j}});
        
        ++idx;
      }else if(i==n-1 && j==m-1 ){
        gr[{idx, vs[i][j]-'0',{i,j}}].push_back({idx-m, vs[i-1][j]-'0',{i-1,j}});
        gr[{idx, vs[i][j]-'0',{i,j}}].push_back({idx-1, vs[i][j-1]-'0',{i,j-1}});
        
        
      }
    }
  }
}
#endif

void transform_graph(graph& gr,std::vector<std::vector<Node>>& vv){
  std::for_each(gr.begin(),gr.end(),[&vv](const auto& p){
                   std::for_each(p.second.begin(),p.second.end(),
                                 [&p,&vv](const auto& n){
                                   if(find(vv[p.first.idx].begin(),vv[p.first.idx].end(),n)==vv[p.first.idx].end()) 
                                     vv[p.first.idx].push_back(n);
                                 });
                   
  });
  for_each(vv.begin(),vv.end(),[](auto& v){std::sort(v.begin(),v.end(),[](auto& a, auto& b)
                                                     {return a.idx<b.idx;});});
}


  #if 1
void c_out_test([[maybe_unused]]std::vector<std::string>& vs,
                [[maybe_unused]] graph& gr,
                [[maybe_unused]] std::priority_queue<Node>&heap,
               [[maybe_unused]] std::vector<std::vector<Node>>& vv){
  #if 0
  std::cout<<vs.size()<<"\n";
  std::copy(vs.begin(),vs.end(),
            std::ostream_iterator<std::string>(std::cout,","));
  #endif
  
  #if 1
  std::cout<<"graph.size()="<<gr.size()<<"\n";
  std::for_each(gr.begin(),gr.end(),[](const auto& p){
    std::cout<<p.first.idx<<"*"<<p.first.data<<"["<<p.first.cd.x<<","<<p.first.cd.y<<"]"
      <<":";
      for(auto& n:p.second){
        std::cout<<n.idx<<"*"<<n.data<<"["<<n.cd.x<<","<<n.cd.y<<"]"<<",";
      }
    std::cout<<"\n";
 });
  #endif
   #if 0 
    while(!heap.empty()){
      std::cout<<heap.top().data<<":"<<heap.top().cd.x<<","<<heap.top().cd.y<<"\n";
      heap.pop();
    }
    
  #endif
  
  #if 1
  int i=0;
  for_each(vv.begin(),vv.end(),[&i](auto & v){
    std::cout<<i<<" : ";
    for(auto& n:v) std::cout<<n.idx<<"-"<<n.data<<",";
    std::cout<<"\n";
    ++i;
  });
   
  
  #endif

}
  #endif


int path_finder(std::string maze){
  std::vector<std::string> vs;
  parting(maze,vs);
  graph gr;
  make_graph(vs, gr);
   std::vector<std::vector<Node>> vv(gr.size(),std::vector<Node>{}) ;
 
  transform_graph(gr,vv); 
  
   const int entry = 0;
  std::cout<<vv.size()<<"\n";
   std::vector<int>shift(vv.size(),-1);
  shift[entry]=0;

  //Node start(entry, shift[entry],{0,0});

  std::priority_queue<Node>heap{};
  heap.push({entry, shift[entry],{0,0}});

  c_out_test(vs,gr,heap,vv);

 
  
  
  #if 1
  while(!heap.empty()){
    auto current = heap.top();
    cout<<"current:"<<current.idx<<"\n";
    heap.pop();
     cout<<"heap.size="<<heap.size()<<"\n";
    auto u = current.idx;
    cout<<"current.next="<<current.idx<<"\n";
    //std::cout<<u<<"\n";
    if(u==(int)(vv.size()-1)){
      cout<<"finish\n";
      return shift[u];
    }
    #if 1
    cout<<"edge[u].size="<<vv[u].size()<<"\n";
    for (size_t i = 0; i <vv[u].size(); i++)
					{
						const auto v = vv[u][i].idx;
      cout<<"edge[u][i].next="<<vv[u][i].idx<<"\n";
						const auto cost = vv[u][i].data;
      cout<<"edge[u][i].cost="<<vv[u][i].data<<"\n";
      cout<<"dist[u]"<<shift[u]<<"\n";
            cout<<"dist[u] + cost("<<shift[u] + cost<<")<dist[v]="<<shift[v]<<"\n";
						if (shift[v] == -1 || shift[u] + cost < shift[v])
						{
               cout<<"current.cost before "<<current.data<<"\n";
              cout<<"current.next before "<<current.idx<<"\n";
              
              
							shift[v] = shift[u] + cost;
              cout<<"dist[v]="<<shift[v]<<"\n";
							current.data = shift[v];
							current.idx = v;
              cout<<"current.cost after "<<current.data<<"\n";
              cout<<"current.next after "<<current.idx<<"\n";
							heap.push(current);
              cout<<"heap.size after push="<<heap.size()<<"\n";
						}
     // for(auto i:shift)std::cout<<i;
      //std::cout<<"\n";
      
      
    }
    #endif
  }
  #endif

  
  
  return shift[vv.size() - 1];
}

#endif


#if 1
using namespace std;

			using node_id_t = int32_t;

			vector<pair<int32_t, int32_t>> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

			struct node
			{
				node_id_t next;
				int32_t cost;
				friend  bool operator<(const node&, const node&);
			};

			bool operator<(const node& lhs,const node &rhs)
			{
				return lhs.cost > rhs.cost;
			}



			int32_t path_finder(const string &literal_maze)
			{
				const auto size = static_cast<int32_t>(floor(sqrt(literal_maze.size())));
				const auto point_size = size * size;

				const auto point_to_id = [size](const int32_t x, const int32_t y) -> node_id_t { return x * size + y;  };
				const auto point_to_literal_id = [size](const int32_t x,const int32_t y) -> node_id_t { return x * (size + 1) + y;  };

				vector<vector<node>> edge(point_size, vector<node>{});
				for(auto x=0;x<size;x++)
				{
					for(auto y=0;y<size;y++)
					{
						for(const auto &dir: directions)
						{
							const auto next_x = x + dir.first;
							const auto next_y = y + dir.second;
							if(next_x>=0&&next_y>=0&&next_x<size&&next_y<size)
							{
                std::cout<<"point_to_id(x, y)"<<point_to_id(x, y)<<"\n";
                 std::cout<<"point_to_literal_id(next_x,next_y)"<<point_to_literal_id(next_x,next_y)<<"\n";
                std::cout<<"abs(literal_maze[point_to_literal_id(x,y)]-literal_maze[point_to_literal_id(next_x,next_y)]"<<(abs(literal_maze[point_to_literal_id(x,y)]-literal_maze[point_to_literal_id(next_x,next_y)]))<<"\n";
								edge[point_to_id(x, y)]
								.push_back(
									node{
										point_to_id(next_x,next_y),
										abs(literal_maze[point_to_literal_id(x,y)]-literal_maze[point_to_literal_id(next_x,next_y)])
									}
								);
							}
						}
					}
				}

        for(size_t i=0;i<edge.size();++i){
          std::cout<<i<<":";
          for(auto n: edge[i]) std::cout<<n.next<<",";
          std::cout<<"\n";
        }
        std::cout<<"\n";
				const node_id_t entry = 0;

        std::cout<<"point_size-"<<point_size<<"\n";
				vector<int32_t> dist(point_size, -1);
				dist[entry] = 0;

				priority_queue<node> unknown{};
				unknown.push(node{ entry,dist[entry] });
        std::cout<<"---------\n";
				while(!unknown.empty())
				{
					auto current = unknown.top();
          //cout<<"current:"<<current.next<<"\n";
					unknown.pop();
         // cout<<"heap.size="<<unknown.size()<<"\n";
					node_id_t u = current.next;
          //cout<<"current.next="<<current.next<<"\n";
					if(u == point_size-1)
					{
            cout<<"finish\n";
						return dist[u];
					}
         // cout<<"edge[u].size="<<edge[u].size()<<"\n";
					for (auto i = 0; i < (int)edge[u].size(); i++)
					{
						const auto v = edge[u][i].next;
            //cout<<"edge[u][i].next="<<edge[u][i].next<<"\n";
						const auto cost = edge[u][i].cost;
            //cout<<"edge[u][i].cost="<<edge[u][i].cost<<"\n";
            //cout<<"dist[u]"<<dist[u]<<"\n";
            //cout<<"dist[u] + cost("<<dist[u] + cost<<")<dist[v]="<<dist[v]<<"\n";
						if (dist[v] == -1 || dist[u] + cost < dist[v])
						{
              //cout<<"current.cost before "<<current.cost<<"\n";
              //cout<<"current.next before "<<current.next<<"\n";
              
							dist[v] = dist[u] + cost;
             // cout<<"dist[v]="<<dist[v]<<"\n";
							current.cost = dist[v];
							current.next = v;
             // cout<<"current.cost after "<<current.cost<<"\n";
             // cout<<"current.next after "<<current.next<<"\n";
							unknown.push(current);
              //cout<<"heap.size after push="<<unknown.size()<<"\n";
						}
            //for(auto i:dist)std::cout<<i;
      //std::cout<<"\n";
					}
				}
        
				return dist[point_size - 1];
			}
#endif

///////////////////////////////////////////////////.........
#include <unordered_map>
#include <map>
#include <utility>
#include <vector>
#include <sstream>
#include <iostream>
#include <iterator>
#include <set>
#include <queue>
#include <cmath>
#include <memory>


struct Crd{
  int x,y;
};

struct Node{
  int idx;
  int data;
  Crd cd;
  Node (int i,int d, Crd c):idx(i), data(d), cd(c) {}
  bool operator==(const Node& other)const{
    return (data==other.data &&
            cd.x==other.cd.x &&
            cd.y==other.cd.y);
  }
  bool operator<(const Node& other)const{
    return data>other.data;
  }
};

struct hasher{
  size_t operator()(const Node& n)const{
    std::hash<int>ih;
    auto f=ih(n.cd.x);
    auto s=ih(n.cd.y);
    auto t=ih(n.data);
    auto fr=ih(n.idx);
    return (f*f*f+s*s*s+t*t*t+fr*fr*fr)^((f*f+s*s+t*t+fr*fr)<<1);
  }
};

using hash_graph = std::unordered_map<const Node,std::vector<Node>,hasher>;

using vec_graph = std::vector<std::vector<std::shared_ptr<Node>>>;

void parting(std::string& s, std::vector<std::string>& vs){
  std::stringstream ss;
  ss.str(s);
  for(std::string w; std::getline(ss,w,'\n');){
    vs.push_back(std::move(w));
  }
}

void make_graph(std::vector<std::string>& vs, vec_graph& gr, std::string& maze){
  std::vector<std::pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
  int sz = (int)vs.size();
  auto vert = [sz](const int& x,const int& y){return (x*sz + y);};
  auto ids = [sz](const int& x,const int& y){return (x*(sz+1) + y);};
  for(int x=0;x<sz;++x){
    for(int y=0;y<sz;++y){
      for(const auto& d: dir){
        const auto xt= x+d.first;
        const auto yt= y+d.second;
        if(xt>=0 && yt>=0 && xt<sz && yt<sz){
          gr[vert(x,y)].push_back(std::make_shared<Node>(Node(vert(xt,yt), std::abs(maze[ids(x,y)]-maze[ids(xt,yt)]),{xt,yt})));
        }
      }
    }
  }
}

#if 1
void make_hash_graph(std::vector<std::string>& vs,[[maybe_unused]] hash_graph& gr){
  int n = (int)vs.size();
  int m =(int)vs[0].size();
  int idx=0;
  for(int i=0;i<n;++i){
    for(int j=0;j<m;++j){
      if(i==0 && j==0){
        gr[{idx, std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j}}].push_back({idx+1, std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j+1}});
        gr[{idx, std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i,j}}].push_back({idx+m, std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i+1,j}});
        ++idx;
      }
      else if((i==0 || i==n-1) && j!=m-1 ){
        if(i==0 && j!=m-1 && j!=0){
          gr[{idx, std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j}}].push_back({idx+1, std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j+1}});
          gr[{idx, std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j}}].push_back({idx-1, std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j-1}});
        }
          if(i==n-1 && j!=m-1 && j!=0){
        gr[{idx, std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i,j}}].push_back({idx-m, std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i-1,j}});
            gr[{idx, std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j}}].push_back({idx-1, std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j-1}});
            gr[{idx, std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j}}].push_back({idx+1, std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j+1}});}
        if(i==n-1 && j!=m-1 && j==0){
          gr[{idx, std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j}}].push_back({idx+1, std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j+1}});
           gr[{idx, std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i,j}}].push_back({idx-m, std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i-1,j}});
        }
          ++idx;
      
      }else if((j==0 || j==m-1) && i!=n-1 ){
        if(j==0 && i!=0)
          gr[{idx,std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i,j}}].push_back({idx-m,std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i-1,j}});
          gr[{idx,std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i,j}}].push_back({idx+m,std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i+1,j}});
        if(j==m-1 && i!=0)
          gr[{idx,std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i,j}}].push_back({idx-m,std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i-1,j}});
        if(j==m-1 && i==0){
          gr[{idx,std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j}}].push_back({idx-1,std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j-1}});
          gr[{idx,std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i,j}}].push_back({idx+m,std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i+1,j}});}
        ++idx;
       
      }else if(i!=0 && i!=n-1 && j!=0 && j!=m-1 ){
        gr[{idx, std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j}}].push_back({idx+1,std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j+1}});
        gr[{idx,std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i,j}}].push_back({idx+m,std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i+1,j}});
        
        gr[{idx,std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j}}].push_back({idx-1,std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j-1}});
        gr[{idx,std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i,j}}].push_back({idx-m,std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i-1,j}});
        
        gr[{idx+m,std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i+1,j}}].push_back({idx,std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i,j}});
        gr[{idx+1,std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j+1}}].push_back({idx,std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j}});
        //+->- []
        gr[{idx-m,std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i-1,j}}].push_back({idx,std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i,j}});
        gr[{idx-1,std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j-1}}].push_back({idx,std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j}});
        ++idx;
      }else if(i==n-1 && j==m-1 ){
        gr[{idx,std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i,j}}].push_back({idx-m, std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i,j}});
        gr[{idx,std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j}}].push_back({idx-1,std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j-1}});
        gr[{idx-m,std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i-1,j}}].push_back({idx,std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i,j}});
        gr[{idx-1,std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j-1}}].push_back({idx,std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j}});
      }
    }
  }
  for_each(gr.begin(),gr.end(),[](auto& p){
   std::sort(p.second.begin(),p.second.end(),[](auto& a,auto& b){return a.idx<b.idx;});
  });
  
  for_each(gr.begin(),gr.end(),[](auto& p){
    p.second.erase(std::unique(p.second.begin(),p.second.end()),p.second.end());
  });
}
#endif

void transform_graph(hash_graph& gr,std::vector<std::vector<Node>>& vv){
  std::for_each(gr.begin(),gr.end(),[&vv](const auto& p){
                   std::for_each(p.second.begin(),p.second.end(),
                                 [&p,&vv](const auto& n){
                                   if(find(vv[p.first.idx].begin(),vv[p.first.idx].end(),n)==vv[p.first.idx].end()) 
                                     vv[p.first.idx].push_back(n);
                                 });
                   
  });
  for_each(vv.begin(),vv.end(),[](auto& v){std::sort(v.begin(),v.end(),[](auto& a, auto& b)
                                                     {return a.idx<b.idx;});});
}

void c_out_test([[maybe_unused]] vec_graph& gr, [[maybe_unused]] hash_graph& gr1){
  #if 0
  int i = 0;
  std::for_each(gr.begin(),gr.end(),[&i](const auto& vc){
    std::cout<<i<<"*"<<"\n";
    std::for_each(vc.begin(),vc.end(),[](const auto& n){
      std::cout<<"idx = "<<n.get()->idx<<", data: "<<n.get()->data<<", crd=["<<n.get()->cd.x<<", "<<n.get()->cd.y<<"]"<<"\n";
    });
    ++i;
    std::cout<<"<->\n";
  });
  #endif
  std::cout<<"graph.size()="<<gr1.size()<<"\n";
  std::for_each(gr1.begin(),gr1.end(),[](const auto& p){
    std::cout<<p.first.idx<<"*"//<<p.first.data<<"["<<p.first.cd.x<<","<<p.first.cd.y<<"]"
      <<":";
      for(auto& n:p.second){
        std::cout<<n.idx<<"*"//<<n.data<<"["<<n.cd.x<<","<<n.cd.y<<"]"
          <<",";
      }
    std::cout<<"\n";
 });
}



int solution(vec_graph& gr,std::vector<int>& shift,int psz){
  std::priority_queue<Node>heap;
  heap.push(Node(0,shift[0],{0,0}));
  while(!heap.empty()){
    Node current = heap.top();
    heap.pop();
    int id = current.idx;
    if(id==psz-1){
      return shift[id];
    }
    for(auto& n: gr[id]){
      auto next = (*n.get()).idx;
      auto cost = (*n.get()).data;
      if(shift[next]==-1 || shift[id]+cost<shift[next]){
        shift[next]=shift[id]+cost;
        current.data=shift[next];
        current.idx=next;
        heap.push(current);
      }
    }
  }
  return shift[psz-1];
}

int solution_h(std::vector<std::vector<Node>>& gr,std::vector<int>& shift,int psz){
  std::priority_queue<Node>heap;
  heap.push(Node(0,shift[0],{0,0}));
  while(!heap.empty()){
    Node current = heap.top();
    heap.pop();
    int id = current.idx;
    if(id==psz-1){
      return shift[id];
    }
    for(auto& n: gr[id]){
      auto next = n.idx;
      auto cost = n.data;
      if(shift[next]==-1 || shift[id]+cost<shift[next]){
        shift[next]=shift[id]+cost;
        current.data=shift[next];
        current.idx=next;
        heap.push(current);
      }
    }
  }
  return shift[psz-1];
}



int path_finder(std::string maze)
{
  std::vector<std::string> vs;
  parting(maze,vs);
  int sz = (int)vs.size();
  int psz = sz * sz;
  vec_graph gr(psz, std::vector<std::shared_ptr<Node>>{});
  hash_graph hg;
  make_graph(vs, gr, maze);
  make_hash_graph(vs,hg);
  std::vector<std::vector<Node>> vv(psz, std::vector<Node>{});
  transform_graph(hg,vv);
  #if 1
  c_out_test(gr,hg);
  #endif
  
  std::vector<int>shift(psz,-1);
  shift[0] = 0;
  
  std::vector<int>shif(psz,-1);
  shif[0] = 0;

  //int res = solution(gr, shift, psz);
  int res1=solution_h(vv,shif,psz);
  
  return res1;
}//работает после трансформа хеша в вектор векторов




///////////////
#include <unordered_map>
#include <map>
#include <utility>
#include <vector>
#include <sstream>
#include <iostream>
#include <iterator>
#include <set>
#include <queue>
#include <cmath>
#include <memory>


struct Crd{
  int x,y;
};

struct Node{
  int idx;
  int data;
  Crd cd;
  Node (int i,int d, Crd c):idx(i), data(d), cd(c) {}
  bool operator==(const Node& other)const{
    return (data==other.data &&
            cd.x==other.cd.x &&
            cd.y==other.cd.y);
  }
  bool operator<(const Node& other)const{
    return data>other.data;
  }
};

struct hasher{
  size_t operator()(const Node& n)const{
    std::hash<int>ih;
    auto f=ih(n.cd.x);
    auto s=ih(n.cd.y);
    auto t=ih(n.data);
    auto fr=ih(n.idx);
    return (f*f*f+s*s*s+t*t*t+fr*fr*fr)^((f*f+s*s+t*t+fr*fr)<<1);
  }
};

using hash_graph = std::unordered_map<const Node,std::vector<Node>,hasher>;

using vec_graph = std::vector<std::vector<std::shared_ptr<Node>>>;

void parting(std::string& s, std::vector<std::string>& vs){
  std::stringstream ss;
  ss.str(s);
  for(std::string w; std::getline(ss,w,'\n');){
    vs.push_back(std::move(w));
  }
}

void make_graph(std::vector<std::string>& vs, vec_graph& gr, std::string& maze){
  std::vector<std::pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
  int sz = (int)vs.size();
  auto vert = [sz](const int& x,const int& y){return (x*sz + y);};
  auto ids = [sz](const int& x,const int& y){return (x*(sz+1) + y);};
  for(int x=0;x<sz;++x){
    for(int y=0;y<sz;++y){
      for(const auto& d: dir){
        const auto xt= x+d.first;
        const auto yt= y+d.second;
        if(xt>=0 && yt>=0 && xt<sz && yt<sz){
          gr[vert(x,y)].push_back(std::make_shared<Node>(Node(vert(xt,yt), std::abs(maze[ids(x,y)]-maze[ids(xt,yt)]),{xt,yt})));
        }
      }
    }
  }
}

#if 1
void make_hash_graph(std::vector<std::string>& vs,[[maybe_unused]] hash_graph& gr){
  int n = (int)vs.size();
  int m =(int)vs[0].size();
  int idx=0;
  for(int i=0;i<n;++i){
    for(int j=0;j<m;++j){
      if(i==0 && j==0){
        gr[{idx, std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j}}].push_back({idx+1, std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j+1}});
        gr[{idx, std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i,j}}].push_back({idx+m, std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i+1,j}});
        ++idx;
        
     }
      if((i==0 || i==n-1) && j!=m-1){   
        
        if(i==0 && j!=m-1 && j!=0){
          gr[{idx, std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j}}].push_back({idx+1, std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j+1}});
          gr[{idx, std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j}}].push_back({idx-1, std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j-1}});
          gr[{idx,std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i,j}}].push_back({idx+m,std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i+1,j}});
        ++idx;
        }
        if(i==n-1 && j!=m-1 && j!=0){
            gr[{idx, std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i,j}}].push_back({idx-m, std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i-1,j}});
            gr[{idx, std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j}}].push_back({idx-1, std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j-1}});
            gr[{idx, std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j}}].push_back({idx+1, std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j+1}});
        ++idx;
        }
        
        if(i==n-1 && j!=m-1 && j==0){
          gr[{idx, std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j}}].push_back({idx+1, std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j+1}});
           gr[{idx, std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i,j}}].push_back({idx-m, std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i-1,j}});
        ++idx;
        }
        
         // ++idx;
      
      }
      if((j==0 || j==m-1) && i!=n-1 ){
        if(j==0 && i!=0){
          gr[{idx,std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i,j}}].push_back({idx-m,std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i-1,j}});
          gr[{idx,std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i,j}}].push_back({idx+m,std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i+1,j}});
          gr[{idx, std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j}}].push_back({idx+1, std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j+1}});
        ++idx;
        }
        if(j==m-1 && i!=0){
          gr[{idx,std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i,j}}].push_back({idx-m,std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i-1,j}});
        gr[{idx,std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i,j}}].push_back({idx+m,std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i+1,j}});
        gr[{idx,std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j}}].push_back({idx-1,std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j-1}});
        ++idx;
        }
        if(j==m-1 && i==0){
          gr[{idx,std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j}}].push_back({idx-1,std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j-1}});
          gr[{idx,std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i,j}}].push_back({idx+m,std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i+1,j}});
        ++idx;}
        //++idx;
       
      }
      if(i!=0 && i!=n-1 && j!=0 && j!=m-1 ){
        gr[{idx, std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j}}].push_back({idx+1,std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j+1}});
        gr[{idx,std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i,j}}].push_back({idx+m,std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i+1,j}});
        
        gr[{idx,std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j}}].push_back({idx-1,std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j-1}});
        gr[{idx,std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i,j}}].push_back({idx-m,std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i-1,j}});
        
        gr[{idx+m,std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i+1,j}}].push_back({idx,std::abs((vs[i][j]-'0')-(vs[i+1][j]-'0')),{i,j}});
        gr[{idx+1,std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j+1}}].push_back({idx,std::abs((vs[i][j]-'0')-(vs[i][j+1]-'0')),{i,j}});
        
        gr[{idx-m,std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i-1,j}}].push_back({idx,std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i,j}});
        gr[{idx-1,std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j-1}}].push_back({idx,std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j}});
        ++idx;
      }
      if(i==n-1 && j==m-1 ){
        gr[{idx,std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i,j}}].push_back({idx-m, std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i,j}});
        gr[{idx,std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j}}].push_back({idx-1,std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j-1}});
        gr[{idx-m,std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i-1,j}}].push_back({idx,std::abs((vs[i][j]-'0')-(vs[i-1][j]-'0')),{i,j}});
        gr[{idx-1,std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j-1}}].push_back({idx,std::abs((vs[i][j]-'0')-(vs[i][j-1]-'0')),{i,j}});
      }
    }
  }
  for_each(gr.begin(),gr.end(),[](auto& p){
   std::sort(p.second.begin(),p.second.end(),[](auto& a,auto& b){return a.idx<b.idx;});
  });
  
  for_each(gr.begin(),gr.end(),[](auto& p){
    p.second.erase(std::unique(p.second.begin(),p.second.end()),p.second.end());
  });
}
#endif

void transform_graph(hash_graph& gr,std::vector<std::vector<Node>>& vv){
  std::for_each(gr.begin(),gr.end(),[&vv](const auto& p){
                   std::for_each(p.second.begin(),p.second.end(),
                                 [&p,&vv](const auto& n){
                                   if(find(vv[p.first.idx].begin(),vv[p.first.idx].end(),n)==vv[p.first.idx].end()) 
                                     vv[p.first.idx].push_back(n);
                                 });
                   
  });
  for_each(vv.begin(),vv.end(),[](auto& v){std::sort(v.begin(),v.end(),[](auto& a, auto& b)
                                                     {return a.idx<b.idx;});});
}

void c_out_test([[maybe_unused]] vec_graph& gr, [[maybe_unused]] hash_graph& gr1){
  #if 0
  int i = 0;
  std::for_each(gr.begin(),gr.end(),[&i](const auto& vc){
    std::cout<<i<<"*"<<"\n";
    std::for_each(vc.begin(),vc.end(),[](const auto& n){
      std::cout<<"idx = "<<n.get()->idx<<", data: "<<n.get()->data<<", crd=["<<n.get()->cd.x<<", "<<n.get()->cd.y<<"]"<<"\n";
    });
    ++i;
    std::cout<<"<->\n";
  });
  #endif
  std::cout<<"graph.size()="<<gr1.size()<<"\n";
  std::for_each(gr1.begin(),gr1.end(),[](const auto& p){
    std::cout<<p.first.idx<<"*"<<p.first.data<<"["<<p.first.cd.x<<","<<p.first.cd.y<<"]"
      <<":";
      for(auto& n:p.second){
        std::cout<<n.idx<<"*"<<n.data<<"["<<n.cd.x<<","<<n.cd.y<<"]"
          <<",";
      }
    std::cout<<"\n";
 });
}



int solution(vec_graph& gr,std::vector<int>& shift,int psz){
  std::priority_queue<Node>heap;
  heap.push(Node(0,shift[0],{0,0}));
  while(!heap.empty()){
    Node current = heap.top();
    heap.pop();
    int id = current.idx;
    if(id==psz-1){
      return shift[id];
    }
    for(auto& n: gr[id]){
      auto next = (*n.get()).idx;
      auto cost = (*n.get()).data;
      if(shift[next]==-1 || shift[id]+cost<shift[next]){
        shift[next]=shift[id]+cost;
        current.data=shift[next];
        current.idx=next;
        heap.push(current);
      }
    }
  }
  return shift[psz-1];
}

int solution_h(hash_graph& gr,std::vector<int>& shift,int psz){
  std::priority_queue<Node>heap;
  heap.push(Node(0,shift[0],{0,0}));
  while(!heap.empty()){
    std::cout<<heap.size()<<"\n";
    Node current = heap.top();
    heap.pop();
    int id = current.idx;
    if(id==psz-1){
      return shift[id];
    }
    auto node=find_if(gr.begin(),gr.end(),[&id](const auto& p){return p.first.idx == id;});
    Node nd=(*node).first;
    for(auto& n: gr[nd]){
      auto next = n.idx;
      auto cost = n.data;
      if(shift[next]==-1 || shift[id]+cost<shift[next]){
        shift[next]=shift[id]+cost;
        nd.data=shift[next];
        nd.idx=next;
        heap.push(nd);
      }
    }
  }
  return shift[psz-1];
}



int path_finder(std::string maze)
{
  std::vector<std::string> vs;
  parting(maze,vs);
  int sz = (int)vs.size();
  int psz = sz * sz;
  vec_graph gr(psz, std::vector<std::shared_ptr<Node>>{});
  hash_graph hg;
  make_graph(vs, gr, maze);
  make_hash_graph(vs,hg);
  std::vector<std::vector<Node>> vv(psz, std::vector<Node>{});
  transform_graph(hg,vv);
  #if 1
  c_out_test(gr,hg);
  #endif
  
  std::vector<int>shift(psz,-1);
  shift[0] = 0;
  
  std::vector<int>shif(psz,-1);
  shif[0] = 0;

  //int res = solution(gr, shift, psz);
  int res1=solution_h(hg,shif,psz);
  for(auto i:shif)std::cout<<i<<",";
  
  return res1;
}