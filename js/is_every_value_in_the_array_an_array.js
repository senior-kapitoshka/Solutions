const arrCheck = v => v.filter(i=>!Array.isArray(i)).length===0

///////////////
const arrCheck = a => a.every(Array.isArray) ;
//////
const arrCheck = require('ramda').all(Array.isArray)
//////////
