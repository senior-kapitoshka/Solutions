const carry = (f)=>{
    return (lhs)=>{
      return (rhs)=>{
        return f(lhs,rhs);
      }
    }
  }
  
  const add=carry( (lhs,rhs)=>{
      return lhs+rhs;
    } );
  
    
    ///////////
    const add = a => b => a+b;
    ///////
    function add(x) {
        return function(y) {
          return x + y
        }
      }