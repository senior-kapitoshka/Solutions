function createDict(k, val){
    let res={};
    k.forEach((x,i)=>res[x]=val[i]==undefined?null:val[i]);
    return res;
  }

  /////////////////
  function createDict(keys, values){
    return keys.reduce(function(o, v, i){
      return o[v] = i in values ? values[i] : null, o;
    }, {});
  }

  ////////////
  createDict=(a,b)=>a.reduce((a,c,d)=>((a[c]=b[d]??null)||1)&&a,{})