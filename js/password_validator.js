function password(s) {
    return s.length<8?false:/(?=.*[A-Z]+)(?=.*[a-z]+)(?=.*[0-9]+)/.test(s);
}
////////////
function password(str) {
    return str.length >= 8 &&
           /[a-z]/.test(str) &&
           /[A-Z]/.test(str) &&
           /\d/.test(str);
}
///////////
const password = str => /^(?=.*[A-Z])(?=.*[a-z])(?=.*\d).{8,}$/.test(str);
//////////
function password(str) {
    return /^(?=.*[0-9])(?=.*[A-Z])(?=.*[a-z]).{8,}$/.test(str);
  }