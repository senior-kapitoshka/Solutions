const makePlural = (opt, n) => {
    return (n % 10 === 1 && n!==11)?opt[0]:
                  ( n % 10 >1 && n % 10 <5 && (n<10 || n>19))?opt[1]:
                          opt[2];
  }

  ///////////////
  const makePlural = (options, number) => {
    if (number >= 5 && number <= 20) return options[2];
    switch (number % 10) {
      case 1:
        return options[0];
      case 2:
      case 3:
      case 4:
        return options[1];
      default: 
        return options[2];
    }
  }
  /////////////
  makePlural=(Q,S)=>Q[10<S&S<15|!(S%=10)|4<S?2:1<S?1:0]
  ////////////
  const makePlural = (options, number) => {

    if (/(^1[1234]|[567890])$/.test(number))
      return options[2];
  
    if (number % 10 === 1)
      return options[0];
  
    return options[1];
  
  }
  /////////
  const makePlural = (options, number) => { 
    number = number.toFixed(0);
    return number.match(/\d*(5|6|7|8|9|0|11|12|13|14)$/) ? options[2] : (number.match(/\d*(2|3|4)$/) ? options[1] : options[0]);
 }
 ///////////
 const makePlural = (options, number) => {
    return options[number % 10 === 1 && number !== 11 ? 0
                   : number % 10 < 5 && number % 10 !== 0 && (number < 11 || number > 14) ? 1 : 2];
  }
  /////////
  