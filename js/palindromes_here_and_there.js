
function convertPalindromes(n) {
    return n.reduce((res,i)=>{
      let s=i.toString();
      s===s.split('').reverse().join('')?res.push(1):res.push(0);
      return res;
    },[]);
  };
  /////////////
  function convertPalindromes(numbers) {
    return numbers.map(str => 
        Number(str.toString() == str.toString().split('').reverse().join('')))
  };

  /////////////
  function convertPalindromes(numbers) {
    return numbers.map(v=>+(v===+[...v+''].reverse``.join``))
 };