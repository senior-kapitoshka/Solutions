function areEqual(value1, value2) {
    return require("lodash").isEqual(value1, value2);
  }
  ///////////
  function areEqual(value1, value2) {
    if (typeof value1 !== 'object' || typeof value2 !== 'object')
      return value1 === value2
      
    const keys = [...new Set([
        ...Object.keys(value1),
        ...Object.keys(value2)
      ])
    ]
        
    return keys.every(key => areEqual(value1[key], value2[key]))
  }
  //////////
  const areEqual = require('lodash').isEqual;
  //////////
  const sortAndStringify = val =>
  typeof val !== 'object'
  ? val
  : JSON.stringify(Object.entries(val)
                         .sort(([a],[b]) => a < b)
                         .reduce((acc, [key, value]) => ({... acc, [key]: sortAndStringify(value)}), {}))


const areEqual = (val1, val2) =>
  sortAndStringify(val1) === sortAndStringify(val2);
  ////////////
  function areEqual(value1, value2) {
    return Object.keys(value1).length === Object.keys(value2).length 
    && Object.keys(value1)
    .every(key => Array.isArray(value1[key]) 
    ? value1[key]
    .every((v,i) => v === value2[key][i]) 
    : typeof value1[key] === "object" 
    ? areEqual(value1[key], value2[key]) 
    : value1[key] === value2[key]);
  }