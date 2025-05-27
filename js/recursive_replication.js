function replicate(times, number) {
    let res=[];
    
    const recs = (times, number) =>{
      if(times<=0) return;
      res.push(number);
      return recs(times-1,number);
    }
    recs(times,number);
    return res;
  }

  ///////////

  function replicate(times, number) {
    return times > 0 ? [number, ...replicate( times - 1, number )] : [];
  }

  ///////////
  function replicate(times, number) {
    return times < 1? [] : [number].concat(replicate(times - 1, number));
  }
  ///////
  function replicate(times, number) {
    return times > 0 ? Array(times).fill(number) : [];
  }
  /////////
  function replicate(times, number) {
    return Array.from({length: times}, () => number);
  }
  //////////
  