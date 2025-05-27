function sc(wn){
    let cnt=0
    for(let i=0;i<8;i+=4){
      for(let j=0;j<8;j+=4){
        let t=0;
        for(let x=i;x<i+4;++x){
          for(let y=j;y<j+4;++y){
            t+=wn[x][y];
          }
        }
        if(t>5)cnt+=t;
      }
    }
    return cnt;
  }
  ////////////
  const sc = watermelon =>
  watermelon.reduce((pre, val, idx) => (val.forEach((v, i) => pre[(i > 3) + (idx > 3) * 2] += v), pre), [0, 0, 0, 0])
    .reduce((pre, val) => pre + val * (val > 5), 0);
    ////////////
    function sc(watermelon) {
        let resBigNameCauseTooShort = [0, 0, 0, 0]
        watermelon.forEach((e,i) => {
          e.forEach((x,j) => {
            resBigNameCauseTooShort[(i<4)<<1 | j<4] += x
          })
        })
        return resBigNameCauseTooShort.reduce((s,x) => s + (x>5 && x), 0)
      }