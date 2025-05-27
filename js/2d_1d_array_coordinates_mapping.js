function to1D(x, y, sz) {
    let cnt=0;
    for(let j=0;j<sz[1];++j){
      for(let i=0;i<sz[0];++i){
        if(i===x && j===y) return cnt;
        ++cnt;
      }
    }
  }
  
  function to2D(n, sz) {
    let cnt=0;
    for(let j=0;j<sz[1];++j){
      for(let i=0;i<sz[0];++i){
        if(cnt++===n) return [i,j];
      }
    }
  
  }
  //////////
  function to1D(x, y, [w,h]) {
    return y * w + x;
  }
  
  function to2D(n, [w,h]) {
    return [n%w, n/w|0];
  }

  /////////
  function to1D(x, y, [w]) { return y*w+x }

function to2D(n, [w]) { return [n%w, ~~(n/w)] }