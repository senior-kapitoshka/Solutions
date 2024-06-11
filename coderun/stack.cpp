#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void st_or_st(std::vector<double>&vc, size_t sz){
    std::vector<double>stack;
    std::vector<double>stock;
    stack.reserve(sz);
    stock.reserve(sz);
    while(stock.size()!=sz){
        for(size_t i=0;i<sz;){
            if(stack.empty() && stock.empty()){
                if(i+1!=sz){
                    
                    if(vc[i]>vc[i+1]){
                        stack.insert(stack.begin(),1,vc[i]);
                        ++i;
                    }else if(vc[i]<vc[i+1]){
                        stock.push_back(vc[i]);
                        ++i;
                    }
                }else if(i+1==sz){
                    stock.push_back(vc[i]);
                    ++i;
                }
            }else if(stack.empty() && !stock.empty() && !vc.empty()){
               if(i+1!=sz){
                   
                    if(vc[i]>stock.back()){
                        std::cout<<"0";
                        return;
                    }
                    else if(vc[i]>vc[i+1] && vc[i]>stock.back()){
                        stack.insert(stack.begin(),1,vc[i]);
                        ++i;
                    }else if(vc[i]<vc[i+1] && vc[i]>stock.back()){
                        stock.push_back(vc[i]);
                        ++i;
                    }else{
                        std::cout<<"0\n";
                        return;
                    }
               }else if(i+1==sz){
                   stock.push_back(vc[i]);
                    ++i;
               }
            }else if(!stack.empty() && stock.empty() && !vc.empty()){
                
                if(i+1!=sz){
                    if(vc[i]>vc[i+1] && vc[i]<stack.front()){
                        stack.insert(stack.begin(),1,vc[i]);
                        ++i;
                    }else if((vc[i]<vc[i+1] && vc[i]>stack.front()) || (vc[i]>vc[i+1] && vc[i]>stack.front())){
                        stock.push_back(stack.front());
                        stack.erase(stack.begin());
                        stack.insert(stack.begin(),1,vc[i]);
                        ++i;
                    }else if(vc[i]<vc[i+1] && vc[i]<stack.front()){
                        stock.push_back(vc[i]);
                        ++i;
                    }else{
                        std::cout<<"0\n";
                        return;
                    }
                }
                else if(i+1==sz){
                    if(vc[i]<stock.back()){
                        std::cout<<"0\n";
                            return;
                    }else if(vc[i]>stack.front()){
                       stock.push_back(stack.front());
                        stack.erase(stack.begin());
                        stack.insert(stack.begin(),1,vc[i]);
                        ++i;
                   }else if(vc[i]<stack.front()){
                       stock.push_back(vc[i]);
                        ++i;
                    }
               }
            }else if(!stack.empty() && !stock.empty() && !vc.empty()){
                
                if(i+1!=sz){
                    if(vc[i]<stock.back()){
                        std::cout<<"0\n";
                            return;
                    }else if(vc[i]>stack.front() && vc[i]>stock.back()){
                        if(stack.front()>stock.back()){
                            stock.push_back(stack.front());
                            stack.erase(stack.begin());
                            stack.insert(stack.begin(),1,vc[i]);
                            ++i;
                        }else{
                            std::cout<<"0\n";
                            return;
                        }
                    }else if(vc[i]<stack.front() && vc[i]>stock.back()){
                        if(vc[i]<vc[i+1]){
                            stock.push_back(vc[i]);
                            ++i;
                        }
                        else if(vc[i]>vc[i+1]){
                            stack.insert(stack.begin(),1,vc[i]);
                            ++i;
                        }
                    }
                }else if(i+1==sz){
                    if(vc[i]<stock.back()){
                        std::cout<<"0\n";
                            return;
                    }else if(vc[i]>stack.front()){
                       stock.push_back(stack.front());
                        stack.erase(stack.begin());
                        stack.insert(stack.begin(),1,vc[i]);
                        ++i;
                   }else if(vc[i]<stack.front()){
                       stock.push_back(vc[i]);
                        ++i;
                    }
               }     
            }else if(!stack.empty() && !stock.empty() && vc.empty()){
                if(stack.front()>stock.back()){
                    stock.push_back(stack.front());
                    stack.erase(stack.begin());
                }else{
                    std::cout<<"0\n";
                        return;
                }
            }
        }
    }   
    std::cout<<"1\n";
        return;
    
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
        st_or_st(vc,sz);
        
    }

	return 0;
}