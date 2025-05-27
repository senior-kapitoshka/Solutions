function capital(cs){
    return cs.map((i)=>`The capital of ${i.state||i.country} is ${i.capital}`);
  }

  /////////
  function capital(capitals){
    return capitals.map(function (hash) {
      return Object.keys(hash).reduce(function (a, b) {
        return 'The capital of ' + hash[a] + ' is ' + hash[b] 
      })
    })
  }