#include <utility>
#include <iostream>
template<typename S>
void shift(S&& s,std::string& ns){
  size_t j=0;
  for(size_t i=0;i<std::forward<S>(s).size();++i){
    if(i%2==0){
      ns+=std::forward<S>(s)[i];
    }else if(i%2!=0){
      ns.insert(j,1,std::forward<S>(s)[i]);
      ++j;
    }
  }
}

template<typename S>
void enshift(S&& s,std::string& ns){
  ns=std::forward<S>(s).substr(std::forward<S>(s).size()/2);
  size_t j=1;
  for(size_t i=0;i<std::forward<S>(s).size()/2;++i){
    ns.insert(j,1,std::forward<S>(s)[i]);
    j+=2;
  }
}

std::string encrypt(std::string text, int n)
{
  if(n<=0) return text;
  if(text.empty()) return "";
  std::string t=text;
  std::string s;
    while(n!=0){
      s.clear();
      shift(t,s);
      t=s;
      --n;
    }
  
  return t;
}

std::string decrypt(std::string text, int n)
{
    if(n<=0) return text;
  if(text.empty()) return "";
    std::string t=text;
  std::string s;
  while(n!=0){
      s.clear();
      enshift(t,s);
      t=s;
      --n;
    }
  
  return t;
}

//////////////////////////////

#include <iostream>
#include <iterator>
#include <string>
#include <numeric>
#include <algorithm>

bool isInvalid(std::string text, int n){
    if(text.empty()) return true;
    if(n <= 0) return true;
}

std::string encrypt(std::string text, int n)
{   
    for(int i = 0; i<n; i++){
      std::string evenChars;
      std::string oddChars;
      auto counter {1};
      std::for_each(text.begin(), text.end(), 
                    [&counter,&evenChars,&oddChars](auto a){
                    return (counter++)%2 ? oddChars.push_back(a) : evenChars.push_back(a);
                    });
      text = evenChars + oddChars;
    }
    
    return text;
}

std::string decrypt(std::string text, int n)
{
    for(int i = 0; i<n; i++){
      std::string firstHalf {text.substr(0,text.size()/2)};
      std::string secondHalf {text.substr(text.size()/2)};
      std::string decodedText;
      
      for(int i = 0; i<firstHalf.length(); i++){
          decodedText.push_back(secondHalf.at(i));
          decodedText.push_back(firstHalf.at(i));
      }      
      if(text.size()%2) decodedText.push_back(secondHalf.back());
      text = decodedText;
    }    
    
    return text;
}