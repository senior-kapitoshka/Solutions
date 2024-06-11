#include <string>
using namespace std;

int content_weight(int bt, string s)
{
  if(s[s.find_last_of(' ')+1]=='s'){
    return (bt*std::stoi(s.substr(0,s.find_first_of(' ')))/(std::stoi(s.substr(0,s.find_first_of(' ')))+1))/std::stoi(s.substr(0,s.find_first_of(' ')));
  }else if(s[s.find_last_of(' ')+1]=='l'){
    return bt/(std::stoi(s.substr(0,s.find_first_of(' ')))+1)*std::stoi(s.substr(0,s.find_first_of(' ')));
  }
  return 0;
}

//////////////
int content_weight(int bottle_weight, std::string scale) {
  int x;
  std::string times, comparator;
  
  std::stringstream s(scale);
  s >> x >> times >> comparator;
  if (comparator == "larger") {
    return bottle_weight * x / (x + 1);
  } else {
    return bottle_weight / (x + 1);
  }
}
///////////////
int content_weight( int b, std::string s ) {
  int t{ stoi( s )};
  return ( s[ s.size()-6 ] == 'l' ? b * t : b ) / ++t;
}
////////////
int content_weight(int bottle_weight, std::string scale)
{
  int n {std::stoi(scale)};
  bottle_weight /= n + 1;
  return scale.find("larger") != std::string::npos ? bottle_weight * n : bottle_weight; 
}
////////////
#include <string>
#include <regex>
using namespace std;

int content_weight(const int bottle_weight, const string& scale) {
    static const regex rscale{ R"(^(\d+) times (larger|smaller)$)" };
    smatch match;
    if(!regex_match(scale, match, rscale)) throw std::invalid_argument{ "Meh" };
    const auto times = match[2] == "larger" ? std::stod(match[1].str()) : 1. / std::stod(match[1].str());
    return bottle_weight * times / (times + 1);
}
/////////////
