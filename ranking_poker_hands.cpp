#include <unordered_map>
#include <map>
#include <vector>
#include <sstream>
#include <utility>
#include <functional>
#include <numeric>

enum class Hand:int {
  HC,//
  PR,//
  TP,//
  TK,//
  LA,
  ST,//
  FL,//
  FH,//
  FK,//
  SF,//
  FR
};

bool line(const std::map<int,std::vector<char>,std::greater<int>>&mp){
  int i=mp.begin()->first;
  for(auto it=next(mp.begin());it!=mp.end();++it){
    if(i-(it->first)!=1) return false;
    i=it->first;
  }
  return true;
}

bool low_ace(const std::map<int,std::vector<char>,std::greater<int>>&mp){
  int i=5;
  if(mp.begin()->first!=14) return false;
  for(auto it=next(mp.begin());it!=mp.end();++it){
    if(it->first!=i--) return false;
  }
  return true;
}

struct PokerHand {
  PokerHand (const char* pokerhand) {
    parse(pokerhand);
    if(suit_to_val.size()==1 && val_to_suit.size()==5 && line(val_to_suit)){
      hand=Hand::SF;
      highest=(*std::max_element(val_to_suit.begin(),val_to_suit.end(),[](auto& lhs,auto& rhs){return lhs.second.size()>rhs.second.size();})).first;
    }else if(suit_to_val.size()==4 && val_to_suit.size()==2){
      hand=Hand::FK;
      highest=(*std::max_element(val_to_suit.begin(),val_to_suit.end(),[](auto& lhs,auto& rhs){return lhs.second.size()<rhs.second.size();})).first;
    }else if(suit_to_val.size()==3 && val_to_suit.size()==2){
      hand=Hand::FH;
      highest=(*std::max_element(val_to_suit.begin(),val_to_suit.end(),[](auto& lhs,auto& rhs){return lhs.second.size()<rhs.second.size();})).first;
    }else if(suit_to_val.size()==1 && val_to_suit.size()==5 && !line(val_to_suit)){
      hand=Hand::FL;
      highest=(*std::max_element(val_to_suit.begin(),val_to_suit.end(),[](auto& lhs,auto& rhs){return lhs.second.size()>rhs.second.size();})).first;
    }else if(suit_to_val.size()>1 && val_to_suit.size()==5 && line(val_to_suit)){
      hand=Hand::ST;
      highest=(*std::max_element(val_to_suit.begin(),val_to_suit.end(),[](auto& lhs,auto& rhs){return lhs.second.size()>rhs.second.size();})).first;
    }else if(check()==Hand::TK){
      hand=Hand::TK;
       highest=std::find_if(val_to_suit.begin(),val_to_suit.end(),[](auto&p){return p.second.size()==3;})->first;
    }else if(check()==Hand::TP){
      hand=Hand::TP;
       highest=std::find_if(val_to_suit.begin(),val_to_suit.end(),[](auto&p){return p.second.size()==2;})->first;
    }else if(check()==Hand::PR){
      hand=Hand::PR;
       highest=std::find_if(val_to_suit.begin(),val_to_suit.end(),[](auto&p){return p.second.size()==2;})->first;
    }else if(check()==Hand::HC){
      hand=Hand::HC;
       highest=val_to_suit.begin()->first;
    }else if(check()==Hand::LA){
      hand=Hand::LA;
       highest=14;
    }
  }
  void parse(const char* s){
    std::stringstream ss;
    ss.str(s);
    str=ss.str();
    for(std::string w;std::getline(ss,w,' ');){
      suit_to_val[w[1]].push_back(isdigit(w[0])?(int)(w[0]-'0'):w[0]=='T'?10:w[0]=='J'?11:w[0]=='Q'?12:w[0]=='K'?13:14);
      vals.push_back(isdigit(w[0])?(int)(w[0]-'0'):w[0]=='T'?10:w[0]=='J'?11:w[0]=='Q'?12:w[0]=='K'?13:14);
    }
    std::for_each(suit_to_val.begin(),suit_to_val.end(),[this](auto& p){
      for(auto& i:p.second){
        val_to_suit[i].push_back(p.first);
      }
    });
    std::sort(vals.begin(),vals.end(),std::greater<int>());
  }
  Hand check(){
    int vals=std::count_if(val_to_suit.begin(),val_to_suit.end(),[](auto& p)
                            {return p.second.size()==2;});
    bool triplet=std::any_of(val_to_suit.begin(),val_to_suit.end(),[](auto& p)
                            {return p.second.size()==3;});
    bool la=low_ace(val_to_suit);
    return (vals==1)?Hand::PR:(vals==2)?Hand::TP:triplet?Hand::TK:la?Hand::LA:Hand::HC;
  }
  std::string str;
  int highest;
  Hand hand;
  
  std::unordered_map<char,std::vector<int>> suit_to_val;
  std::map<int,std::vector<char>,std::greater<int>> val_to_suit;
  mutable std::vector<int>vals;
};

bool operator>(const PokerHand& lhs, const PokerHand& rhs){
  return lhs.hand>rhs.hand || (lhs.highest>rhs.highest && lhs.hand==rhs.hand);
}
bool operator<(const PokerHand& lhs, const PokerHand& rhs){
  return lhs.hand<rhs.hand || (lhs.highest<rhs.highest && lhs.hand==rhs.hand);
}
bool operator==(const PokerHand& lhs, const PokerHand& rhs){
  return lhs.highest==rhs.highest && lhs.hand==rhs.hand;
}

enum class Result { Win, Loss, Tie };


Result compare (const PokerHand &p, const PokerHand &op) {

if(p>op ){
  return Result::Win;
}else if(p<op ){
  return Result::Loss;
}else if(p==op){
  if(std::equal(p.vals.begin(),p.vals.end(),op.vals.begin(),op.vals.end())){
     return Result::Tie;
  }
  else return std::lexicographical_compare(p.vals.begin(),p.vals.end(),op.vals.begin(),op.vals.end())?Result::Loss:Result::Win;
}
  return Result::Tie;
}

////////////////////

#include <string>
#include <array>
#include <algorithm>

class PokerHand {
  std::string rank;
/* ------------------------------------------------------------------------------------------------- */
// Produce a string whose lexicographic rank order reflects the ranking of the hand in poker.
// Examples:  "41000-63"     ;four of a kind (6s), the odd card is a 3
//            "22100-928"    ;two pair (9s and 2s), the odd card is an 8
//            "32000-da"     ;full house with three kings and two 10s
//            "312ST-ba987"  ;jack-high straight
// Hex digits (abcde) are used instead of TJQKA to get the lexicographic order right.  
  public: 
  PokerHand (const char* pokerhand) {
    bool isFlush = pokerhand[ 1] == pokerhand[ 4] && 
                   pokerhand[ 1] == pokerhand[ 7] && 
                   pokerhand[ 1] == pokerhand[10] &&
                   pokerhand[ 1] == pokerhand[13];
                   
    auto value = [] (auto x) {
      const static std::string force("..23456789TJQKA");
      return force.find(x);
    };

    std::array<unsigned, 15> cards;
    cards.fill(0);
    for (auto i = 0; i < 13; i += 3) cards[value(pokerhand[i])] ++; 
//  In an ace-low straight (but not in any other situation), an ace is considered to have rank 1:
    if( cards[2] == 1 && cards[3] == 1 && cards[4] == 1 && cards[5] == 1 && cards[14] == 1 ) {
      cards[1] = 1;
      cards[14] = 0;
    } 
    
    bool isStraight = (std::search_n(cards.begin(), cards.end(), 5, 1) != cards.end());
    
    std::string first, second;
    for (auto amount = 4; amount > 0; amount --)
      for (auto card = 14; card > 1; card --) if (cards[card] == amount) {
        first.push_back('0' + amount);
        second.push_back(card + (card < 10 ? '0' : 'a'));
      }
      
    if (isStraight) first = isFlush ? "5STFL" : "312ST";
    else if (isFlush) first = "313FL";
  
    rank = first + "-" + second;  
  };
  
  bool operator < (const PokerHand& other) const {
    return rank < other.rank;
  };
};

enum class Result { Win, Loss, Tie };

Result compare (const PokerHand &player, const PokerHand &opponent) {
  return (player < opponent) ? Result::Loss : (opponent < player) ? Result::Win : Result::Tie; 
}
/////////////////////



