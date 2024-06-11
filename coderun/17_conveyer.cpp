#if 0 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

bool st_or_st(std::vector<double>&vc){ 
    if(vc.empty() || vc.size()==1 || vc.size()==2) return true;
    bool res=true;
    for(size_t i=0;i<vc.size()-2;++i){
        if(vc[i]==vc[i+1] && vc[i]==vc[i+2]) continue;
        else if(vc[i]<vc[i+1] && vc[i]>vc[i+2] && vc[i+1]>vc[i+2]){
            res=false;
            break;
        }
            
    }
    return res;
}

int main() 
{
    size_t tests=0;
    size_t sz=0;
    std::cin>>tests;
    for(size_t i=0;i<tests;++i){
        std::cin>>sz;
        std::vector<double>vc(sz);
        for(size_t j=0;j<sz;++j){
            std::cin>>vc[j];
        }
        if(st_or_st(vc)) std::cout<<"1\n";
        else std::cout<<"0\n";
        
    }

	return 0;
}

////////////////////////////
#endif
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

bool st_or_st(std::vector<double>&vc){ 
    if(vc.empty() || vc.size()==1 || vc.size()==2) return true;
    bool res=true;
    std::vector<double>stack;
    std::vector<double>stock;
    for(size_t i=0;i<vc.size()-2;){
        if(vc[i]<vc[i+1] && vc[i]>vc[i+2] ){
            res=false;
            break;
        }
        else if((vc[i]>=vc[i+1] && vc[i]<=vc[i+2]) || (vc[i]>=vc[i+1] && vc[i]>=vc[i+2])){
            if(stack.empty()){
                stack.insert(stack.begin(),1,vc[i]);
                ++i;
            }
            else{
                if(stack.front()>vc[i]){
                    stack.insert(stack.begin(),1,vc[i]);
                    ++i;
                }else{
                    stock.push_back(stack.front());
                    stack.erase(stack.begin());
                    
                }
            }
        }else if(vc[i]<=vc[i+1] && vc[i]<=vc[i+2]){
            if(stock.empty()){
                stock.push_back(vc[i]);
                ++i;
            }
            else{
                if(stock.back()<vc[i] && !stack.empty() && stack.front()>vc[i]){
                    stock.push_back(vc[i]);
                    ++i;
                }else if(stock.back()<vc[i] && stack.empty()){
                    stock.push_back(vc[i]);
                    ++i;
                }else if(stock.back()<vc[i] && !stack.empty() && stack.front()<vc[i]){
                     stock.push_back(stack.front());
                    stack.erase(stack.begin());
                    
                }else if(stock.back()>vc[i]){
                    res=false;
                    break;
                }
            }
        }
            
    }
    return res;
}

int main() 
{
    size_t tests=0;
    size_t sz=0;
    std::cin>>tests;
    for(size_t i=0;i<tests;++i){
        std::cin>>sz;
        std::vector<double>vc(sz);
        for(size_t j=0;j<sz;++j){
            std::cin>>vc[j];
        }
        if(st_or_st(vc)) std::cout<<"1\n";
        else std::cout<<"0\n";
        
    }

	return 0;
}
