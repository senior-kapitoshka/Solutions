Array.prototype.first = function(){
    if(this.length === 0) return undefined;
    return this[0];
  }
  Array.prototype.last = function(){
    if(this.length === 0) return undefined;
    return this[this.length-1];
  }

////////////////
Array.prototype.first = function() {
    return this[0];
  };
  
  Array.prototype.last = function() {
    return this[this.length-1];
  };
  
  ////////
  Object.assign(Array.prototype, {
    first() {
      return this[0];
    },
    last() {
      return this[this.length - 1];
    },
  });

  ///////////
  Array.prototype.first = function() {
    return this.at(0);
  }
  
  Array.prototype.last = function() {
    return this.at(-1);
  }

  ////////
  