#include <string>
#include <algorithm>
#include <sstream>
#include <numeric>
#include <regex>
#include <cmath>

class Rainfall
{
public:
    static double mean(std::string town, const std::string &str, std::vector<double>&&vd={}){
      std::stringstream ss(str);
      double sum=0.0;
      int cnt=0;
      std::regex r("([\\d]+.[\\d]+)");
      for(std::string s;std::getline(ss,s);){
        if(s.substr(0,s.find_first_of(":"))==town){
          auto rb=std::sregex_iterator(s.begin(),s.end(),r);
          auto re=std::sregex_iterator();
          for(auto it=rb;it!=re;++it){
            vd.push_back(std::stod(it->str()));
            sum+=std::stod(it->str());
            ++cnt;
          }
        }
      }
      return (sum==0.0 && cnt==0)?(-1):sum/cnt;
    }
    static double variance([[maybe_unused]]std::string town, [[maybe_unused]]const std::string &strng){
      std::vector<double>arr;
      double m=mean(town,strng,std::move(arr));
      double sum=std::accumulate(arr.begin(),arr.end(),0.0,[&m](double sum, double curr){
        return sum+=std::pow((curr-m),2);
      });
      int cnt=(int)arr.size();
      return (sum==0.0 && cnt==0)?(-1):sum/cnt;
    }
};

//////////////////////////////////

#include <string>
#include <algorithm>
#include <sstream>
#include <numeric>
#include <regex>
#include <cmath>

class Rainfall
{
  
public:

  
    static double mean(std::string town, const std::string &str){
      std::stringstream ss(str);
      double sum=0.0;
      int cnt=0;
      std::regex r("([\\d]+.[\\d]+)");
      for(std::string s;std::getline(ss,s);){
        if(s.substr(0,s.find_first_of(":"))==town){
          auto rb=std::sregex_iterator(s.begin(),s.end(),r);
          auto re=std::sregex_iterator();
          for(auto it=rb;it!=re;++it){
            sum+=std::stod(it->str());
            ++cnt;
          }
        }
      }
      return (sum==0.0 && cnt==0)?(-1):sum/cnt;
    }
    static double variance(std::string town, const std::string &strng){
      double m=mean(town,strng);
      std::stringstream ss(strng);
      double sum=0.0;
      int cnt=0;
      std::regex r("([\\d]+.[\\d]+)");
      for(std::string s;std::getline(ss,s);){
        if(s.substr(0,s.find_first_of(":"))==town){
          auto rb=std::sregex_iterator(s.begin(),s.end(),r);
          auto re=std::sregex_iterator();
          for(auto it=rb;it!=re;++it){
            sum+=std::pow((std::stod(it->str())-m),2);
            ++cnt;
        }
      }
    }

      return (sum==0.0 && cnt==0)?(-1):sum/cnt;
    }
  
};

/////////////////////////////
#include <string>
#include <sstream>
#include <regex>
#include <numeric>

template<typename T>
inline T convert_string(const std::string& s)
{
  std::istringstream sstr(s);
  T x;
  if(!(sstr >> x)) 
    return T{};
  return x;
}

class Rainfall
{
public:
    static double mean(std::string town, const std::string &strng)
    {
      std::vector<double> rainfall_values;
      parse_data(strng, town, rainfall_values);
      if(rainfall_values.empty())
        return -1.0;
      return mean(rainfall_values);
    }
    
    static double variance(std::string town, const std::string &strng)
    {
      std::vector<double> rainfall_values;
      parse_data(strng, town, rainfall_values);
      if(rainfall_values.empty())
        return -1.0;
      double mean_rainfall = mean(rainfall_values);
      // Replace each entry in rainfall_values by the squared difference
      // to the mean, variance is then given by the mean of rainfall_values.
      for(auto& x : rainfall_values)
        x = (x - mean_rainfall) * (x - mean_rainfall);
      return mean(rainfall_values);
    }
private:
    static double mean(const std::vector<double>& data)
    {
      if(data.empty()) return 0.0;
      return std::accumulate(data.begin(), data.end(), 0.0) /
             static_cast<double>(data.size());
    }
    
    static void parse_data(const std::string& data, const std::string& town, std::vector<double>& rainfall_values)
    {
      rainfall_values.clear();
      std::stringstream sstr{data};
      std::string current;
      // Iterate through the lines to find the right town
      while(std::getline(sstr, current))
      {
        // We have found the right line if it starts with the
        // town.
        if(current.find(town) == 0)
        {
          // Let's be picky about syntax and just insist that the
          // town is followed by a colon.
          if(current.find_first_of(":") != town.size())
            return;
          // Found the right town!
          // Find all numbers in the line using regular expressions
          std::regex expression("[0-9]+.?[0-9]*");
          using regex_iter = std::regex_iterator<std::string::iterator>;

          regex_iter end;          
          for(regex_iter it{current.begin(), current.end(), expression};
              it != end; ++it)
          {
            std::string match{it->str()};
            rainfall_values.push_back(convert_string<double>(match));
          }
          
          return;
        }
      }
    }
};

////////////////////////
#include <string>
#include <sstream>
#include <array>
#include <numeric>
#define NOTFOUND (size_t)-1
using std::string;
class Rainfall
{
public:
    template<typename T>
    static double acc(std::array<double,12> a, T func){
      return std::accumulate(a.begin(), a.end(), (double)0, func);
    }
    static std::array<double,12> parser(string town, string data){
      double start{data.find(town+":")}, end{data.find("\n",start)};
      if(start == NOTFOUND) return {start};
      if(end >= data.length()) end = data.length();
      std::stringstream ss{data.substr(start,end)};
      std::array<double,12> a;
      for(auto& i:a)
        ss >> town >> i;
      return a;
    }
    static double mean(string town, const string &strng){
      auto a = parser(town,strng);
      if(a[0] == NOTFOUND) return -1;
      return acc(a, std::plus<double>())/12.0;
    };
    static double variance(string town, const string &strng){
      auto a = parser(town,strng);
      if(a[0] == NOTFOUND) return -1;
      auto b = acc(a, std::plus<double>())/12.0;
      auto c = acc(a, [b](auto d,auto e){return d+(e-b)*(e-b);})/12.0;
      return c;
    };
};

/////////////////////////
#include <string>
#include <regex>
#include <optional>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

class Rainfall {
    struct Data {
        const std::string name;
        const std::vector<double> points;
        
        Data(const std::string& name, const std::vector<double>& points): 
            name{ name }, points{ points } {}
    };
    
    static std::optional<Data> extract(const std::string& town, const std::string& data) {
        static const std::regex rdata_list{ R"((\w+):(.+)(\n|$))" };
        static const std::regex rdata_vals{ R"(\d+\.\d+)" };
      
        const auto data_list = std::find_if(
            std::sregex_iterator{ data.cbegin(), data.cend(), rdata_list },
            std::sregex_iterator{},
            [&town](const std::smatch& match) {
                return match[1] == town;
            }
        );
      
        if(data_list == std::sregex_iterator{}) {
            return std::nullopt;
        }
      
        const auto& spoints = (*data_list)[2].str();
        std::vector<double> points;
      
        std::transform(
            std::sregex_token_iterator{ spoints.cbegin(), spoints.cend(), rdata_vals },
            std::sregex_token_iterator{},
            std::back_inserter(points),
            [](const std::string& s) { return std::stod(s); }
        );
                
        return Data(town, points);
    }
  
    static double mean(const std::vector<double>& p) {
        if(p.empty()) return -1.0;
        return std::accumulate(p.cbegin(), p.cend(), 0.) / p.size();
    }
  
    static double variance(const std::vector<double>& p) {
        if(p.empty()) return -1.0;
        const auto μ = mean(p);
        return std::accumulate(
            p.cbegin(), p.cend(), 0.,
            [&μ](const double acc, const double x) {
                const auto dx = x - μ;
                return acc + dx * dx;
            }
        ) / p.size();
    }
  
public:
    static double mean(const std::string& town, const std::string& sdata) {
        const auto data = extract(town, sdata);
        if(!data) return -1.0;
        return mean(data->points);
    }

    static double variance(const std::string& town, const std::string& sdata) {
        const auto data = extract(town, sdata);
        if(!data) return -1.0;
        return variance(data->points);
    }
};
///////////////////////
#include <string>
#include <regex>
#include <numeric>
#include <cmath>

class Rainfall
{
    static std::sregex_iterator get_towns_values(const std::string &town, const std::string &data);
public:
    static double mean(std::string town, const std::string &data);
    static double variance(std::string town, const std::string &data);
};

std::sregex_iterator Rainfall::get_towns_values(const std::string &town, const std::string &data)
{
    std::smatch m;
    static std::string line;
    line = std::regex_search(data, m, std::regex{town + ":(.*)"}) ? m[1] : std::string("error -1");
    static const std::regex re{R"([a-zA-Z]+ (.*?)(?:,|$))"};
    return {line.cbegin(), line.cend(), re};
}

double Rainfall::mean(std::string town, const std::string &data)
{
    int count = 0;
    return std::accumulate(get_towns_values(town, data), {}, 0.0, [&count](double sum, auto &&el){
        return ++count, sum + std::stod(el[1]);
    }) / count;
}

double Rainfall::variance(std::string town, const std::string &data)
{
    double avg = mean(town, data);
    if (avg < 0) return avg;
    int count = 0;
    std::vector<double> sqs;
    std::transform(get_towns_values(town, data), {}, std::back_inserter(sqs), [&](auto &&el){
        return ++count, std::pow(std::stod(el[1]) - avg, 2);
    });
    return std::accumulate(sqs.begin(), sqs.end(), 0.0) / count;
}

//////////////////