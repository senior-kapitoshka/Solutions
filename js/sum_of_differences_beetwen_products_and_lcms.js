function gcd(a, b) {
    return !b ? a : gcd(b, a % b);
}

function lcm(a, b) {
    return (a * b) / gcd(a, b);   
}

function sumDifferencesBetweenProductsAndLCMs(ps){
  let res=0;
  ps.map((p)=>{
    if((p[0]===1 && p[1]===1) ||(p[0]===0 && p[1]===0))return 0;
    else{
      res+=(p[0]*p[1]-lcm(p[0],p[1]));
    }
    return res;
  });
  return res;
}

////////////////
function sumDifferencesBetweenProductsAndLCMs(pairs){
    const gcd = (x,y) => x == 0 ? y : gcd(y % x, x)
    const lcm = (x,y) => x * y == 0 ? 0 : x * y / gcd(x,y)  
    return pairs.map(c => c[0] * c[1] - lcm(c[0],c[1])).reduce((a,c) => a + c, 0);
  }
  ////////////
  const gcd = (a, b) =>
  b ? gcd(b, a % b) : a || 1;

const lcm = (a, b) =>
  a * b / gcd(a, b);

const sumDifferencesBetweenProductsAndLCMs = pairs =>
  pairs.reduce((sum, [a, b]) => sum + a * b - lcm(a, b), 0);