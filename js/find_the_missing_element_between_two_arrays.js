function findMissing(arr1, arr2) {
    let mp={};
    let mp2={}
    arr1.forEach(_=>mp[_]=mp[_]+1||1);
    arr2.forEach(_=>mp2[_]=mp2[_]+1||1);
    for(let i of arr1){
      if(mp2[i]==undefined || mp[i]-mp2[i]===1) return i;
    }
    return 0;
  }
  ///////////
  const findMissing = (arr1, arr2) => {
    arr1 = arr1.sort();
    arr2 = arr2.sort();
    for(let i = 0; i < arr1.length; i++){
      if(arr1[i] != arr2[i]) return arr1[i];
    }
  }
  ///////////
  function findMissing(arr1, arr2) {
    const reducer = (accumulator, currentValue) => accumulator + currentValue
 return arr1.reduce(reducer, 0) - arr2.reduce(reducer, 0);
 }
 ////////////
 const sum = arr => arr.reduce((a, b) => a + b, 0);

const findMissing = (arr1, arr2) => sum(arr1) - sum(arr2);
/////////
function findMissing(arr1, arr2) {
    return arr1.reduce((a,b)=>a^b,0) ^ arr2.reduce((a,b)=>a^b,0)
  }
  ////////
  function findMissing(arr1, arr2) {
    return arr1.sort().filter((e,i) => arr2.sort()[i] !== e)[0]
    }