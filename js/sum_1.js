function sum(lhs) {
    return lhs===undefined?
      0:
    (rhs)=>rhs===undefined?
      lhs:
      sum(lhs+rhs) ;
  }

  //////////////
  function sum(num) {
    if(num === undefined) return 0;
    return function(next) {
      if(next === undefined) return num;
  
      return sum(num + next);
    }
  }


  ////////////
  function sum(x) {
    const nil = a => a == undefined;
    return nil(x) ? 0 : n => nil(n) ? x : sum(n + x);
  }

  ////////
  let s = 0;
function sum(n) {
  if(n==undefined){
    let t = s;
    s = 0;
    return t;
  } s+= n;
  return sum;
}
/////////
sum=(a,b=0)=>a==void 0?b:c=>sum(c,b+a)
////////////
function sum(a = 0) {
    function f (b = 0) {
        return (a += b, arguments.length ? f : a);
    }

    return arguments.length ? f : a;
}

/////////
function sum(...args) {
    if (args.length == 0) return 0;
    return (...next) => {
      if ([].slice.call(next).length == 0) return [].slice.call(args).reduce( (a, b) => a += b )
      return sum( [].slice.call(args).reduce( (sum, current) => sum += current ) + [].slice.call(next).reduce( (sum, current) => sum += current ) );
    }
  }