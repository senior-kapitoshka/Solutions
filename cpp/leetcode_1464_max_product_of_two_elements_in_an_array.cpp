class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx1=0,mx2=0;
        for(auto i:nums){
            if(i>mx1){
                mx2=mx1;
                mx1=i;
            }else if(i>mx2){
                mx2=i;
            }
        }
        return (mx1-1)*(mx2-1);
    }
};