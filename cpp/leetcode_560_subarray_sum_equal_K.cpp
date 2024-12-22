class Solution {
public:
    int subarraySum(vector<int>& n, int k) {
        std::unordered_map<int,int>mp;
        int cnt=0;
        int s=0;
        mp[s]=1;
        for(auto i:n){
            s+=i;
            int find=s-k;
            if(mp.count(find)){
                cnt+=mp[find];
            }
            ++mp[s];
        }
        return cnt;
    }
};