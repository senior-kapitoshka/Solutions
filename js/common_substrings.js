function substringTest(str1, str2){
    let n=str1.length;
     let m=str2.length;
    for(let i=0;i<n-1;++i){
      for(let j=0;j<m-1;){
        if(str1[i].toLowerCase()===str2[j].toLowerCase() && str1[i+1].toLowerCase()===str2[j+1].toLowerCase()) return true;
        else ++j;
      }
    }
    return false;
  }

  //////////////
  function SubstringTest(str1, str2)
{
  str1 = str1.toLowerCase();
  str2 = str2.toLowerCase();
  for(var i = 0 ; i< str2.length-1;i++){
     if(str1.indexOf(str2.substr(i,2))>-1)
       return true;
  }
  return false;
}
///////////////
function SubstringTest(str1, str2) {
    let [xs, ys] = [str1.toLowerCase(), str2.toLowerCase()]
    return xs.substring(0, xs.length - 1)
    .split('')
    .some((x, i) => ys.indexOf(x + xs[i + 1]) > - 1)
}
///////////////
const SubstringTest = (s1, s2) => /(..).*\|.*\1/i.test(s1 + '|' + s2);
//////////////
const SubstringTest = (str1, str2) => {
    for (let i = 0; i < str1.length - 1; i++) {
      if (new RegExp(str1.substring(i, i + 2), 'gi').test(str2)) return true
    }
  
    return false
  }
  //////////
  function SubstringTest(s,t) {
    [s,t] = (s.length<t.length ? [s,t] : [t,s]).map(s => s.toLowerCase());
    return [...s].some((c,i) => i && t.indexOf(s[i-1]+c)!=-1);
}