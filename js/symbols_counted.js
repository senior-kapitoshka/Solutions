const transform = (s) => {
    let dict={};
    s.split('').map((c)=>dict[c]=dict[c]+1||1);
    return s.split('').map((c)=>{
      if(dict[c]>1){
        let res=`${c}${dict[c]}`;
        delete dict[c];
        return res;
      }
      return dict[c]===1?c:'';
    }).join('');
  }
  ////////////
  const transform = s => {
    var h=[...s].reduce((h,c)=>(h[c]=h[c]+1||1,h),{});
    return Object.keys(h).map(c=>h[c]===1?c:c+h[c]).join('');
  }
  ///////////
  const transform = s => s.replace(/./g, (x, i, r) => (r = s.match(new RegExp(`${x}`, 'g')).length) > 1 ? s.indexOf(x) == i ? x + r : '' : x);
  //////////
  const transform = (s) => {
    return [...new Set(s)].map(e=>[...s].filter(a=>a===e).length===1 ? e : `${e}${[...s].filter(a=>a===e).length}`).join``
    }
    /////////
    const transform = str =>
  str.replace(/(.)(?<!\1.+)/g, ch => ch + --str.split(ch).length)
     .replace(/1|\D(?!\d)/g, '');
     //////
     const transform = (s) => {
        return [...new Set(s)].map(e => s.indexOf(e)==s.lastIndexOf(e)?e:e+[...s].filter(c=>c==e).length).join('');
      }
      //////////
      const transform = (s) => {
        res = {}
        s.split('').forEach(c => {
          if (!(c in res)) res[c] = 0
          res[c]++
        })
        return Object.entries(res).map(([k,v]) => v>1 ? k+v : k).join('')
      }