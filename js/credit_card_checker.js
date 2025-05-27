const validCard=(c)=>{
    return c.replace(/ /g,'').split('')
    .reduce((res,curr,i)=>{
      let x=parseInt(curr);      
      return res+=i%2===0?
            (x*2>9?
             x*2-9:x*2)
            :x
    }
    ,0)%10===0;
  }

  ///////////
  function validCard ( card ) {
    return !([...card.replace(/ /g, '')].reduceRight((sum, digit, index) => {
      digit = +digit;
      
      return sum += index % 2 ? digit : ((digit = 2 * digit) > 9 ? digit - 9 : digit);
    }, 0) % 10);
  }
  ///////
  