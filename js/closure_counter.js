const counter = (x = 0) => () => ++x;
//////////
function counter() {
    let count = 1;
    return function () {
      return count++; 
    }
 }
 ////////
 
const counter = () => (count => () => count++)`1`