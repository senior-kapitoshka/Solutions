class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::map<int,int>mp;
        for(auto i:s){
            ++mp[i];
        }
        int cnt=0;
        for(auto i:g){
            auto it=mp.lower_bound(i);
            if(it!=mp.end()){
                ++cnt;
                if(it->second--==1) mp.erase(it);
            }
        }
        return cnt;
    }
};

///////////////////////
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        int n = g.size();
        int m = s.size();
        sort(g.begin(),g.end(),greater<int>());
        sort(s.begin(),s.end(),greater<int>());
        int i = 0;
        int j = 0;
        while (i<n && j<m)
        {
            if(s[j] >= g[i] )
            {
                ans++;
                j++;
            }
            i++;
       }
       return ans;
    }
};