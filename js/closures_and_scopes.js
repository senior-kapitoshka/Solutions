function createFunctions(n) {
    var cs = [];
  
    for (let i=0; i<n; i++) {
      cs.push(function() {
        return i;
      });
    }
    
    return cs;
  }
  ///////////
  function createFunctions(n) {
    var callbacks = [];
    
    var factory = function(x){
      return function(){
        return x;
      };
    };
  
    for (var i=0; i<n; i++) {
      callbacks.push(factory(i));
    }
    
    return callbacks;
  }
  ////////////
  let createFunctions = (n) => Array.from(Array(n), (_, i) => () => i);
  /////////
  