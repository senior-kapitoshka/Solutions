#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

int main() 
{
	std::vector<long long>vc;
    for(std::string i;std::getline(std::cin,i,' ');){
        if(i.front()=='-'|| isdigit(i.front())){
            int x=std::stoll(i);
        vc.push_back(x);
        }
    }
    std::sort(vc.begin(),vc.end());
    if((*vc.begin()*(*next(vc.begin())))>=((*prev(vc.end()))*(*prev(prev(vc.end())))))
            std::cout<<*vc.begin()<<" "<<(*next(vc.begin()))<<"\n";
    else 
        std::cout<<(*prev(prev(vc.end())))<<" "<<(*prev(vc.end()))<<"\n";
	return 0;
}