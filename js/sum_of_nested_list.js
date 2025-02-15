const sumNested = arr => {
  return arr.flat(15).reduce((sum,curr)=>sum+=curr,0);
};

////////////
const sumNested = arr => arr
  .toString()
  .split(',')
  .reduce((acc, curr) => acc + Number(curr), 0)

/////////
const sumNested = arr => {
  if (Array.isArray(arr)) {
    return arr.reduce(function(accumulator, currentValue) {
      return accumulator + sumNested(currentValue);
    }, 0);
  } else {
    return arr;
  }
};

///////////
const sumNested = arr => 
arr.flat(Infinity).reduce((a,b) => a+b, 0) 
//////////
const sumNested = arr =>
  arr.reduce((pre, val) => pre + (Array.isArray(val) ? sumNested(val) : val), 0);
  ///////////
