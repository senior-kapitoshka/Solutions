const createSequence = (rgx) => {
    let str = '';
    for(let i = 32; i <= 126; i++) {
      let x=String.fromCharCode(i);
      str+=(rgx.test(x))?x:'';
    }
    return str;
  };
  
  /*const createSequence = (regex) => {
    let str = '';
    for(let i = 32; i <= 126; i++) {
      str += String.fromCharCode(i);
    }
    console.log(regex.source)
    return str.replace(new RegExp(`[^${regex.source.slice(1, -1)}]`, 'g'), '');
  };*/

  ///////////////
  const createSequence = (regex) => {
    return Array
      .from({length: 256}, (_, i) => String.fromCharCode(i))
      .filter(x => regex.test(x)).join('');
  }

  ////////////
  const createSequence = regex => [...Array(200)].reduce((str, _, i) => {
    let char = String.fromCharCode(i);
    return str + (regex.test(char) ? char : '');
  }, '');

  ///////////
  