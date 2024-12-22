class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        std::unordered_map<int,int>mp;
        for(int i=0;i<n.size();++i){
            if(mp.count(t-n[i])){
                return {mp[t-n[i]],i+1};
            }
            mp[n[i]]=i+1;
        }
        return {-1,-1};
    }
};

////////////////////////
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans;
        int i=0;
        int j=numbers.size()-1;
        while(numbers[i]+numbers[j]!=target){
            if((numbers[i]+numbers[j])>target){
                j--;
            }
            else if((numbers[i]+numbers[j])<target){
                i++;
            }
        }
        ans.push_back(i+1);
        ans.push_back(j+1);
        return ans;
    }
};