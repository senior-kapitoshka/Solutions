#include <string>

class RomanHelper{
  public:
    std::string to_roman(unsigned int n){
      std::map<int,char>mp={{1,'I'},
      {5,'V'},
      {10,'X'},
      {50,'L'},
      {100,'C'},
      {500,'D'},
      {1000,'M'}};
      std::string s=std::to_string(n);
      size_t sz=s.size();
      std::string res="";
      for(size_t i=0;i<s.size();++i){
        if(sz==4){
          res+=std::string(s[i]-'0',mp[1000]);
        }else if(sz==3){
          if(s[i]-'0'<4){
            res+=std::string(s[i]-'0',mp[100]);
          }else if(s[i]-'0'==4){
            res+=mp[100];
            res+=mp[500];
          }else if(s[i]-'0'==5){
            res+=mp[500];
        }else if(s[i]-'0'>5 && s[i]-'0'<9){
            res+=mp[500];
            res+=std::string((s[i]-'0')-5,mp[100]);
          }else if(s[i]-'0'==9){
            res+=mp[100];
            res+=mp[1000];
          }else if(s[i]-'0'==0) continue;
        }else if(sz==2){
          if(s[i]-'0'<4){
            res+=std::string(s[i]-'0',mp[10]);
          }else if(s[i]-'0'==4){
            res+=mp[10];
            res+=mp[50];
          }else if(s[i]-'0'==5){
            res+=mp[50];  
          }else if(s[i]-'0'>5 && s[i]-'0'<9){
            res+=mp[50];
            res+=std::string((s[i]-'0')-5,mp[10]);
          }else if(s[i]-'0'==9){
            res+=mp[10];
            res+=mp[100];
          }else if(s[i]-'0'==0) continue;
        }else if(sz==1){
          if(s[i]-'0'<4){
            res+=std::string(s[i]-'0',mp[1]);
          }else if(s[i]-'0'==4){
            res+=mp[1];
            res+=mp[5];
           }else if(s[i]-'0'==5){
            res+=mp[5];
          }else if(s[i]-'0'>5 && s[i]-'0'<9){
            res+=mp[5];
            res+=std::string((s[i]-'0')-5,mp[1]);
          }else if(s[i]-'0'==9){
            res+=mp[1];
            res+=mp[10];
          }else if(s[i]-'0'==0) continue;
        }
        --sz; 
      }
      return res;
    }
    int from_roman(std::string rn){
      std::map<char,int>mp={{'I',1},
      {'V',5},
      {'X',10},
      {'L',50},
      {'C',100},
      {'D',500},
      {'M',1000}};
        int res=mp[rn.front()];
        for(size_t i=1;i<rn.size();++i){
          if(mp[rn[i-1]]>=mp[rn[i]])
            res+=mp[rn[i]];
          else{
            res=mp[rn[i]]-mp[rn[i-1]]>res?mp[rn[i]]-mp[rn[i-1]]:
            res+(mp[rn[i]]-mp[rn[i-1]]*2);
          }
        }
        return res;
  }
} RomanNumerals;

//////////////////////////////////
#include <unordered_map>

using namespace std;

class RNHelper {
public:
    string to_roman(int num) {
        string r[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int n[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string rnum = "";
        for (int i = 0 ; i < 13; ++i) {
            while (num >= n[i]) {
                num -= n[i];
                rnum += r[i];
            }
        }
        return rnum;
    }
    
    int from_roman(string rnum) {
        unordered_map<char, int> ri = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int n = rnum.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            if (i + 1 < n && ri[rnum[i]] < ri[rnum[i+1]])
                res -= ri[rnum[i]];
            else res += ri[rnum[i]];
        }
        return res;
    }
};

RNHelper RomanNumerals;

///////////////////
#include <string>

using namespace std;

class RomanHelper{
  private:
    const vector<pair<unsigned int, string>> dict {
      {1000,  "M"},
      {900,   "CM"},
      {500,   "D"},
      {400,   "CD"},
      {100,   "C"},
      {90,    "XC"},
      {50,    "L"},
      {40,    "XL"},
      {10,    "X"},
      {9,     "IX"},
      {5,     "V"},
      {4,     "IV"},
      {1,     "I"},
    };
  public:
  
    string to_roman(unsigned int n){
      string r = "";        
      while (n != 0)
        for (auto p : dict)
          for (; n >= p.first; r += p.second, n -= p.first);
      return r;
    }
  
    int from_roman(string rn){
      int r = 0;
      while (rn != "")
        for (auto p : dict)
          for (; rn.length() > 0 && search(rn.begin(), rn.end(), p.second.begin(), p.second.end()) == rn.begin()
               ; r += p.first, rn = rn.substr(p.second.length()));
      return r;
    }
  
} RomanNumerals;

//////////////////
#include <map>

struct RomanNumerals {
    std::string to_roman(unsigned num);
    unsigned from_roman(std::string num);
} RomanNumerals;

std::string RomanNumerals::to_roman(unsigned num){
    std::string res;
    std::map<unsigned, std::string, std::greater<unsigned>> mp{
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},{100, "C"}, {90, "XC"},
        {50, "L"},{40, "XL"},{10, "X"},{9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
    std::for_each(mp.begin(), mp.end(), [&](const auto& it){
                      for(unsigned i{0}; i < num/it.first; res += it.second, ++i);
                      num %= it.first;
                  });
    return res;
}

unsigned RomanNumerals::from_roman(std::string num){
    unsigned res{0};
    std::map<char, unsigned> mp{{'M', 1000}, {'D', 500},{'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
    for(std::string::size_type i{0}; i < num.size() - 1; ++i)
        res += (mp[num[i]] >= mp[num[i+1]] ? mp[num[i]] : -mp[num[i]]);
    res += mp[num[num.size() - 1]];
    return res;
}

////////////////////
#include <string>
#include <map>

class RomanHelper{
  public:
    std::string to_roman(unsigned int n);
    int from_roman(std::string rn);
} RomanNumerals;
//-------------------------------------------
std::string RomanHelper::to_roman(unsigned int n){
  const std::vector<std::vector<std::string>> t
  {{"","M","MM","MMM",""  , "",  "",   "",    "",  ""},
   {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
   {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
   {"","I","II","III","IV","V","VI","VII","VIII","IX"}};
  
  return t[0][n/1000]+t[1][n%1000/100]+t[2][n%100/10]+t[3][n%10];
}
//--------------------------------------------
int RomanHelper::from_roman(std::string rn){
  std::map<char, int> t={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
  int res = 0;
  
  for (size_t i = 0; i < rn.size()-1; i++){   
    if (t[rn[i]]<t[rn[i+1]]) res -= t[rn[i]];
    else res += t[rn[i]];  
  }
  
  return res+t[rn.back()];
}

//////////////////
#include <string>

const std::string numerals[][4] = {
//        0     10     100    1000  
        {""    , ""   , ""   , ""  },  // 0
        {"I"   ,"X"   ,"C"   ,"M"  },  // 1
        {"II"  ,"XX"  ,"CC"  ,"MM" },  // 2
        {"III" ,"XXX" ,"CCC" ,"MMM"},  // 3
        {"IV"  ,"XL"  ,"CD"  ,""   },  // 4
        {"V"   ,"L"   ,"D"   ,""   },  // 5
        {"VI"  ,"LX"  ,"DC"  ,""   },  // 6
        {"VII" ,"LXX" ,"DCC" ,""   },  // 7
        {"VIII","LXXX","DCCC",""   },  // 8
        {"IX"  ,"XC"  ,"CM"  ,""   }   // 9
};

class RomanHelper{
  public:
    std::string to_roman(unsigned int number) {
    // Returns a string containing the Roman Numeral representation of the integer.

      if (number >= 4000 || number <= 0) return "";

      std::string ret_roman = "";
      int i = number, dig = 0, razr = 0;
      while (i > 0) {
        dig = i%10;
        i /= 10;
        ret_roman = numerals[dig][razr] + ret_roman;
        if (razr < 3) razr++;
      }

      return ret_roman;
    }
  
  
  
    int from_roman(std::string rn){
    // Returns an integer number from the Roman Numeral rn.  
      
      int multiplier[] = {1, 10, 100, 1000};
      int ret_num = 0;
      
      int razr = 3;
      do {
        // search numerals in the string
        for (int i = 9; i > 0; i--) {
          std::string candidate = numerals[i][razr];
          if (candidate == "") continue;
          std::string to_compare = rn.substr(0, candidate.size());
          if (candidate == to_compare) {
            ret_num += i * multiplier[razr];
            rn.erase(0, candidate.size());
          }
        }
      } while (razr-->0);
 
      return ret_num;
    }
} RomanNumerals;

