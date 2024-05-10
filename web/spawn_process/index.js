const express = require('express');
const { spawn } = require('child_process');
const fs = require('fs');
const scriptName = 'main.py';
const app = express();
function runScript()
{
  const pythonScript=spawn('py',[scriptName]);
     app.get('/main', (req, resp) => {
         resp.send('Hello World!');
        
     });
    app.listen(3000, () => {
        console.log('Server is running on port 3000');
    });
}
// function transmitData() {
//   const filePath = 'dummy.txt';
//   //metoda readFile este asincrona precum fetch!
//   fs.readFile(filePath, 'utf8', (err, data) => {
//       if (err) {
//           console.error("Error reading file:", err);
//           return;
//       }
//       console.log("File content:", data);
//       return data;
//   });
// }
runScript();
const scriptum=spawn('py',['test.py']);