class Solution {
public:
    int pivotIndex(vector<int>& n) {
        std::vector<int>lf,rt;
        lf.reserve(n.size());
        rt.reserve(n.size());
        std::inclusive_scan(n.begin(),n.end(),
        std::back_inserter(lf));
        std::inclusive_scan(n.rbegin(),n.rend(),
        std::back_inserter(rt));
        std::reverse(rt.begin(),rt.end());
        for(int i=0;i<n.size();++i){
            if(lf[i]==rt[i]) return i;
        }
        return -1;
    }
};

//////////////////////
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int pre[nums.size() + 1];
        pre[0] = 0;
        for(int i = 0; i < nums.size(); ++i){
            pre[i + 1] = pre[i] + nums[i];
        }
        for(int i = 0; i < nums.size(); ++i){
            if((pre[i] + pre[i + 1] )== pre[nums.size()]) 
                return i;
        }
        return -1;
    }
};

////////////
