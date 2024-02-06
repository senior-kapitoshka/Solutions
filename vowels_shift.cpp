#include <execution>

void s(std::vector<std::pair<char,int>>&vp, int n){
    
    while(n){
        std::vector<std::pair<char,int>>b(vp.begin(),prev(vp.end()));
    b.insert(b.begin(),vp.back());
       
        for(size_t i=0;i<vp.size();++i){
           vp[i].first=b[i].first;
       }
        --n;
    }
}

std::string vowelShift(std::string t, int n)
{
  std::string v="aeiou";
  
  std::vector<std::pair<char,int>>vp;
  for(size_t i=0;i<t.size();++i){
    //if(find(std::execution::par,v.begin(),v.end(),t[i])!=v.end())
    if(t[i]=='a'||t[i]=='e'||t[i]=='i'||t[i]=='o'||
      t[i]=='u'){
      vp.push_back({std::move(t[i]),i});
    }
  }
  s(vp,n);
  for(auto i:vp){
    t[i.second]=i.first;
  }
  return t;
}
