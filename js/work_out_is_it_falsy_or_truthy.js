function falsyOrTruthy(arr) {
    let [t,f]=arr.reduce((res,curr)=>{
      if(curr) res[0].push(curr);
      else res[1].push(curr);
      return res;
    },[[],[]]);
   
      const isEven = arr.length % 2 === 0;
     
     if (isEven && t.length === 0) return [];
     if (!isEven && f.length === 0) return [];
   
     return isEven ? t : f;
   }
   ////////////////
   const falsyOrTruthy=arr=>arr.filter(x=>!x==arr.length%2)
   ///////////
   function falsyOrTruthy(arr) {
    return (arr.length & 1) === 0
      ? arr.filter((el) => Boolean(el))
      : arr.filter((el) => !Boolean(el));
  }
  ////////
  