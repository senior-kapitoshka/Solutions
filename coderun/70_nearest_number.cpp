#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() 
{
	int n=0;
    std::cin>>n;
    std::vector<int>st;
    for(int i=0;i<n;++i){
        int x=0;
        std::cin>>x;
        st.push_back(x);
    }
    int z=0;
    std::cin>>z;
    std::sort(st.begin(),st.end());
    
    if(z>=st.back()){
        std::cout<<st.back();
        return 0;
    }else if(z<=st.front()){
        std::cout<<st.front();
        return 0;
    }
    for(size_t i=1;i<st.size();++i){
        if(z==st[i-1] || z==st[i]){
            std::cout<<z;
            return 0;
        }else if(z<st[i] && z>st[i-1]){
            if((z-st[i])<(st[i-1]-z)){
                std::cout<<st[i-1];
                return 0;
            }else{
                std::cout<<st[i];
                return 0;
            }
        }
    }
	return 0;
}

