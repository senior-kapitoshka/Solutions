function toQueryString (obj) {
    return Object.keys(obj).map((k)=> Array.isArray(obj[k])?
                                obj[k].map((i)=>`${k}=${i}`).join("&"):
                                `${k}=${obj[k]}`).join("&");
  }
  //////////
  const toQueryString = (obj) => Object.keys(obj)
  .reduce((arr, key) => {
    let val = obj[key]
    
    if ( ! Array.isArray(val)) val = [ val ]

    return arr.concat(val.map(v => `${key}=${v}`))
  }, [])
  .join('&')
  //////////
  function toQueryString(o) {
    return [].concat(
        ...Object.keys(o).map(
            k => Array.isArray(o[k]) ?
            o[k].map(v => `${k}=${v}`) :
             `${k}=${o[k]}`
             )
             ).join`&`;
  }
  ///////////