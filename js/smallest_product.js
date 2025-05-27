function smallestProduct(arr) {
    let min=Number.MAX_SAFE_INTEGER;
    arr.forEach((i)=>min=Math.min(min,i.reduce((lhs,rhs)=>lhs*rhs,1)));
    return min;
   }

   ///////////
   const smallestProduct = a => Math.min(...a.map(e => e.reduce((p, c) => p * c)))
   //////////
   const smallestProduct = arr => arr.reduce((s,n)=> Math.min(s,n.reduce((a,b)=> a*b, 1)), Infinity); 