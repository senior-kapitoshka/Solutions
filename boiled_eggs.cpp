#include <cmath>
unsigned int cookingTime(unsigned int eggs) {
  if(eggs%8==0) return(eggs/8)*5;
  else{
    while(eggs%8!=0){
      ++eggs;
    }
  }
  return(eggs/8)*5;
}

///////////////////
#include <cmath>
unsigned int cookingTime(unsigned int eggs) {
  return ceil(eggs / 8.0) * 5;
}
///////////
unsigned int cookingTime(unsigned int eggs)
{
    unsigned int minutes=0;
    if (eggs==0)
        return 0;
    while(eggs>=8)
        {
            eggs-=8;
            minutes+=5;
        }
    if (eggs>0)
        minutes+=5;

    return minutes;
}
/////////////
unsigned int cookingTime(unsigned int eggs) {
  
  return eggs%8 == 0 ? 5*(eggs/8):5*(eggs/8)+5;
}
////////////
