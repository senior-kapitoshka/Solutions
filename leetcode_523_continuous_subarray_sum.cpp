class Solution {
public:
    bool checkSubarraySum(vector<int>& n, int k) {
        int prev=0;
        int sum=0;
        if(k==0) return false;
        std::unordered_set<int>st;
        for(auto i:n){
            sum+=i;
            int mode = sum % k;
            if(st.count(mode)) return true;
            st.insert(prev);
            prev=mode;
        }
        return false;
    }

};