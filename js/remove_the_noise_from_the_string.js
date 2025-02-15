function removeNoise(s){
    "%$&/#·@|º\\ª".split("").map((i)=>s=s.replaceAll(i,""));
    return s;
  }
  //////////
  function removeNoise(str){
	return str.replace(/[%$&/#·@|º\\ª]/g, '');
}
////////////
function removeNoise(str){
    "%$&/#·@|º\\ª".split("").forEach(e => str = str.split(e).join(''));
    return str;
  }