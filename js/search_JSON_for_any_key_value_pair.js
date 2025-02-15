function getCharacters(o, k, v) {
    var res = [];
    for(let c of o.characters){
      if(c[k]!==undefined && c[k].toLowerCase()===v.toLowerCase()){
        res.push(c);
      }
    }
    return res;
  }

  ////////////
  const getCharacters = (obj, key, val) => {
    val = val.toLowerCase();
    return obj.characters.filter(v => (v[key] || '').toLowerCase() == val);
  }

  ////////////
  function getCharacters(obj, key, val) {
    return obj.characters.filter(c => RegExp("^" + val + "$", "i").test(c[key]));
  }

  ////////////
  