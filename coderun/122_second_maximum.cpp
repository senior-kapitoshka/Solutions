#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <functional>
#include <queue>

int main() 
{
    int x=std::numeric_limits<int>::min();
    std::priority_queue<int,std::vector<int>,std::less<int>>q;
    while(x!=0){
        std::cin>>x;
         q.push(x);
    }
    if(q.size()==1) std::cout<<q.top()<<"\n";
    else{
        int nx=q.top();
        q.pop();
        while(nx==q.top()){
            q.pop();
        }
        std::cout<<q.top()<<"\n";
    }

	return 0;
}