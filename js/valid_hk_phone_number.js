const isValidHKPhoneNumber=(s)=>/^\d{4}\s{1}\d{4}$/g.test(s);

const hasValidHKPhoneNumber=(s)=>/\d{4}\s{1}\d{4}/g.test(s);
/////////////
isValidHKPhoneNumber = str => /^\d{4} \d{4}$/.test(str)
hasValidHKPhoneNumber = str => /\d{4} \d{4}/.test(str)