class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::unordered_map<int,int>mp;
        nums.erase(std::remove_if(nums.begin(),nums.end(),[&mp](auto& i)
        {
            ++mp[i];
            return mp[i]>2;
        }),nums.end());
        return nums.size();
    }
};

//////////////////////
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 2;

        if (nums.size() <= 2) return nums.size();
        
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;       
    }
};