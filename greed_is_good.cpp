#include <vector>
#include <map>

int score(const std::vector<int>& dc) {
  std::map<int,int>mp;
  for(auto i:dc){
    ++mp[i];
  }
  int res=0;
  for(int i=1;i<=6;++i){
    if(i==1 && mp.count(i)){
      res+=mp[i]<3?(mp[i]*100):mp[i]==3?1000:mp[i]==4?1100:1200;
    }else if(i==5 && mp.count(i)){
      res+=mp[i]<3?(mp[i]*50):mp[i]==3?500:mp[i]==4?550:600;
    }else{
      res+=mp[i]>=3?(i*100):0;
    }
  }
  return res; // your code here
}

//////////////
#include <vector>

int score(const std::vector<int>& dice) {
    int val[6] {0}; int res=0;
    for (int i=0; i<5; ++i) ++val[dice[i]-1];
    for (int i=0; i<6; ++i) res+= ((val[i]>=3)*(((i!=0 && i!=4)*((i+1)*100))+((i==0)*(1000+(val[i]-3)*100))+((i==4)*(500+(val[i]-3)*50))))+((val[i]<3)*(((i==0)*100+(i==4)*50)*val[i]));
    return res;
}
////////////
