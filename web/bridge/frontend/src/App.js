import logo from './logo.svg';
import './App.css';
import React, { useState, useEffect } from 'react';
import axios from 'axios';
const address="127.0.0.1:5000/";
const fileName="dummy";
function App() {
  const [fileContent, setFileContent] = useState('');

  useEffect(() => {
      //fetchData();
      axios.get("127.0.0.1:5000/main")
              .then(response => {
                  setFileContent(response.data);
                  console.log(response.data);
              })
              .catch(error => {
                  console.error('Error fetching file:', error);
              });
  }, []);

  // const fetchData = () => {
  //    
  // };
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
