
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& is) {
        std::sort(is.begin(),is.end(),[](auto& lhs,auto&rhs){
            return lhs.front()<rhs.front();
        });
        std::vector<std::vector<int>>st;
        st.push_back(is.front());
        for(int i=1;i<is.size();++i){
            if(st.back().back()>=is[i].front()){
                int back=st.back().back()>is[i].back()?
                st.back().back():is[i].back();
                std::vector<int>t{st.back().front(),back};
                st.pop_back();
                st.push_back(t);
            }else{
                st.push_back(is[i]);
            }
        }
        return st;
    }
};

////////////////
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < n; ++i){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(ans.empty() || start > ans.back()[1]){
                ans.push_back(intervals[i]);
            }else{
                ans.back()[1] = max(ans.back()[1], end);
            }
        }
        return ans;
    }
};