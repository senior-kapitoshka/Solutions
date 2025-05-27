function clean(arr) {
    return arr.filter(function () { return true });
  }
  ///////////
  const clean = arr => arr.filter(_ => true);
  ///////////
  const clean = Object.values
  //////////////
  function clean(arr) {
    var ar=[]
    for(var i=0; i<arr.length; ++i) 
    if (i in arr) 
      ar.push(arr[i]);
    return ar;
  }