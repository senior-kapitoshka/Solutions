#include <exception>
#include <cmath>

class Kata
{
public:
  void prepare(std::string& s){
    for(char i='A';i<='Z';++i){
      s+=i;
    }
    for(char i='a';i<='z';++i){
      s+=i;
    }
    for(int i=0;i<=9;++i){
      s+=std::to_string(i);
    }
    s+=".,:;-?! '()$%&";
    s+='"';
  }
    std::string encrypt(std::string tx)
    {
      if(tx.empty()) return tx;
        std::string s;
      prepare(s);
        std::transform(tx.begin(),tx.end(),tx.begin(),[i=0,&s](char c)mutable->char{
          if(s.find(c)==s.npos) throw std::exception();
          if((i)%2!=0 && isupper(c) && isalpha(c)){
            ++i;
            return tolower(c);
          }
          else if(isalpha(c) && (i)%2!=0 && islower(c)){
            ++i;
            return toupper(c);
          }
          ++i;
          return c;
        });

      std::string x;
      std::transform(tx.begin(),prev(tx.end()),next(tx.begin()),std::back_inserter(x),
                    [&s](auto& curr, auto& next){
                    
                      int i=(int)s.find(curr)-(int)s.find(next);
                      
                      return i<0?s[(i+77)]:s[i];
                    });
      x.insert(0,1,s[76-(int)s.find(tx.front())]);
      
      return x;
    }
  
    std::string decrypt(std::string et)
    {
      if(et.empty()) return et;
       std::string s;
      prepare(s);
      std::string res;
      res.insert(0,1,s[std::abs((int)s.find(et.front())-76)]);
      char x=s[std::abs((int)s.find(et.front())-76)];
      std::for_each(next(et.begin()),et.end(),[&s,&x,&res](auto& c){
        if(s.find(c)==s.npos) throw std::exception(); 
        if(s.find(c)>77/2){
          int i=77+s.find(x)-s.find(c);

          x=s[i%77];
          res+=s[i%77];
        }else{

          int i=s.find(x)-s.find(c);

          x=s[(77+i)%77];
          res+=s[(77+i)%77];
        }
        
      });

      std::transform(res.begin(),res.end(),res.begin(),[i=0](auto& c)mutable->char{
         if((i)%2!=0 && isupper(c) && isalpha(c)){
            ++i;
            return tolower(c);
          }
          else if(isalpha(c) && (i)%2!=0 && islower(c)){
            ++i;
            return toupper(c);
          }
          ++i;
          return c;
      });
      
        return res;
    }
};

////////////////////////
#include <exception>
#include <string>

class Kata {
	const std::string region = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.,:;-?! '()$%&\"";

	static char switchCase(char const &c)
	{
		if (c >= 'A' && c <= 'Z')
			return c + 'a' - 'A';
		if (c >= 'a' && c <= 'z')
			return c + 'A' - 'a';
		return c;
	}

	static void step1(std::string &text)
	{
		for (auto i = 1; i < text.size(); i += 2)
			text[i] = switchCase(text[i]);
	}

	void step2(std::string const &text_in, std::string &text_out)
	{
		for (auto i = 1; i < text_in.size(); i++) {
			int diff = region.find(text_in[i - 1]) - region.find(text_in[i]);

			auto index = diff < 0 ? diff + 77 : diff;

			text_out[i] = region[index];
		}
	}

	void step3(std::string &text)
	{
		auto index = region.find(text[0]);
		text[0] = region[76 - index];
	}

public:
	std::string encrypt(std::string text)
	{
		if (text.empty())
			return text;

		if (text.find_first_not_of(region) != std::string::npos) {
			throw std::exception();
		}

		step1(text);

		std::string orig = text;
		step2(orig, text);

		step3(text);

		return text;
	}

	std::string decrypt(std::string encryptedText)
	{
		if (encryptedText.empty())
			return encryptedText;

		if (encryptedText.find_first_not_of(region) != std::string::npos)
			throw std::exception();

		step3(encryptedText);

		step2(encryptedText, encryptedText);

		step1(encryptedText);

		return encryptedText;
	}
};

/////////////////
