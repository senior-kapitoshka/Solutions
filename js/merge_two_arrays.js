function mergeArrays(a, b) {
    var res=[];
    let flag=true;
    let i=0;
    if(a.length<b.length){
      n=a.length;
    }else{
      n=b.length;
      flag=false;
    }
    for(;i<n;++i){
      res.push(a[i]);
      res.push(b[i]);
    }
    if(!flag){
      while(i<a.length){
        res.push(a[i++]);
      }
    }else{
      while(i<b.length){
        res.push(b[i++]);
      }
    }
    return res;
  }
  ///////////////
  const _ = require('lodash')

function mergeArrays(a, b) {
  return _.compact(_.flatten(_.zip(a, b)))
}

///////////
const mergeArrays = ( $ , $2) => 
    [...Array($.length + $2.length)].reduce((acc, el, i) =>
         acc.concat( $[i],$2[i]), []).filter(e => e)
//////////
function mergeArrays(a, b) {
    let answer = [];
    
    for (let i = 0; a[i] || b[i]; i++) {
      if (a[i]) {answer.push(a[i])};
      if (b[i]) {answer.push(b[i])};
    }
    
    return answer;
  }

  ////////
  function mergeArrays(a, b, result=[]) {
    // new Array    make a new empty array with the longer input array
    //   .fill      give each index something to map over
    //   .forEach   for each index in indexArray
    //              push the corresponding a & b value to resultArray
    new Array(a.length < b.length ? b.length : a.length)
      .fill()
      .forEach( 
        (_, i) => result.push(a[i], b[i])
      )
    
    // strip any undefined entries out of resultArray, and return it
    return result.filter(x=>!!x)
  }

  /////////
  function mergeArrays(a, b) {
    // your code here
    var returnArray = [];
    var counter = 0;
    while (a[counter] || b[counter] ){
      if(a[counter]){
        returnArray.push(a[counter]);
      }
      if(b[counter]){
        returnArray.push(b[counter]);
      }
      counter++;
      
     }
     return returnArray;
  }