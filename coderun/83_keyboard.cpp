#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() 
{
    int n=0;
	std::cin>>n;
    std::vector<int>vc;
    vc.reserve(n+1);
    for(int i=0;i<n;++i){
        int x=0;
        std::cin>>x;
        vc.push_back(x);
    }
    int k=0;
    std::cin>>k;
    std::vector<int>kn;
    kn.reserve(k+1);
   for(int i=0;i<k;++i){
        int x=0;
        std::cin>>x;
        kn.push_back(x);
    }
    std::vector<std::string>vs(n,"NO");
    std::for_each(kn.begin(),kn.end(),[&vc,&vs](auto& i){
        i-=1;
       --vc[i];
        if(vc[i]<0) vs[i]="YES";
        else vs[i]="NO";
    });
    for(auto& p:vs){
        std::cout<<p<<"\n";
    }
	return 0;
}