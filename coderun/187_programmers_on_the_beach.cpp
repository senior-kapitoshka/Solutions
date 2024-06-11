#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <execution>

int main() 
{
	int ts=0;
    size_t all=0;

    std::cin>>ts;
    for(int i=0;i<ts;++i){
        std::cin>>all;
        std::vector<int> vc(all);
        for(size_t j=0;j<all;++j){
            std::cin>>vc[j];
        }
        std::sort(vc.begin(),vc.end());
        int mn=std::numeric_limits<int>::max();
        std::for_each(vc.begin(),prev(vc.end()),
            [&mn,&vc,k=0](auto& c)mutable
        {
            mn=std::min(mn,c^vc[k+1]);
            ++k;
        });
        std::cout<<mn<<"\n";
    }
    
	return 0;
    
}