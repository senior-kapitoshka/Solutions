#include <string>

using namespace std;


string rotate(const string& s , int n)
{
  int len = s.size();
  string res(len, '.');
  for(int i=0;i<len;i++)
  {
    res[((n+i)%len+len)%len] = s[i];
  }
  return res;
}



std::string encode(int n, std::string str)
{
  
  vector<int> res;
  
  for(int i=0;i<str.size();i++)
    if(str[i]==' ')
      res.push_back(i);
  
  string temp;
  int x;
  
  for(int i=0;i<n;i++)
  {
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    // 공백 제거
    temp = str.substr(str.size()-n);
    str = temp+str.substr(0, str.size()-n);
    // 2단계 완료
    
    for(auto s : res)
      str.insert(s, 1, ' ');
    
    
    x=0;
    for(auto s : res)
    {
      if(s<=x)
        continue;
      temp = str.substr(x, s-x);
      temp = rotate(temp, n);
      str.replace(x, s-x, temp);
      
      x = s+1;
      while(str[x]==' ')
        x++;
    }
       temp = str.substr(x, str.size()-x);
      temp = rotate(temp, n);
      str.replace(x, str.size()-x, temp);
    
  }
  
  
  
  
    return to_string(n)+" "+str;
}

std::string decode(std::string str)
{
  
    auto it = str.find(' ');
    int n = stoi(str.substr(0, it));
  
    vector<int> res;
  str = str.substr(it+1);
    for(int i=0;i<str.size();i++)
      if(str[i]==' ')
        res.push_back(i);
  
    string temp;
    int x;
  
  for(int i=0;i<n;i++)
  {
    x=0;
    for(auto s : res)
    {
      if(x>=s)
        continue;
      temp = str.substr(x, s-x);
      temp = rotate(temp, -n);
      str.replace(x, s-x, temp);
      
      x = s+1;
      while(str[x]==' ')
        x++;
    }
    
      temp = str.substr(x, str.size()-x);
      temp = rotate(temp, -n);
      str.replace(x, str.size()-x, temp);
    
    
      str.erase(remove(str.begin(), str.end(), ' '), str.end());
    
     temp = str.substr(0, n);
     str = str.substr(n)+temp;
    
     for(auto s : res)
       str.insert(s, 1, ' ');
    
    
    
    
    
    
    
    
    
  }
  
  
  
  return str;
  
  }

#if 0

#include <string>
#include <regex>
#include <vector>
#include <sstream>

void remove_ws(std::string& str, std::string& copy){
  std::regex w("[\\s]*");
 copy= std::regex_replace(str,w,"");
}

void shift(int n,std::string& str){
  std::string t=str;
      for(size_t i=0;i<str.size();++i){
      t[i]=str[((str.size()-n%str.size())+i%str.size())%str.size()];
    }
  
  std::swap(t,str);
}

void insert_ws(std::string& copy,std::string& str){
  std::transform(str.begin(),str.end(),str.begin(),[i=0,&copy](auto& c)
                 mutable{
    if(c==' ') return c;
    return copy[i++];
  });
}

void shift_substr(int n,std::string& str,std::string& copy){
  std::vector<std::string> vs;
  std::stringstream ss(str);
    for(std::string w;std::getline(ss,w,' ');){
      shift(n,w);
      copy+=w;
  }
}

std::string encode(int n, std::string str)
{
  int i=0;
  while(i<n){
    std::string copy;
    remove_ws(str,copy);
    shift(n,copy);
    insert_ws(copy,str);
    
    copy.clear();
    shift_substr(n,str,copy);
    insert_ws(copy,str);
    ++i;
    
  }
  str.insert(0,std::to_string(n)+" ");
    return str;
}

std::string decode(std::string str)
{
    return "";
}

#endif