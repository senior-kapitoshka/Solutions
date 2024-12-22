class Solution {
public:
    bool isPalindrome(string s) {
        char* str=(char*)malloc(s.size()*2);
        char* p=str;
        for(size_t i=0;i<s.size();++i){
            if(isalpha(s[i])|| isdigit(s[i])) *p++=tolower(s[i]);
        }
        *p='\0';
        int i=0,j=strlen(str)-1;
        while(i<j){
            if(str[i++]!=str[j--]){
                free(str);
                 return false;
                 }
        }
        free(str);
        return true;
    }
};

/////////////////////
class Solution {
public:
    bool pal(const string &str, int i, int j) {
        // Base case: if indices cross, it's a palindrome
        if (i >= j) {
            return true;
        }
        // Skip non-alphanumeric characters
        if (!isalnum(str[i])) {
            return pal(str, i + 1, j);
        }
        if (!isalnum(str[j])) {
            return pal(str, i, j - 1);
        }
        // Check if characters are equal (ignoring case)
        if (tolower(str[i]) != tolower(str[j])) {
            return false;
        }
        // Recursive check
        return pal(str, i + 1, j - 1);
    }

    bool isPalindrome(string s) {
        // Check palindrome with the cleaned string
        return pal(s, 0, s.size() - 1);
    }
};

///////////////////
class Solution {
public:
    bool isPalindrome(string s) {
        int start=0;
        int end=s.size()-1;
        while(start<=end){
            if(!isalnum(s[start])){
                start++;
                continue;
            }
            if(!isalnum(s[end])){
                end--;
                continue;
            }
            if(tolower(s[start])!=tolower(s[end])) return false;
            else{
                start++;
                end--;
            }
        }
        return true;
    }
};

/////////////////
