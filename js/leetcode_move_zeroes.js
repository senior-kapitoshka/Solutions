var moveZeroes = function(n) {
    let i=0;
    let j=n.length;
    while(i<j){
        if(n[i]===0){
            n.splice(i,1);
            n.push(0);
            --j
        }else ++i;
    }
};
///////////////
var moveZeroes = function(n) {
    for(let i=0,j=0,x=n.length;i<x;++i){
        if(n[i]!==0){
            let t=n[j];
            n[j]=n[i];
            n[i]=t;
            ++j;
        }
    }
};