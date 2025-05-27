function findAB(ns,c){
    if (c==0) return [ns[0], 0];
    let n=ns.length;
    for (let i=0; i < n; ++i) {
        let t = c / ns[i];
        if (t != t || 0) continue;
        if (ns.indexOf(t, i + 1)>=0) return [ns[i], t];
    }
    return null;
  }

  //////////
  function findAB(ns,c){
    if (c==0) return [ns[0], 0];
    let n=ns.length;
    for (let i=0; i < n; ++i) {
        let t = c / ns[i];
        if (t != t || 0) continue;
        if (ns.indexOf(t, i + 1)>=0) return [ns[i], t];
    }
    return null;
  }