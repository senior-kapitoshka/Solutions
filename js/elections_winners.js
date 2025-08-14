function electionsWinners(v, k) {
  let mx=Math.max(...v);
  return k===0?
    k+(v.filter(i=>i===mx).length===1):
    v.filter(i=>i+k>mx).length
}

//////////////