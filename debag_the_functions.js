function multi(a) {
    return a.reduce((acc,curr)=>acc*curr,1);
  }
  function add(a) {
    return  a.reduce((acc,curr)=>acc+curr,0);
  }
  function reverse(str) {
    return str.split("").reverse().join("");
  }

  /////////////
  function multi(arr) {
    return arr.reduce((a, b) => a * b)
  }
  function add(arr) {
    return arr.reduce((a, b) => a + b)
  }
  function reverse(str) {
    return str.split('').reverse().join('')
  }

  ///////////
  const multi = arr => arr.reduce((a,b)=> a*b);

const add = arr=> arr.reduce((a,b)=> a+b);

const reverse = str => str.split('').reverse().join('');