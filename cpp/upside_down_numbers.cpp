bool check(int x){
  std::string s=std::to_string(x);
  if(s.size()%2!=0 && (s[s.size()/2]!='1' && s[s.size()/2]!='8' && s[s.size()/2]!='0'))return false;
  int i=0,j=s.size()-1;
  while(i<j){
    if((s[i]=='6' && s[j]=='9') || (s[i]=='9' && s[j]=='6') || 
       (s[i]==s[j] && (s[i]=='1'|| s[i]=='8' || s[i]=='0'))){
      ++i;
      --j;
    }else return false;
  }
  return true;
}


int solve(int x, int y) {
  int cnt=0;
    for(int i=x;i<y;++i){
      if(check(i)){
        ++cnt;
      }
    }
  return cnt;
}

///////////////////////////
int solve(int x, int y) {
  auto is_upside_down = [] (auto z) {
    auto temp = 0;
    for (auto i = z; i != 0; i /= 10) {
      int last = i % 10;
      if (last == 2 || last == 3 || last == 4 || last == 5 || last == 7) return false;
      if      (last == 6) last = 9;
      else if (last == 9) last = 6;
      temp = 10 * temp + last;
    }
    return z == temp;
  };
  
  int count = 0;
  for (int i = x; i < y; i ++) if (is_upside_down(i)) count ++;
  return count;
}

/////////////////////////
int solve(int x, int y)
{
    int n = 0;
    while (x < y) {
        std::div_t k = { x };
        int z = 0;
        while (k.quot) {
            int d = (k = std::div(k.quot, 10)).rem;
            if (d == 6)
                d = 9;
            else if (d == 9)
                d = 6;
            else if (d != 1 && d != 8 && d)
                break;
            z = z * 10 + d;
        }
        if (z == x)  
            ++n;
        ++x;
    }
    return n;
}

/////////////////////
#include <unordered_map>
#include <string>

bool isUpsideDown(int n) {
    std::string s = std::to_string(n);
    std::string rev = std::string(s.rbegin(), s.rend()), res = "";
    std::unordered_map<char, char> hash = { { '0', '0' }, { '1', '1' }, { '8', '8' }, { '6', '9' }, { '9', '6' } };
    for (char ch : rev)        
        if (hash.find(ch) == hash.end()) 
            return false;
        else
            res += hash[ch];   
    return stoi(res) == n;
}

int solve(int x, int y) {
    int c = 0;
    for (int i = x; i < y; ++i)
        if (isUpsideDown(i))             
            c++;        
    return c;
}

/////////////////
