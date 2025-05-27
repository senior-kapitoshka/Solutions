function validateEAN(eanCode) {
    let sum=eanCode.split('').slice(0,12)
      .reduce((sum,curr,i)=>
                        {
                          sum+=i%2===0?curr*1:curr*3;
      return sum;
                        },0);
   return (sum%10===0 && parseInt(eanCode[12])===0) || 10-(sum)%10===parseInt(eanCode[12]);
  }

  ////////////////
  function validateEAN(code) {
    for (var sum = 0, i = 0; i < 12; i++) {
      sum += code[i] * ((i & 1) ? 3 : 1)
    }
    
    return (10 - (sum % 10)) % 10 === +code[12]
  }
  //////////////
  function validateEAN(eanCode){
  
    var sumMod = eanCode.slice(0, 12).split('').reduce(function(s, v, i){
      return s + (i % 2 ? v * 3 : +v);
    }, 0) % 10;
    
    return eanCode[12] == (sumMod ? 10 - sumMod : 0);
  }
  ///////////
  const validateEAN = eanCode =>
  (10 - [...eanCode.slice(0, -1)]
  .reduce((pre, val, idx) => pre + val * (idx % 2 ? 3 : 1), 0) % 10) % 10 == eanCode[12];