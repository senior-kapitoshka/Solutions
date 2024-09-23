//прошло
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>


std::string calculate_shift(const std::string& word) {
    if (word.empty()) return "";

    std::stringstream ss;
    for (size_t i = 1; i < word.size(); ++i) {
        int shift = (word[i] - word[i - 1] + 26) % 26;
        ss << shift << ',';
    }
    return ss.str();
}


int main() 
{
	std::string s;
    std::getline(std::cin,s);
    std::map<size_t,std::map<std::string,std::string>>vv;
    std::stringstream ss(s);
    for(std::string w;std::getline(ss,w,' ');){
        vv[w.size()][calculate_shift(w)]=w;
    }
    int n;
    std::cin>>n;
    std::getchar();
    std::vector<std::string>vs;
    vs.reserve(n);
    for(int i=0;i<n;++i){
        std::string s;
        std::getline(std::cin,s);
        vs.push_back(s);
    }
    std::vector<std::string>res;
    res.reserve(vs.size());
    std::transform(vs.begin(),vs.end(),std::back_inserter(res),
        [&vv](auto& s){
            std::string calc=calculate_shift(s);
            return vv[s.size()][calc];
        });
    for(auto i:res) std::cout<<i<<"\n";

	return 0;
}


#if 0
//3 из 39
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std::literals;



struct S{
    std::string s;
    size_t sz;
    std::vector<int>cd;
    std::vector<int>ap;
};

S transforming(std::string s){
    const std::string alph ="abcdefghijklmnopqrstuvwxyz"s;
    std::map<char,int>mp;
    std::vector<int>vst;
    std::vector<int>a;
    for(int i=0;i<s.size();++i){
        if(!mp.count(s[i])){
            mp[s[i]]=i;
            vst.push_back(i);
        }else{
            vst.push_back(mp[s[i]]);
        }
        a.push_back(alph.find(s[i]));
    }
    return S{s,s.size(),vst,a};
}

int main() 
{
	std::string s;
    std::getline(std::cin,s);
    std::vector<S>vv;
    std::stringstream ss(s);
    for(std::string w;std::getline(ss,w,' ');){
        vv.push_back(transforming(w));
    }
    int n;
    std::cin>>n;
    std::getchar();
    std::vector<std::string>vs;
    vs.reserve(n);
    for(int i=0;i<n;++i){
        std::string s;
        std::getline(std::cin,s);
        vs.push_back(s);
    }
    std::vector<std::string>res;
    res.reserve(vs.size());
    std::transform(vs.begin(),vs.end(),std::back_inserter(res),
        [&vv](auto& s){
            const std::string alph ="abcdefghijklmnopqrstuvwxyz"s;
            std::map<char,int>mp;
            std::vector<int>vst;
            std::vector<int>a;
            for(int i=0;i<s.size();++i){
                if(!mp.count(s[i])){
                    mp[s[i]]=i;
                    vst.push_back(i);
                }else{
                    vst.push_back(mp[s[i]]);
                    
                }
                    a.push_back(alph.find(s[i]));
            }
            auto it=std::find_if(vv.begin(),vv.end(),[sz=s.size(),&vst,&a](auto c){
                if(c.sz!=sz) return false; 
                bool flag=true;
                for(int i=1;i<a.size();++i){
                    if(std::abs(a[i-1]-c.ap[i-1])==std::abs(a[i]-c.ap[i])) continue;
                    else if(std::abs(a[i-1]-c.ap[i-1])==std::abs(a[i]-c.ap[i])) return false;
                }
                return c.sz==sz && c.cd==vst && flag;
            });
            return it->s;
        });
    for(auto i:res) std::cout<<i<<"\n";

	return 0;
}

#endif
#if 0
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std::literals;


std::string calculate_shift(const std::string& word) {
    if (word.empty()) return "";

    std::stringstream ss;
    for (size_t i = 1; i < word.size(); ++i) {
        int shift = (word[i] - word[i - 1] + 26) % 26;
        ss << shift << ',';
    }
    return ss.str();
}


struct S{
    std::string s;
    size_t sz;
    std::string calc;
};

S transforming(std::string s){
    return S{s,s.size(),calculate_shift(s)};
}

int main() 
{
	std::string s;
    std::getline(std::cin,s);
    std::vector<S>vv;
    std::stringstream ss(s);
    for(std::string w;std::getline(ss,w,' ');){
        vv.push_back(transforming(w));
    }
    int n;
    std::cin>>n;
    std::getchar();
    std::vector<std::string>vs;
    vs.reserve(n);
    for(int i=0;i<n;++i){
        std::string s;
        std::getline(std::cin,s);
        vs.push_back(s);
    }
    std::vector<std::string>res;
    res.reserve(vs.size());
    std::transform(vs.begin(),vs.end(),std::back_inserter(res),
        [&vv](auto& s){
            std::string calc=calculate_shift(s);
            auto it=std::find_if(vv.begin(),vv.end(),[sz=s.size(),calc](auto c){
                return c.sz==sz && c.calc==calc;
            });
            return it->s;
        });
    for(auto i:res) std::cout<<i<<"\n";

	return 0;
}

#endif

#if 0
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std::literals;


std::string calculate_shift(const std::string& word) {
    if (word.empty()) return "";

    std::stringstream ss;
    for (size_t i = 1; i < word.size(); ++i) {
        int shift = (word[i] - word[i - 1] + 26) % 26;
        ss << shift << ',';
    }
    return ss.str();
}


struct S{
    std::string s;
    std::string calc;
};

S transforming(std::string s){
    return S{s,calculate_shift(s)};
}

int main() 
{
	std::string s;
    std::getline(std::cin,s);
    //std::vector<S>vv;
    std::map<size_t,std::vector<S>>vv;
    std::stringstream ss(s);
    for(std::string w;std::getline(ss,w,' ');){
        vv[w.size()].push_back(transforming(w));
    }
    int n;
    std::cin>>n;
    std::getchar();
    std::vector<std::string>vs;
    vs.reserve(n);
    for(int i=0;i<n;++i){
        std::string s;
        std::getline(std::cin,s);
        vs.push_back(s);
    }
    std::vector<std::string>res;
    res.reserve(vs.size());
    std::transform(vs.begin(),vs.end(),std::back_inserter(res),
        [&vv](auto& s){
            std::string calc=calculate_shift(s);
            auto it=std::find_if(vv[s.size()].begin(),vv[s.size()].end(),[calc](auto c){
                return c.calc==calc;
            });
            return it->s;
        });
    for(auto i:res) std::cout<<i<<"\n";

	return 0;
}
#endif


#if 0

//4 из 39//////////////////////
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

constexpr int kBase = 27;
constexpr int kMod = 1e9 + 7;


int calculate_shift(const string& word) {
    if (word.empty()) return 0;

    int shift = 0;
    for (size_t i = 1; i < word.size(); ++i) {
        int diff = (word[i] - word[i - 1] + 26) % 26;
        shift = (shift * kBase + diff) % kMod;
    }
    return shift;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<int, vector<vector<string>>> words;
    string line;
    getline(cin, line);
    istringstream iss(line);
    string word;
    while (iss >> word) {
        int shift = calculate_shift(word);
        if (words.find(shift) == words.end()) {
            words[shift] = vector<vector<string>>(101);
        }
        words[shift][word.size()].push_back(word);
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> word;
        int shift = calculate_shift(word);
        int length = word.size();
        if (words.find(shift) != words.end() && !words[shift][length].empty()) {
            cout << words[shift][length][0] << endl;
        }
    }
    return 0;
}
#endif

#if 0
///29 из 39///////////////////
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

string calculate_shift(const string& word) {
    if (word.empty()) return "";

    stringstream ss;
    for (size_t i = 1; i < word.size(); ++i) {
        int shift = (word[i] - word[i - 1] + 26) % 26;
        ss << shift << ',';
    }
    return ss.str();
}

int main() {
    unordered_map<string, unordered_map<int, vector<string>>> words;
    string line;
    getline(cin, line);
    istringstream iss(line);
    string word;
    while (iss >> word) {
        words[calculate_shift(word)][word.size()].push_back(word);
    }
    /*for(auto i: words){
        std::cout<<i.first<<"-";
        for(auto j:i.second){
            std::cout<<j.first<<"-";
            for(auto z:j.second){
                std::cout<<z<<",";
            }
            std::cout<<"\n";
        }
        std::cout<<"\n";
    }*/
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> word;
        string shift = calculate_shift(word);
        int length = word.size();
        if (words.find(shift) != words.end() && words[shift].find(length) != words[shift].end()) {
            cout << words[shift][length][0] << endl;
        }
    }
    return 0;
}
#endif
