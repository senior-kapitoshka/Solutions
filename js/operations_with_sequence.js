const calc =(a)=> a.map((j,i)=>{
    let res=j>0?j*j:j;
    if((i+1)%3===0){
      res*=3;
    }
    if((i+1)%5===0){
      res*=-1;
    }
    return res;
  }).reduce((curr,sum)=>sum+curr,0);
  //////////////
  function calc(a) {
    return a.reduce((a, elt, i) => {
        if (elt > 0) elt *= elt;
        if ((i + 1) % 3 === 0) elt *= 3;
        if ((i + 1) % 5 === 0) elt *= -1;
        return a + elt;
      }, 0);
  }
  /////////////
  const calc = a => a.reduce((n, x, i) => n + (x > 0 ? x * x : x) * ((i + 1) % 3 ? 1 : 3) * ((i + 1) % 5 ? 1 : -1), 0)