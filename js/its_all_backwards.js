function flipper(sA){
    Object(sA).reverse().forEach(function(s,id,arr){
      if(s.length!=1) arr[id]=s.substring(0,s.length-1).toLowerCase()
        +s.substring(s.length-1).toUpperCase();
      else arr[id]=s;
    });
    return sA.join(" ");
  }

  ///////////
  function flipper(stringArr){
    return stringArr.map(v => v.slice(0,-1).toLowerCase() + (v.length >1 ? v.substr(-1).toUpperCase() : v))
    .reverse().join(' ')
    }
    ////////////
    function flipper(stringArr){
        return stringArr.reverse().map(e => e.length>1?e.slice(0,-1).toLowerCase()+e.slice(-1).toUpperCase():e).join(' ');
      }

      ///////////
      function flipper(stringArr){
        return stringArr.map(el => {
          return el.length < 2 ? el 
               : el.toLowerCase().replace(/\w$/, el => el.toUpperCase());
        }).reverse().join(' ');
      }