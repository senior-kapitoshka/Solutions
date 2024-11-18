class Solution {
public:
    struct S{
        int mx=0;
        int cnt=0;
        char c;
    };
    int maxPower(string str) {
        S s(1,1,str.front());
        for(size_t i=1;i<str.size();++i){
            if(str[i]==s.c){
                ++s.cnt;
                s.mx=std::max(s.cnt,s.mx);
            }else{
                s.c=str[i];
                s.cnt=1;
            }
        }
        return s.mx;
    }
};

//////////////////////
class Solution {
public:
    int maxPower(string s) {
        if(s.size()==0) return 0;

        int maxi=0;
        int currMaxi=0;

        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1])
                currMaxi++;

            else
                currMaxi=0;

            maxi=max(currMaxi,maxi);               
        }

        //+1 coz, full length of the longest repeating substring is included
        return maxi+1;
    }
};