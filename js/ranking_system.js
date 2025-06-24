function rankings(arr){
    let s=arr.slice(0);
    arr.sort((a,b)=>b-a);
    return s.map((c)=>arr.indexOf(c)+1);
  }

  ////////////////////
  function rankings(arr){
    const a = arr.slice().sort((a,b)=>b-a)
    return arr.map(x=>a.indexOf(x)+1)
  }

  /////////
  function rankings(arr){
    const sorted = [...arr].sort((a, b) => b - a);
    return arr.map(e => sorted.indexOf(e) + 1);
  }

  ////////////
  