function arrange(arr){
    return arr.sort((lhs,rhs)=>{
      let l=[...lhs.matchAll(/([0-9]+)([A-Z]+)/g)];
      let r=[...rhs.matchAll(/([0-9]+)([A-Z]+)/g)];
      return l.map(a=>a[2]==="G"?parseInt(a[1]):
                a[2]==="KG"?parseInt(a[1])*100:
                parseInt(a[1])*1000000)-
              r.map(a=>a[2]==="G"?parseInt(a[1]):
                a[2]==="KG"?parseInt(a[1])*100:
                parseInt(a[1])*1000000);
    })
    
    }
    ///////////
    const arrange = arr =>
  (val => arr.sort((a, b) => val(a) - val(b)))
  (val => parseInt(val) * {G: 1, KG: 1000, T: 1000000}[val.replace(/\d/g, ``)]);
  //https://developer.mozilla.org/en-US/docs/Glossary/IIFE

    /////////////
    function arrange(arr){
        const sorted=(w)=>{
        if (w.slice(-2)==='KG') return w.slice(0,-2)*1
        else if (w.slice(-1)==='T') return w.slice(0,-1)*1000
        else return w.slice(0,-1)*0.001
        }
        return arr.sort((a,b)=>sorted(a)-sorted(b))
      }

      //////////
      function arrange(arr){
        console.log(arr);
        return arr.sort((x,y)=>+w(x) > +w(y));
      }
      
      function w(x){
        return x.replace("KG","000").replace("G","").replace("T","000000")
      }  