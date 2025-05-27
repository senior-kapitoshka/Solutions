function twentyOne(c1, c2, c3) {
    let s1=c1.substr(0,c1.length-1),
        s2=c2.substr(0,c2.length-1),
        s3=c3.substr(0,c3.length-1),
        sum=(/^\d/.test(s1)?
            parseInt(s1):
            s1==="J"?2:
            s1==="Q"?3:
            s1==="K"?4:
            11)+
            (/^\d/.test(s2)?
            parseInt(s2):
            s2==="J"?2:
            s2==="Q"?3:
            s2==="K"?4:
            11)+
            (/^\d/.test(s3)?
            parseInt(s3):
            s3==="J"?2:
            s3==="Q"?3:
            s3==="K"?4:
            11);
    return sum>21?"more":sum<21?"less":"twenty-one";
  }

  ////////////
  function twentyOne(...cards) {
    let score = cards.map(c => c.slice(0, c.length - 1))
                     .reduce((p, c) => p + (/\d/.test(c) ? parseInt(c) : {"J": 2, "Q": 3, "K": 4, "A": 11}[c]), 0);
    return score > 21 ? "more" : score < 21 ? "less": "twenty-one";
  }
  /////////
  function twentyOne(card1, card2, card3) {
    let table = {'A':11, '2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8,'9':9,'10':10,'J':2,'Q':3, 'K':4};
    let res = table[card1.replace(/[♣♦♥]/, '')]+table[card2.replace(/[♣♦♥]/, '')]+table[card3.replace(/[♣♦♥]/, '')]
    return res === 21 ? 'twenty-one' : res > 21 ? 'more' : 'less';
}
////////
