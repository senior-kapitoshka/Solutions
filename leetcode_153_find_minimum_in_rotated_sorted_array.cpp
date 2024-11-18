class Solution {
public:
    int findMin(vector<int>& n) {
        if(n.size()==1) return n[0];
        int l=0;
        int r=n.size()-1;
        if(n[l]<n[r]) return n[l];
        while(l<=r){
            int m=l+(r-l)/2;
            if((m==0 ||n[m]<n[m-1] ) && (m==n.size()-1 || n[m]< n[m+1])){
                return n[m];
            }else if(n[m]<n[r]){
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return -1;
    }
};