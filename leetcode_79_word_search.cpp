//73 of 87

class Solution {
public:
    bool check(const vector<vector<char>>& bd,int i,int j,std::string wd){
        std::array<int,4>x={-1,0,1,0};
        std::array<int,4>y={0,1,0,-1};
        std::queue<std::tuple<int,int,int>>q;
        std::vector<int>d(wd.size(),-1);
        d.front()=1;
        int m=0;
        q.push({i,j,m});
        std::set<std::pair<int,int>>vis;
        vis.insert({i,j});
        while(!q.empty()){
            auto [k,l,v]=q.front();
            std::cout<<"front:"<<bd[k][l]<<k<<"-"<<l<<"-"<<v<<"\n";
            q.pop();
            for(int a=0;a<4;++a){
                int h=k+x[a];
                int g=l+y[a];
                int e=v+1;
                if(h>=0 && h<bd.size() && g>=0 && g<bd[0].size() && bd[h][g]==wd[e] && !vis.count({h,g})){
                    std::cout<<"to push:"<<bd[h][g]<<h<<"-"<<g<<"-"<<e<<"\n";
                    q.push({h,g,e});
                    d[e]=1;
                    vis.insert({h,g});
                    for(auto c:d)std::cout<<c<<",";
                    std::cout<<"\n";
                }
            }
        }
        for(auto c:d)std::cout<<c<<",";
                    std::cout<<"\n";
        return std::all_of(d.begin(),d.end(),[](auto& p){
            return p==1;
        });
    }

    bool exist(vector<vector<char>>& bd, string wd) {
        for(int i=0;i<bd.size();++i){
            for(int j=0;j<bd[0].size();++j){
                if(bd[i][j]==wd.front() && check(bd,i,j,wd)){
                    return true;
                }
            }
        }
        return false;
    }
};

////////////////////
class Solution {
public:
    bool check(const vector<vector<char>>& bd,int& i,int& j,int& cnt,const std::string& wd,
    std::vector<std::vector<int>>&vb){
        if(cnt==wd.size()) return true;
        if(i<0 || i>=bd.size() || j<0 || j>=bd[0].size() || vb[i][j]==1 || bd[i][j]!=wd[cnt]) 
            return false;
        vb[i][j]=1;

        int c=cnt+1;
        int q=i+1;
        int w=i-1;
        int e=j+1;
        int r=j-1;
        bool res=check(bd,q,j,c,wd,vb)||
        check(bd,i,e,c,wd,vb)||
        check(bd,w,j,c,wd,vb)||
        check(bd,i,r,c,wd,vb) ;
        vb[i][j]=0;
        return res;
    }

    bool exist(vector<vector<char>>& bd, string wd) {
        int cnt=0;
        std::vector<std::vector<int>>vb(bd.size(),std::vector<int>(bd[0].size(),0));
        for(int i=0;i<bd.size();++i){
            for(int j=0;j<bd[0].size();++j){
                if(bd[i][j]==wd.front() && check(bd,i,j,cnt,wd,vb)){
                    return true;
                }
            }
        }
        return false;
    }
};

//////////////////
class Solution {
public:
    int index(int i, int j, int m) {
        return i * m + j;
    }
    bool busy(uint64_t mask, int i, int j, int m) {
        int idx = index(i, j, m);
        return (mask & (1ULL << idx)) > 0;
    }
    uint64_t set_bit(uint64_t mask, int i, int j, int m) {
        int idx = index(i, j, m);
        return mask | (1ULL << idx);
    }
    void check(queue<pair<int, uint64_t>>& q, const vector<vector<char>>& board, const string& word, int idx, int i, int j) {
        int n = board.size();
        int m = board[0].size();
        auto p = q.front();
        uint64_t mask = p.second;
        bool inside = i >= 0 && i < n && j >= 0 && j < m;
        if (inside && !busy(mask, i, j, m) && board[i][j] == word[idx]) {
            int new_idx = index(i, j, m);
            uint64_t new_mask = set_bit(mask, i, j, m);
            q.push(make_pair(new_idx, new_mask));
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int L = word.size();
        queue<pair<int, uint64_t>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == word[0]) {
                    int idx = index(i, j, m);
                    q.push(make_pair(idx, 1ULL << idx));
                }
            }
        }
        while (!q.empty()) {
            auto p = q.front();
            uint64_t mask = p.second;
            int bits = __popcount(mask);
            if (bits == L) {
                return true;
            }
            int i = p.first / m;
            int j = p.first % m;
            check(q, board, word, bits, i - 1, j);
            check(q, board, word, bits, i + 1, j);
            check(q, board, word, bits, i, j + 1);
            check(q, board, word, bits, i, j - 1);
            q.pop();
        }
        return false;
    }
};