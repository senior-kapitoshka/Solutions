function separateTypes(int) {
    let res={
      string:[],
      number:[],
      boolean:[]
    };
    for(let i of int){
      if(typeof i ==="string"){
        res.string.push(i);
      }else if(typeof i ==="number"){
        res.number.push(i);
      }else if(typeof i ==="boolean"){
        res.boolean.push(i);
      }
    }
    if(res.string.length==0) delete res.string;
    if(res.number.length==0) delete res.number;
    if(res.boolean.length==0) delete res.boolean;
    return res;
  }

////////////////////
function separateTypes(input) {
    return input.reduce((types, value) => {
      const valueType = typeof value
      const type = types[valueType]
      types[valueType] = type ? [...type, value] : [value]
      return types
    }, {})

    //////////////
    function separateTypes(input) {
        const dic = {};
        const arr = [...new Set(input.map(el => typeof el))]
        arr.map(el => dic[el] = input.filter(e=> typeof e === el))
        return dic;
      }