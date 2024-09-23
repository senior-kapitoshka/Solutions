#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool bin_sr(const std::vector<long long>&vn, long long x){
    int i=0;
    int j=(int)vn.size()-1;
    while(i<=j){
        int m=(i+j)/2;
        if(x==vn[m]) return true;
        if(x>vn[m]){
            i=m+1;
        }else if(x<vn[m]){
            j=m-1;
        }
    }
    return false;
}

int main() 
{
	int n,k;
    std::cin>>n>>k;
    std::vector<long long>vn,vk;
    vn.reserve(n);
    vk.reserve(k);
    for(int i=0;i<n;++i){
        int x;
        std::cin>>x;
        vn.push_back(x);
    }
    for(int i=0;i<k;++i){
        int x;
        std::cin>>x;
        vk.push_back(x);
    }
    std::sort(vn.begin(),vn.end());
    for(auto i:vk){
        if(bin_sr(vn,i)) std::cout<<"YES\n";
        else std::cout<<"NO\n";
    }

	return 0;
}