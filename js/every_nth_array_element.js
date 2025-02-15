function every(arr, int=0, st=0){
    let res=[];
    for(let i=st,n=arr.length;i<n;i+=int===0?1:int){
      res.push(arr[i]);
    }
    return res;
  }
  /////////////
  function every(arr, interval = 1, start = 0){
	return arr.slice(start).filter((a, i) => i % interval === 0)
}
////////////
const every = (arr, interval, start) =>
    arr.slice(start).filter((_, idx) => !(idx % interval));
//////////
