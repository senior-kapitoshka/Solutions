function perc (mins) {
    if(typeof mins !=='number' || mins>100 || mins<1) return "invalid track time" ;
    return [
      `${Math.round(mins*30*4)} kicks`,
      `${Math.round(mins*30*8)} hihats`,
      `${Math.round(mins*30*2)} claps`
    ]
  };

  ////////////
  const perc = mins =>
  isNaN(mins) || mins < 1 || mins > 100 ? `invalid track time` :
    [[120, `kicks`], [240, `hihats`], [60, `claps`]].map(val => `${Math.round(val[0] * mins)} ${val[1]}`);
    //////////////
    