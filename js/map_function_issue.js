var func = function(i){
    return i%2===0
}

const map=(a, f)=>
  (typeof f!=='function')?
    'given argument is not a function':
    a.every(i=> !isNaN(parseInt(i)))?
    a.map(i=>f(i)):
  'array should contain only numbers'


  /////////////
  const func = item =>
  !(item % 2);

const map = (arr, somefunction) =>
  typeof somefunction !== `function` ? `given argument is not a function` :
    arr.some(isNaN) ? `array should contain only numbers` :
      arr.reduce((pre, val) => [...pre, somefunction(+val)], []);