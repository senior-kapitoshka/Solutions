function listToArray(l) {
    let arr=[];
    for(let p=l;p;p=p.next){
      arr.push(p.value);
    }
    return arr;
  }

  ////////////
  function listToArray(list) {
    return !list ? [] : [list.value].concat(listToArray(list.next));
  }
  ////////
  const listToArray = list => list === null ? [] : [list.value, ...listToArray(list.next)];
  /////////
  let $=_=>_&&[_.value,...$(_.next)||[]]

const listToArray = $