class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s=="") return true;
        size_t j=0;
        for(size_t i=0;i<t.size();++i){
            if(t[i]==s[j]){
                std::cout<<t[i]<<s[j]<<"\n";
                ++j;
            }
        }
        return j==s.size();
    }
};

