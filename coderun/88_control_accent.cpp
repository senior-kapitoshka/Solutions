#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

int main() 
{
    std::map<std::string,std::set<std::string>>mp;
    int n=0;
    std::cin>>n;
    for(int i=0;i<n;++i){
        std::string s,t;
        std::cin>>s;
        t=s;
        std::transform(t.begin(),t.end(),t.begin(),[](auto& c)
        {
            return tolower(c);
        });
        mp[t].insert(s);
    }
    int cnt=0;
    for(std::string w;std::getline(std::cin,w,' ');){
        std::string t;
        std::transform(w.begin(),w.end(),std::back_inserter(t),
            [](auto& c){
                return tolower(c);
            });
        
        if(!mp.count(t)){
            int up=std::count_if(w.begin(),w.end(),[]
            (auto& c){
                return isupper(c);
            });
            if(up!=1) ++cnt;
        }else if(mp.count(t)){
            if(!mp[t].count(w)){
                 ++cnt;
            }
        }
    }
    std::cout<<cnt<<"\n";
    
	return 0;
}

///////////////////
n = int(input())
accents = {}
for i in range(n):
    word = input()
    base_form = word.lower()
    if base_form not in accents:
        accents[base_form] = set()
    accents[base_form].add(word)

errors = 0
sent = input().split()
for word in sent:
    base_form = word.lower()
    if (base_form in accents and word not in accents[base_form]
            or len([l for l in word if l.isupper()]) != 1):
        errors += 1
print(errors)