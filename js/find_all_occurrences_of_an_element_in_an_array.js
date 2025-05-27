const findAll = (a, n) => {
    return a.reduce((res,curr,i)=>{
      if(curr===n) res.push(i);
            return res;
    },[])
  }

  /////////////
  const findAll = (nums, find) => nums
  .reduce((acc, num, index) => num === find ? [...acc, index] : acc, [])

  ///////////
  const findAll = (arr, n) => arr.map((el, i) => el === n ? i : 'str').filter(e => e !== 'str')
  //////
  