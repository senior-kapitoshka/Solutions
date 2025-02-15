function left$( str, i ) {
    if(typeof(i)==="number"){
      return Math.abs(i)>=str.length?str:
        i>=0?str.substring(0,i):
        str.substring(0,str.length+i);
    }else if(typeof(i)==="string"){
      if(i.length===1){
        return str.substring(0,str.indexOf(i));
      }else{
        return str.substring(0,str.indexOf(i));
      } 
    }else{
      return str[0];
    }
    
  }
  
  function right$( str, i ){
    if(typeof(i)==="number"){
      return Math.abs(i)>=str.length?str:
        i>=0?str.substring(str.length-i):
        str.substring(Math.abs(i));
    }else if(typeof(i)==="string"){
      if(i.length===1){
        return str.substring(str.lastIndexOf(i)+1);
      }else{
        return str.substring(str.lastIndexOf(i)+i.length);
      }
    }else{
      return str[str.length-1];
    }
  }
/////////////////////////
const left$ = (str, i = 1) =>
    typeof i === `string` ? str.split(i).shift() : str.slice(0, i);
  
  const right$ = (str, i = 1) =>
    typeof i === `string` ? str.split(i).pop() : i ? str.slice(-i) : ``;


  ////////////////////
  function left$( str, i ) {
    if (i === undefined) i = 1;
    if (typeof i === 'string') i = str.indexOf(i);
    return str.slice(0, i);
  }
  
  function right$( str, i ){
    if (i === undefined) i = 1;
    if (typeof i === 'string') i = str.length - str.lastIndexOf(i) - i.length;
    return i ? str.slice(-i) : '';
  }
  ////////////
  function left$(str, i) {
    if (i == undefined) return str[0]
    if (i.big) i = str.search(i)
    return str.slice(0, i)
  }
  
  function right$(str, i) {
    if (i == undefined) return str.slice(-1)
    if (i.big) i = str.length - (str.lastIndexOf(i) + i.length)
    return i && str.slice(-i) || ''
  }
  ////////////
