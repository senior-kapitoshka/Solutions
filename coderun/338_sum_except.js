function sumExcept(a, i, n) {
    if(i%1 !== 0 || i<0)  i=0;
    if(n%1 !== 0 || n<0)  n=0;
    return a.map((elem,curr)=>{
       return ((curr<i || curr>=i+n) && elem%1===0)?elem:0;
    }).reduce((sum,curr)=>sum+=curr);
   }
////////////////////

function sumExcept(a, i, n) {
    var res=0;
    if(i%1 !== 0 || i<0)  i=0;
    if(n%1 !== 0 || n<0)  n=0;
    var z=i+n;
    for(let x=0,y=a.length;x<y;++x){
       if(x<i || x>=z){
           if(a[x]%1===0) res+=a[x];
       }
    }
    return res;
   }

   ///////////////
   function sumExcept(a, i, n) {
    i = i < 0 || (i | 0) !== i ? 0 : i;
    n = n < 0 || (n | 0) !== n ? 0 : n;
    let sum = 0;

    for (let j = 0; j < i; j++) {
        sum += (a[j] | 0) === a[j] ? a[j] : 0;
    }

    for (let j = i + n; j < a.length; j++) {
        sum += (a[j] | 0) === a[j] ? a[j] : 0;
    }

    return sum;
}

////////////
function sumExcept(a, i, n) {
    if(i<0 || i%1!==0){
        i=0;
    }
    if(n<0 || n%1!==0){
        n=0;
    }
    a = a.filter((elem, current)=>{
        if(current<i || current>i+n-1){
            return elem;
        }
    })

    return a.reduce((a,b)=>{
        if(b%1!==0 || b<0){
            return a
        } else {return a+b}},0)
}