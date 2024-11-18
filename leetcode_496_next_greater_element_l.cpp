class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& n1, vector<int>& n2) {
        std::unordered_map<int,int>mp;
        std::vector<int>st;
        for(int i=n2.size()-1;i>=0;--i){
            while(!st.empty() && st.back()<=n2[i]) st.pop_back();
            if(!st.empty()) mp[n2[i]]=st.back();
            else mp[n2[i]]=-1;
            st.push_back(n2[i]);
        }
        std::vector<int>res;
        std::transform(n1.begin(),n1.end(),
        std::back_inserter(res),[&mp](auto i){
            return mp[i];
        });
        return res;
    }
};