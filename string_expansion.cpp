#include <vector>
#include <utility>

std::string h(std::string s,int i){
  std::string r;
  if(i==0) return s;
  while(i!=0){
    r.insert(0,s);
    --i;
  }
  return r;
}

std::string solve(std::string s){
    s.erase(s.find_first_of(')'));
    std::vector<std::pair<int,std::string>> vp;
  while(s.find_last_of('(')!=s.npos){
    std::string l=s.substr(s.find_last_of('(')+1);
    std::string i;
    int j=1;
    if(isdigit(s[s.find_last_of('(')-j])){
        while(isdigit(s[s.find_last_of('(')-j])){
         i.insert(0,1,s[s.find_last_of('(')-j]);
            ++j;
        }
        s.erase(s.find_last_of('(')-j+1);
    }else{
        i="0";
        s.erase(s.find_last_of('('));
    }
    vp.push_back({std::stoi(i),l});
    }
  if(vp.size()==1) return h(vp[0].second,vp[0].first);
  for(size_t i=1;i<vp.size();++i){
    vp[i].second+=h(vp[i-1].second,vp[i-1].first);
  }
  return s+h(vp.back().second,vp.back().first);
}
/////////////////////
#include <string>
#include <algorithm>

std::string solve(std::string s){
    std::string a(s.rbegin(), s.rend()), b, c;   // reverse the input string to access characters in reverse.
    for (char ch : a){                           // start iteration. 
        if (isalpha(ch)) b += ch;                // Is char a letter? Add it to string b. 
        else if (isdigit(ch)){                   // Is char a digit string?
            int i = ch - '0' - 1;                // convert the char to number - 1. It's one less (-1) because 'b' already holds one copy. 
            c = b;                               // copy current string. Try and see that b += b in the while loop below fails.   
            while (i--) b += c;                  // concatenate a repeat of the string i times.               
        }
    }
    return std::string (b.rbegin(), b.rend());   // reverse string and return.
}
//////////////////////////////////
using namespace std ;
string solve(string str)
{
	string newStr = ""; string RepitingPart = ""; 
	int i = str.length();  int j = 0;
	while  (--i >= 0 )
	{
		if ((!isdigit(str[i])) && ( str[i] != '(' )&& (str[i] != ')')) newStr += str[i];
		if (isdigit(str[i]))	{	RepitingPart = newStr; while (++j < str[i] - 48) newStr += RepitingPart; j = 0;}
	}
	reverse(newStr.begin(), newStr.end());
	return newStr; 
}