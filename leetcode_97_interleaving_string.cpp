// 102 / 106
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        size_t k=0,l=0;
        for(size_t i=0;i<s3.size();++i){
            if(k!=s1.size() && l!=s2.size()){
                if(s3[i]==s1[k] && s3[i]!=s2[l]){
                    ++k;
                }else if(s3[i]==s2[l] && s3[i]!=s1[k]){
                    ++l;
                }else if(s3[i]==s2[l] && s3[i]==s1[k]){
                    size_t x=i;
                    size_t y=l;
                    size_t z=k;
                    while(s3[x]==s2[y] && s3[x]==s1[z]){
                        if(x==s3.size() || y==s2.size() || z==s1.size()){
                            return false;
                        }
                        ++x;++y;++z;
                    }
                    if(s3[x]==s2[y]){
                        ++l;
                    }else{
                        ++k;
                    }
                }
            }else if(k==s1.size() && l!=s2.size()){
                if(s3[i]==s2[l]){
                    ++l;
                }
            }else if(l==s2.size() && k!=s1.size()){
                if(s3[i]==s1[k]){
                    ++k;
                }
            }else return false;
        }
        return k==s1.size() && l==s2.size();
    }
};

///////////////////
class Solution {
public:
   int rec(int i1,int i2,int i3,string &s1,string &s2,string &s3,int n1,int n2,int n3,vector<vector<vector<int>>>&dp)
   {
       if (i1==n1 && i2==n2 && i3==n3)
       return 1;
       if (i3==n3) return 0;
       if (dp[i1][i2][i3]!=-1) return dp[i1][i2][i3];
       int a=0;
       if(i1<n1 && s3[i3]==s1[i1])
       a=rec(i1+1,i2,i3+1,s1,s2,s3,n1,n2,n3,dp);
       int b=0;
        if(i2<n2 && s3[i3]==s2[i2])
       b=rec(i1,i2+1,i3+1,s1,s2,s3,n1,n2,n3,dp);
       return dp[i1][i2][i3]=a||b;
   }
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size(),n2=s2.size(),n3=s3.size();
        vector<vector<vector<int>>>dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,-1)));
        return rec(0,0,0,s1,s2,s3,n1,n2,n3,dp);
    }
};