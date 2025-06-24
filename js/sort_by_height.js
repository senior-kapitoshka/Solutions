function sortByHeight(a) {
    let [x,y]=a.reduce((res,curr,i)=>{
      if(curr===-1) res[0].push(i);
      else res[1].push(curr);
      return res;
    },[[],[]]);
     y.sort((l,r)=>l-r);
     let res=[];
     for(let i=0,j=0,l=0,n=a.length;i<n;++i){
       if(i===x[j]){
         res.push(-1);
         ++j;
       }else{
         res.push(y[l++]);
       }
     }
     return res;
   }
   /////////////////
   function sortByHeight(a) {
    var na=a.slice().sort((a,b)=>a-b).filter(a=>a!=-1), p=0;
    return a.map(a=>a==-1?-1:na[p++])
 }
 //////////
 const sortByHeight = a =>
  (arr => a.map(val => ~val ? arr.shift() : -1))
  (a.filter(val => ~val).sort((a, b) => a - b));
  //////////
  function sortByHeight(a) {  
    let b = a.filter(x => x>-1).sort((a,b) => a-b);
    let k=0;
    return a.map(x => x==-1 ? -1 : b[k++]);
  }
  ////////
  