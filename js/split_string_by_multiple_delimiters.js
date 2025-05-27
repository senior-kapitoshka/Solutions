function multipleSplit(s, d=[]){
    let rgx=new RegExp(`[${d.map((c)=>{
      if(c==='*'|| c==='-' || c==='\\') return '\\'+c;
      return c;
    }).join('')}]`);
    return s.split(rgx).filter(Boolean);
  }
  //////////
  function multipleSplit(string, delimiters=[]){
    let arr = [string];
    for (let d of delimiters) {
      arr = arr.reduce((r, s) => r.concat(s.split(d)), []);
    }
    return arr.filter(Boolean);
  }
  /////////
  function multipleSplit(string, delimiters=[]){
    var reg = new RegExp('['+delimiters.join('\\')+']', 'g');
    return string.split(reg).filter(function(str) {
      return !!str;
    })
  }
  ///////////
  const multipleSplit = (string, delimiters = []) =>
  string.split(new RegExp(`[${delimiters.join(`\\`)}]`)).filter(Boolean);