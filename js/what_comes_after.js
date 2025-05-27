function comes_after(str,l) {
    let res="";
    [...str].forEach((c,i)=>(c.toLowerCase()===l.toLowerCase() &&
                             i<str.length-1 &&
                            str[i+1].match(/[A-Za-z]/i))?
                     res+=str[i+1]
                     :res+="");
    return res;
  }

  ////////////
  function comes_after(str,l) {
    return (str.match(new RegExp(`(?<=${l})[a-z]`,'gi'))||[]).join('');
  }
  ////////////
  function comes_after(str,l,rex=RegExp(l,"i")) {
    return [...str].filter( (c,i) => i && rex.test(str[i-1]) && /[a-z]/i.test(c) ).join``
  }
  ///////////
  const comes_after = (s,c) => s.split("").filter( (v,i) => (s[i-1]||"").toLowerCase()===c.toLowerCase() && /[a-z]/gi.test(v) ).join("") ;