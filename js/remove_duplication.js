function removeDuplication(a){
    return a.filter(i=>a.indexOf(i)===a.lastIndexOf(i));
  }
  ///////////
  function removeDuplication(arr) {
    const counts = new Map();
    for (const x of arr)
      counts.set(x, (counts.get(x) || 0) + 1);
    return arr.filter(x => counts.get(x) == 1);
  }
  ////////
  const removeDuplication = array => {
    const reps = array.reduce((acc, curr) => ({ ...acc, [curr]: (acc[curr] || 0) + 1 }), {});
    return array.filter(n => reps[n] === 1);
  };