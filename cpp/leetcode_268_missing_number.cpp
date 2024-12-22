class Solution {
public:
    int missingNumber(vector<int>& n) {
        return std::accumulate(n.begin(),n.end(),0,
        [i=0](auto sum,auto curr)mutable{
            return sum+=1+(i++)-curr;
        });
    }
};