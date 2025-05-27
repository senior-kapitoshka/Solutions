function pluck(objs, name) {
    return objs.reduce((arr,o)=>{
      arr.push(o[name]||undefined);
       return arr;
    },[]);
  }
  //////////
  function pluck(objs, name) {
    return objs.map(function(obj) { return obj[name] });
  }
  ///////
  function pluck(objs, name) {
    return objs.reduce((acc, cur) => 
      acc = cur[name] ? [ ...acc, cur[name] ] : [ ...acc, undefined ]
    , [])
  }
  ////
  