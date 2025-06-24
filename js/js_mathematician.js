function calculate() {
    let x=[...arguments].reduce((a,b)=>a+b,0);
    return function(){
      let y=[...arguments].reduce((a,b)=>a+b,0);
      return x+y;
    }
  }
  ///////////
  const calculate = (...args1) => (...args2) => [...args1, ...args2].reduce((s, v) => s + v);
  //////////
  function calculate(...a) {
    return function (...b) {
      return [...a, ...b].reduce((sum, n) => sum + n)
    };
  }
  /////////////
  