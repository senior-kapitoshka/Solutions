#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

void BFS(int from, const std::unordered_map<int,std::vector<int>>&gr,
std::vector<std::pair<int,int>>& dist_plus_nhb,std::vector<int>&vis){
    std::queue<int>que;
    que.push(from);
    dist_plus_nhb[from-1]={0,-1};
    vis[from-1]=1;
    while(!que.empty()){
        
        int node=que.front();
        que.pop();
            for(auto i: gr.at(node)){
                if(vis[i-1]==0){
                    dist_plus_nhb[i-1].second=node;
                    dist_plus_nhb[i-1].first=dist_plus_nhb[node-1].first+1;
                    vis[i-1]=1;
                    que.push(i);
                }
            }
        } 
}

int main() 
{
    int n=0;
    std::cin>>n;
    std::unordered_map<int,std::vector<int>>gr;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            int x=0;
            std::cin>>x;
            if(x==1)gr[i+1].push_back(j+1);
        }
    }

    int from=0,to=0;
    std::cin>>from>>to;
    std::vector<std::pair<int,int>>dist_plus_nhb(n);
    std::vector<int>vis(n);

   if(from!=to && !gr.empty()){
       BFS(from, gr, dist_plus_nhb, vis);
        std::cout<<dist_plus_nhb[to-1].first<<"\n";
        if(dist_plus_nhb[to-1].first!=-1) {
            std::vector<int>ans;
            ans.push_back(to);
            int node=dist_plus_nhb[to-1].second;
            while(node!=-1){
                ans.push_back(node);
                node=dist_plus_nhb[node-1].second;
            }
            for(int i=ans.size()-1;i>=0;--i){
                std::cout<<ans[i]<<" ";
            }
        }
    }else{
       if(from==to)std::cout<<0;
       if(gr.empty()) std::cout<<-1;
    }
    
	return 0;
}

//////////////////////////
//В неориентированном графе требуется найти минимальный путь между двумя вершинами.

#include <iostream>
#include <vector>
#include <queue>

class Graph {


public:
    int num_ver = 0;
    std::vector<std::vector<int>> graph;
    std::vector<int> mark;
    std::vector<bool> used;
    std::vector<std::pair<int, int>> d;

    Graph(int V);

    void addEdge(int src, int dest);

    void DFS(int);

    void BFS(int vertex);
};

Graph::Graph(int vertices) {
    num_ver = vertices;
    graph.resize(vertices + 1);
    mark.resize(vertices + 1);
    d.resize(vertices + 1);
    used.resize(vertices + 1);
}

void Graph::addEdge(int src, int dest) {
    graph[src].push_back(dest);
}

void Graph::DFS(int vertex) {
    used[vertex] = true;
    for (auto now: graph[vertex]) {
        if (!used[now]) {
            DFS(now);
        }
    }
}

void Graph::BFS(int start) {
    std::queue<int> q;
    // Инициализация: есть информация про начальную вершину
    q.push(start);
    d[start] = {0, -1};// first-это расстояние, second- это предок.
    mark[start] = 1;
    // Главный цикл - пока есть серые вершины
    while (!q.empty()) {
        // Берем первую из них
        int v = q.front();
        q.pop();
        // Пробегаемся по всем ее соседям
        for (int i = 0; i < (int) graph[v].size(); ++i) {
            // Если сосед белый
            if (mark[graph[v][i]] == 0) {
                // То вычисляем расстояние
                d[graph[v][i]].second = v;
                d[graph[v][i]].first = d[v].first + 1;
                // И он становится серым
                mark[graph[v][i]] = 1;
                q.push(graph[v][i]);
            }
        }
    }
}


int main() {
    int V = 0, tmp = 0;
    std::cin >> V;
    Graph g(V);
    for (int i = 1; i < V + 1; ++i) {
        for (int j = 1; j < V + 1; ++j) {
            std::cin >> tmp;
            if (tmp == 1) {
                g.addEdge(i, j);

            }
        }
    }
    int start = 0, finish = 0;
    std::cin >> start >> finish;
    g.DFS(start);
    if (g.used[finish]) {
        g.BFS(start);
        if (g.d[finish].first != 0) {
            std::cout << g.d[finish].first << std::endl;
            std::vector<int> ans;
            ans.push_back(finish);
            int cur_v = g.d[finish].second;
            while (cur_v != -1) {
                ans.push_back(cur_v);
                cur_v = g.d[cur_v].second;
            }
            std::reverse(ans.begin(), ans.end());
            for (auto now: ans) {
                std::cout << now << " ";
            }
        } else {
            std::cout << g.d[finish].first;
        }
    } else {
        std::cout << -1;
    }
    return 0;
}





