function maxPossibleScore(obj, arr) {
    return Object.entries(obj).reduce((sum,[k,v])=>{
                      sum+=arr.includes(k)?v*2:v;
                      return sum;
    }
                      ,0);
  }

/////////////
function maxPossibleScore(obj, arr) {
    return Object.keys(obj).concat(arr).map(x=>obj[x]||0).reduce((a,b)=>a+b)
  }
  
  ///////////////
  const maxPossibleScore = (obj, arr) =>
  [...Object.keys(obj), ...arr].reduce((pre, val) => pre + (obj[val] || 0), 0);
  /////////
  