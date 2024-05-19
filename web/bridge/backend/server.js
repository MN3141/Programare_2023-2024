const express=require('express');//gestionare memorie pt server
const app=express();
const port=5000;
const cors = require('cors');//Cross Origin Resource Sharing
const path=require('path');
app.use(cors());

app.listen(port,()=>{
    console.log("Server running on port ",port);
});
app.get('/get',(req,res)=>{
    const fileName="../test.json";
    console.log("Sending file...");
    //res.send("Sending file");//FARA SEND NU SE INCARCA PAGINA
    const filePath = path.join(__dirname,fileName);//alegere cale relativ la directorul proiectului
    res.sendFile(filePath, {
        headers: {
          'Content-Type': 'application/json'
        }
      });
});