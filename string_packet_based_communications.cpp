#include <regex>
#include <fmt/format.h>

std::string communicationModule(std::string p)
{
  constexpr int x=10000;
  std::regex r("^([\\d|\\w]{4})([\\d|\\w]{4})([\\d]{4})([\\d]{4})([\\d|\\w]{4})$");
  std::smatch m;
  std::regex_match(p,m,r);
  std::string res;
  std::string m3=m[3];
  std::string m4=m[4];
  if(m[2]=="0F12"){
    if(m3=="0000"){
      res=m4;
    }else if(m4=="0000"){
      res=m3;
    }else{
      res=(std::stoi(m3.substr(m3.find_first_not_of('0')))+std::stoi(m4.substr(m4.find_first_not_of('0')))<x)?
        std::to_string(std::stoi(m3.substr(m3.find_first_not_of('0')))+std::stoi(m4.substr(m4.find_first_not_of('0')))):
      "9999";
    }
  }else if(m[2]=="B7A2"){
    if(m3=="0000"){
      res="0000";
    }else if(m4=="0000"){
      res=m3;
    }else{
      res=(std::stoi(m3.substr(m3.find_first_not_of('0')))-std::stoi(m4.substr(m4.find_first_not_of('0')))>0)?
        std::to_string(std::stoi(m3.substr(m3.find_first_not_of('0')))-std::stoi(m4.substr(m4.find_first_not_of('0')))):
      "0000";
    }
  }else if(m[2]=="C3D9"){
    if(m3=="0000" || m4=="0000"){
      res="0000";
    }else{
      res=(std::stoi(m3.substr(m3.find_first_not_of('0')))*std::stoi(m4.substr(m4.find_first_not_of('0')))<x)?
        std::to_string(std::stoi(m3.substr(m3.find_first_not_of('0')))*std::stoi(m4.substr(m4.find_first_not_of('0')))):
      "9999";
    }
  }
  if(res.size()==1){
    res.insert(0,"000");
  }else if(res.size()==2){
    res.insert(0,"00");
  }else if(res.size()==3){
    res.insert(0,"0");
  }
  std::string m1=m[1];
  std::string m5=m[5];
  return fmt::format("{}{}{}{}{}",m1,"FFFF",res,"0000",m5);
}

///////////////
#include <iomanip>
std::string communicationModule( std::string p ) {
  const int d1{ stoi( p.substr( 8, 4 ) ) }, d2{ stoi( p.substr( 12, 4 ) ) },
    r{ p[ 4 ] == '0' ? d1 + d2 : p[ 4 ] == 'B' ? d1 - d2 : d1 * d2 };
  std::ostringstream out;
  out << std::setw( 4 ) << std::setfill( '0' ) << ( r < 0 ? 0 : r > 9999 ? 9999 : r );
  return p.replace( 4, 12, "FFFF" + out.str() + "0000" ), p;
}

////////////////////
#include <regex>
#include <map>
#include <functional>

std::map<std::string, std::function<int (const int&, const int&)>> codes = { {"0F12",std::plus<>()}, {"B7A2",std::minus<>()}, {"C3D9", std::multiplies<>()} };

std::string communicationModule(std::string packet) {
    std::smatch m;
    std::regex_match(packet, m, std::regex("(.{4})(0F12|B7A2|C3D9)(\\d{4})(\\d{4})(.{4})"));
    std::string result = std::to_string(std::min(9999, std::max(0, codes[m[2]](std::stoi(m[3]), std::stoi(m[4])))));
    return m[1].str() + "FFFF" + std::string(4 - result.size(),'0') + result + "0000" + m[5].str();
}

///////////////////////////
#include <fmt/core.h>
#include <unordered_map>

std::string communicationModule(std::string p)
{
  int D1 = std::stoi(p.substr(8, 4)), D2 = std::stoi(p.substr(12, 4));
  
  std::unordered_map<std::string, std::string> ops = {
    {"0F12", fmt::format("{:04}", std::min(D1+D2, 9999))},
    {"B7A2", fmt::format("{:04}", std::max(D1-D2, 0))},
    {"C3D9", fmt::format("{:04}", std::min(D1*D2, 9999))}
  };
  
  return fmt::format("{}FFFF{}0000{}", p.substr(0,4), ops[p.substr(4,4)], p.substr(16,4));
}

/////////////////////
#include <string>
#include <map>
#include <functional>

using namespace std;

string communicationModule(const string &packet)
{
  static map<string,function<int(int,int)>> operations = {{"0F12",plus<int>()}, {"B7A2",minus<int>()},{"C3D9",multiplies<int>()}};
  string header = packet.substr(0,4), ins = packet.substr(4,4), footer = packet.substr(16,4);
  int data1 = stoi(packet.substr(8,4)), data2 = stoi(packet.substr(12,4));
  string ans = to_string(min(9999,max(0,operations[ins](data1, data2))));
  return header + "FFFF" + string(4-ans.size(),'0') + ans + "0000" + footer;
}

//////////////////////
#include <string>
#include <functional>
#include <map>
#include <sstream>
#include <iomanip>

using namespace std;

map<string, function<int(int, int)>> funcs = {
  make_pair("0F12", [](int n1, int n2) { return n1 + n2; }),
  make_pair("B7A2", [](int n1, int n2) { return n1 - n2; }),
  make_pair("C3D9", [](int n1, int n2) { return n1 * n2; }),
};

string communicationModule(string packet)
{
  int n1 = stoi(packet.substr(8, 4));
  int n2 = stoi(packet.substr(12, 4));
  int num = funcs[packet.substr(4, 4)](n1, n2);
  
  if (num < 0) num = 0;
  if (num > 9999) num = 9999;
  
  stringstream stream;
  stream << setfill('0') << setw(4) << num;
  
  packet.replace(4, 12, "FFFF00000000");
  packet.replace(8, 4, stream.str());
  
  return packet;
}

//////////////////