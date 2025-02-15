function highestValue(a, b) {
    let as=a.split("").reduce((acc,curr)=>acc+curr.charCodeAt(),0);
    let bs=b.split("").reduce((acc,curr)=>acc+curr.charCodeAt(),0);
    return as>bs?a:as<bs?b:a;
  }
  /////////////
  function highestValue(a, b) {
    const getSum = (str) => {
      return str.split('').reduce((acc, cur) => acc + Number(cur.codePointAt(0)), 0);
    }
    return getSum(b) > getSum(a) ? b : a;
  }
  ////////////
  function highestValue(a, b) {
    return [...a].reduce((c, d) => c + d.charCodeAt(), 0) >= [...b].reduce((c, d) => c + d.charCodeAt(), 0) ? a : b
  }
  //////////
  