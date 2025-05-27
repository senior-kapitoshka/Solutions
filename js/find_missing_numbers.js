function findMissingNumbers(arr){
    return arr.reduce((res,curr,i)=>{
      let a=[];
      if(i<arr.length-1){
        for(let j=curr+1;j<arr[i+1];++j){
            a.push(j);
          }
        }
      res=res.concat(a);
      return res;
    },[]);
  }
  //////////
  const findMissingNumbers = arr =>
  Array.from({length: arr.slice(-1) - arr[0]}, (_, idx) => arr[0] + idx).filter(val => !arr.includes(val));
  //////////
  const findMissingNumbers=arr=>arr.length<2 ? [] : (full=>full.filter(a=>arr.indexOf(a)==-1))(new Array(arr[arr.length-1]-arr[0]+2).join("a").split("").map((a,i)=>i+arr[0]));
  /////////
  