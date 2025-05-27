function oddBall(arr){
    for(let i=0,n=arr.length;i<n;++i){
      if(typeof arr[i]==='number' && arr[arr[i]]==='odd') return true;
    }
    return false;
  }

  //////////
  function oddBall(arr){
    return arr.includes(arr.indexOf("odd"));
}

///////////
function oddBall(arr){
    return arr.some(e => arr[e] === 'odd');
  }

  ///////////
  