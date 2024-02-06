#include <numeric>
using  vps = std::vector<std::pair <std::string, std::string> > ;

class PartList
{
public:
    static vps partlist(std::vector<std::string> &so){
       vps ans(so.size()-1);
  auto dash_fold = [](std::string a, std::string b)
    {
        return std::move(a) + ' '  + b;
    };
  std::string h;
  for(size_t i=1;i<so.size();++i){
    if(i!=1){
        h+=' ';
    }
    h+=so[i-1];
    
    ans[i-1].first=h;
    ans[i-1].second=std::accumulate(std::next(so.begin(),i+1), so.end(),so[i], dash_fold);
            
    }
    return ans;
    }
};

/////////////////////////////////////////////////

#include <numeric>

using namespace std;

class PartList
{
public:
    static std::vector<std::pair <std::string, std::string>> partlist(std::vector<std::string> &arr)
    {
      vector<pair<string, string>> result;
      auto combine = [](string a, string b) { return a + ' ' + b; };
      for (int i = 1; i < arr.size(); i++)
      {
        result.emplace_back(
          accumulate(arr.begin() + 1, arr.begin() + i, arr[0], combine),
          accumulate(arr.begin() + i + 1,  arr.end(), arr[i], combine));
      }
      return result;
    }
};

//////////////////////////////////////////
using namespace std;
class PartList
{
public:
    static vector<pair <string, string>> partlist(vector<string> &arr){
        vector<pair<string, string>> output;
        for(unsigned int i=1; i<arr.size(); i++){
            string out1, out2;
            for(unsigned int j=0; j<i; j++){
                out1+=arr[j];
                if(j+1!=i)out1+=' ';}
            for(unsigned int j=i; j<arr.size(); j++){
                out2+=arr[j];
                if(j+1!=arr.size())out2+=' ';}
            output.push_back({out1, out2});
        }
        return output;
    }
};
//////////////////////////////////////

class PartList
{
public:
    static std::vector<std::pair <std::string, std::string>> partlist(std::vector<std::string> &arr)
    {
      std::vector<std::pair <std::string, std::string>> result;
      
      for (int i = 0; i < arr.size() - 1; i++)
      {
        std::ostringstream first, second;

        for (int j = 0; j <= i;) first << arr[j] << (++j <= i ? " " : "");

        for (int j = i + 1; j < arr.size();) second << arr[j] <<  (++j < arr.size() ? " " : "");
        
        result.push_back(std::make_pair(first.str(), second.str()));
      }
      
      return result;
    }
};
/////////////////////////////////////////


class PartList
{
public:
	static std::vector<std::pair <std::string, std::string>> partlist(std::vector<std::string> arr)
	{
		std::vector<std::pair <std::string, std::string>> v;
		std::string s1, s2;
		for (size_t i = 1; i < arr.size(); ++i)
		{
			for (size_t j = 0; j < arr.size(); ++j) (j < i) ? (s1 += arr[j] + " ") : (s2 += arr[j] + " ");
			s1.pop_back(); s2.pop_back();
			v.push_back({ s1, s2 });
			s1 = ""; s2 = "";
		}
		return v;
	}
};
////////////////////////////////////

class PartList {

public:
    static std::vector<std::pair <std::string, std::string>> partlist(std::vector<std::string> &arr) {
      
      std::vector<std::pair<std::string, std::string>> answer;
      int n = arr.size();          
    
      for (int i = 0; i < n-1; ++i) {
        
        std::string some_str, some_str2;
        
        for (int j = 0; j <= i; ++j )   { some_str += arr[j] + " "; }
        for (int k = i + 1; k < n; ++k) { some_str2 += arr[k] + " "; }
        
        some_str.pop_back();
        some_str2.pop_back();
        
        answer.push_back({some_str, some_str2});
      }
      
    return answer;
  }    
};

/////////////////////////////////////
#include <vector>
#include <string>
#include <utility>
#include <numeric>

class PartList
{
public:
    static std::vector<std::pair <std::string, std::string>> partlist(std::vector<std::string> &arr)
    {
        auto comb = [](std::string const& a, std::string const& b) { return a + ' ' + b; };
        std::vector<std::pair<std::string, std::string>> res; res.reserve(arr.size() - 1);
        for (auto i = 1; i < arr.size(); ++i)
            res.emplace_back(std::reduce(arr.begin() + 1, arr.begin() + i, arr[0], comb),
                             std::reduce(arr.begin() + i + 1, arr.end(), arr[i], comb));
        return res;
    }
};