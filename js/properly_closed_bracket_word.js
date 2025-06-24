function closedBracketWord(w) {
    let i=0,j=w.length-1;
    if(w.length%2!==0) return false;
    while(i<j){
      if((w[i].charCodeAt(0)-97)+ (w[j].charCodeAt(0)-122)!==0){
        return false;
      }
      ++i;
      --j;
    }
    return true;
  }
  ////////////
  function closedBracketWord(s) {
    return s === s.split("")
    .reverse()
    .map(c => "abcdefghijklmnopqrstuvwxyz"["zyxwvutsrqponmlkjihgfedcba".indexOf(c)])
    .join("");
  }