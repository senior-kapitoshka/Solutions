function wasCalledWithNew() {
    return new Boolean(new.target);
  }
  /////////
  function wasCalledWithNew() {
    return Boolean();
    
  }
  
  wasCalledWithNew.prototype.valueOf = function() {
    return true;
  }
  //////
  function wasCalledWithNew() {
    if (new.target) this.valueOf = () => true
    return false
  }
  //////
  