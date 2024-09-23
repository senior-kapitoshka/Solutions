#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

int main() 
{
	std::deque<int>f,s;
    for(int i=0;i<5;++i){
        int x=0;
        std::cin>>x;
        f.push_back(x);
    }
    for(int i=0;i<5;++i){
        int x=0;
        std::cin>>x;
        s.push_back(x);
    }

    int cnt=0;
    while(!f.empty() || !s.empty() || cnt>=1000000){
        if(f.front()>s.front() && ((f.front()!=0 && f.front()!=9) || 
            (s.front()!=0 && s.front()!=9))){
            f.push_back(f.front());
            f.push_back(s.front());
            f.pop_front();
            s.pop_front();
            ++cnt;
            if(s.empty()) break;
            
        }else if(f.front()<s.front() && ((f.front()!=0 && f.front()!=9) || 
            (s.front()!=0 && s.front()!=9))){
                s.push_back(f.front());
            s.push_back(s.front());
            
            f.pop_front();
            s.pop_front();
            ++cnt;
            if(f.empty()) break;
            
            
        }else if(f.front()==9 && s.front()==0){
            s.push_back(f.front());
            s.push_back(s.front());
            
            f.pop_front();
            s.pop_front();
            ++cnt;
            if(f.empty()) break;
            
        }else if(f.front()==0 && s.front()==9){
            
            f.push_back(f.front());
            f.push_back(s.front());
            f.pop_front();
            s.pop_front();
            ++cnt;
            
            if(s.empty()) break;
             
            
        }else{
             f.push_back(f.front());
            s.push_back(s.front());
            f.pop_front();
            s.pop_front();
            
        }
    }
    if(f.empty()) std::cout<<"second "<<cnt<<"\n";
    else if(s.empty()) std::cout<<"first "<<cnt<<"\n";
    else if(cnt>=1000000) std::cout<<"botva\n";

	return 0;
}