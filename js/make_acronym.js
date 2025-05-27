let toAcronym=(i)=>
(i.split(" ").map((s)=>s.substring(0,1).toUpperCase()).join(""));

///////////
function toAcronym( input ){
    return input.replace(/(\w).*?\b[^\w]*/g,"$1").toUpperCase()
  }
  ////////
  const toAcronym = inp =>
  inp.match(/\b\w/g).join(``).toUpperCase();