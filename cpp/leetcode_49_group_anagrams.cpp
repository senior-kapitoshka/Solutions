class Solution {
    struct hsh{
        size_t operator()(const std::vector<int>& vc)const{
            size_t h2=0;
            for(size_t i=0;i<256;++i) 
                if(vc[i]!=0) 
                    h2+=(i^vc[i])<<1;
            return h2;        
        }
    };

    void hash2hash(std::string_view s,std::unordered_map<std::vector<int>,std::vector<std::string>,hsh>&mp){
        std::vector<int>vc(256,0);
        for(auto i:s){
            ++vc[i];
        }
        mp[vc].push_back(std::string(s)); 
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& ss) {
        std::unordered_map<std::vector<int>,std::vector<std::string>,hsh>mp;
        for(auto& s:ss){
            hash2hash(s,mp);
        }
        std::vector<std::vector<std::string>> res;
        res.reserve(mp.size());
        std::for_each(mp.begin(),mp.end(),[&res](auto& p){res.push_back(p.second);});
        return res;
    }


    #if 0
    // 60/120~
    void hash2hash(std::string_view s,std::unordered_map<int,std::vector<std::string>>&mp){
        std::vector<int>vc(256,0);
        int h1=0;
        for(auto i:s){
            ++vc[i];
            h1+=i;
        }
        int h2=0;
        for(size_t i=0;i<256;++i) if(vc[i]!=0) h2+=(i^vc[i])<<1;
        mp[h1^h2].push_back(std::string(s)); 
    }

    vector<vector<string>> groupAnagrams(vector<string>& ss) {
        std::unordered_map<int,std::vector<std::string>>mp;
        for(auto& s:ss){
            hash2hash(s,mp);
        }
        std::vector<std::vector<std::string>> res;
        res.reserve(mp.size());
        std::for_each(mp.begin(),mp.end(),[&res](auto& p){res.push_back(p.second);});
        return res;
    }
    #endif

};
////////////////////////////
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for (string& s : strs) {
            string key = s; 
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }
        
        vector<vector<string>> ans;
        
        for (auto& pair : mp) {
            ans.push_back(pair.second);
        }
        
        return ans;
    }
};