#include <algorithm>
std::vector<std::string> splitMessage(std::string mg, int cnt)
{
    std::vector<std::string>vss(0);
    if(cnt<0) return vss;
    std::vector<std::string>vs(cnt);
    if(mg.empty()) return vs;
    std::string s(mg.begin(),mg.end());
    std::fill(s.begin(),s.end(),'-');
    std::fill(vs.begin(),vs.end(),s);
    int i=0;
    int m=0;
    while(i!=cnt){
      for_each(vs.begin(),vs.end(),[&i,mg,&m,cnt](auto& s){
        for(int j=i;j<(int)mg.size();j+=m*cnt){
          s[j]=mg[j];
          ++m;
          j=i;
        }
        ++i;
        m=0;
      });
    }
    return vs;
}
////////////////////////////////////
std::vector<std::string> splitMessage(std::string message, int count)
{
    if(count <= 0) return {};
    std::vector<std::string> result(count, std::string(message.length(), '-'));
    
    for(int i = 0; i < message.length(); ++i)
      result[i % count][i] = message[i];
    
    return result;
}
///////////////////////////////
std::vector<std::string> splitMessage(std::string message, int count)
{
    std::vector<std::string> result;
    result.insert(result.begin(), count, std::string(message.length(),'-'));
    
    int index = 0;
    for (unsigned i = 0; i < message.length(); ++i)
      {
      result[index][i] = message[i];
      index = (index + 1) % count;
      }
    
    return result;
}
///////////////////////
