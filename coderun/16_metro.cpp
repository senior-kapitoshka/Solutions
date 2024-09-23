//2 из 25
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

void BFS(std::vector<std::vector<int>>&gr,int from, int to,int& res){
    std::queue<int>q;
    q.push(from);
    std::vector<int>dist(gr.size()+1,0);
    dist[from]=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        if(node==to) break;
        for(auto i:gr[node]){
            dist[i]=dist[node]+1;
            q.push(i);
        }
    }
    res=dist[to]==0?-1:dist[to];
}


void make_graph(std::vector<std::set<int>>&vs,
 std::vector<std::vector<int>>&gr){
    std::for_each(vs.begin(),vs.end(),[&gr,&vs](auto& s)
    {
         for(auto j:vs){
             if(s!=j){
                 std::vector<int>sct;
                 std::set_intersection(s.begin(),
                     s.end(),j.begin(),j.end(),
                     std::back_inserter(sct));
                 if(!sct.empty()){
                     gr[(*s.begin())]=sct;
                 }
             }
         }   
    });
 }

int main() 
{
    int all,n;
    std::cin>>all;
    std::cin>>n;
    std::vector<std::set<int>>vs;
    for(int i=0;i<n;++i){
        int m;
        std::cin>>m;
        std::set<int>st;
        for(int j=0;j<m;++j){
            int v;
            std::cin>>v;
            st.insert(v);
        }
        vs.push_back(st);
    }
    int from,to;
    std::cin>>from>>to;
    for(auto i:vs){
        if(i.count(from) && i.count(to)){
            std::cout<<0;
            return 0;
            
        }
        if(i.count(from)){
            from=*i.begin();
        }
        if(i.count(to)){
            to=*i.begin();
        }
    }
    std::vector<std::vector<int>>gr(all+1,std::vector<int>{});
    make_graph(vs,gr);
    int res=0;
    BFS(gr,from,to,res);
    std::cout<<res<<"\n"

	return 0;
}

///////////////////////////////////////


#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <climits>



int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> vertex(m + 1, -1);
    std::map<int, std::set<int>> edges, stations;
    for (int i = 0; i < m; ++i) {
        int p;
        std::cin >> p;
        for (int u = 0; u < p; ++u) {
            int j;
            std::cin >> j;
            for (int k : stations[j]) {
                edges[k].insert(i);
                edges[i].insert(k);
            }
            stations[j].insert(i);
        }
    }
    int a, b;
    std::cin >> a >> b;
    auto starts = stations[a];
    auto ends = stations[b];
    std::vector<int> dist, curr_dist;
    for (int i : starts) {
        vertex[i] = 0;
        dist.push_back(i);
    }
    int curr = 0, ma = 0;
    while (curr <= ma) {
        for (int v : dist) {
            for (int next : edges[v]) {
                if (vertex[next] == -1) {
                    ma = curr + 1;
                    vertex[next] = curr + 1;
                    curr_dist.push_back(next);
                }
            }
        }
        dist.swap(curr_dist);
        curr++;
    }
    int ans = INT_MAX;
    for (int i : ends) {
        if (vertex[i]!=-1 && vertex[i] < ans) {
            ans = vertex[i];
        }
    }
    std::cout << (ans == INT_MAX ? -1 : ans);
}