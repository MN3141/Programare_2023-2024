const express = require('express');
const { spawn } = require('child_process');
const fs = require('fs');
const scriptName = 'main.py';
const app = express();
const port = 5000;
const fileName = "dummy";
const fileExtension = ".txt";
function runScript() {
    app.get('/main', (req, resp) => {
        resp.send('Hello Python!');
        const pythonScript = spawn('python', [scriptName]);//generates dummy.txt
    });
    if (fs.existsSync(fileName + fileExtension)) {
        console.log("Ita");
        app.get('/' + fileName, (req, res) => {
            fs.readFile(fileName + fileExtension, 'utf8', (err, data) => {
                if (err) {
                    console.log("ERROR!");
                    res.status(500).send('Error reading file');
                    return;
                }
                console.log(data);
                res.send(data);
            });
        });
    }
    else console.log(fileName + ' does not exist!');
    app.listen(port, () => {
        console.log('Server is running on port ' + port);
    });
}
runScript();