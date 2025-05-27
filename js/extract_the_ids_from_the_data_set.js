
function extractIds(data, ids = []){
    let search = (item) => {
      for(var key in item){
        if(key == 'id')
          ids.push(item[key]);
        if(typeof item[key] === 'object')
          search(item[key]);      
      }
    };
    return search(data), ids;
  }
//////////////
function extractIds(data){
    return [].concat(...Object.keys(data).map(function(item) {
        return item === 'id' ? data[item] : extractIds(data[item]);
      }))
  }

  //////////////
  function extractIds(data){
    return (JSON.stringify(data).match(/\d+/g)||[]).map(x=>+x)
  }
  ///////////
  const extractIds = data =>
	[data.id]
		.concat(data.items ? data.items.map(extractIds): [])
    .filter(x => x)
    .reduce((a, b) => a.concat(b), [])
    //////////
const extractIds = ({id, items}) =>
    !id ? []
    : !items ? [id]
    : [id].concat(...items.map(extractIds));
    ///////////////

    function extractIds(data){
        function extract(ids, obj) {
          if (obj.id != null) ids.push(obj.id);
          if (obj.items) obj.items.forEach(extract.bind(null, ids));
          return ids;
        }
        
        return extract([], data);
      }
      
      ////////////

      const extractIds = obj => Object.entries(obj).reduce(
        (rarr, [k,v]) => 
          k === 'id' ? [...rarr, v] : 
          k === 'items' ? rarr.concat(...v.map(extractIds)) :
          rarr
        , [])
        
        /////////
        

