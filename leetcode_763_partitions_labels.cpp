class Solution {
public:
    vector<int> partitionLabels(string s) {
        std::map<char,int>last;
        for(size_t i=0;i<s.size();++i){
            last[s[i]]=(int)i;
        }
        std::vector<int>res;
        int left=0, right=0;
        for(size_t i=0;i<s.size();++i){
            right=std::max(right,last[s[i]]);
            if(i==right){
                res.push_back(right-left+1);
                left=i+1;
            }
        }
        return res;
    }
};

//////////////////
class Solution {
public:
    vector<int> partitionLabels(string s) {
        std::map<char,int>mp;
        for(size_t i=0;i<s.size();++i){
            mp[s[i]]=(int)i;
        }
        std::vector<int>res;
        int mx=0;
        int prev=-1;
        for(size_t i=0;i<s.size();++i){
            mx=std::max(mx,mp[s[i]]);
            if(i==mx){
                res.push_back(mx-prev);
                prev=mx;
            }
        }
        return res;
    }
};

////////////////////
