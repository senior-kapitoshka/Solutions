//fail closed tests
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

int main() 
{
	std::string s;
    int x,y;
    std::cin>>x>>y;
    std::cin>>s;

    int i=0;
    int j=0;
    std::pair<int,int>res={-1,-1};
    std::unordered_map<char,std::vector<int>>mp; 
    while(j<x){
        if(mp[s[j]].size()<y){
            mp[s[j]].push_back(j);
        }else{
            if(res.first<j-i){
                res.first=j-i;
                res.second=i;
            }
            i=mp[s[j]].back();
            j=i;
            mp.clear();
        }
        ++j;
    }
    
    std::cout<<res.first<<" "<<res.second+1<<"\n";
	return 0;
}

///////////////////////////////
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;



int main() {
    int x, y;
    cin >> x >> y;
    string s;
    cin >> s;

    std::pair<int,int> res;
    size_t j = 0;
    unordered_map<char, int> mp;

    for (int i = 0; i < x; ++i) {
        while (j < x && mp[s[j]] < y) {
            ++mp[s[j]];
            ++j; 
        }
        if (res.first <j - i ) {
            res.first=j-i;
            res.second=i;
        }
        --mp[s[i]];
    }
    std::cout<<res.first<<" "<<res.second+1<<"\n";

    return 0;
}