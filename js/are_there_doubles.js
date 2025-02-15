function doubleCheck(s){
    console.log(s);
    let str=s.toLowerCase().replace(/[\\w]/gi,"");
    for(let i=0,n=s.length;i<n-1;++i){
      if(str[i]===str[i+1]) return true;
    }
      return false;
  }

  ////////////
  const doubleCheck = (str) => /(.)\1/i.test(str);

  ////////////
  function doubleCheck(str){
    let strArr = str.toLowerCase().split("");
    return strArr.some((c, i) => c === strArr[i + 1]);
}

////////
const doubleCheck = RegExp.prototype.test.bind(/(.)\1/i);