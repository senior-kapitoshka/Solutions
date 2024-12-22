
////pass not all tests
#include <string>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std::literals;

std::vector<std::string> dictionary({".",":",":.","::","|:","⟔","⊓","☐","⧄","☒"});

std::string write (unsigned int num) {
  if(num==0) return "";
  std::string dot="";
  if(num>10){
    int x=num/10;
    int y=num%10;
    while(x>0){
      dot+="☒";
      --x;
    }
    dot+=dictionary[y-1];
  }else{
    return num==1?"."s:num==2?":"s:
    num==3?":."s:num==4?"::"s:num==5?"|:"s:
    num==6?"⟔"s:num==7?"⊓"s:num==8?"☐"s:num==9?"⧄"s:"☒"s;
  }
  return dot;
}
unsigned int read (std::string dot) {
  if(dot.empty()) return 0;
  unsigned int num=0;
  if(dot.find("☒")==dot.npos && (dot.size()==3 || dot.size()==2))
    if((dot.back()=='.' || dot.back()==':') && dot.size()==3) {return 0;}
    else {return std::distance(dictionary.begin(),
                                                   std::find(dictionary.begin(),dictionary.end(),dot))+1;}
  std::regex r("^[☒]*(.|:|(:.)|(::)|(\\|:)|⟔|⊓|☐|⧄)");
  if(!std::regex_match(dot,r) ){
    return 0;
  }else{
    int cnt=0;
    std::regex rx("☒");
    auto bg= std::sregex_iterator(dot.begin(),dot.end(),rx);
    auto ed=std::sregex_iterator();
    for(auto it=bg;it!=ed;++it){
      ++cnt;
    }
      num=cnt*10+((dot.substr(dot.size()-3)=="☒")?0:(dot.back()=='.' && *(dot.end()-2)!=':')?1:(dot.back()==':' && *(dot.end()-2)!=':'&& *(dot.end()-2)!='|')?2:((dot.back()=='.' && *(dot.end()-2)==':') || dot.back()==':')?std::distance(dictionary.begin(),
                    std::find(dictionary.begin(),dictionary.end(),dot.substr(dot.size()-2)))+1:
                  
    std::distance(dictionary.begin(),
                    std::find(dictionary.begin(),dictionary.end(),dot.substr(dot.size()-3)))+1);

  }
  
  return num;
}

///////////////
#include <string>
#include <vector>
#include <algorithm>

const std::vector<std::string> dictionary{"",".",":",":.","::","|:","⟔","⊓","☐","⧄","☒"};

std::string write (unsigned int num) {
  std::string dot;
  while (num>=10) {
    dot+=dictionary[10];
    num-=10;
  }
  return dot+dictionary[num];
}

unsigned int read (const std::string &dot) {
  // Legal forms are a certain number of 10 (0..n) plus optionally one digit less ten 10 
  unsigned int num{0};
  
  const auto &ten=dictionary[10];
  auto it=dot.begin();
  while (it+ten.size()<=dot.end() && std::equal(it,it+ten.size(),ten.begin())) {
    num+=10;
    it+=ten.size();
  }
  if (it==dot.end()) return num;
  
  for (unsigned int i:{9,8,7,6,5,4,3,2,1}) {
    const auto &ds=dictionary[i];
    if (std::string{it,it+ds.size()}==ds) {
      num+=i;
      it+=ds.size();
      break; // Max one at the end of 10 sequence
    }
  }

  return it==dot.end()? num:0;
}
/////////////////
#include <string>
#include <vector>

std::vector<std::string> dictionary({".",":",":.","::","|:","⟔","⊓","☐","⧄","☒"});

std::string write (unsigned int num) {
  std::string dot;
  if (num == 0)
    return "";
  while (num >= 10){
    dot += dictionary[9];
    num -= 10;
  }
  if (num > 0)
    dot += dictionary[num - 1];
  return dot;
}
unsigned int read (std::string dot) {
  unsigned int num = 0;
  // BEWARE ! unicode chars like ☒ are 3 chars long...
  while (dot.find(dictionary[9]) == 0){
    num += 10;
    dot.erase(0,3);
  }
  for (unsigned int i = 0; i < dictionary.size(); ++i){
    if (dot == dictionary[i]){
      num += i + 1;
      dot.erase(0, dictionary[i].size());
      break;
    }
  }
  if (dot.empty())
    return num;
  return 0;
}
///////////////////////
#include <string>
#include <vector>

std::vector<std::string> dictionary({".",":",":.","::","|:","⟔","⊓","☐","⧄","☒"});

std::string write (unsigned int num) {
  std::string dot;
  if (num == 0)
    return "";
  while (num >= 10){
    dot += dictionary[9];
    num -= 10;
  }
  dot += dictionary[num - 1];
  return dot;
}
unsigned int read (std::string dot) {
  unsigned int num = 0;
  // BEWARE ! unicode chars like ☒ are 3 chars long...
  while (dot.find(dictionary[9]) == 0){
    num += 10;
    dot.erase(0,3);
  }
  for (unsigned int i = 0; i < dictionary.size(); ++i){
    if (dot == dictionary[i]){
      num += i + 1;
      dot.erase(0, dictionary[i].size());
      break;
    }
  }
  if (dot.empty())
    return num;
  return 0;
}