#include <string>
#include <vector>
#include <algorithm>
#include <deque>

// Place the n+1 integers in a list such that, in order
// they will fit into the inequalities.
std::vector<int> interweave(const std::string& iq, const std::vector<int>& is) {
  std::deque<int>nv(is.begin(),is.end());
  std::sort(nv.begin(),nv.end());
  if(!iq.find("<>") && !iq.find("><") && iq.front()=='<'){
    return std::vector<int>(nv.begin(),nv.end());
  }
  else if(!iq.find("<>") && !iq.find("><") && iq.front()=='>'){
    return std::vector<int>(nv.rbegin(),nv.rend());
  }
  std::vector<int>res(is.size(),0);

  for(size_t i=0;i<iq.size()-1;++i){
    if(iq[i]=='<' && iq[i+1]=='>'){
      res[i+1]=nv.back();
      nv.pop_back();
    }else if(iq[i]=='>' && iq[i+1]=='<'){
      res[i+1]=nv.front();
      nv.pop_front();
    }
  }
  for(size_t i=0;i<res.size();++i){
    if(res[i]==0){
      if(iq[i]=='<'){
        res[i]=nv.front();
        nv.pop_front();
      }
      else if(iq[i]=='>'){
        res[i]=nv.back();
        nv.pop_back();
      }
      else {
        res[i]=nv.back();
        nv.pop_back();
      }
    }
  }
  return res;
}

/////////////////////////
std::vector<int> interweave( const std::string& ineqs, const std::vector< int >& ints ) {
  std::vector< int > sorted{ ints }, result( ints.size() );
  sort( sorted.begin(), sorted.end() );
  size_t i{}, l{}, r{ sorted.size()-1 };
  for ( const char sign : ineqs )
    result[ i++ ] = sorted[ sign == '<' ? l++ : r-- ];
  return result[ i ] = sorted[ l ], result;
}

///////////////////////////

#include <algorithm>
#include <string>
#include <vector>

std::vector<int> interweave(const std::string& ineqs, std::vector<int> ints) {
  std::sort(ints.begin(), ints.end());
  auto it_a = ints.cbegin();
  auto it_b = ints.crbegin();
  std::vector<int> res;
  res.reserve(ints.size());
  for (char x : ineqs)
    res.push_back(x == '<' ? *it_a++ : *it_b++);
  res.push_back(*it_a);
  return res;
}

//////////////////////
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> interweave(const std::string& ineqs, const std::vector<int>& ints) {
  std::vector<int> copy = ints;
  std::vector<int> solve;
  std::sort(copy.begin(), copy.end());
  int min{0};
  int max{(int)copy.size() - 1};

  for (const auto& ch : ineqs) {
    if (ch == '<') {
       solve.push_back(copy[min++]);
    } else {
       solve.push_back(copy[max--]);
    }
  }
  solve.push_back(copy[min]);
  return solve;
}

///////////////////
#include <string>
#include <vector>
#include <algorithm>
// Place the n+1 integers in a list such that, in order they will fit into the inequalities.
std::vector<int> interweave(const std::string& ineqs, const std::vector<int>& ints) {
    // Think.. once 'ints' list is sorted, for a given INDEX all the smaller are to to the left, and all the
    // greater are to the right. Thus... we reinvented a bubblesort like algo!!
    std::vector<int> sorted {ints};
    std::sort(sorted.begin(),sorted.end());
    bool mod=true;
    while (mod) {
      mod=false;
      for (size_t inx=0; inx<ineqs.size();++inx) {
        if (ineqs[inx]=='>' && sorted[inx]<sorted[inx+1]) {
          std::swap(sorted[inx],sorted[inx+1]);
          mod=true;
        }
      }
    }
  return sorted;
}