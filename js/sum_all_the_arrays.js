function arraySum(arr) {
    return arr.reduce((sum,curr)=>{
      if(typeof curr==='number') sum+=curr;
      else if(Array.isArray(curr)) sum+=arraySum(curr);
      return sum;
    },0);
  }
  //////////
  function arraySum(arr) {
    return arr.reduce((n, x) => n + (Array.isArray(x) ?
                                         arraySum(x) :
                                          isNaN(x) ?
                                                 0 :
                                                x), 0)
  }
  ///////
  function arraySum(arr) {
    return (arr+'').split(',').reduce((s,cv)=>s+(+cv||0),0);
  }
  /////////
