function newYorker(t) {
    return  t.split(".").map(s=>{
                                if(s!=="" && s!==" "){return s+" my guy."}
                                 return s;} 
                            ).reduce((acc,curr)=>acc+curr,new String);
  }

  /////////////
  newYorker=(t)=>t.split('.').join(' my guy.')

  /////////
  function newYorker(text) {
    return text.replace(/\./g,' my guy.')
 }