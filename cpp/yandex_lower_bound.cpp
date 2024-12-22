//////////////*
6 11
1 1 4 4 8 120 
1 2 3 4 5 6 7 8 63 64 65 


10 10
-5 1 1 3 5 5 8 12 13 16 
0 3 7 -17 23 11 0 11 15 7 

*////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main(){
    int n,k;
    std::vector<int>vc1,res;
    std::cin>>n>>k;
    vc1.reserve(n);
    res.reserve(k);
    for(int i=0;i<n;++i){
        int x;
        std::cin>>x;
        vc1.push_back(x);
    }
    for(int i=0;i<k;++i){
        int x;
        std::cin>>x;
        auto it=std::lower_bound(vc1.begin(),vc1.end(),x);
        if(it==vc1.end())res.push_back(vc1.back());
        else if(it!=vc1.end()){
            if(it==vc1.begin()){
                res.push_back(vc1.front());
            }else{
                if(abs(x-*it)<abs(x-*prev(it))){
                    res.push_back(*(it));
                }else{
                    res.push_back(*prev(it));
                }
            }
        }
    }
    for(auto i:res){
        std::cout<<i<<"\n";
    }
}