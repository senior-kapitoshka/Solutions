int sumOfABeach(String b) {
  b=b.toLowerCase();
  const arr={"sand", "water", "fish","sun"};
  int cnt=0;
  for(var w in arr){
    if(b.indexOf(w)!=-1){
      for(int i=0,j=w.length;i<=b.length-w.length;++i,++j){
        if(b.substring(i,j)==w)cnt++;
      }
    }
  }
  return cnt;
}

///////////
int sumOfABeach(beach)=>new RegExp(r"(sand|water|fish|sun)", caseSensitive: false)
      .allMatches(beach)
      .length;

      //////////////////
      int sumOfABeach(String beach) {
  RegExp words = RegExp('sand|water|fish|sun', caseSensitive: false);
  return words.allMatches(beach).length;
}