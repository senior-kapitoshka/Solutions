function missingNo(n) {
    return n.length*(n.length+1)/2-n.reduce((a,b)=>a+b,0);
  }

  /////////////
  function missingNo(nums) {
    let a = Array(100).fill().map((e,i)=>i+1).reduce((z,x)=>z+x);
    return a - nums.reduce((z,x)=>z+x);
  }