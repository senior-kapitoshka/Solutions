function findUnique(ns) {
    let dict={};
    ns.forEach((i)=>dict[i]=(dict[i]||0)+1);
    return parseInt(Object.keys(dict).filter((i)=>dict[i]===1)[0]);
  }

  /////////
  function findUnique(numbers) {
    return numbers.reduce((a, b) => a ^ b);
  }

  //////////
  function findUnique(numbers) {
    var set = new Set();
    
    numbers.forEach(
                      x => {  if(set.has(x))
                                set.delete(x);
                              else 
                                set.add(x);  }
                    );
    
    return set.values().next().value;
  }
  /////////
  function findUnique(numbers) {
    let obj = numbers.reduce((a,c) => {a[c+'']?a[c+'']++:a[c+'']=1;return a},{});
    return numbers.find(e => obj[e+'']===1);
  }
  //////////
  function findUnique(numbers) {
	let res = numbers.reduce(function(prev, elem) {
		prev[elem] = (prev[elem] || 0) + 1;
		return prev;
	  }, {});
     
	for (let key in res) {
		if(res[key] === 1) {
			return +key;
		}
	}
}