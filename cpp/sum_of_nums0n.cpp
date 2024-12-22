#include <algorithm>
#include <numeric>
using namespace std;

class SequenceSum{
  int count;
  public:
  SequenceSum (int);
  string showSequence();
  
};

string SequenceSum::showSequence(){
  if(count==0) return "0=0";
  if(count<0) return to_string(count)+"<0";
  vector<int>vc(count+1);
  iota(vc.begin(),vc.end(),0);
  int s=accumulate(vc.begin(),vc.end(),0);
  auto pl=[](string a,int b){return move(a)+'+'+to_string(b);};
  string res=accumulate(next(vc.begin()),vc.end(),to_string(vc[0]),pl);
  res+=" = "+to_string(s);
  return res;
}

SequenceSum::SequenceSum (int c) {
  count = c;
}

/////////////////////////////
string SequenceSum::showSequence(){
    if (count < 0) return to_string(count) + "<0";
    if (!count) return "0=0";
    stringstream ss; ss << 0;
    for (int i = 1; i <= count; ++i)
      ss << '+' << i;
    ss << " = " << count * (count+1) / 2;
    return ss.str();
}