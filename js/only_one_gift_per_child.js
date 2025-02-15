let set=new Set();

function handOutGift(n) {
  if(set.has(n))throw new Error();
  return set.add(n);
}
/////////////
const handOutGift =
  ((arr = []) => name => arr.includes(name) ? (() => {throw new Error()})() : arr.push(name))
  ();
  /////////////
  