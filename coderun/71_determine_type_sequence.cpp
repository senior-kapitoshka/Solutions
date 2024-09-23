
//5 тестов
#include <iostream>
#include <string>
#include <vector>

int main() 
{
	std::vector<long long>vl;
    long long y;
    while(true){
        std::cin>>y;
        if(y==-2000000000) break;
        vl.push_back(y);
    }
    int x=0;
    for(size_t i=1;i<vl.size();++i){
        if((vl[i]==vl[i-1] && x==0 && x!=1 && x!=-1) ||
            (vl[i]==vl[i-1] && x==2 && x!=1 && x!=-1)||
            (vl[i]==vl[i-1] && x==-2 && x!=1 && x!=-1)){
            continue;
        }else if(vl[i]==vl[i-1] && x==1){
            ++x;
        }else if(vl[i]==vl[i-1] && x==-1){
            --x;
        }else if(vl[i]>vl[i-1] && x==0){
            ++x;
        }else if(vl[i]<vl[i-1] && x==0){
            --x;
        }else if((vl[i]>vl[i-1] && x==1) || (vl[i]>vl[i-1] && x==2)){
            continue;
        }else if((vl[i]<vl[i-1] && x==-1) || (vl[i]<vl[i-1] && x==-2)){
            continue;
        }else if((vl[i]<vl[i-1] && x==1) ||
            (vl[i]>vl[i-1] && x==-1) ||
            (vl[i]>vl[i-1] && x==-2)||
            (vl[i]<vl[i-1] && x==2)){
            x=5;
        }
        
    }
        switch(x){
            case 0:std::cout<<"CONSTANT";
                break;
            case 1:std::cout<<"ASCENDING";
                break;
            case -1:std::cout<<"DESCENDING";
                break;
             case 2:std::cout<<"WEAKLY ASCENDING";
                break;
             case -2:std::cout<<"WEAKLY DESCENDING";
                break;
            case 5:std::cout<<"RANDOM";
                break;
        }
    return 0;
}

////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>

int main() 
{
	std::vector<long long>vl;
    long long y;
    while(true){
        std::cin>>y;
        if(y==-2000000000) break;
        vl.push_back(y);
    }
    std::string type;
    for(size_t i=1;i<vl.size();++i){
        const long long previous = vl[i - 1];
        const long long current = vl[i];
    if (type.empty()) {
      if (current < previous) type = "DESCENDING";
      else if (current == previous) type = "CONSTANT";
      else type = "ASCENDING";
    } else if (type == "CONSTANT") {
      if (current < previous) type = "WEAKLY DESCENDING";
      else if (current > previous) type = "WEAKLY ASCENDING";
    } else if (type == "ASCENDING") {
      if (current < previous) type = "RANDOM";
      else if (current == previous) type = "WEAKLY ASCENDING";
    } else if (type == "WEAKLY ASCENDING") {
      if (current < previous) type = "RANDOM";
    } else if (type == "DESCENDING") {
      if (current == previous) type = "WEAKLY DESCENDING";
      else if (current > previous) type = "RANDOM";
    } else if (type == "WEAKLY DESCENDING") {
      if (current > previous) type = "RANDOM";
    }
  }
    std::cout<<type<<"\n";
    return 0;
}