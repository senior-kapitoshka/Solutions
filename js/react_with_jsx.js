let React = require('react')

var myHeader= 
      <h1>My three favorite codewarriors are nobody, nothing and nowhere</h1>;


var CodewarsLink = React.createClass({
  render: function() {
    return (
      <a href={`http://www.codewars.com/users/${this.props.user}`}>{this.props.user}</a>
    )
  }
});

var Leaderboard = React.createClass({
  render: function() {
    return(
      <div>
        {this.props.leaders.map(leader => <a href={"http://www.codewars.com/users/" + leader}>{leader}</a>)}
      </div>
    )
  }
});

//////////
const React = require("react")

const myHeader = 
  <h1>My three favorite codewarriors are noLan, jhoffner and OverZealous</h1>;

const CodewarsLink = ({user}) => 
  <a href={"http://www.codewars.com/users/" + user}>{user}</a>;

const Leaderboard = ({leaders}) => 
  <div>{leaders.map(e => <CodewarsLink user={e} />)}</div>;