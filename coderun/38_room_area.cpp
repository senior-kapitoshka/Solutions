

#include <iostream>
#include <string>
#include <vector>
#include <set>

void DFS(std::set<std::pair<int,int>>& vis,const std::vector<std::vector<char>>&mx,const int sz,
std::pair<int,int>&& node,int& cnt){
    if(node.first>sz || node.second>sz 
        || node.second<0 || node.first<0) return;
    if(vis.count(node)) return;
    if(mx[node.first][node.second]=='*') return;
    else if(mx[node.first][node.second]=='.'){
        vis.insert(node);
        ++cnt;
        #if 0
       DFS(vis,mx,sz,{node.first+1,node.second+1},cnt);
         DFS(vis,mx,sz,{node.first-1,node.second+1},cnt);
         DFS(vis,mx,sz,{node.first+1,node.second-1},cnt);
         DFS(vis,mx,sz,{node.first-1,node.second-1},cnt);
         //в условии не указано, что нужно проверять стенки по диагонали
        #endif
         DFS(vis,mx,sz,{node.first,node.second+1},cnt);
         DFS(vis,mx,sz,{node.first,node.second-1},cnt);
         DFS(vis,mx,sz,{node.first+1,node.second},cnt);
         DFS(vis,mx,sz,{node.first-1,node.second},cnt);
    } 
}

int main() 
{
    int n=0;
    std::cin>>n;
	std::vector<std::vector<char>>mx(n,std::vector<char>(n,'z'));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            
            std::cin>>mx[i][j];
        }
    }
    int x,y;
    std::cin>>x>>y;

    std::set<std::pair<int,int>>vis;
    int cnt=0;

    DFS(vis,mx,n,{x-1,y-1},cnt);
    std::cout<<cnt<<"\n";
    
	return 0;
}


//c github

class Lab {
public:
    char room[1000][1000];
    size_t S = 0;

    void fun(size_t x, size_t y);
};

void Lab::fun(size_t x, size_t y) {
    if (room[x][y] == '.') {
        S++;
        room[x][y] = '*';
        fun(x - 1, y);
        fun(x + 1, y);
        fun(x, y - 1);
        fun(x, y + 1);
    }
}

int main() {
    Lab lab;
    int n = 0;
    std::cin >> n;
    for (size_t i = 1; i < n + 1; ++i) {
        for (size_t j = 1; j < n + 1; ++j) {
            std::cin >> lab.room[i][j];
        }
    }
    size_t x = 0, y = 0;
    std::cin >> x >> y;
    lab.fun(x, y);
    std::cout << lab.S;
    return 0;
}