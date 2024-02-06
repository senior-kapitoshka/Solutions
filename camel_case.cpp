#include <string>
#include <algorithm>


std::string to_camel_case(std::string text) {
  if(text.empty()) return "";
  int i=0;
  for_each(text.begin(),text.end(),
                [&i,&text](char& a)
                 {
                   if(a == '-' || a == '_')
                    {
                        text.erase(i,1);
                        text[i] = toupper(text[i]);
                    }
                    ++i;
                  });
  return text;
}

////////////////////////////////////////////////
#include <string>
#include <iostream>


std::string to_camel_case(std::string text) {
  std::cout<<text<<"\n";
  if(text.empty()) return "";
  std::string ans;
  for(size_t i=0;i<text.size();++i){
    if((text[i]!='_')&&(text[i]!='-')){
      ans+=text[i];
      
    }else if(text[i]=='_'){
      ans+=std::toupper(text[i+1]);
      i+=1;
    }
    
    else if(text[i]=='-'){
      ans+=std::toupper(text[i+1]);
      i+=1;
    }
  }
  return ans;
}
///////////////////////////////////
#include <string>


std::string to_camel_case(std::string text)
{
  for(int i = 0; i < text.size(); ++i)
  {
    if(text[i] == '-' || text[i] == '_')
    {
      text.erase(i,1);
      text[i] = toupper(text[i]);
    }
  }
  return text;
}
///////////////////////////////////

#include <string>
#include <vector>
#include <algorithm>

std::string to_camel_case(std::string text)
{
	if (text.empty()) return text;

	static std::vector<char> const remove { '-','_' };

	for (auto i = 0; i < text.length();++i) {
		auto current = text[i];
		if (std::find(remove.begin(), remove.end(), current) != remove.end()) {
			text.erase(i, 1);
			text[i] = toupper(text[i]);
		}
	}
	return text;
}
///////////////////////////////////
#include <string>
#include <cctype>

std::string to_camel_case(std::string text) {
  for(int i = 0; i < text.size(); i++)
    if(text[i] == '-' || text[i] == '_')
      text.replace(i, 2, 1, toupper(text[i + 1]));
  return text;
}
/////////////////////////////
