std::vector<std::string> wave(std::string y){
  if(y.empty())return {};
  std::vector<std::string> ans;
  for(size_t i=0;i<y.size();++i){
    if(isalpha(y[i])){
      std::string x=y;
    x[i]=toupper(x[i]);
    ans.push_back(x);
    }
  }
  return ans;
}
////////////////////////////////////////
using namespace std;
std::vector<std::string> wave(std::string x){
  vector <string> op;
  string temp=x;
  for(int i=0;i<x.length();i++)
  {
    if(x[i]==' ')continue;
    temp[i] = toupper(temp[i]);
    op.push_back(temp);
    temp=x;
  }
  return op;

}
//////////////////////////////////////
