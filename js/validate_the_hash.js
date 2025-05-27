function malwareValidate(h) {
    return [...new Set(h.filter((i)=>{
        return i.length===10 && (i.match(/[a-z]/g) || []).length===5 &&
                         (i.match(/[0-9]/g) || []).length===5}))];
}

///////////
const malwareValidate = h => 
                    h.filter((e,i)=>
                             e.replace(/[\d]/g,'').length == 5  &&
                              e.replace(/[a-z]/g,'').length == 5 &&
                               h.indexOf(e) == i)

//////////
function malwareValidate(hashArr) {
    return Array.from(
      new Set(
        hashArr.filter(el =>
          /^(?=.{10}$)(?=(.*[\d].*){5})(.*[a-z].*){5}/.test(el)
        )
      )
    );
  }
  ////////
  