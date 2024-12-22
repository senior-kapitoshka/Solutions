class Solution {
public:
    void DFS(int i,int j,std::vector<std::vector<char>>&g){
        if(i<0 || i==g.size() || j<0 || j==g[0].size() || g[i][j]=='0') return;
        g[i][j]='0';
        DFS(i+1,j,g);
        DFS(i-1,j,g);
        DFS(i,j+1,g);
        DFS(i,j-1,g);
    }

    int numIslands(vector<vector<char>>& g) {
        int cnt=0;
        for(int i=0;i<g.size();++i){
            for(int j=0;j<g[0].size();++j){
                if(g[i][j]=='1'){
                    ++cnt;
                    DFS(i,j,g);
                }
            }
        }
        return cnt;
    }
};

/////////////////////