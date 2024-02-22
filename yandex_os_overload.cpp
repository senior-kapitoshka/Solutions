#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <array>
#include <set>
using namespace std;

template<typename T>
std::ostream& operator<<(std::ostream& os,const std::vector<T>& c){
    //std::copy(c.begin(),c.end(),std::ostream_iterator<int>(os," "));
   for(size_t i=0;i<c.size();++i){
       os<<c[i];
       if(i!=c.size()-1) os<<", ";
   }
    return os;
}
template<typename T>
std::ostream& operator<<(std::ostream& os,const std::set<T>& c){
    //std::copy(c.begin(),c.end(),std::ostream_iterator<int>(os," "));
    size_t j=0;
   for(auto& i:c){
       os<<i;
       if(j!=c.size()-1) os<<", ";
       ++j;
   }
    return os;
}

int main() {
    const vector<int> ages = {10, 5, 2, 12};
    cout << ages << endl;
    const set<string> cats = {"Мурка"s, "Белка"s, "Георгий"s, "Рюрик"s};
cout << cats << endl;
    
    return 0;
}
////////////////////////////////
#include <iostream>
#include <set>
#include <vector>

using namespace std;

template <typename Element>
ostream& operator<<(ostream& out, const vector<Element>& container) {
    bool is_first = true;
    for (const auto& element : container) {
        if (!is_first) {
            out << ", "s;
        }
        is_first = false;
        out << element;
    }
    return out;
}

template <typename Element>
ostream& operator<<(ostream& out, const set<Element>& container) {
    bool is_first = true;
    for (const auto& element : container) {
        if (!is_first) {
            out << ", "s;
        }
        is_first = false;
        out << element;
    }
    return out;
}

int main() {
    const set<string> cats = {"Мурка"s, "Белка"s, "Георгий"s, "Рюрик"s};
    cout << cats << endl;
}

//////////////////////////////////
/////PRINT
/////////////////////
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

#if 0
template <typename ContainerType>
void Print(ostream& out, const ContainerType& c) {
    size_t j=0;
    for (auto &i:c) {
        if (j != sizeof(c)/sizeof(decltype(c.begin()))) {
            out << i << ", "s;
            ++j;
        } else {
            out << i;
        }
    }
}
#endif
template <typename ContainerType>
void Print(ostream& out, const ContainerType& container); 

template <typename Type>
ostream& operator<<(ostream& out, const vector<Type>& container) {
    Print(out, container);
    return out;
}

template <typename Type>
ostream& operator<<(ostream& out, const set<Type>& container) {
    Print(out, container);
    return out;
}

template <typename ContainerType>
void Print(ostream& out, const ContainerType& container) {
    for (auto it = container.begin(); it != container.end(); ++it) {
        if (next(it) != container.end()) {
            out << *it << ", "s;
        } else {
            out << *it;
        }
    }
}

int main() {
    const set<string> cats = { "Мурка"s, "Белка"s, "Георгий"s, "Рюрик"s };
    cout << cats << endl;

    const vector<int> ages = { 10, 5, 2, 12 };
    cout << ages << endl;
}