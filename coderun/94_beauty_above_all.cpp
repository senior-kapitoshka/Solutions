//6 of 19

#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() 
{
	int n,m;
    std::cin>>n>>m;
    std::vector<int>vc;
    std::map<int,int>mp;
    vc.reserve(n);
    for(int i=0;i<n;++i){
        int x;
        std::cin>>x;
        vc.push_back(x);
        ++mp[x];
    }
    int i=0;
    int j=n-1;
    int mn=n;
    while(i<j){
        if(mp[vc[i]]>1){
            --mp[vc[i]];
            ++i;
        }
        if(mp[vc[j]]>1){
            --mp[vc[j]];
            --j;
        }
        if(mp[vc[i]]==1 && mp[vc[j]]==1) break;
    }
    std::cout<<i+1<<" "<<j+1<<'\n';

	return 0;
}


////////////
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

int main() 
{
	int n,m;
    std::cin>>n>>m;
    std::vector<int>vc;
    vc.reserve(n);
    for(int i=0;i<n;++i){
        int x;
        std::cin>>x;
        vc.push_back(x);
    }
    std::pair<int,int> res={-1,-1};
    std::unordered_map<int,int>mp;
    int dist = 0;
    int mn = n+1;
    int i=0;
    for(int j=0;j<n;++j){
        ++mp[vc[j]];
        if (mp[vc[j]] == 1) dist++;

        while (dist == m) {
            if (j - i + 1 < mn) {
                mn = j - i + 1;
                res = {i + 1, j + 1};
            }
            --mp[vc[i]];
            if (mp[vc[i]] == 0) dist--;
            ++i;
        }
    }
    
    std::cout<<res.first<<" "<<res.second<<'\n';

	return 0;
}
