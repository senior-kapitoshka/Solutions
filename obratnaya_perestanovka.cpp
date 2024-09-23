
#include <iostream>
#include <vector>


int main(){
    int n;
    std::cin>>n;
    std::vector<int>vc;
    std::vector<int>res(n);
    vc.reserve(n);
    for(int i=0;i<n;++i){
        int x;
        std::cin>>x;
        vc.push_back(x);
    }
    for(int i=0;i<n;++i){
        res[vc[i]-1]=i+1;
    }
    for(auto i:res) std::cout<<i<<' ';
}

////////////////////
#include <iostream>
#include <vector>
 
int main() {
    int n;
    std::cin >> n;
 
    std::vector<int> seats(n);
    for (int guest = 1; guest <= n; ++guest) {
        int seat;
        std::cin >> seat;
        seats[seat - 1] = guest;
    }
 
    for (int guest : seats) {
        std::cout << guest << " ";
    }
    std::cout << "\n";
}