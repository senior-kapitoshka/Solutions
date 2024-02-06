#include <algorithm>
int longest_palindrome(const std::string &s)
{
    int maxlen = 0;
    for ( int i = 0; i < s.size(); ++i )
    for ( int j = 0; j < s.size(); ++j )
    {
      std::string sub = s.substr(i, s.size()-j);
      std::string rev = sub;
      std::reverse ( rev.begin(), rev.end());
      
      if ( sub == rev )
        maxlen = sub.size() > maxlen ? sub.size() : maxlen;
    }
    
    
    return maxlen;
}
///////////////////////
bool isPalindrome(const std::string &s)
{
    return std::equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
}

int longest_palindrome(const std::string &s)
{
    int res = 0;
    for (std::size_t i = 0; i < s.size(); ++i)
        for (int j = 1; j + i <= s.size(); ++j)
            if (isPalindrome({s.begin() + i, s.begin() + i + j}))
                res = std::max(res, j);
    return res;
}
///////////////////
