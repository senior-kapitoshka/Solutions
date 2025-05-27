function encode(s) {
    return s.split("").map((c)=>String.fromCharCode(c.charCodeAt(0)*6)).join("");
}

function decode(s) {
    return s.split("").map((c)=>String.fromCharCode(c.charCodeAt(0)/6)).join("");
}
/////////
const f = g => s => s.replace(/./g, c => String.fromCharCode(g(c.charCodeAt(0))));
const encode = f(c => c*6);
const decode = f(c => c/6);
////////
function encode(str) {
    return [...str].map(c=>String.fromCharCode(c.charCodeAt()*6)).join('');
  }
  
  function decode(str) {
    return [...str].map(c=>String.fromCharCode(c.charCodeAt()/6)).join('');
  }