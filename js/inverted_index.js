function buildInvertedIndex(coll, t, cs, mt) {
    let res=[];
    let suff=cs?"":"i";
    if(!mt){
      let reg= new RegExp(t,suff);
      for(let i=0,n=coll.length;i<n;++i){
        if(reg.test(coll[i])){
          res.push(i+1);
        }
      }
    }else{
      let reg=new RegExp("\\w*"+t+"\\w*",suff);
      for(let i=0,n=coll.length;i<n;++i){
        if(reg.test(coll[i])){
          res.push(i+1);
        }
      }
    }
    return res;
  }
///////////////
function buildInvertedIndex(collection, term, caseSensitive, exactMatch) {
    let regex;
    const flags = caseSensitive ? "" : "i";
    
    if (exactMatch) {
      regex = new RegExp("\\b" + term + "\\b", flags);
    }
    else {
      regex = new RegExp(term, flags);
    }
    
    return collection.reduce((t, x, i) => {
      if (regex.test(x)) {
        t.push(i + 1);
      }
      
      return t;
    }, []);
  }
//////////////
function buildInvertedIndex(collection, term, caseSensitive, exactMatch) {

    let regex = new RegExp(exactMatch ? '\\b' + term + '\\b' : term, caseSensitive ? '' : 'i')
    , matches = [];
  
    for (let i = 0; i < collection.length; i++)
      if (regex.test(collection[i]))
        matches.push(i + 1);
  
    return matches;
  
  }
  ///////////
  const buildInvertedIndex = (collection, term, caseSensitive, exactMatch) =>
    (reg => collection.map((val, idx) => reg.test(val) ? idx + 1 : null).filter(Boolean))
    (new RegExp(`${exactMatch ? `\\b` : ``}${term}${exactMatch ? `\\b` : ``}`, `${caseSensitive ? `` : `i`}`));
    /////////////
    const buildInvertedIndex = (collection, term, caseSensitive, exactMatch) =>
        collection.reduce((p,c,i) => {
                                  if(new RegExp(`${exactMatch ? ("\\b"+term+"\\b") : term}`,`${caseSensitive ? "" : "i"}`).test(c)) 
                                    p.push(i+1); return p;
                                }, []);
 /////////////
 const buildInvertedIndex = (collection, term, caseSensitive, exactMatch) => {
    const flag = caseSensitive ? '' : 'i'
    const str = exactMatch ? `\\W*\\b${term}\\b\\W*` : `\\w*${term}\\w*`
    const res = []
  
    collection.forEach((val, i) => {
      if(new RegExp(str, flag).test(val)) {
        res.push(i + 1)
      }
    })
  
    return res
  }
  ///////////////

  