let recycleMe=(r)=>{ 
    let res=[0,0,0];
    r.forEach((i)=>{
        if(i>0)++res[0];
        else if(i<0)++res[1];
        else if(i===0) ++res[2];
    });
    return res;
  }
////////////////
var recycleMe = arr => arr.reduce((r,x) => (r[x>0?0:x?1:2]++, r), [0,0,0]);

  //////////
  const recycleMe = r => {
    let glass = r.filter(x=>x<0).length
    let plastic = r.filter(x=>x>0).length
    let card = r.filter(x=>x==0).length
    return [plastic,glass,card]
  }
  //////////
  function recycleMe(recycle) { 
    return recycle.reduce((b, r) => (++b[r > 0 ? 0 : r < 0 ? 1 : 2], b), [0, 0, 0]);
  }
  //////////////
