#include <string>

std::string createPhoneNumber(const int arr [10]){
  std::string ans="              ";
  ans[0]='(';
  ans[4]=')';
  ans[5]=' ';
  for(int i=0;i<10;++i){
    if(i<3) ans[i+1]=(arr[i])+'0';
    else if(i>=3 && i<=6) ans[i+3]=(arr[i])+'0';
    ans[9]='-';
    if(i>=6) ans[i+4]=(arr[i])+'0';
  }
  return ans;
}
////////////////////////////////
#include <string>

std::string createPhoneNumber(const int arr [10]){
  char buf[15];
  snprintf(buf, sizeof(buf), "(%d%d%d) %d%d%d-%d%d%d%d%d", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9]);
  return buf;
}
/////////////////////////
#include <string>

std::string createPhoneNumber(const int digits[10]) {
  std::string res = "(...) ...-....";
  for (unsigned is = 0, id = 0; is < res.length(); is++)
    if (res[is] == '.')
      res[is] = '0' + digits[id++];
  return res;
}
/////////////////////////////////////
#include <string>
#include <sstream>
#include <iomanip>

std::string createPhoneNumber(const int arr [10])
{
  std::stringstream ss;
  
  ss
    << "(" << arr[0] << arr[1] << arr[2] << ") "
    << arr[3] << arr[4] << arr[5] << "-"
    << arr[6] << arr[7] << arr[8] << arr[9];
  
  
  return ss.str();
}
///////