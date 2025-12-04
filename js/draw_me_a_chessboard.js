function chessBoard(r, c) {
    let res=[];
    for(let i=0;i<r;++i){
      let t=[];
      for(let j=0;j<c;++j){
        if((j%2===0 && i%2===0) || (j%2===1 && i%2===1)){
          t.push("O");
        }else if((j%2===1 && i%2===0) || (j%2===0 && i%2===1)){
          t.push("X");
        }
      }
      res.push(t);
    }
    return res;
  }

/////////////////
function chessBoard(rows, columns) {
    return Array.from({length: rows},
         (_,i) => Array.from({length: columns},
         (_,j) => 'OX'[(i+j)%2]));
  }  

//////////////////
const chessBoard = (rows, columns) =>
  [...Array(rows)].map((_, idx) =>
   [...Array(columns)].map((_, i) => 
   `OX`[idx + i & 1]));
   /////////////
     