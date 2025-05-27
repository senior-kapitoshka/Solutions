
function smallWordHelper(str){
    return str.split(' ')
      .map((s)=>s.length<=3?
                              s.toUpperCase():
                             s.replace(/[aeoiu]/gi,''))
      .join(' ');
  }
  /////////////
  function smallWordHelper(s){
    return s.replace(/[^\s]+/gi,x => x.length>3?x.replace(/[aeiou]/gi,''):x.toUpperCase());
  }
  ///////////
  