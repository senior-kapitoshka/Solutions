function brightest(cs){
  let mx=0;
  let id=0;
  for(let i=0,n=cs.length;i<n;++i){
    let arr=[...cs[i].matchAll(/#(..)(..)(..)/g)];
    arr.map(a=>{
      let val=Math.max(parseInt(a[1],16),parseInt(a[2],16),parseInt(a[3],16));
      if(val>mx){
        mx=val;
        id=i;
      }
    });
  }
  return cs[id];
}
/////////////
function sB(s){
  return Math.max(...[s.slice(1, 3), s.slice(3, 5), s.slice(5, 7)].map(x => parseInt(x, 16)))
}

function brightest(colors){
  return colors.sort((a, b) => sB(b) - sB(a))[0]
}