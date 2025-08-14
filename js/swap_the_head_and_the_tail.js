function swapHeadAndTail(arr) {
  for(let i=0,
      j=arr.length%2===0?
      arr.length/2:
      Math.ceil(arr.length/2),
      n=arr.length;
      j<n;++i,++j){
    let x=arr[i];
    arr[i]=arr[j];
    arr[j]=x;
  }
  
  return arr;
}

////////////////////

const swapHeadAndTail = (arr, mid = arr.length / 2) => [
  ...arr.slice(-mid),
  ...arr.slice(mid, -mid), 
  ...arr.slice(0, mid)
];


///////////////
const swapHeadAndTail = arr =>
  (val => [...arr.slice(-val), ...arr.slice(val, -val), ...arr.slice(0, val)])
  (arr.length / 2);

  /////////

  const swapHeadAndTail = arr => {
  const len = arr.length
  const midd = ~~(len / 2)

  if(len % 2 === 1) {
    return [...arr.slice(midd + 1), arr[midd], ...arr.slice(0, midd)]
  } else {
    return [...arr.slice(midd), ...arr.slice(0, midd)]
  }
}