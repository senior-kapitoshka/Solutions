function getElement(array, indexes) {
    let res=array[indexes[0]];
    for(let i=1;i<indexes.length;++i){
      res=res[indexes[i]];
    }
    return res;
  }
  ///////////
  function getElement(array, indexes) {
    return indexes.reduce((a, i) => a[i], array);
  }
  //////////////
  const getElement = require('lodash/get');
  /////////////
  const getElement = (array, indexes) => {
    let res = array.slice()
  
    for (let i of indexes) {
      res = res[i]
    }
  
    return res
  }
  ///////////
  function getElement(array, indexes) {
    var result= "array"
    for(var i=0; i<indexes.length;i++){
      result+="[" + indexes[i] +"]";
    }
    return eval(result)
  }
  ///////////
  function getElement(a, j) {
    for (let i of j){
      a = a[i]
    }
    return a
  }