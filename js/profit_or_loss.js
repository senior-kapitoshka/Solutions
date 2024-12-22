function profitLoss(r){
    let s=r.reduce((lhs,rhs)=>lhs+rhs[0],0.0);
    let p=r.reduce((lhs,rhs)=>lhs+(rhs[0]*100/(100+rhs[1])),0.0);
    return Number((s-p).toFixed(2));
  }

  //////////////
  const profitLoss = records => +records.reduce((a, v) => v[0] - v[0] / (1 + v[1] / 100) + a, 0).toFixed(2);
  ///////////
  function profitLoss(records){
    return Math.round(records
      .map(function(entry) { return entry[0] * (1 - (100 / (entry[1]+100)));})
      .reduce(function(total,x) {return total + x}) * 100) / 100;
  }