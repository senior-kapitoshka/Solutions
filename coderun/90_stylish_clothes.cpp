//3 из 50
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <limits>
#include <algorithm>

int main() 
{
    int n=0;
	std::cin>>n;
    std::set<int>f;
    for(int i=0;i<n;++i){
        int x;
        std::cin>>x;
        f.insert(x);
    }
    int m=0;
	std::cin>>m;
    std::set<int>s;
    for(int i=0;i<m;++i){
        int x;
        std::cin>>x;
        s.insert(x);
    }
    std::vector<int>res;
    std::set_intersection(f.begin(),f.end(),s.begin(),s.end(),std::back_inserter(res));
    if(!res.empty()) std::cout<<res.front()<<" "<<res.front();
    else{
        int mn=std::numeric_limits<int>::max();
        std::pair<int,int>r;
        std::for_each(f.begin(),f.end(),[&s,&r,&mn](auto& c){
            int lb=*s.lower_bound(c);
            int ub=*s.upper_bound(c);
            if(c-lb<mn){
                mn=c-lb;
                r={c,lb};
            }
            if(c-ub<mn){
                mn=c-ub;
                r={c,ub};
            }
        });
        std::cout<<r.first<<" "<<r.second;
    }


	return 0;
}

/////////////////////////////
//17 из 50
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <limits>
#include <algorithm>

int main() 
{
    int n=0;
	std::cin>>n;
    std::vector<int>f;
    for(int i=0;i<n;++i){
        int x;
        std::cin>>x;
        f.push_back(x);
    }
    int m=0;
	std::cin>>m;
    std::vector<int>s;
    for(int i=0;i<m;++i){
        int x;
        std::cin>>x;
        s.push_back(x);
    }
    std::pair<int,int>res;
    int mx=std::max(n,m);
    int i=0;int j=0;
    int mn=std::numeric_limits<int>::max();
    while (i <= mx && j <= mx) {
    if (f[i] == s[j]){ 
        std::cout<<f[i]<<" "<<s[j];
        return 0;
    }
    const int diff = std::abs(f[i] - s[j]);

    if (mn > diff) {
      mn = diff;
      res = {f[i],s[j]};
    }

    if (f[i] < s[j]) {
      ++i;
    } else {
      ++j;
    }
  }
  std::cout<<res.first<<" "<<res.second;

	return 0;
}

///////////////////
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct{
    int minimum, Tshirt, pants;
} help;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n;
    vector<int> Tshirts(n);
    for (int i = 0; i < n; i++)
        cin >> Tshirts[i];
    cin >> m;
    vector<int> pants(m);
    vector<int>::iterator iter = Tshirts.begin();;
    help answer;
    answer.minimum = 10000001;
    for (int i = 0; i < m; i++){
        cin >> pants[i];
        while ((*iter) < pants[i] && iter != Tshirts.end())
            iter++;
        if (answer.minimum > abs(pants[i] - (*iter))){
            answer.minimum = abs(pants[i] - (*iter));
            answer.Tshirt = (*iter);
            answer.pants = pants[i];
        }
        iter != Tshirts.begin() ? iter-- : iter = iter;
        if (answer.minimum > abs(pants[i] - (*iter))){
            answer.minimum = abs(pants[i] - (*iter));
            answer.Tshirt = (*iter);
            answer.pants = pants[i];
        }
    }
    cout << answer.Tshirt << " " << answer.pants;
}