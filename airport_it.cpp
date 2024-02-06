class Route
{
public:
    std::string in;
    
    std::string out;
    
    Route(std::string in, std::string out)
    {
        this->in = in;
        this->out = out;
    }
    
    ~Route() { };
};

std::string itinerary(std::vector<Route> tr)
{
    std::string ans;
    std::vector<std::string>vs;
    for(size_t i=0;i<tr.size();++i){
      if(vs.empty()||(!vs.empty()&&(vs.back()!=tr[i].in))){
        vs.push_back(tr[i].in);
        vs.push_back(tr[i].out);
      }
      else if(vs.back()==tr[i].in){
        vs.push_back(tr[i].out);
      }
    }
  for(size_t i=0;i<vs.size();++i){
    ans+=vs[i];
    if(i!=vs.size()-1) ans+="-";
  }
  return ans;
}

////////////////////////////////////
std::string itinerary( std::vector< Route > travel ) {
  std::string route{ travel[ 0 ].in + '-' + travel[ 0 ].out };
  for ( size_t i{ 1 }; i < travel.size(); ++i )
    route += ( travel[ i ].in != travel[ i - 1 ].out ?
      '-' + travel[ i ].in : "" ) + '-' + travel[ i ].out;
  return route;
}
//////////////////////////////////
#include <boost/algorithm/string/join.hpp>

std::string itinerary(std::vector<Route> travel)
{
    std::vector<std::string> vec;
    for(int i = 0; i < travel.size();i++){
      if( (i > 0 && *(vec.end()-1) != travel[i].in) || (i == 0) )
        vec.push_back(travel[i].in);     
      vec.push_back(travel[i].out);
    }
    return  boost::algorithm::join(vec, "-");
}
/////////////////////////////////////ACCUMULATE
#include <range/v3/numeric/accumulate.hpp>
#include <range/v3/view/sliding.hpp>
#include <string>

std::string itinerary(std::vector<Route> travel) {
  using namespace ranges;
  return accumulate(travel | views::sliding(2), std::string { travel[0].in + '-' + travel[0].out },
                    [] (auto& acc, const auto& p) -> auto& {
                      if (p[0].out != p[1].in) { acc.append("-").append(p[1].in); }
                      return acc.append("-").append(p[1].out);
                    });
}
//////////////////////////////////////////////
#include <string>
#include <utility>
#include <numeric>
std::string itinerary(const std::vector<Route> &travel){
  if (travel.empty()) return "";
  return std::accumulate(std::next(travel.cbegin()),travel.cend(),
                         travel[0].in+"-"+travel[0].out,
                         [last=travel[0].out](auto &s, auto &r) mutable {
                           return s+"-"+((r.in!=std::exchange(last,r.out))?r.in+"-":"")+r.out;
                         });
}
////////////////////////////OSTREAM
#include <set>

std::string itinerary(std::vector<Route> travel) {
  std::vector<std::string> destinations{travel[0].in};
  for (auto trip : travel) {
    if (trip.in != destinations.back()) destinations.push_back(trip.in);
    destinations.push_back(trip.out);
  }
  std::ostringstream stream;
  std::copy(destinations.begin(), destinations.end(), std::ostream_iterator<std::string>(stream, "-"));
  std::string res = stream.str();
  res.pop_back();
  return res;
}