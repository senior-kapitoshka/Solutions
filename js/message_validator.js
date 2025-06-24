function isAValidMessage(mg){
    let arr= [...mg.matchAll(/([0-9]{1,2}|[a-zA-Z]+)/g)].map(m=>m[1]);
    if(arr.length%2===1) return false;
    for(let i=1;i<arr.length;i+=2){
      if(arr[i].length!==parseInt(arr[i-1])) return false;
    }
    return true;
  }
  /////////
  function isAValidMessage(message){
    return !message.replace(/(\d+)(\D*)/g,(_,m,n)=>m-n.length||'')
  }
  ///////////
  function isAValidMessage(message){
    const match = message.match(/\d+|[a-z]+/gi) || [];
    
    return !(match.length % 2) && match.every((c, i) => !(i % 2) || c.length === Number(match[i - 1]))
  }