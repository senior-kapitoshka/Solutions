const once=(fn)=> {
    let flag=1;
    return function () {
      if(flag){
        flag=0;
        return fn.apply(this,arguments);
      }
      return undefined;
    }
  }

  //////////
  const once = (fn, cnt = 0) =>
  (...args) => cnt++ ? undefined : fn(...args);

  ///////////
  function once(fn) {
    let called = false
    return function(...args) {
      if (called === false) {
        called = true
        return fn(...args)
      }
    }
  }