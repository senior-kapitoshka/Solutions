function arrayInfo(arr){
    let i=0,f=0,s=0,w=0;
    arr.forEach((a)=>{
      if(typeof(a)==="number"){
        if(a%1===0)++i;
        else ++f;
      }else if(typeof(a)==="string"){
        if(a.match(/[ ]+/)) ++w;
        else ++s;
      }
    })
    return arr.length===0?
      "Nothing in the array!":
      [[arr.length],
       [i===0?null:i],
       [f===0?null:f],
       [s===0?null:s],
       [w===0?null:w],
      ]
  }
  ///////////
  function arrayInfo(arr){
    if (arr.length === 0) return 'Nothing in the array!';
    return [[arr.length], 
            [arr.filter(x => x === parseInt(x)).length || null],
            [arr.filter(x => typeof x === 'number' && (/\./).test(x)).length || null], 
            [arr.filter(x => typeof x === 'string' && x !== ' ').length || null], 
            [arr.filter(x => x === ' ').length || null]];
  }
  ///////////
  function arrayInfo(arr){
    if (arr.length == 0) {return 'Nothing in the array!';}
    var a = arr.length;
    var b = (arr.filter(x => Number.isInteger(x)) || []).length;
    var c = (arr.filter(x => typeof x == "number" && !Number.isInteger(x)) || []).length;
    var d = (arr.filter(x => typeof x == "string" && x !== " ") || []).length;
    var e = (arr.filter(x => x == " ") || []).length;
    
    return [[a || null], [b || null], [c || null], [d || null], [e || null]]
  }
  ///////////
  function arrayInfo(arr) {
    if (!arr.length) return 'Nothing in the array!'
    
    return [
      x => true,
      Number.isInteger,
      x => typeof x == 'number' && !Number.isInteger(x),
      x => typeof x == 'string' && x != ' ',
      x => x == ' '
    ].map(f => [arr.filter(f).length || null])
  }
  //////////
  