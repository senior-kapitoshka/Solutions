
function frame(bs) {
  
    // You can access the preloaded `blz` dictionary like this: blz["R"]
    
    let flag=false;
    let sum= [...bs.matchAll(/([A-Z]{1}[a-z]?([0-9]{1,2})?)/g)].map(m=>m[1]).reduce(
      (sum,curr)=>{
        
        let x=[...curr.matchAll(/([0-9]{1,2})/g)].map(m=>m[1]);
        let y=[...curr.matchAll(/([A-Z]{1}[a-z]?)/g)].map(m=>m[1])[0];
        if(x==='W' || blz[y]===undefined) flag=true;
        sum+=x.length===1?blz[y]*parseInt(x):blz[y];
        return sum;
      },0
    );
    return flag?'Foul':(sum>147)?'invalid data':sum;
  }
  ///////////
  function frame(balls) {

    let regex = /([RYGPW]|B[nek])(\d*)/g
    ,   match = null
    ,   score = 0;
  
    while (match = regex.exec(balls))
      if (match[1] === 'W')
        return 'Foul';
      else
        score += blz[match[1]] * (match[2] || 1);
  
    return score > 147 ? 'invalid data' : score;
  
  }
  ///////////
  function frame(balls) {
    if (/W/.test(balls)) return 'Foul'
    let score = 0
    balls.replace(/([A-Z][a-z]?)(\d*)/g, (m, color, count) => {
      count = count || 1
      score += blz[color] * count
    })
    if (score > 147) return 'invalid data'
    return score
  }