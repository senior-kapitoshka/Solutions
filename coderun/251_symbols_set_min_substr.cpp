//pass 13 of 92

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <limits>

int main() 
{
    std::string s,x;
	std::cin>>s>>x;
    size_t min=std::numeric_limits<int>::max();
    for(size_t i=0;i<s.size();++i){
        for(size_t j=i;j<=s.size();++j){
            std::string t=s.substr(i,j);
            std::set<char> st(t.begin(),t.end());
            if(std::all_of(x.begin(),x.end(),[&st](auto& c)
            {
                return st.count(c);
            })) min=std::min(min,t.size());
        }
    }
    if(min!=std::numeric_limits<int>::max())std::cout<<min;
    else std::cout<<0;

	return 0;
}

/////////////
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <limits>

void check(std::string& s,std::string& letters ){
    std::string n;
     int min = -1;
    for (char i: s) {
        if (letters.find(i) == std::string::npos) {
            n = "";
            continue;
        }
        n += i;
        int flag = 0;
        int min_position = n.size();
        for (char j: letters) {
            int position = n.find_last_of(j);
            if (position != std::string::npos) {
                flag++;
                if (position < min_position) {
                    min_position = position;
                }
            }
        }
        if (flag == letters.size()) {
            n.erase(0, min_position);
            if (min == -1) {
                min = n.size();
            } else {
                min = std::min(min, (int) n.size());
            }
        }
    }
    if(min==-1) std::cout<<0;
    else std::cout<<min<<"\n";
}

int main() 
{
    std::string s,x;
	std::cin>>s>>x;
    check(s,x);

	return 0;
}