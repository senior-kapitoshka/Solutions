#include <unordered_map>
#include <array>
#include <fmt/format.h>

std::array<std::string,12>hr={
  "one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve"
};

std::string chitos(int num) {
        if (!num) return "zero";
        std::string str = "";
        std::vector<std::string> ones = {"zero", "one", "two", "three", "four","five","six","seven","eight","nine","ten", "eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
        std::vector<std::string> tens = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
        if (num/100 > 0) str += ones[num/100] + " hundred";
        if (num%100 >= 20)
            str += (str.empty() ? "" : " ") + tens[num%100/10] + (num%10 ? " " + ones[num%10] : "");
        else if (num%100 > 0)
            str += (str.empty() ? "" : " ") + ones[num%100];
        return str;
}

std::string solve(std::string t){
  int x,y;
	sscanf(t.c_str(),"%d:%d",&x,&y);
  if(y==0 && x==0){
    return "midnight";
  }else if(y==0 && x!=0){
    return fmt::format("{} o'clock",hr[(x-1)%12]);
  }else if(x==0){
    if(y==30){
      return "half past midnight";
    }else if(y<30){
      if(y==15){
        return "quarter past midnight";
      }else{
        if(y==1){
          return "one minute past midnight";
        }else{
          return fmt::format("{} minutes past midnight",chitos(y));
        }
      }
    }else if(y>30){
      if(y==45){
        return "quarter to one";
      }else{
        if(y==59){
          return "one minute to one";
        }else{
          return fmt::format("{} minutes to one",chitos(60-y));
        }
      }
    }
  }else if(x==23){
    if(y==30){
      return "half past eleven";
    }else if(y<30){
      if(y==15){
        return "quarter past eleven";
      }else{
        if(y==1){
          return "one minute past eleven";
        }else{
          return fmt::format("{} minutes past eleven",chitos(y));
        }
      }
    }else if(y>30){
      if(y==45){
        return "quarter to midnight";
      }else{
        if(y==59){
          return "one minute to midnight";
        }else{
          return fmt::format("{} minutes to midnight",chitos(60-y));
        }
      }
    }
  }else{
    if(y==30){
      return fmt::format("half past {}",hr[(x-1)%12]);
    }else if(y<30){
      if(y==15){
        return fmt::format("quarter past {}",hr[(x-1)%12]);
      }else{
        if(y==1){
          return fmt::format("one minute past {}",hr[(x-1)%12]);
        }else{
          return fmt::format("{} minutes past {}",chitos(y),hr[(x-1)%12]);
        }
      }
    }else if(y>30){
      if(y==45){
        return fmt::format("quarter to {}",hr[x%12]);
      }else{
        if(y==59){
          return fmt::format("one minute to {}",hr[x%12]);
        }else{
          return fmt::format("{} minutes to {}",chitos(60-y),hr[x%12]);
        }
      }
    }
  }
  return "fuck you";
}

//////////////////////////////////////////////
std::string solve(std::string time){
	std::vector<std::string> words = {"midnight", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen",
							"fourteen", "quarter", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "twenty one", "twenty two", "twenty three",
							"twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine", "half"};

	int h = stoi(time.substr(0, 2)), m = stoi(time.substr(3, 2));
	std::string pst = "past";

	if (m > 30){
		pst = "to";
		m = 60 - m;
		h++;
	}
	h = h <= 12 ? h : h % 12;

	if (!m) 
		return words[h] + (h ? " o'clock" : "");

	if (m % 15)
		pst = ((m - 1) ? "minutes " : "minute ") + pst;

	return words[m] + " " + pst + " " + words[h];
}
//////////////////////////
std::string solve( std::string time ) {
  int h{ stoi( time ) }, m{ stoi( time.substr( 3 )) }, f{ m > 30 };
  const std::string w[]{ "midnight","one","two","three","four","five",
    "six","seven","eight","nine","ten","eleven","twelve","thirteen",
    "fourteen","quarter","sixteen","seventeen","eighteen","nineteen",
    "twenty","twenty one","twenty two","twenty three","twenty four",
    "twenty five","twenty six","twenty seven","twenty eight",
    "twenty nine","half" };
  if ( f ) ++h, m = 60 - m;
  if ( h > 12 ) h %= 12;
  return m ? w[ m ] + ( m == 1 ? " minute" : m % 15 ? " minutes" : "" )
    + ( f ? " to " : " past " ) + w[ h ] : h ? w[ h ] + " o'clock" : *w;
}
/////////////////////
