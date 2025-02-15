Array.prototype.size = function() {
    let cnt=0;
    this.forEach((_)=>++cnt);
    return cnt;
  };

  ////////////
  Array.prototype.size = function() {
    return this.reduce(acc => acc + 1, 0);
  };
  //////////
  Array.prototype.size = function() {
    let count = 0, i;
    for(i in this) 
      if(this.hasOwnProperty(i))
        count++;
    return count;
  };