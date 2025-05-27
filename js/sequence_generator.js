function sequence(n, pn) {
    var res= new Array(n);
    if(typeof pn=="function"){
      res.fill(undefined);
      res=res.map((x,i)=>pn(x,i));
    }else{
      res.fill(pn);
    }
    return res;
  }
  /////////////
  function sequence(n, pattern) {
    return Array.from({length: n}, typeof pattern === "function" ? pattern : () => pattern)
  }
  /////////
  const sequence = (n, pattern) =>
  [...Array(n)][typeof pattern === `function` ? `map` : `fill`](pattern);
  /////////
  