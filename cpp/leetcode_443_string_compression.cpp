class Solution {
public:
    struct S{
        char c;
        uint32_t n; 
    };
    void check_and_add(S s,std::vector<char>&res, int& cnt){
        if(s.n==1){
            res.push_back(s.c);
            ++cnt;
        }else if(s.n<10){
            res.push_back(s.c);
            res.push_back(s.n+'0');
            cnt+=2;
        }else if(s.n>=10){
                res.push_back(s.c);
                std::vector<char>vc;
                to_chars(s.n,vc);
                cnt+=vc.size()+1;
                std::copy(vc.rbegin(),vc.rend(),std::back_inserter(res));
        }
    }

    void to_chars(uint32_t n,std::vector<char>&vc){
        while(n){
            char x=n%10+'0';
            vc.push_back(x);
            n/=10;
        }
    }
    int compress(vector<char>& cs) {
        if(cs.size()==1){
            std::vector<char> res{cs.front()};
            std::swap(cs,res);
             return 1;
        }else if(cs.empty()){
            return 0;
        }
        std::vector<char>res;
        int cnt=0;
        res.reserve(cs.size());
        S s{cs.front(),1};
        for(size_t i=1;i<cs.size();++i){
            if(s.c==cs[i]){
                ++s.n;
            }else{
                check_and_add(s,res,cnt);
                s.c=cs[i];
                s.n=1;
            }
        }
        check_and_add(s,res,cnt);
        std::swap(cs,res);
        return cnt;
    }
};

////////////////////////
class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> s;
        for(int c=0;c<chars.size();){
            char cs = chars[c];
            int count = 0;
            while (c < chars.size() && chars[c] == cs) {
                count++;
                c++;
            }
            s.push_back(cs);
            if (count > 1) {
                string countS = to_string(count);
                for (char c : countS) {
                    s.push_back(c);
                }
            }
        }
        chars.clear();
        for(int i=0;i<s.size();i++){
            chars.push_back(s[i]);
        }
        return chars.size();
        
    }
};