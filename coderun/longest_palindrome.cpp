#include <iostream>

#include <vector>


bool checkPal(std::vector<int> &s, int low, int high) {
    while (low < high) {
        if (s[low] != s[high])
            return false;
        low++;
        high--;
    }
    return true;
}


int longestPalindrome(std::vector<int>& s) {
  
    int n = s.size();

    int maxLen = 1, start = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (checkPal(s, i, j) && (j - i + 1) > maxLen) {
                start = i;
                maxLen = j - i + 1;
            }
        }
    }

    return maxLen;
}

int main() {
    std::vector<int> s;
    int n=0;
    std::cin>>n;
    s.reserve(n);
    for(int i=0;i<n;++i){
        int x=0;
        std::cin>>x;
    	s.push_back(x);
    }
    int res=longestPalindrome(s);
    res==1? std::cout<<0 : std::cout << res ;
    return 0;
}
