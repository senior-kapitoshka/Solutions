function imageFilter(arr) {
    let reg=RegExp("^([\\w]+)\\.(jpg|png|tiff|svg|bmp|gif)$","i");
    let res=[];
    for(let a of arr){
      if(a.match(reg)){
        let regs=a.match(reg);
        res.push([a,regs[1],regs[2]]);
      }else{
        res.push(null);
      }
    }
    return res;
  }

  ///////////
  function imageFilter(arr) {
    return arr.map(file => file.match(/^(.+)\.(bmp|gif|jpg|png|tiff)$/i))
  }
  ////////////
  