class Solution {
public:
    int minOperations(vector<int>& n, int k) {
        std::vector<int>arr(k,0);
        int cnt=0;
        for(int i=n.size()-1;i>=0;--i){
            if(n[i]>k){
                ++cnt;
                 continue;
            }else{
                arr[n[i]-1]=1;
                ++cnt;
            }
            if(std::all_of(arr.begin(),arr.end(),[](auto j){return j==1;})) 
                break;
        }
        return cnt;
    }
};

//////////////
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> collection;
        int n=nums.size();
        while(collection.size()!=k){
            for(int i=1;i<=k;i++){
                if(nums.back()==i)
                    collection.insert(nums.back());
            }
            nums.pop_back();
        }
        return n-nums.size();
    }
};

////////////////
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> st;
        int result = 0;

        for(int i=nums.size()-1;i>=0;i--)
        {
            if(st.size() == k)
                break;
            else if(nums[i]<=k)
                st.insert(nums[i]);
            result++;
        }
        return result;
    }
};