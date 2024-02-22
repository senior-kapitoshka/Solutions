#include <string>
#include <vector>
#include <stack>

std::string range_extraction(std::vector<int> args) {
  if(args.empty()) return "";
  std::string ans;
 std::vector<std::string> vs;
  int cnt=0;
  for(size_t i=0;i<args.size();){
    cnt=0;
    int str=args[i];
    std::string start=std::to_string(str);
    while(i!=args.size()-1 && args[i+1]-args[i]==1){
      ++cnt;
      ++i;
    }
    if(cnt>0){
      if(cnt>1){
        int m=str+cnt;
        start+="-"+std::to_string(m);
      }else --i;
    }
    vs.push_back(start);
    ++i;
    
  } 
  ans+=vs[0];
  for(size_t i=1;i<vs.size();++i){
    ans+=",";
    ans+=vs[i];
  }
  return ans;
}



std::string range_extraction(const std::vector<int> &args) {
    auto fast = args.begin(), slow = args.begin();
    std::string ans;
    while (fast != args.end()) {
        while (fast + 1 != args.end() && *(fast + 1) == *fast + 1) ++fast;
        if (fast - slow >= 2) {
            ans += std::to_string(*slow) + "-" + std::to_string(*fast) + ",";
            slow = fast + 1;
            ++fast;
        } else {
            ans += std::to_string(*slow) + ",";
            fast = slow + 1;
            ++slow;
        }
    }
    if (!ans.empty()) ans.pop_back();
    return ans;
}




Andela is searching for a ML Engineer (Computer Vision)
fpohtmeh, loneinass
#include <string>
#include <set>

std::string range_extraction(std::vector<int> args)
{
    using Range = std::pair<int, int>;
    std::vector<Range> ranges;
    for(auto &i : args)
        if(ranges.empty() || ranges.back().second + 1 != i)
            ranges.push_back({i, i});
        else
            ++ranges.back().second;

    std::string result;
    for(auto &r : ranges)
        if(r.first == r.second)
            result.append(std::to_string(r.first) + ",");
        else
            result.append(std::to_string(r.first) +
                          ((r.first + 1 == r.second) ? ',' : '-') +
                          std::to_string(r.second) +
                          ",");
    result.pop_back();
    return result;
}
1 similar code variation is grouped with this one
Show Variations
Best Practices41Clever36
 5ForkCompare with your solutionLink
Slinet6056, Little Slinet, hatruc, coder_macro26692
std::string range_extraction(const std::vector<int> &args) {
    auto fast = args.begin(), slow = args.begin();
    std::string ans;
    while (fast != args.end()) {
        while (fast + 1 != args.end() && *(fast + 1) == *fast + 1) ++fast;
        if (fast - slow >= 2) {
            ans += std::to_string(*slow) + "-" + std::to_string(*fast) + ",";
            slow = fast + 1;
            ++fast;
        } else {
            ans += std::to_string(*slow) + ",";
            fast = slow + 1;
            ++slow;
        }
    }
    if (!ans.empty()) ans.pop_back();
    return ans;
}
Best Practices8Clever1
 0ForkCompare with your solutionLink
erikpeyronson
#include <string>
#include <vector>

std::string format_range(int first, int last) {
  if (first == last) {
    return std::to_string(first) + ",";
  }
  
  if (last == first + 1) {
    return std::to_string(first) + "," + std::to_string(last) + ",";
  }
  
  return std::to_string(first) + "-" + std::to_string(last) + ",";
}

std::string range_extraction(std::vector<int> args) {
  std::string ret{};
  auto it = args.begin();
  
  while (it != args.end()) {
    auto range_end = it;
    auto number = *it;
    
    while (*(range_end + 1) == *range_end + 1 ) {
      if (++range_end == args.end()) break;
    }
    ret += format_range(number, *range_end);
    it = range_end + 1 ;
  }
  
  ret.pop_back(); 
  return ret;  
}

Best Practices5Clever1
 0ForkCompare with your solutionLink
MeltedSakura, Belora, Shchuka, Belorabo
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string range_extraction(vector<int> args) {
  int a = args[0], b = args[0];
  stringstream ss;
  for(auto p = begin(args)+1; p <= end(args); ++p){
    if(p == end(args) || p[0] > p[-1]+1){
      ss << a;
      if(a != p[-1])
        ss << ((p[-1]-a<=1)? ',' : '-') << p[-1];
      ss << ',';      
      a = p[0];
    }
  }
  string s = ss.str();
  s.pop_back();
  return s;
}
Best Practices4Clever8
 0ForkCompare with your solutionLink
Collision., PiotrLO3
#include <string>
#include <vector>

std::string range_extraction(std::vector<int> args) {
	std::string answer;

	if (args.size() == 1)
	{
		answer = answer + std::to_string(args[0]);
		return answer;
	}

	const int max = args.size();
	for (int i = 0; i < max; i++)
	{
		int current = args[i];

		if (i == max - 1)
		{
			answer = answer + std::to_string(args[i]);
			return answer;
		}
		else
		{
			for (int j = i + 1; j < max; j++)
			{
				
				if (args[j] == current + j - i)
				{	
					if(j!=max-1)continue;
					else {
						if (i == j-1) 
						{
							answer = answer + std::to_string(args[i]);
							answer.push_back(',');
							answer = answer + std::to_string(args[j]);
							return answer;
						}
						else
						{
							answer = answer + std::to_string(args[i]);
							answer.push_back('-');
							answer = answer + std::to_string(args[j]);
							return answer;
						}
					}
				}
				else
				{
					if (j == i + 1) answer = answer + std::to_string(args[i]);
					else if (j == i + 2)
					{
						answer = answer + std::to_string(args[i]);
						answer.push_back(',');
						answer = answer + std::to_string(args[i + 1]);
						i = j - 1;
					}
					else
					{
						answer = answer + std::to_string(args[i]);
						answer.push_back('-');
						answer = answer + std::to_string(args[j - 1]);
						i = j - 1;
					}
					break;
				}
			}
		}

		answer.push_back(',');
	}

	return answer;
}
Best Practices3Clever0
 1ForkCompare with your solutionLink
yogeshk4124
#include <string>
#include <vector>
using namespace std;
std::string range_extraction(std::vector<int> v) {
  stringstream ss("");
  int c=0;
  for(int i=0;i<v.size();i++){
  	if(v[i+2]==v[i]+2){
  	ss<<v[i];
		int j=i+3;
	  while(v[j]-v[j-1]==1){j++;}
		i=j-1;
		ss<<"-"<<v[i]<<",";
	}
	else ss<<v[i]<<",";
	}
  return (ss.str()).substr(0,ss.str().length()-1);
}