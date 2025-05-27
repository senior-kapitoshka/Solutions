function secondLargest(array){
    let arr;
    if(array && typeof(array)!=='string')arr=[...new Set(array.map(_=>parseInt(_)).filter(_=>_===0||_))]
                                                     .sort((l,r)=> r-l);
    return !arr?undefined:arr[1];
  }
  ///////////
  function secondLargest(a) {

    return Array.isArray(a) ? a.filter( v => typeof v==="number" ||
                                            (typeof v==="string" && ! Number.isNaN(Number(v)))
                                      )
                               .map( Number )
                               .sort( (a,b) => b-a )
                               .filter( (v,i,a) => i===a.indexOf(v) )
                               [1]
                            : undefined
    ;
  
  }
  ////////
  const secondLargest = array =>
  Array.isArray(array) ? [...new Set(array.filter(val => !isNaN(parseInt(val))).map(Number))].sort((a, b) => b - a)[1] : undefined;
  /////////
  