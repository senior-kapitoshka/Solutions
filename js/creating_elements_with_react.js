var React = require("react");

function createElement(content, tag, props) {
  return React.createElement(tag||'div',props||{},content);
}

function createUnorderedList(lst) { 
  return createElement(
    lst.map((el,i)=> createElement(el,'li',{key:i++}))
                       ,'ul')
}

//////////////
let React = require('react'),
    createElement = (content, tag = 'div', opts) => React.createElement(tag, opts, content),
    createUnorderedList = arr => { 
      let children = arr.map((el,i) => createElement(el, 'li', { key: i }) )
      return createElement(children, 'ul')
    }
    ///////////

    let React = require('react');

    function createElement(content, tag='div', props={}) {
      return React.createElement(tag, props, content);
    }
    
    function createUnorderedList(list=[]) {
      return React.createElement('ul', {}, list.map((str, i) => React.createElement('li', {key : +i}, str)));
    }
    
    /////////////
    let React = require('react'); // Yippeeee!! 

function createElement(content = 'Hello World', Tag = 'div', props) {
	return <Tag {...props}>{content}</Tag>;
}

function createUnorderedList(list) { 
	return (
  	<ul>
    	{list.map((item, i) => <li key={i}>{item}</li>)}
    </ul>
  );
}