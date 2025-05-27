function archersReady(ars){
    return ars.length===0?false:ars.every((i)=>i>=5 );
  }

  /////////
  var archersReady = aa => !!aa.length && aa.every(a => a >= 5);
  /////////
  const archersReady = archers =>
  !!archers.length && archers.every(val => val > 4);