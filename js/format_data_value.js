function formatDataValue(data) {
  if(data===0) return "0MB";
  let arr=[];
  for(let i=0;data>=1;++i){
    if(i===0){
      if(data%1000!==0)arr.push(`${data%1000}MB`);
    }
    else if(i===1){
      if(data%1000!==0)arr.push(`${data%1000}GB`);
    }
    else{
      if(data%1000!==0)arr.push(`${data%1000}TB`);
    }
    data=Math.floor(data/1000);
  }
  return arr.reverse().join(' ');
}

///////////
ormatDataValue = d =>
 [`${Math.floor(d / 1e6)}TB`,
  `${Math.floor(d / 1e3 % 1e3)}GB`,
   `${d % 1e3}MB`].filter(x => parseInt(x))
                    .join` ` || `0MB`

                    /////////////////////
                    const formatDataValue = (data) =>
                    [[~~(data/1e6), 'TB'], [~~((data%1e6)/1e3), 'GB'], [data%1e3, 'MB']]
                      .filter(v => v[0] > 0)
                      .map(v => v[0] + v[1])
                      .join(' ') || "0MB";
//////////
function formatDataValue(data) {
    if (data*1 == 0) return '0MB';
    let n = data.toString().split('').reverse().join('');
    return n.replace(/(.{3})/g,'$1 ')
            .split(' ')
            .filter(n => n != '')
            .map(n => n.split('').reverse().join('') * 1)
            .map((n, i) => i == 0 ? n + 'MB' : i == 1 ? n + 'GB' : n + 'TB')
            .filter(e => e[0] != '0')
            .reverse()
            .join(' ');
  }