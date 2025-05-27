Array.prototype.map=function(f){
    return this.reduce((arr,val)=>{ arr.push(f(val));return arr;},[]);
  }

  ////////////
  Array.prototype.map = function(func){
    var res = [];
    for(var i=0;i<this.length;i++){
      res.push(func(this[i]));
    }
    return res;
  }
  //////////
  Array.prototype.map = function(func){
    var res = [];
    this.forEach(function(...args){res.push(func(...args));});
    return res;
  }