/*
fail random tests
var buy = function(x, arr){
  let dict = arr.reduce((dict,curr,i)=>{
    dict[curr]=i;
    return dict;
  },{});
  for(let i=0,n=arr.length;i<n;++i){
    if(dict[x-arr[i]]!==undefined) return [i,dict[x-arr[i]]];
  }
  return null;
};*/
var buy = function(x, arr){
    for (var i=0; i<arr.length-1; ++i)
      for (var j=i+1; j<arr.length; ++j)
        if (arr[i]+arr[j]==x)
          return [i,j]
    return null;
  };