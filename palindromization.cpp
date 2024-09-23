#include <string>
#include <deque>

std::string Palindromization(std::string el, int n){
  if(el.empty() || n<=1) return "Error!";
  std::string res;
  if(n%2==0){
    int x=n/2;
    std::string s;
    for(size_t i=0;x>0;++i,--x){
      s+=el[i%el.size()];
    }
    std::string t(s.rbegin(),s.rend());
    res=s+t;
  }else{
    int x=n/2+1;
    std::string s;
    for(size_t i=0;x>0;++i,--x){
      s+=el[i%el.size()];
    }
    std::string t(next(s.rbegin()),s.rend());
    res=s+t;
  }
  return res;
}

////////////////////////
#include <string>

std::string Palindromization(const std::string& elements, int n) {
  if (elements.empty() || n < 2) return "Error!";
  std::string palindrome(n, 0);
  for (int i = 0, j = n - 1; i <= j; ++i, --j) {
    char c = elements[i % elements.length()];
    palindrome[i] = c;
    palindrome[j] = c;
  }
  return palindrome;
}

////////////////////
std::string Palindromization(std::string elements, int n) {
  int m = elements.length();
  if (m == 0 || n < 2) return "Error!";
  std::string result(n, ' ');
  for (int i=0; i<(n+1)/2; ++i) result[i] = result[n-i-1] = elements[i%m];
  return result;
}

/////////////////////
#include <string>

using namespace std;

string Palindromization(string elements, int n){
  if(elements.empty() || n<2) {
    return "Error!";
  }
  string out="";
  for(int i=0; i<(n+1)/2; i++) {
    out+=elements[i%elements.length()];
  }
  for(int i=out.length()-1-n%2; i>=0; i--) {
    out+=out[i];
  }
  return out;
}

//////////////////
