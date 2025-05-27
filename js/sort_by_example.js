function exampleSort(a,e){
  let map={};
  for(let i=0;i<a.length;++i){
    map[a[i]]=(map[a[i]]||0)+1;
  }
  console.log(map);
  let res=[];
  for(let i=0;i<e.length;++i){
    if(map[e[i]]){
      for(let j=0;j<map[e[i]];++j){
        res.push(e[i]);
      }
    }
  }
  return res;
}
//////////////
function exampleSort(arr,exampleArr){
    return exampleArr.flatMap(x => arr.filter(y => x === y));
  }

  ///////////
  const exampleSort = (arr, exampleArr) =>
  exampleArr.reduce(
    (acc, curr) => [...acc, ...arr.filter((num) => num === curr)],
    []
  );
///////////

function exampleSort(arr, exampleArr){
    arr.sort( (x,y) => exampleArr.indexOf(x) - exampleArr.indexOf(y) );
    return arr;
  }
  /////////////
  function exampleSort(arr,exampleArr){
    var ar=[];
    for (var i=0; i<exampleArr.length; ++i)
      for (var j=0; j<arr.length; ++j)
        if (arr[j]==exampleArr[i])
          ar.push(arr[j]);
    return ar;
  }
  /////////
  function exampleSort(arr, ord) {
    const o = ord.reduce((o, n, i) => (o[n] = i, o), {});
    return arr.sort((a, b) => o[a] - o[b]);
  }
  //////////
  const exampleSort = (arr, example) => {

    // cache example array searches (ranks)
    
    let cache = {};
    let rank = value => 
      cache.hasOwnProperty(value)
      ? cache[value]
      : cache[value] = example.indexOf(value);
    
    return arr.sort((a, b) => rank(a) - rank(b));
  }