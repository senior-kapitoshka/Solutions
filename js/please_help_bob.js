function errBob(str){
    return str.split(" ").map((s)=>{
      if(/^[A-Za-z]*[aouie]{1}[,!?.]?$/i.test(s) || s.length===0){
        return s;
      }
      if(s[s.length-1]<='Z' && s[s.length-1]>='A') s+="ERR";
      else if(/^[A-Za-z]*[A-Z]{1}[,!?.]+$/i.test(s)){
       if(s[s.length-2]<='Z' && s[s.length-2]>='A')
        s=s.substr(0,s.length-1)+"ERR"+ s.substr(s.length-1);
        else
        s=s.substr(0,s.length-1)+"err"+ s.substr(s.length-1);  
      }
      else s+="err";
      return s;
    }).join(" ");
  }

  //////////////
  const errBob = string =>
  string
    .replace(/([bcdfghjklmnpqrstvwxyz])(\W|$)/g, '$1err$2')
    .replace(/([BCDFGHJKLMNPQRSTVWXYZ])(\W|$)/g, '$1ERR$2');

    //////////
    function errBob(string){
        return string.replace(/([^aeiou\W])(\W|$)/ig, "$1err$2").replace(/([A-Z])err/g, "$1ERR");
      }

      ////////
      function errBob(s){
        return s.replace(/[b-df-hj-np-tv-z](?=\W|$)/gi,m=>m+(m.charCodeAt()<90?"ERR":"err"));
      }

      ////////
      const errBob = str =>
  str.replace(/\w\b/g, match =>
    /[^aeiou]/i.test(match)
      ? match.toLowerCase() === match
        ? `${match}err`
        : `${match}ERR`
      : match
  )