function killer(s, d) {
    return Object.keys(s).reduce((res,k)=>{
      if(d.every(v=>s[k].includes(v))) res=k;
      return res;
    },'');
  }
  /////////////
  function killer(suspectInfo, dead) {
    return Object.keys(suspectInfo).find(x => dead.every(y => suspectInfo[x].includes(y)))
   }
   ///////////
   