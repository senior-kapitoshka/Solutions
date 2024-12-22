class Solution {
public:
    string countAndSay(int n) {
        std::string s="1";
        for(int i=1;i<n;++i){
            std::string t;
            int cnt=1;
            char c=s.front();
            if(s.size()==1){
                t+=std::to_string(cnt);
                t+=c;
            }
            else{
                for(int j=1;j<s.size();++j){
                    if(s[j]==c){
                        ++cnt;
                    }else{
                        t+=std::to_string(cnt);
                        t+=c;
                        c=s[j];
                        cnt=1;
                    }
                }
                t+=std::to_string(cnt);
                t+=c;
            }
            std::swap(t,s);
        }
        return s;
    }
};

/////////////////
class Solution {
public:
    string countAndSay(int n) {
        switch (n) {
            case 1 : return "1";
            default: {
                auto s = countAndSay(n - 1);
                string res;
                res.reserve(s.size());
                for (int i = 0, e = s.size(); i < e;) {
                    int j = i + 1;
                    auto c = s[i];
                    for (; j < e && s[j] == c; ++j);
                    res.push_back('0' + j - i);
                    res.push_back(c);
                    i = j;
                }
                return res;
            }
        }
    }
};

///////////////////
class Solution {
public:
    string count(string &s){
        char currentChar = s[0];
        int count = 0;
        string res = "";
        for(char c : s){
            if(currentChar == c)
                count++;
            else {
                res += to_string(count) + currentChar;
                count = 1;
                currentChar = c;
            }
        }
        res += to_string(count)+currentChar;
        return res;
    }

    string countAndSay(int n) {
        if(n == 1)
            return "1";

        string res = "1";
        for(int i = 1; i<n; i++){
            res = count(res);
        }
        return res;
    }
};