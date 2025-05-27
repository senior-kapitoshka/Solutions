function splitTheBill(x) {
    console.log(x);
  
    let vals=Object.values(x);
     let y=(vals.reduce((lhs,rhs)=>lhs+rhs))/vals.length;
    Object.keys(x).map((val)=>x[val]=Number((x[val]-y).toFixed(2)));
    return x;
  }

  ////////////
  function splitTheBill(x) {
    var average = 0;
    var count = 0;
    
    for(item in x){
      average += x[item];
      count++;
    }
    average = average / count;  
    
    for(item in x){
      x[item] = Math.round((x[item] - average) * 100) / 100;
    }
    
    return x;
  }
  //////////
  