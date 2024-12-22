function evenChars(s) {
    if(s.length<=1 || s.length>100)return "invalid string";
    res=[];
    for(let i=0, n=s.length;i<n;++i){
     if(i%2!=0) res.push(s[i]);
    }
    return res;
  }
  ////////////////
  function evenChars(string) {
    return (string.length < 2 || string.length > 100) ? "invalid string" : 
    [...string].filter((x, i) => i % 2);
  }
  ////////////////
  const evenChars = (str) => 1 < str.length && str.length < 100
  ? Array.from(str).filter((_, i) => i & 1)
  : "invalid string"