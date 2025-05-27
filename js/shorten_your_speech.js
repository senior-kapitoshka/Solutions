var shortenSpeech = function (str) {
    const trim=(s)=>{
      let id=s.substr(3).search(/[aoieu]/);
      return id===-1?s:new String(s.substr(0,id+3)+'.')
    }
    return str.split(" ").map((s)=>s.length>=4?
                              trim(s):
                              s).join(" ");
    
  }

  /////////
  const shortenSpeech = s => s.replace(/\b(\S{3,}?)[aeiou]\S*/g, '$1.');
  //////
  var shortenSpeech = str => str.replace(/(\S{3,}?)[aeiou]\S*/g, '$1.')
  ////////
  const shortenSpeech = str =>
  str.replace(/([a-z']{3}[^aeiou\s]*)([aeiou][a-z,']*)/gi, '$1.')
  ///////
  var shortenSpeech = function (str) {
    return str.split(' ').map(e => e.length>3? e.slice(0,3)+e.slice(3).split(/[aeiou]/)[0]+(/[aeiou]/.test(e.slice(3))?'.':''):e).join(' ');
  }
  /////////
  const shortenSpeech = (str) => {	
    return str.split(' ')
      .map(w=>{
        if (w.length<4) return w;
        const ix = w.split('').slice(3).findIndex( l=> l.match(/[a|e|i|o|u]/));
        if (ix < 0) return w;
        return `${w.split('').slice(0, ix+3).join('')}.`
      })
      .join(' ')
  }