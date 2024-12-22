class Solution {
public:

    int maxScore(vector<int>& cp, int k) {
        if(cp.size()==k) 
            return std::accumulate(cp.begin(),cp.end(),0);
        if(k==1) return std::max(cp.front(),cp.back());    
        int sum= std::accumulate(cp.begin(),cp.begin()+k,0);
        int mx=sum;
        for(int i=0;i<k;++i){
            mx=mx-cp[k-1-i]+cp[cp.size()-1-i];
            sum=std::max(sum,mx);
        }
        return sum;
    }
};   

///////////////////
class Solution {
public:
    int maxScore(vector<int>& cardpoints, int k) {
        int totalsum = 0;
        for(int i=0;i<cardpoints.size();i++){
            totalsum +=cardpoints[i];
        }
        int windowsize=0;
        for(int i=0;i<cardpoints.size()-k;i++){
            windowsize +=cardpoints[i];
        }
        
        int n = cardpoints.size();
        int left = 0;
        int right = n-k;
        int ans = 0;
        ans = max(ans, totalsum-windowsize);
        while(right<n){
            windowsize -= cardpoints[left];
            left++;
            windowsize += cardpoints[right]; 
            right++; 
            ans = max(ans, totalsum-windowsize);
        }
        return ans;
    }
};