function isItBugged(c){
    return /^\d{2}-\d{2}-\d{4} \d{2}:\d{2}$/.test(c);
   }

   ///////////
   function isItBugged(code){
    return /^\d\d-\d\d-\d{4} \d\d:\d\d$/.test(code);
  }
  //////////
  function isItBugged(s){
    return s[2]=='-'&&s[5]=='-'&&s[10]==' '&&s[13]==':'&&s.length===16
  }
  ////////
  