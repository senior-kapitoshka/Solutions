function findDuplicatePhoneNumbers(pns){
    let dict={
      2:['A', 'B','C'],
  3:['D', 'E','F'],
  4:['G', 'H','I'],
  5:['J', 'K','L'],
  6:['M', 'N','O'],
  7:['P', 'R','S'],
  8:['T', 'U','V'],
  9:['W', 'X','Y'],};
    let mp={};
    pns.map(
      (n)=>n.replaceAll("-","").toUpperCase().split("")
        .map((c)=>{
          if(!/^\d+$/.test(c)){ 
            let res;
            Object.keys(dict).forEach((k)=>{
              if(dict[k].includes(c)) res=k;
            });
            return res;
          }
          return c;
        })
      ).forEach((n)=> {
      let  str=`${n[0]}${n[1]}${n[2]}-${n[3]}${n[4]}${n[5]}${n[6]}`;
                mp[str]=(mp[str] || 0)+1;
    });
       let res=Object.keys(mp).map(key => ({
          key: `${key}:${mp[key]}`,
          value: mp[key]
      }));
    res.sort((lhs,rhs)=>{
      return lhs.value-rhs.value;
    })
    for(var o of res) console.log(o);
    return res.map((o)=>{if(o.value>1)return o.key}).filter((o)=>o!==undefined);
  }
/////////////////
const _ = require('lodash');

const digitsForLetters = {
  A: '2', B: '2', C: '2', 
  D: '3', E: '3', F: '3', 
  G: '4', H: '4', I: '4', 
  J: '5', K: '5', L: '5', 
  M: '6', N: '6', O: '6', 
  P: '7', R: '7', S: '7', 
  T: '8', U: '8', V: '8', 
  W: '9', X: '9', Y: '9', 
}

function findDuplicatePhoneNumbers(phoneNumbers) {
  return _(phoneNumbers)
    .groupBy(toStandardForm)
    .mapValues(_.size)
    .pickBy(cnt => cnt >= 2)
    .map((cnt, num) => `${num}:${cnt}`)
    .value()
    .sort();
}

function toStandardForm(phoneNumber) {
  return phoneNumber
    .replace(/[^\dA-Z]/ig, '')
    .toUpperCase()
    .replace(/./g, c => digitsForLetters[c] || c)
    .replace(/^.../, '$&-');
}

//////////
function findDuplicatePhoneNumbers(a) {
    var r = [/[ABC]/i,/[DEF]/i,/[GHI]/i,/[JKL]/i,/[MNO]/i,/[PRS]/i,/[TUV]/i,/[WXY]/i];
    a = a.map(s => s.replace(/-/g,'').replace(/\D/g,c => r.findIndex(r => r.test(c))+2).replace(/^\d{3}/,'$&-'));
    return Object.keys(a=a.reduce((a,s) => (a[s] = (a[s]|0)+1, a),{})).filter(k => 1<a[k]).sort().map(k => k+':'+a[k]);
}

/////////////
function findDuplicatePhoneNumbers(phoneNumbers){
    const counts = {}
    let phone = []
    const newArray = phoneNumbers.map(x => {
      return x.toUpperCase()
              .replace(/[ABC]/g, "2")
              .replace(/[DEF]/g, "3")
              .replace(/[GHI]/g, "4")
              .replace(/[JKL]/g, "5")
              .replace(/[MNO]/g, "6")
              .replace(/[PRS]/g, "7")
              .replace(/[TUV]/g, "8")
              .replace(/[WXY]/g, "9")
              .replace(/[-_]/g, '')
              .replace(/^([0-9]{3})/, "$1-")
    });
    newArray.map(x => { counts[x] = (counts[x] || 0) + 1} )
    for (const key in counts) {
      if (!(counts[key] === 1)){
        phone.push(key+':'+counts[key]);
      }
    }
    phone.sort()
    return phone
  }

  ///////////
  function findDuplicatePhoneNumbers(ar){
	const tome = 'ABCDEFGHIJKLMNOPRSTUVWXY';
	let ix = ar.reduce((a,e) => {
		let v = e.replace(/-/g,'').replace(/[A-Za-z]/g,e => Math.floor(tome.indexOf(e.toUpperCase()) / 3) + 2),
			w = v.slice(0,3) + '-' + v.slice(3);
		a[w] ? a[w]++ : a[w] = 1;
		return a},{});
	return Object.keys(ix).filter(e => ix[e] > 1).map(e => `${e}:${ix[e]}`).sort();
}