function highlight(code) {
  let dict={'F':'<span style="color: pink">',
            'L':'<span style="color: red">',
            'R':'<span style="color: green">',
           'D':'<span style="color: orange">'};
  return code.replaceAll(/(F+)/g,`${dict['F']}$1</span>`)
  .replaceAll(/(L+)/g,`${dict['L']}$1</span>`)
  .replaceAll(/(R+)/g,`${dict['R']}$1</span>`)
  .replaceAll(/([0-9]+)/g,`${dict['D']}$1</span>`);
}

//////////////
function highlight(code) {
  const style = color => `<span style="color: ${color}">$&</span>`;
  
  code = code.replace(/F+/g, style('pink'));
  code = code.replace(/L+/g, style('red'));
  code = code.replace(/R+/g, style('green'));
  code = code.replace(/[0-9]+/g, style('orange'));
  
  return code;
}

/////////////
const color = char => {
  return { F: 'pink', L: 'red', R: 'green' }[char] || 'orange';
};

const highlight = code =>
  code.replace(/([FRL]|\d+)\1*/g, m => 
    '<span style="color: ' + color(m[0]) + '">' + m + '</span>');
////////////////
const highlight = code =>
  code.replace(/F+|L+|R+|\d+/g, val => `<span style="color: ${{F: `pink`, L: `red`, R: `green`}[val[0]] || `orange`}">${val}</span>`);
