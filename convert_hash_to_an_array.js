function convertHashToArray(hsh){
    var res=[];
    var keys=Object.keys(hsh);
    for (let i = 0; i < keys.length; i++) {
      res.push([keys[i], hsh[keys[i]]])
    }
    return res;
  }
  ////////////////
  function convertHashToArray(hash){
    let arr = [];
  
    for (let k in hash) {
      arr.push([k, hash[k]]);
    }
  
    return arr.sort();
  }

  //////////////
  const convertHashToArray = o => Object.entries(o).sort();
  /////////////
  function convertHashToArray(hash){
    let result = [];
    Object.keys(hash).sort().map(item => result.push([item,hash[item]]));
    return result;
  }
  /////////////
  function convertHashToArray(hash){
    return Object.entries(hash).sort();
  }
  ///////////
