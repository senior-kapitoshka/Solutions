class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        std::unordered_map<int,int>mp;
        for(int i=0;i<n.size();++i){
            int r=t-n[i];
            if(mp.count(r)){
                return {mp[r],i};
            }
            mp[n[i]]=i;
        }
        return {};
    }
};

//////////////////
class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        for(int i=0;i<n.size();++i){
            for(int j=i+1;j<n.size();++j){
                if(n[i]+n[j]==t){
                    return {i,j};
                }
            }
        }
        return {};
    }
};