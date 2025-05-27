
function sc(sd,ss){
    let str="^";
    let cnt=0;
    for(var c of sd){
      if(c==='~'){
        if(cnt===0){
          ++cnt;
          str+=".";
        }else{
          ++cnt;
          str+=".";
        }
      }else{
        if(cnt===0){
          str+=c;
        }else{
          str+=c;
          cnt=0;
        }
      }
    }
    let res="";
    const rgx = new RegExp(str,"gi");
    ss.map(s=>{
      if(s.match(rgx)){
        if(res===""){
          res+=s;
        }else{
          res+=',';
          res+=s;
        }
      }
    });
    return res;
  }
  ///////////////
  function sc(said,suspects){
    s =said.replace(/~/g, '.')
    var re = new RegExp(`^${s}`, "i");
    return suspects.filter(x => x.match(re)).join(',')
}
///////////////

const sc = (said,suspects) => {
    const exp = '^' + said.replace(/(~+)/g, m => `.{${m.length}}`);
    const reg = new RegExp(exp, 'i');
  
    return suspects.filter(s => reg.test(s)).join(',');
  }

  ////////////
  function sc(said, suspects) {
    return suspects.filter(suspect => RegExp('^' + said.replace(/~/ig, '.'), 'i').test(suspect)).join();  
  }

  ////////
  const sc = (said, suspects) => {
    const saidRgx = said.replace(/~/g, '.');
    const isSuspect = new RegExp(`^${ saidRgx }`, 'i');
    return suspects.filter(isSuspect.test.bind(isSuspect)).join();
  }