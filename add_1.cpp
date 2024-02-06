#include <string>
#include <cctype>

std::string incrementString(const std::string &str)
{
  std::string ans=str;
  if(isdigit(ans[0]) && isdigit(ans[ans.size()-1])){
      int t=stoi(ans);
      t+=1;
      std::string ans1=std::to_string(t);
    if(ans1.size()<ans.size()){
          while(ans1.size()!=ans.size()){
              ans1.insert(0,1,'0');
          }
      }
      return ans1;
    }else if(!isdigit(ans[ans.size()-1])){
        ans+="1";
        return ans;
    }
      
  else{
  for(size_t i=ans.size()-1;i>0;--i){
    if(isdigit(ans[i])){
      if(ans[i]!='9') {
        ans[i]+=1;
        break;
      }else if(isdigit(ans[i]) && !isdigit(ans[i-1])){
        ans[i]='1';
        ans+="0";
        break;
      }
      else{
          ans[i]='0';
      }
    }
  }
      
  }
  return ans;
}


string incrementString(const string& str) {
  
  string s = str;
  
  if (s.empty() || !isdigit(s.back()))
    return s + "1";
  
  for (int i = s.size() - 1; i >= 0; i--) {
    char& c = s[i];
    if (isdigit(c)) {
      if (c < '9') {
        c++;
        return s;
      } else {
        c = '0';
        continue;
      }
    } else {
      s.insert(i+1, "1");
      return s;
    }
  }
      
  return s;
}