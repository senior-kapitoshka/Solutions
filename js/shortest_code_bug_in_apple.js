const sc=(a)=>[...a]
              .reduce((r,b,x)=>{
          y=b.indexOf('B')
    return (y!==-1)?[x,y]:r
              },0)

///////////////////////
sc=a=>[a.findIndex(r=>j=~r.indexOf('B')),~j]
//////////////
sc=a=>[a.findIndex(v=>~(i=v.indexOf(`B`))),i]
///////////
function sc(a){return s=a.join().indexOf("B")/2,i=a[0].length,[s/i|0,s%i]}
///////
sc = a => {
    for(y in a)
      if((x = a[y].indexOf("B")) >= 0)
        return [y*1,x]
  }
  /////////////
  const sc = a =>
  a.reduce(
    (acc, l, i) => ((ind = l.indexOf('B')) >= 0 ? [i, ind] : acc),
    [0, 0]
  )
  ///////////
  sc=a=>a.reduce((q,x,i)=>x.reduce((r,y,j)=>y=='B'?[i,j]:r,q),0)
  ///////////
  sc=a=>a.reduce((p,v,i)=>~(j=v.indexOf("B"))?[i,j]:p,0)