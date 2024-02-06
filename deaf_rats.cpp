#include <utility>
#include <vector>
#include <iostream>

int pars(std::string &t){
  int cnt=0;
  while(true){
    size_t p=t.find_first_of('O');
    if(p==std::string::npos) break;
    if(p!=0 && t[p-1]=='~'){
        size_t x= t.find_first_of('P');
        if(x==std::string::npos) ++cnt;
        else if(x!=std::string::npos && p>x) ++cnt;
      t.erase(0,p+1);
    }else if(p==0 && t[p+1]=='~'){
      size_t x= t.find_first_of('P');
        if(x!=std::string::npos) ++cnt;
      t.erase(0,p+2);
    }else if(p!=0 && t[p+1]=='~'){
        size_t x= t.find_first_of('P');
        if(x!=std::string::npos && p<x) ++cnt;
      t.erase(0,p+2);
    }
  }
  return cnt;
}


int countDeafRats(const std::string &t)
{
    std::string c=t;
  return pars(c);
}

///////////////////////////////
int countDeafRats(const std::string &town)
{
    int count = 0;
    int i = 0;
    while (town[i] != 'P') {
      switch (town[i]){
        case 'O': count++;
        case '~': i++;
        default : i++;
      }
    }
    i++;
    while (i < town.size()) {
      switch (town[i]){
        case '~': count++;
        case 'O': i++;
        default : i++;
      }
    }
    return count;
}
///////////////////////
int countDeafRats(const std::string &town)
{
    std::string clean{town};
    clean.erase(remove_if(clean.begin(), clean.end(), isspace), clean.end()); // erase whitespace
    int res = 0;
    
    // No matter where the flute, O must always appear on odd positions
    // If not, the rat is facing the wrong way.
    for(int i = 1; i< clean.length(); i+=2) { 
        if(clean[i] != 'O') { res ++; }
    }
    return res;
}