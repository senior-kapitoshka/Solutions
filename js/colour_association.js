function colourAssociation(a){
    return a.reduce((res,curr)=>{
      let obj=new Object;
      obj[curr[0]]=curr[1];
      res.push(obj);
      return res; 
    },[]);
  }

  ///////////
  const colourAssociation = array => 
  array.map(([colour, association]) =>
   ({[colour]:association}))
  //////////////

  function colourAssociation(array){
    return array.map(x => ({ [x[0]]: x[1]}));
  }

  ///////
  
