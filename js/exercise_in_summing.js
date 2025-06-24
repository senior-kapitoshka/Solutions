function minimumSum(v, n) {
    return v.sort((a,b)=>a-b).reduce((sum,curr,i)=>
                                     sum+=(i<n)?curr:0,0)
    
  }
  
  function maximumSum(v, n) {
    return v.sort((a,b)=>b-a).reduce((sum,curr,i)=>
                                     sum+=(i<n)?curr:0,0)
  }
  //////////
  const minimumSum = (values, n) =>
  values.sort((a, b) => a - b).slice(0, n).reduce((pre, val) => pre + val, 0);
const maximumSum = (values, n) =>
  values.sort((a, b) => b - a).slice(0, n).reduce((pre, val) => pre + val, 0);