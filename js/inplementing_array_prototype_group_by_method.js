Array.prototype.groupBy = function(fn) {
    return this.reduce((res,curr)=>{
      if(typeof fn ==="function"){
        if(!res[fn(curr)]){
          res[fn(curr)]=[];
          res[fn(curr)].push(curr);
        }else res[fn(curr)].push(curr);
      }else{
        if(!res[curr]){
          res[curr]=[];
          res[curr].push(curr);
        }else res[curr].push(curr);
      }
      return res;
    }
                       ,{})
  }
  /////////////
  Array.prototype.groupBy = function(fn) {
    return this.reduce(function(o, a){
      var v = fn ? fn(a) : a;
      return (o[v] = o[v] || []).push(a), o;
    }, {});
  }
  /////////
  const _ = require('lodash');
Array.prototype.groupBy = function(fn){
  return _.groupBy(this, fn);
}