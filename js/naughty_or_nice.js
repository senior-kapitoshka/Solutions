function getNiceNames(p){
    return p.reduce((arr,i)=>{
      if(i.wasNice)arr.push(i.name);
      return arr;
    },[])
  }
  
  function getNaughtyNames(p){
    return p.reduce((arr,i)=>{
      if(!i.wasNice)arr.push(i.name);
      return arr;
    },[])
  }

  ///////////
  function getNiceNames(people){
    return people.filter(p => p.wasNice).map(p => p.name);
  }
  
  function getNaughtyNames(people){
     return people.filter(p => !p.wasNice).map(p => p.name);
  }

  ///////
  const getNiceNames = people =>
  people.reduce((pre, val) => val.wasNice ? [...pre, val.name] : pre, []);

const getNaughtyNames = people =>
  people.reduce((pre, val) => val.wasNice ? pre : [...pre, val.name], []);