Array.prototype.reverse = function() {
    let i=0,
        j=this.length-1;
    while(i<=j){
      let t=this[i];
      this[i]=this[j];
      this[j]=t;
      ++i;--j;
    }
    return this;
  };
  ///////////
  Array.prototype.reverse = function() {
    var arr = this.splice(0);  
    
    while(arr.length) {
      this.push(arr.pop());
    }   
    
    return this;
  };
  /////////////
  Array.prototype.reverse = function() {
    var copy = this.slice(0);
    return this.forEach(function(el, i){ this[i] = copy.pop();}, this), this;
  };