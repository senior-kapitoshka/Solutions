function isItANum(str) {
    let res=str.replace(/[^0-9]+/gi,'');
    return /^0{1}[0-9]{10}$/.test(res)?
      res:"Not a phone number";
  }
/////////////
const isItANum = str =>(str.replace(/\D/g,'').match(/^0\d{10}$/) 
|| ['Not a phone number'])[0];
////////////
const isItANum = str =>
  (str.replace(/\D/g, ``).match(/^0\d{10}$/) || [`Not a phone number`])[0];
