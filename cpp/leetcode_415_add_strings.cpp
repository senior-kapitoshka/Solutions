class Solution {
public:
    void add(std::string& r,std::string &s){
        int i=s.size()-1;
        int c=0;
        std::for_each(r.rbegin(),r.rend(),[&i,&s,&c](auto& curr)mutable{

            if(i>=0){
                int t=(curr-'0'+s[i]-'0'+c)%10;
                c=(curr-'0'+s[i]-'0'+c)/10;
                curr=t+'0';
            }else if(i<0){
                int t=(curr-'0'+c)%10;
                c=(curr-'0'+c)/10;
                curr=t+'0';
            }
            --i;
        });
        if(c>0) {
            r=std::to_string(c)+r;
        }
    }
    string addStrings(string n1, string n2) { 
        std::string res;
        if(n1.size()>=n2.size()){
            add(n1,n2);
        }else{
            add(n2,n1);
        }
        return n1.size()>=n2.size()?n1:n2;
    }
};

///////////////////////////
class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1[0] == '0') {
            return num2;
        } else if (num2[0] == '0') {
            return num1;
        }
        string result;
        int carry = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        while (i >= 0 || j>= 0 || carry) {
            int sum = carry;

            if (i >= 0) {
                sum += num1[i] - '0';
                --i;
            }

            if (j >= 0) {
                sum += num2[j] - '0';
                --j;
            }

            int digit = sum % 10;
            carry = sum / 10;
            result += digit + '0';
        }
        
        std::reverse(result.begin(), result.end());
        return result;
    }
};