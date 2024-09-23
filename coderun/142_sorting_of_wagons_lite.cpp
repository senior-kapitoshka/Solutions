#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() 
{
	std::vector<int>t;
    int n=0;
    std::cin>>n;
    t.reserve(n);
    for(int i=0;i<n;++i){
        int x;
        std::cin>>x;
        t.push_back(x);
    }
    std::vector<int>st;
    std::vector<int>res;
    for(int i=0;i<n;){
        if(st.empty() || st.back()>t[i]){
            st.push_back(t[i]);
            ++i;
        }
        else if(st.back()<t[i]){
            res.push_back(st.back());
            st.pop_back();
        }
    }
    if(!st.empty()){
        std::copy(st.rbegin(),st.rend(),std::back_inserter(res));
    }
    if(std::is_sorted(res.begin(),res.end())) std::cout<<"YES\n";
    else std::cout<<"NO\n";

	return 0;
}