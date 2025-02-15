function whoseBicycle(d1, d2, d3) {
    let f=Object.values(d1).reduce((curr,sum)=> sum+=curr);
    let s=Object.values(d2).reduce((curr,sum)=> sum+=curr);
    let t=Object.values(d3).reduce((curr,sum)=> sum+=curr);
    var min=0;
    Object.values(ageTable).forEach((v)=> min=Math.min(v,min));
    return (f>s && f>t)?'I need to buy a bicycle for my first son.':
            (s>f && s>t)?'I need to buy a bicycle for my second son.':
            (t>s && t>f)?'I need to buy a bicycle for my third son.':
            (s===t && f===s)?
            (ageTable['firstSonAge']===min?'I need to buy a bicycle for my first son.':
          ageTable['secondSonAge']===min?'I need to buy a bicycle for my second son.':
    'I need to buy a bicycle for my third son.'):
            (f===s && s>t && f>t)?
            (ageTable['firstSonAge']===min?'I need to buy a bicycle for my first son.':
              'I need to buy a bicycle for my second son.'):
             (s===t && s>f && t>f)?
            (ageTable['secondSonAge']===min?'I need to buy a bicycle for my second son.':
                'I need to buy a bicycle for my third son.'):
            (ageTable['firstSonAge']===min?'I need to buy a bicycle for my first son.':
                'I need to buy a bicycle for my third son.');
            
  }

  //////////////
  function whoseBicycle(dairy1, dairy2, dairy3) {
    const diaries = [dairy1, dairy2, dairy3];
    const son = {
      0: 'first',
      1: 'second',
      2: 'third'
    };
    const scores = diaries.map((diary, index) => {
      const keys = Object.keys(diary);
      
      return keys.reduce((acc, cur) => acc + diary[cur], 0);
    });
    
    const maxValue = Math.max(...scores);
    
    const maxDiary = scores.lastIndexOf(maxValue);
    
    return `I need to buy a bicycle for my ${son[maxDiary]} son.`;
  }

  /////////
  function whoseBicycle(a, b, c) {
    [a, b, c] = [a, b, c].map(x => Object.values(x).reduce((y, z) => y + z, 0));
    let n = Math.max(a, b, c);
    return `I need to buy a bicycle for my ${n === c ? "third" : n === b ? "second" : "first"} son.`;
  }

  //////////
  function whoseBicycle(d1, d2, d3) {
    var s1=0, s2=0, s3=0;
    for (var key in d1)
      s1+=d1[key];
    for (var key in d2)
      s2+=d2[key];
    for (var key in d3)
      s3+=d3[key];
    return s1>s2&&s1>s3?"I need to buy a bicycle for my first son.":s2>s1&&s2>s3?"I need to buy a bicycle for my second son.":"I need to buy a bicycle for my third son.";
  }

  ////////
  