class Solution {
public:
    char slowestKey(vector<int>& rs, string k) {
        std::pair<int,char>pr={rs.front(),k.front()};
        for(int i=1;i<rs.size();++i){
            int res=rs[i]-rs[i-1];
            if(res>pr.first){
                pr.second=k[i];
            }else if(res==pr.first){
                if(pr.second<k[i]) pr.second=k[i];
            }
            pr.first=std::max(res,pr.first);
        }
        return pr.second;
    }
};

////////////////