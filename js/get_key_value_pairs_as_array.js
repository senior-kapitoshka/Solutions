function keysAndValues(data){
    return Object.keys(data).reduce((res,curr)=>{
      res[0].push(curr);
      res[1].push(data[curr]);
      return res;
    },[[],[]]);
  }
  //////////
  function keysAndValues(data){
    return [Object.keys(data), Object.values(data)];
}