class Solution {
public:
    int numJewelsInStones(string j, string s) {
        std::unordered_map<char,int>mp;
        for(auto i:s) ++mp[i];
        int cnt=0;
        for(auto c:j){
            cnt+=mp[c];
        }
        return cnt;
    }
};

////////////////////////
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelSet(jewels.begin(), jewels.end());
        int count = 0;
        for (char stone : stones) {
            if (jewelSet.find(stone) != jewelSet.end()) {
                count++;
            }
        }
        
        return count;
    }
};