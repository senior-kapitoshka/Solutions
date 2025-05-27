function chain(i, fs) {
    fs.forEach((f)=>i=f(i));
     return i;
   }
   ///////////
   function chain(v, fns) {
    return fns.reduce(function(v, fn) { return fn(v) }, v);
  }
  /////////
  chain = (input, fs) => fs.reduce((acc,x) => x(acc), input);