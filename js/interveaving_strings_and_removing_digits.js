function interweave(s1, s2) {
    let n=s1.length+s2.length;
    var res="";
    for(let i=0;i<s1.length;){
      if(s1[i]<=9 && s1[i]>=0 && s2[i]<=9 && s2[i]>=0 && s1[i]!==' ' && s2[i]!==' '){
        ++i;
      }else if(s1[i]<=9 && s1[i]>=0 && s1[i]!==' '){
        if(i<s2.length)res+=s2[i];
        ++i;
      }else if(s2[i]<=9 && s2[i]>=0 && s2[i]!==' '){
        if(i<s1.length)res+=s1[i];
        ++i;
      }else{
        if(i<s1.length)res+=s1[i];
        if(i<s2.length)res+=s2[i];
        ++i;
      }
      
    }
  
    return res ;
  }

  ///////////
  function interweave(s1, s2) {
    let s = '', l = Math.max(s1.length, s2.length);
    for(let i = 0; i < l; i++) {
      if(s1[i]) s += s1[i];
      if(s2[i]) s += s2[i];
    }
    return s.replace(/\d/g,'').trim();
  }
  //////////
  function interweave(s1, s2) {  
    let result = "";
    for (var i=0; i<s1.length; ++i) {
      result += s1[i] + (s2[i] || '');
    }
    
    return result.replace(/\d/g, '');
  }
  /////////
  const interweave = (s1, s2) =>
  s1.replace(/(?<=.)/g, (_, idx) => s2[--idx] || ``).replace(/\d/g, ``).trim();
  ////////
  function interweave(s1, s2) {
    s2 = s2 + " "
    return [...s1].map((x, i) => x + s2[i]).join``.trim().replace(/\d/g, "")
  }