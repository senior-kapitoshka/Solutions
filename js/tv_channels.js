function redarr(arr) {
    let dict={};
     [...new Set(arr)].sort().forEach((curr,i)=>dict[i]=curr);
    return dict;
  
  }
  ////////
  function redarr(arr) {
    return Object.assign({}, Array.from(new Set(arr)).sort());
  }
  //////////
  function redarr(arr) {
    return Object.assign({}, [...new Set(arr)].sort())
  }

  ////////
  function redarr(arr) {
    return [...new Set(arr)].sort().reduce((acc,el,i) => {
      acc[i] = el 
      return acc 
    },{})
  }

  ////////
  const redarr = arr =>
  ({ ...[...new Set(arr.sort())] });

  ////////
  redarr=a=>[... new Set(a)].sort().reduce((a,b,c)=>(a[c]=b)&&a,{})