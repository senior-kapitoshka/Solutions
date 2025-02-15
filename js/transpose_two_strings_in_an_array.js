function transposeTwoStrings (a) {
    let n=Math.max(a[0].length,a[1].length);
    let res='';
    for(let i=0;i<n;++i){
      res+=i<a[0].length?a[0][i]:" ";
      res+=" ";
      res+=i<a[1].length?a[1][i]:" ";
      res+=i<n-1?"\n":"";
    }
      return res;
  }
  /////////////////
  function transposeTwoStrings(arr){
    var result = [];
    var len = Math.max(arr[0].length, arr[1].length);
    
    for (var i = 0; i < len; i++) {
      var column = (arr[0][i] || " ") + " " + (arr[1][i] || " ");
      result.push(column);
    }
    
    return result.join("\n");
  }
  //////////
  function transposeTwoStrings (array) {
    const long = array[0].length>=array[1].length?array[0]:array[1];
      return [...long].map((e,i) => (array[0][i]||' ')+' '+(array[1][i]||' ')).join('\n');
  }
  //////////////
  function transposeTwoStrings(arr){
    return [ ...Array( Math.max( ...arr.map(el => el.length) ) ) ]
      .map( (_,i) => (arr[0][i] || ' ') + ' ' + (arr[1][i] || ' ') )
      .join('\n');
  }
  ///////////
  const _ = require('lodash');

/**
 * Transpose the given strings (display them from top to bottom).
 */
function transposeTwoStrings(wordArray) {
  return _.trim(
    _.join(
      _.map(
        _.zip(... _.map(wordArray, (_word) => _.split(_word, ''))),
        (_builderStrArray) =>
          `${_.join(_.map(_builderStrArray, (_char) => _.isUndefined(_char) ? ' ' : _char), ' ')}\n`
      ),
    ''
    ),
    '\n'
  );
}
  
  