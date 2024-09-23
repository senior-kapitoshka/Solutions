#include <iostream>
#include <string>
#include <vector>
#include <set>

void DFS(int node,const std::vector<std::vector<int>>&g, std::set<int>& vis){
    if(vis.count(node)) return;
    vis.insert(node);
    for(auto i:g[node]){
        DFS(i,g,vis);
    }
}

int main() 
{
    int v,e;
	std::cin>>v>>e;
    std::vector<std::vector<int>>g(v+1,std::vector<int>{});
    for(int i=0;i<e;++i){
        int t,t1;
        std::cin>>t>>t1;
        g[t].push_back(t1);
        g[t1].push_back(t);
    }
    std::set<int>vis;
    DFS(1,g,vis);

    for(auto i:vis) std::cout<<i<<" ";
    std::cout<<"\n";
	return 0;
}

///////////////////////////////


#include <iostream>
#include <vector>

class Graph {


public:
    size_t num_ver = 0;
    std::vector<std::vector<size_t>> graph;
    std::vector<bool> visited;

    Graph(size_t V);

    void addEdge(size_t src, size_t dest);

    void DFS(size_t vertex);
};

Graph::Graph(size_t vertices) {
    num_ver = vertices;
    graph.resize(vertices + 1);
    visited.resize(vertices + 1);
}

void Graph::addEdge(size_t src, size_t dest) {
    graph[src].push_back(dest);
}

void Graph::DFS(size_t vertex) {
    visited[vertex] = true;
    for (size_t now: graph[vertex]) {
        if (!visited[now]) {
            DFS(now);
        }
    }

}
int main() {
    size_t V = 0, E = 0, quan = 0;
    std::cin >> V >> E;
    Graph g(V);
    for (size_t i = 0; i < E; ++i) {
        size_t fir = 0, sec = 0;
        std::cin >> fir >> sec;
        if (fir != sec) {
            g.addEdge(fir, sec);
        }
    }
    std::cout << 1 << " ";
    for (size_t i = 2; i < V + 1; ++i) {
        g.DFS(i);
        if (g.visited[1]) {
            std::cout << i << " ";
            std::fill(g.visited.begin(),g.visited.end(), false);
        }
    }
    return 0;
}