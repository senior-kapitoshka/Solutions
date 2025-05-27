function each(n, xs) {
    return n===0?[]
            :n===1?xs
            :n===-1?xs.reverse()
            :Math.abs(n)>xs.length?[]
            :n>0?xs.filter((x,i)=>(i+1)%n===0)
            :n<0?xs.reverse().filter((x,i)=>(i+1)%n===0):
            [];
  }

  ////////////
  function each(n, xs) {
    if(n === 0) return [];
    xs = (n > 0) ? xs : xs.reverse();
    
    return xs.filter((item, i) => (i + 1) % n === 0);
  }

  ////////////
  function each(n, xs) {
    return ((n < 0 && xs.reverse()), xs.filter((_, i) => ++i % n < 1));
  }

  /////////
  