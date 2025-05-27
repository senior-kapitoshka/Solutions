function count(n) {
    return Math.floor(new Array(n)
       .fill()
       .map((e,i)=>i+1)
       .reduce((res,e)=>res+Math.log10(e),0))+1;
   };

   ////////////
   function count(n) {
    let res = 1
    let product = 1
    while (n > 0) {
      product *= n
      while (product >= 10) {
        res++
        product /= 10
      }
      n--
    }
    return res
  };
  ///////////
  count=(n)=>Math.ceil(Math.log10(2*Math.PI*n)/2+n*(Math.log10(n/Math.E)))