const freezing=(obj)=>{
    Object.keys(obj).forEach(k=>{
      if(typeof obj[k] === 'object')
        freezing(obj[k]);
    }
       );
    return Object.freeze(obj);
  }
  
  const stone =freezing( {
    feature: 'earth',
    style: {
      color: 'black'
    }
  })


  //////////////
  const stone = Object.freeze({
    feature: 'earth',
    style: Object.freeze({
      color: 'black'
    })
  });

  ////////////
  