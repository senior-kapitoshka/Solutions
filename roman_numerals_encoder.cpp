#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std::literals;
std::string vals="I1 V5 X10 L50 C100 D500 M1000"s;

void prepare(std::string& s,std::map<int,char>&mp,int n,std::vector<int>&vc){
  std::stringstream ss(s);
  for(std::string w;std::getline(ss,w,' ');){
    mp[std::stoi(w.substr(1))]=w[0];
  }
  std::string nr=std::to_string(n);
  std::for_each(nr.rbegin(),nr.rend(),[i=0,&vc](auto& c)mutable{
    if(i==0) {
      vc.push_back((int)(c-'0'));
      ++i;
    }
    else{      
      std::string t(i,'0');
      t.insert(0,1,c);
      vc.push_back(std::stoi(t));
      ++i;
    }
  });
  std::reverse(vc.begin(),vc.end());
}

std::string solution(int nr){
  std::cout<<nr<<"\n";
  std::map<int,char>mp;
  std::vector<int>vc;
  prepare(vals,mp,nr,vc);
  std::string res;
  std::for_each(vc.begin(),vc.end(),[&mp,&res](auto& i){
    if(mp.count(i)) res+=mp[i];
    else if(!mp.count(i) && std::to_string(i)[0]=='9'){
      if(i==9) res+="IX"; 
      else if(i==90) res+="XC";
      else if(i==900) res+="CM";
      
    }else if(!mp.count(i) && std::to_string(i)[0]=='4'){
      if(i==4) res+="IV";
      else if(i==400) res+="CD";
      else if(i==40) res+="XL";
      
  }else{
        int x=i;
        while(x>=0){
        if(mp.count(x)){
          res+=mp[x];
          x-=x;
        }else{
          if(mp.count(prev(mp.lower_bound(x))->first))res+=prev(mp.lower_bound(x))->second;
          x-=prev(mp.lower_bound(x))->first;
        }
         if(x<0) break;
      
      }
    }
    
  });
  std::cout<<"\n"<<res<<"\n";
  return res;
}
////////////////////
std::string solution(int number) {
		const std::map<int, std::string> bases = {
    		{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
		std::string rnum("");
    for (auto it = bases.crbegin(); it != bases.crend(); ) {
    		if (number >= it->first) {
        		number -= it->first;
            rnum += it->second;
        } else {
        		it++;
        }
    }
    
		return rnum;
}
/////////////////
