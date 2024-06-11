
#include <vector>
unsigned long long countChange(const unsigned int money, const std::vector<unsigned int>& coins) {
    std::vector<unsigned long long> v(money + 1, 0);
    v[0] = 1;
    
    for (auto &c : coins) {
        for (int i = 0; i <= (int)money; ++i) {
            if ((int)c <= i) {
                v[i] += v[i - c];
            }
        }
    } 
    return v[money];
}
/////////////////////////////

#include <vector>

unsigned long long check(int n,const std::vector<unsigned int>& v,int s,std::vector<std::vector<unsigned long long>>& dp){
  if(s==0) return dp[n][s]=1;
  if(s<0||n==0) return 0;
  if(dp[n][s]!=-1) return dp[n][s];
  return dp[n][s]=check(n,v,s-v[n-1],dp)+check(n-1,v,s,dp);
}

unsigned long long countChange(const unsigned int money, const std::vector<unsigned int>& coins) {
  std::vector<std::vector<unsigned long long>> dp(coins.size()+1,std::vector<unsigned long long>(money+1,-1));
  return check(coins.size(),coins,money,dp);
}