function stringToIntArray(s){
    return s.split(',')
      .reduce((arr,dig)=>{
        if(dig)arr.push(parseInt(dig));
      return arr;
    },[])
  }

//////////////
function stringToIntArray(s) {
    return s.split(',').filter(Boolean).map(Number)
  }
  
  /////////
  const stringToIntArray=s=>s.split`,`.flatMap(n=>n?+n:[])

  /////////
  const stringToIntArray = s => (s.match(/-?\d+/g) || []).map(Number);