class Solution {
public:
    bool check(std::vector<int>mp1,std::string s2){
        std::vector<int>mp2(26,0);
        for(auto c:s2){ ++mp2[c-97];}
        return mp1==mp2;
    }

    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        std::vector<int>mp1(26,0);
        int hh1=0,hh2=0;
        for(auto c:s1){ ++mp1[c-97];hh1+=c;}
        for(size_t i=0;i<s1.size();++i){ hh2+=s2[i];}
        if(hh1==hh2) if(check(mp1,s2.substr(0,s1.size())))return true;
        int j=0;
        for(int i=s1.size();i<s2.size();++i){
            hh2+=s2[i]-s2[j++];
            if(hh1==hh2){
                if(check(mp1,s2.substr(j,s1.size())))return true;
            }
        }
        return false;
    }
};

////////////////////////
class Solution {
public:
 bool allZero(int *arr){
        for(int i=0;i<26;i++){
            if(arr[i]!=0){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
         if(s2.length()<s1.length()){
            return false;
        }
        int arr[26] = {0};
        for(int i=0;i<s1.length();i++){
            arr[s1[i]-'a']++;
        }
        int len = s1.length();
        for(int i=0;i<s2.length();i++){
            arr[s2[i]-'a']--;
            if(i-len>=0){
               arr[s2[i-len]-'a']++;
            }
            if(allZero(arr)) {
                return true;
            }
        }
        return false;
    }