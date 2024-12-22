class Solution {
public:
    int firstUniqChar(string s) {
        std::unordered_map<char,std::pair<int,size_t>>mp;
        std::for_each(s.begin(),s.end(),[i=0,&mp](auto& c)mutable{
            if(mp.count(c)){
                ++mp[c].first;
            }else{
                mp[c]={1,i};
            }
            ++i;
        });
        size_t min=INT_MAX;
        std::for_each(mp.begin(),mp.end(),[&min](auto& p){
            if(p.second.second<min && p.second.first==1){
                min=p.second.second;
            }
        });
        return min==INT_MAX?-1:min;
    }
};

////////////////////////////
class Solution {
public:
    int firstUniqChar(string s) {
        int count[26];
        int n = s.length();
        for(int i=0; i<n; i++)
        {
            count[s[i]-'a']++;
        }
        for(int i=0; i<n; i++)
        {
            if(count[s[i]-'a']==1)
            {
                return i;
            }
        }
        return -1;
    }
};