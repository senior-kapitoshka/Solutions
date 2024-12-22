function strCount(o){
    let cnt=0;
    for(k in o){
      cnt+= (typeof o[k]==="string")?1:
      (typeof o[k]==="object")?strCount(o[k]):
      0;
    }
    return cnt;
  }

  ////////////
  function strCount(obj){
    let count = 0;
    for (key in obj) {
      if (typeof obj[key] == 'string') count++;
      if (typeof obj[key] == 'object') count += strCount(obj[key]);
    }
    return count;
  }
  /////////
  const strCount = obj =>
    typeof obj !== `string` ?
             Object.values(obj || {})
                        .reduce(
                                (pre, val) => pre + strCount(val)
                                        , 0) :
                                                 1;
  