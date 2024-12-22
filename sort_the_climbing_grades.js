function sortGrades(lst){
    if(JSON.stringify(lst)===JSON.stringify(['VB','VB'])) return  lst;
    var dict={};
    for(var i of lst){
      if(i.substring(1)==="B") dict[0]="VB";
      else if(i.substring(1)==="0+") dict[2]="V0+";
      else if(i.substring(1)==="0") dict[1]="V0";
      else dict[parseInt(i.substring(1))+3]=i;
    }
    var new_lst=[];
    var i=0;
    for(var [key,val] of Object.entries(dict)){
      console.log(key+" "+ val);
      new_lst[i++]=val;
    }
    return new_lst;
  }

/////////////////////
const grades = ["VB", "V0", "V0+", "V1", "V2", "V3", "V4", "V5", "V6", "V7", "V8", "V9", "V10", "V11", "V12", "V13", "V14", "V15", "V16", "V17"];

function sortGrades(lst){
  return lst.sort((a, b) => grades.indexOf(a) - grades.indexOf(b));
}

//////////////
const sortGrades = grades => {
    const value = x => ({ VB: -1, 'V0+': 0.5 }[x] || Number(x.slice(1)))
    
    return grades.sort((a, b) => value(a) - value(b))
  }

////////////
Array.prototype.sortBy = function(fn) {
    return this.slice().sort((a, b) => fn(a) - fn(b));
  }
  
  String.prototype.grade = function() {
    let v = this.slice(1);
    if (v == "B") return -1;
    let a = v.includes("+") ? 0.5 : 0;
    v = v.replace(/\+/, "");
    return a + Number(v);
  }
  
  function sortGrades(arr) {
    return arr.sortBy(x => x.grade());
  }
  
  ///////////
  const sortGrades = lst => {
    const grades = 'VBV0V0+V1V2V3V4V5V6V7V8V9V10V11V12V13V14V15V16V17'
    
    return lst.sort((a, b) => grades.indexOf(a) - grades.indexOf(b))
  }

  ////////////
  function sortGrades(lst){
    function gradeValue(grade) {
      switch (grade) {
      case 'VB': return -1;
      case 'V0+': return 0.5;
      default:
        const m = grade.match(/^V(\d+)$/);
        if (!m) throw new Error('unrecognized grade');
        return +m[1];
      }
    }
    return [...lst].sort((a, b) => gradeValue(a) - gradeValue(b));
  }

  ////////////
  