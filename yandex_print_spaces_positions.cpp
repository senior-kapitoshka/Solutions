#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
void PrintSpacesPositions(std::string& str) {
   for(size_t i=0;i<str.size();){
       auto it=find(str.begin()+i,str.end(),' ');
       if(it==str.end())break;
       i=std::distance(str.begin(),it);
       std::cout<<i<<"\n";
       ++i;
   }
}

int main() {
    using namespace std::literals;
   std::string str = "He said: one and one and one is three"s;
    PrintSpacesPositions(str);
    return 0;
}

///////////////////////
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void PrintSpacesPositions(string& str) {
    for (auto it = find(str.begin(), str.end(), ' '); 
         it != str.end(); it = find(next(it), 
         str.end(), ' ')) {
        cout << distance(str.begin(), it) << endl;
    }
}
