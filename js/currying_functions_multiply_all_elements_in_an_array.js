function multiplyAll(a) {
    return function(i){
      return a.reduce((res,j)=>{
        res.push(j*i);
        return res;
      },[]);
    }
  }

  /////////////
  multiplyAll = a => x => a.map(e => e * x);
  ///////////
  function multiplyAll(arr) {
    return function(n) {
      return arr.map(x => x * n);
    }
  }