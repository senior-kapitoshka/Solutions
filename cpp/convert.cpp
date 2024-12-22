using namespace std;
#include <vector>
#include <regex>
#include <map>

vector<int> scoreboard(const string &s)
{
    static const regex re("nil|one|two|three|four|five|six|seven|eight|nine");
    static unordered_map <string, int> nums = {{"nil", 0},{"one", 1},{"two", 2},{"three", 3},{"four", 4},{"five", 5},{"six", 6},{"seven", 7},{"eight", 8},{"nine", 9}};

    vector<int> res;
    
    for(auto it=sregex_iterator(s.begin(), s.end(), re),end=sregex_iterator(); it != end; ++it)
        res.push_back(nums[it->str()]);

    return res;
}