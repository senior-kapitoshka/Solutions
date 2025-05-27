Array.prototype.only = function(k){
    return k.sort((lhs,rhs)=>lhs-rhs).reduce((res,curr)=>{
      res.push(this[curr]);
      return res;
    },[]);
  }
  //////////////
  Array.prototype.only = function(k) {
    return this.filter((e, i) => k.includes(i));
  }
  //////////
  Array.prototype.only = function(keys) {
    return keys.sort((a,b) => a-b).map(x => this[x])
  }
  