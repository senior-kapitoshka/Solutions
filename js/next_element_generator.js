function* nextElementGenerator(a) {
    while(1) yield* a
  }
  ///////////////
  function* nextElementGenerator(array) {
    yield *array;
    yield *nextElementGenerator(array);
  }
  ///////
  function* nextElementGenerator(array) {
    for (let i=0; i< Infinity; i++){
      yield array[i % array.length]
    }
  }
  ///////
  const nextElementGenerator = $ => (function*(){ while(true){ for(const $$ of $) yield $$; } })();
  ///////
  function* nextElementGenerator(array) {
    var count = 0
    while (true)
      yield array[count++ % array.length]
  }
  ///////
  function* nextElementGenerator(array) {
    let currentValIndex = 0;
    
    while(true) {
      if (currentValIndex === array.length) {
        currentValIndex = 0;
      }
      
      yield array[currentValIndex]
      currentValIndex++
    }
  }
  ////////////
  function* nextElementGenerator(array) {
    for(let i = 0; i <= array.length; i++){
      
      if(i == array.length) i = 0;
      yield array[i]
    }
  }
  //////////
  function* nextElementGenerator(array) {
    if(array.length > 1){
    for(let value of array){
        yield(value);
    }}
    else {
        yield(Number(array))
    }
  }