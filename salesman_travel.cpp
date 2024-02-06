#include <string>
#include <unordered_map>
#include <vector>
#include <utility>
#include <sstream>

class SalesmanTravel
{
public:
    static std::string travel(const std::string& o, std::string z){
      std::unordered_map<std::string,std::vector<std::pair<std::string,std::string>>>mp;
      std::istringstream ss;
      ss.str(o);
      std::vector<std::string>vs;
      for(std::string w;getline(ss,w,',');)
        vs.push_back(std::move(w));
      for_each(vs.begin(),vs.end(),[&mp](auto& s)
               {
                 std::string num = s.substr(0,s.find_first_of(' '));
                 s.erase(0,s.find_first_of(' ')+1);
                 std::string key=s.substr(s.find_last_of(' ')-2);
                 s.erase(s.find_last_of(' ')-3);
                 std::string ad = s;
                 mp[key].push_back({num, ad});
               });
      std::string res=":/";
      if(mp.count(z)){
        if(mp[z].size()==1){
          res.insert(2,mp[z].front().first);
          res.insert(1,mp[z].front().second);
          res.insert(0,z);
        }else{
          std::string ad;
          std::string id;
          for(auto& [i,a]: mp[z]){
            ad+=a;
            ad+=",";
            id+=i;
            id+=",";
          }
          ad.erase(ad.find_last_of(','));
          id.erase(id.find_last_of(','));
          res.insert(2,id);
          res.insert(1,ad);
          res.insert(0,z);
        }
      }else{
        res.insert(0,z);
      }
      return res;
    }
};

/////////////////////////////////////////////////////////
#include <string>

class SalesmanTravel
{
public:
    static std::string travel(const std::string& orgr, std::string zipcode)
     { std::string num,adr;
       int i,j,tmp;
       if((i = orgr.find(zipcode)) == std::string::npos || zipcode == "" || zipcode.size() != 8) return zipcode + ":/";
       do { j = ((j = orgr.rfind(',',i)) == std::string::npos)?0:j+1;
            num = ((num == "")?"/":num+",")+ orgr.substr(j,tmp = orgr.find(' ',j) - j);
            adr = ((adr == "")?"":adr + ",") + orgr.substr(j + tmp + 1,i - j - tmp - 2); }
       while((i = orgr.find(zipcode,i+1)) != std::string::npos);
       return zipcode + ":" + adr + num; }
};
////////////////////////////////
#include <regex>
#include <string>
#include <vector>
 
class SalesmanTravel {
public:
  static std::string travel(const std::string &orgr, std::string zipcode) { 
    std::vector<std::string> fullAddresses;
    auto it = std::find(orgr.begin(), orgr.end(), ',');
    auto prevIt = orgr.begin();
    do {
      fullAddresses.emplace_back(prevIt, it);
      prevIt = ++it;
      it = std::find(it, orgr.end(), ',');
    } while (it != orgr.end());
 
    std::string numbers;
    std::string addresses;
    std::regex zipcodeRegex("([0-9]+)\\s(.*)\\s" + zipcode);
    std::smatch match;
    for (auto &&fullAddress : fullAddresses) {
      if (std::regex_match(fullAddress, match, zipcodeRegex) &&
          match.size() == 3) {
        addresses += (addresses.empty() ? "" : ",") + std::string(match[2]);
        numbers += (numbers.empty() ? "" : ",") + std::string(match[1]);
      }
    }
    
    return zipcode + ":" + addresses + "/" + numbers;
  }
};