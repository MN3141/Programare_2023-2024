import logo from './logo.svg';
import './App.css';
import React, { useState, useEffect } from 'react';
const address = "http://127.0.0.1:5000/get";
function App() {
  const [data, setData] = useState(null);

  useEffect(() => {
    fetch(address)
      .then(response => response.json())
      .then(data => setData(data))
      .catch(error => console.error('Error fetching data:', error));
  }, []);
  if(data)
    {console.log("Data has been sent.");}
  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <p>
          Edit <code>src/App.js</code> and save to reload.
        </p>
        <a
          className="App-link"
          href="https://reactjs.org"
          target="_blank"
          rel="noopener noreferrer"
        >
          Learn React
        </a>
      </header>
    </div>
  );
}

export default App;
