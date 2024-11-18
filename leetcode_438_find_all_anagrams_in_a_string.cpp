
//33 of 65 time limit exceeded
class Solution {
public:
    template<typename It>
    bool check(It cb,It ce,It b,It e){
        std::multiset<typename It::value_type>st(cb,ce);
        std::multiset<typename It::value_type>st2(b,e);
        return st==st2;
    }
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size()) return {};
        std::vector<int>res;
        res.reserve(s.size());
        for(size_t i=0;i<s.size()-p.size()+1;){
            if(check(s.begin()+i,s.begin()+i+p.size(),
                p.begin(),p.end())){
                    res.push_back(i);
                    while(s[i]==s[i+p.size()]){
                        ++i;
                        res.push_back(i);
                    }
                }
            ++i;    
        }
        return res;
    }
};

//////////////////////////////
class Solution {
private:
    std::string s_,p_;    
public:
    bool check(size_t i,size_t j,const std::vector<int>& vc1){
        std::vector<int>vc2(26,0);
        for(size_t x=i;x<=j;++x){
            ++vc2[s_[x]-97];
        }
        return vc1==vc2;
    }
    vector<int> findAnagrams(string s, string p) {
        s_=s;
        p_=p;
        int hs1=0,hs2=0;
        std::vector<int>vc1(26,0);
        for(size_t i=0;i<p.size();++i){
            hs2+=s[i]-97;
            hs1+=p[i]-97;
            ++vc1[p[i]-97];
        }
        int i=0;
        std::vector<int>res;
        res.reserve(s.size());
        if(hs1==hs2 && check(i,p.size()-1,vc1))
            res.push_back(0);
        for(size_t j=p.size();j<s.size();++j){
            hs2+=s[j]-s[i++];
            if(hs2!=hs1) continue;
            else{
                if(check(i,j,vc1)) res.push_back(i);
            }
        }
        return res;
    }
};
