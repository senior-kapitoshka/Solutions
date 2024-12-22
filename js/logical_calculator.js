function logicalCalc(a, op){
    var res=a[0];
    switch(op){
        case "AND": return a.slice(1).reduce((acc,curr)=> acc&curr,res)==0?false:true;
        case "OR": return a.slice(1).reduce((acc,curr)=> acc|curr,res)==0?false:true;
        case "XOR": return a.slice(1).reduce((acc,curr)=> acc^curr,res)==0?false:true;
    }
  }

  //////////////
  var ops = {
    'AND': (a, b) => a && b,
    'OR': (a, b) =>  a || b,
    'XOR': (a, b) => a !== b
  }
  
  
  function logicalCalc(array, op){
    return array.reduce(ops[op]);
  }

  ///////////
  function logicalCalc(array, op){
    if(op === 'AND')return array.every(v => v);
    else if(op === 'OR')return array.some(v => v);
    else return !!array.reduce((s, v) => s ^ v);
  }
  /////////////
  function logicalCalc(array, op) {
    return eval(array.map(x => +x).join({AND: "&", OR: "|", XOR: "^"}[op])) !== 0
  }
  //////////
  const logicalCalc = (array, op) =>
    array.reduce((a, b) =>
      op === 'AND' ? a && b : op === 'OR' ? a || b : a !== b
    );

    ////////////
    function logicalCalc(array, op){
        var op = {AND:"&&",OR:"||",XOR:"!="}[op];
        return array.reduce((a,b)=>eval(`${a}${op}${b}`))
      }

    ///////////
      