function spot(s1,s2){
    let res =[];
    for(let i=0,n=s1.length;i<n;++i){
      if(s1[i]!==s2[i]){
        res.push(i);
      }
    }
    return res;
  }

  //////////////
  function spot(s1,s2){
    return s1.split("").map((v,i) => v != s2[i] ? i : "").filter(v => typeof v == "number");
  }

  /////////////
  const spot = (s1, s2) =>
    [...s1].reduce((pre, val, idx) => val !== s2[idx] ? [...pre, idx] : pre, []);

  ///////////
  function spot(a, b) {
    return [...a].map((c, i) => i).filter(i => a[i] != b[i]);
  }

  /////////
  