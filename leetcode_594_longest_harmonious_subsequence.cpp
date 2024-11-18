class Solution {
public:
    int findLHS(vector<int>& n) {
        std::map<int,int>mp;
        for(auto i:n){
            ++mp[i];
        }
        std::vector<std::pair<int,int>>vc(mp.begin(),mp.end());
        int mx=0;
        if(vc.size()==1) return mx;
        for(size_t i=1;i<vc.size();++i){
            if((vc[i].first-vc[i-1].first)==1){
                mx=std::max(mx,(vc[i-1].second+vc[i].second));
            }
        }
        return mx;
    }
};

////////////////////
class Solution {
public:
    int findLHS(vector<int>& nums) {
        const int n = nums.size();
        if (n < 2) {
            return 0;
        }

        sort(std::execution::par_unseq, nums.begin(), nums.end());
        int result = 0;
        for (int right = 0, left = 0; right < n; ){
            if (nums[right] - nums[left] > 1) {
                ++left;
            } else {
                if (nums[right] - nums[left] == 1)  {
                    result = max(result, right - left + 1);
                }
                ++right;
            }
        }

        return result;
    }
};

///////////////////////
class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        for(auto i : nums) mp[i]++;
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            if(mp[nums[i]+1]){
                ans = max(ans,mp[nums[i]] + mp[nums[i]+1]);
            }
        }
        return ans;
    }
};