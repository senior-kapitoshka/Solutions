#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

struct tmplt{
    std::string tmp;
    std::string cntr;
    std::vector<char>dig;
    int x;
};

int main() 
{
    std::vector<std::vector<char>>vn;
    std::vector<tmplt>vm;
    bool flag=false;
    for(std::string s;std::getline(std::cin,s);){
	    std::stringstream ss(s);
        for(std::string w;std::getline(ss,w);){
            if(w.size()==1 && !flag){
                flag=true;
                int n=std::stoi(w);
                vn.reserve(n);
            }else if(w.size()==1 && flag){
                flag=false;
                int m=std::stoi(w);
                vm.reserve(m);
            }else if(w.size()>1 && flag){
                std::vector<char>t;
                for(auto i:w){
                    if(isdigit(i)){
                        t.push_back(i);
                    }
                }
                vn.push_back(t);
            }else if(w.size()>1 && !flag){
                std::vector<char>t;
                int c=0;
                for(auto i:w){
                    if(isdigit(i)){
                        t.push_back(i);
                    }else if(i=='X'){
                        ++c;
                    }
                }
                vm.push_back(tmplt{w.substr(0,w.find('-')-1),w.substr(w.find('-')+2),t,c});
            }
        }
    }
    std::vector<std::string>res;
    res.reserve(vn.size());
    std::transform(vn.begin(),vn.end(),std::back_inserter(res),[&vm](auto& l){
        auto it=std::find_if(vm.begin(),vm.end(),[&l](auto& t){
            if(t.dig.size()>l.size()) return false;
            return std::equal(t.dig.begin(),t.dig.end(),l.begin(),l.begin()+t.dig.size())
                && t.x==static_cast<int>(l.size())-static_cast<int>(t.dig.size());
            ;
        });
        std::string num;
        std::transform(it->tmp.begin(),it->tmp.end(),std::back_inserter(num),[i=0,l](auto c)mutable{
            return (!isdigit(c) && c!='X')?c:l[i==l.size()-1?i:i++];
        });
        return num+" - "+it->cntr;
    });
    for(auto i:res){
        std::cout<<i<<'\n';
    }

	return 0;
}


//////////////////////////
#include <iostream>
#include <string>
#include <vector>

std::string split(std::string input)
{
    if (input.empty())
        return input;
    std::string output(std::move(input));
    
    for (int i = 0; i < output.size(); i++)
    {
        char symb = (char) output[i];
        if (!(symb > 47 && symb < 58))
        {
            output.erase(i, 1);
            i--;
        }
    }
    return output;
}

class NumberFormat
{
protected:
    std::string country_code;
    std::string operator_code;
    std::string personal_number;
    std::string name;
public:
    explicit NumberFormat(const std::string& format)
    {
        read_format(format);
    }
    
    void read_format(const std::string& format)
    {
        country_code.clear();
        operator_code.clear();
        personal_number.clear();
        name.clear();
        
        if (format.empty())
            return;
        
        auto it = format.begin();
        
        /// country code
        ++it;   // skip plus sign
        for (; *it != ' '; ++it)
            country_code.push_back(*it);
        
        /// operator code
        it += 2; // skip " ("
        for (; *it != ')'; ++it)
            operator_code.push_back(*it);
        
        /// personal number
        it += 2; // skip ") "
        for (; *it != ' '; ++it)
            personal_number.push_back(*it);
        
        /// name
        it += 3; // skip " - "
        for (; it != format.end(); ++it)
            name.push_back(*it);
    }
    
    bool match(const std::string& number) const
    {
        int count = country_code.size()
                    + operator_code.size()
                    + personal_number.size();
        
        if (count != number.size()) // check number and format length
            return false;
        
        if (number.compare(0, country_code.size(), country_code) != 0) // compare numbers country code
            return false;
        
        if (number.compare(country_code.size(), operator_code.size(), operator_code) != 0) // compare numbers operator code
            return false;
        
        for (size_t i = 0; i < personal_number.size(); i++)
        {
            if (personal_number[i] == 'X')
                continue;
            else if (personal_number[i] != number[country_code.size() + operator_code.size() + i])
                    return false;
        }
        return true;
    }
    
    std::string get_formatted_number(const std::string& number)
    {
        std::string formatted;
        formatted = '+' + country_code + " (" + operator_code + ") "
                         + number.substr(operator_code.size() + country_code.size()) + " - " + name;
        return formatted;
    }
};

int main()
{
    size_t n = 0;                       // for storing total number of numbers/formats
    std::vector<std::string> numbers;   // vector for storing numbers
    std::vector<std::string> formatted; // vector for storing formatted numbers
    std::vector<NumberFormat> formats;  // vector of format types
    std::string tmp;                    // temporary string for storing input
    
    // get total amount of phone numbers
    std::cin >> n;
    std::getchar();
    
    for (size_t i = 0; i < n; i++)
    {
        std::getline(std::cin, tmp);
        numbers.push_back(split(tmp)); // get rid of unnecessary symbols and push in the vector
    }
    
    // get total amount of formats
    std::cin >> n;
    std::getchar();
    
    for (size_t i = 0; i < n; i++)
    {
        std::getline(std::cin, tmp);
        formats.emplace_back(NumberFormat(tmp)); // push format in vector
    }
    
    for (const auto& num : numbers)     // for each number
        for (auto& form : formats)      // for each format
            if (form.match(num))        // if number fits format, then get formatted number and push it in vector
                formatted.emplace_back(form.get_formatted_number(num));

    
    for (const auto& p  :formatted)
        std::cout << p << "\n";
    
    return 0;
}