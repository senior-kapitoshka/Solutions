function unique(arr) {
    let dict={};
     return arr.filter((x)=>{
       if(dict[x]){
         return false;
       }
       dict[x]=1;
       return true;
     })
   }

   //////////
   function unique(arr) {
    return [...new Set(arr)].filter(e => true);
  }
   /////////
   function unique(arr) {
    return arr.filter((x, i) => arr.indexOf(x) === i);
  }
  /////////
  const unique = arr =>
  arr.filter((val, idx) => !arr.slice(0, idx).includes(val))
  ///////
  function unique(arr) {
    return Array.from(new Set(arr)).filter(x=>x>-Infinity)
    }
  /////////
  function unique(arr) {
    return arr.sort().filter((v,i,a) => a[i - 1] !== v);
  }  