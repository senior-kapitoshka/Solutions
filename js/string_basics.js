function getUsersIds(str){
    return str.replace(/#/g,'')
      .toLowerCase()
      .split(',').map(s=>s.trim()
                              .replace(/^uid/g,'')
                        .replace(/,/g,'').trim()
                       );
  }
  ///////////////
  function getUsersIds(str){
    return str.toLowerCase().split(', ').map(e=>e.trim().replace(/^(\#*uid)|\#+/g,'').trim());
  }
  ///////////
  const getUsersIds = str =>
  str.toLowerCase()
     .replace(/^[\s#]*uid[\s#]*|#|[\s#]+$/g, '')
     .split(/\s*,\s+uid\s*/);
     //////
     function getUsersIds(str){
        return str.replace(/^\s+|\s*\buid\s*|#|(?<=,)\s+|\s+(?=,)|\s+$/g, "").toLowerCase().split(",");
      }