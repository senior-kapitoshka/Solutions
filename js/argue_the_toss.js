function anArgument() {
  let res='';
  if(arguments.length===0){
    return "You didn\'t give me any arguments.";
  }
  else if(arguments.length===1){
    res=`You gave me ${arguments.length} argument and it is "${arguments[0]}".`;
    return res;
  }
  else if(arguments.length>1)res=`You gave me ${arguments.length} arguments and they are `;
  for(let i=0;i<arguments.length;++i) {
    if(i<arguments.length-2) res+=`"${arguments[i]}", `;
    else if(i<arguments.length-1) res+=`"${arguments[i]}" and `;
    else res+=`"${arguments[i]}".`;
  }
 return res;
}

///////////////////
function anArgument(...args) {
  const n = args.length;
  if( !n ) return 'You didn\'t give me any arguments.';
  if( n === 1 ) return `You gave me 1 argument and it is "${args[0]}".`;
  return `You gave me ${n} arguments and they are "${args.slice(0, n - 1).join('", "')}" and "${args[n - 1]}".`;
}

//////////////
function anArgument(...arr) {
  if(!arr.length) return 'You didn\'t give me any arguments.';
  else if(arr.length==1) return `You gave me 1 argument and it is "${arr[0]}".`;
  else{
    arr = arr.map(e=>`"${e}"`);
    return `You gave me ${arr.length} arguments and they are ${arr.length>2?arr.slice(0,-2).join(', ')+', ':''}${arr.slice(-2).join(' and ')}.`
  }
}

////////////
