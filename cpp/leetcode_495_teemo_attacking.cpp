class Solution {
public:
    int findPoisonedDuration(vector<int>& t, int d) {
        int cnt=0;
        for(size_t i=1;i<t.size();++i){
            if((t[i-1]+d)<=t[i]) cnt+=d;
            else cnt+=t[i]-t[i-1];
        }
        cnt+=d;
        return cnt;
    }
};