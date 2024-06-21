#include <fmt/format.h>

using namespace std;


// MonsterGroup := { type, hitpoints, number, damage }
typedef tuple<string, int, int, int> MonsterGroup;

enum win{
 M1,M2 
};

string who_would_win(const MonsterGroup &mon1, const MonsterGroup &mon2)
{
  bool flag=true;
   MonsterGroup mn1=mon1;
  MonsterGroup mn2=mon2;
  win w;
  while(true){
    if((std::get<1>(mn1)<0 || std::get<1>(mn2)<0) || (std::get<2>(mn1)<=0 || std::get<2>(mn2)<=0)){
      if(std::get<1>(mn1)<=0 || std::get<2>(mn1)<=0){
        w=win::M2;
        break;
      }else if(std::get<1>(mn2)<=0 || std::get<2>(mn2)<=0){
        w=win::M1;
        break;
      }
    }
    if(flag){
      int x=std::get<1>(mn2)+(std::get<2>(mn2)-1)*std::get<1>(mon2)-std::get<2>(mn1)*std::get<3>(mn1);
      std::get<1>(mn2)=x%std::get<1>(mon2);
      std::get<2>(mn2)=x/std::get<1>(mon2)+1;
      if(std::get<1>(mn2)==0){
        std::get<2>(mn2)-=1;
        std::get<1>(mn2)=std::get<1>(mon2);
      }
      flag=false;
    }else{
      int x=std::get<1>(mn1)+(std::get<2>(mn1)-1)*std::get<1>(mon1)-std::get<2>(mn2)*std::get<3>(mn2);
      std::get<1>(mn1)=x%std::get<1>(mon1);
      std::get<2>(mn1)=x/std::get<1>(mon1)+1;
      if(std::get<1>(mn1)==0){
        std::get<2>(mn1)-=1;
        std::get<1>(mn1)=std::get<1>(mon1);
      }
      flag=true;
    }
  }
    return w==win::M1?fmt::format("{} {}(s) won",std::get<2>(mn1),std::get<0>(mn1)):
  fmt::format("{} {}(s) won",std::get<2>(mn2),std::get<0>(mn2)); // your code
}


////////////////////////////////////
using namespace std;

// MonsterGroup := { type, hitpoints, number, damage }
typedef tuple<string, int, int, int> MonsterGroup;

class MonsterFight
{
    class Monster
    {
        string type;
        int hp, n, dmg, totalHP;
    public:
        Monster(const MonsterGroup &mg)
          : type(get<0>(mg)), hp(get<1>(mg)), n(get<2>(mg)), dmg(get<3>(mg)),
            totalHP(hp * n) {}
        string getType  () const { return type;    }
        int    getNumber() const { return n;       }
        int    getAttack() const { return n * dmg; }
        void applyDamage(int damage)
        {
            totalHP -= damage;
            n       -= (int)(n - (float)totalHP / hp);
        }
    };
    
    Monster *attacker, *defender;
public:
    MonsterFight(const MonsterGroup &mon1, const MonsterGroup &mon2)
    {
        attacker = new Monster(mon1);
        defender = new Monster(mon2);
    }
    ~MonsterFight()
    {
        delete attacker;
        delete defender;
    };
    void fight()
    {
        while ( attacker->getNumber() > 0 )
        {
            defender->applyDamage(attacker->getAttack());
            { auto t = attacker; attacker = defender; defender = t; } // swap
        }
    }
    string getWinner() const
    {
        Monster *winner = attacker->getNumber() <= 0 ? defender : attacker;
        return to_string(winner->getNumber()) + " " + winner->getType() + "(s) won";
    }
};

string who_would_win(const MonsterGroup &mon1, const MonsterGroup &mon2)
{
    MonsterFight battle(mon1, mon2);
    battle.fight();
    return battle.getWinner();
}

//////////////////
using namespace std;

// MonsterGroup := { type, hitpoints, number, damage }
typedef tuple<string, int, int, int> MonsterGroup;

string who_would_win(const MonsterGroup &mon1, const MonsterGroup &mon2)
{
    int health1 = get<1>(mon1) * get<2>(mon1);
    int health2 = get<1>(mon2) * get<2>(mon2);

    while(true)
    {      
      int count1 = health1 / get<1> (mon1) + (health1 % get<1> (mon1) != 0 ? 1 : 0);
      health2 -= get<3>(mon1) * count1;
      if(health2 <=0)
        return std::to_string(count1) + " " + get<0>(mon1) + "(s) won";
        
      int count2 = health2 / get<1> (mon2) + (health2 % get<1> (mon2) != 0 ? 1 : 0);
      health1 -= get<3>(mon2) * count2;
      if(health1 <=0)
        return std::to_string(count2) + " " + get<0>(mon2) + "(s) won";  
    }
}
////////////////////
#include <cmath>

using namespace std;

// MonsterGroup := { type, hitpoints, number, damage }
typedef tuple<string, int, int, int> MonsterGroup;

string who_would_win(const MonsterGroup &mon1, const MonsterGroup &mon2)
{
  auto [t1, l1, n1, d1] = mon1;
  auto [t2, l2, n2, d2] = mon2;
  int h1 = l1 * n1;
  int h2 = l2 * n2;
  while ((h1 > 0) && (h2 > 0)) {
    h2 -= ceil((double)h1 / l1) * d1;
    if (h2 > 0) h1 -= ceil((double)h2 / l2) * d2;
  }
  if (h1 > h2) 
    return std::to_string((int)ceil((double)h1 / l1)) + " " + t1 + "(s) won";
  else
    return std::to_string((int)ceil((double)h2 / l2)) + " " + t2 + "(s) won";
}

///////////////
