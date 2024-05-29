//curl -X POST http://localhost:3000/posts -H "Content-Type: application/json" -d '{"name": "John"}'

//curl -X DELETE http://localhost:3000/posts/db0
const { error } = require('console');
const express=require('express');
const fs=require('fs');
const app=express();
const PORT=3000;
const DATABASE_FOLDER='database/';
function fileExists(filePath)
{
    if(fs.existsSync(filePath))
        return 1;
    return 0;
}
function readFile(filePath)
{
    const data=fs.readFileSync(filePath);
    return JSON.parse(data);
}
function writeData(filePath,data)
{
    fs.appendFileSync(filePath,JSON.stringify(data,null,2));
}
app.use(express.json());
app.listen(PORT,()=>{
    console.log("Server running on port: ",PORT);
}
);
app.get('/',(req,res)=>{
    let buffer=[];
    fs.readdirSync(DATABASE_FOLDER).forEach(file => {
        buffer.push(file);
      });
      res.send(buffer);
});
app.get('/posts/:id',(req,res)=>{
    const param=req.params;
    const filePath=DATABASE_FOLDER+param.id+'.json';
    if(fileExists(filePath))
   { const fetchedData=readFile(filePath);
    res.status(201).send(fetchedData);}
    else res.status(404).send("Database does not exit!");
});
app.post("/posts/",(req,res)=>
{
    const fileNumber=fs.readdirSync(DATABASE_FOLDER).length;
    const requestData=req.body;
    if(requestData)
    {
        const fileName=DATABASE_FOLDER+'db'+fileNumber+'.json';
        writeData(fileName,requestData);
        res.send("Data created succesfully");
    }
    else res.send("Request input is null");
});
app.delete('/posts/:id',(req,res)=>{
    const param=req.params;
    const filePath=DATABASE_FOLDER+param.id+'.json';
    if(fileExists(filePath))
    {
        fs.unlinkSync(filePath);
        res.send("File removed succesfully");
    }
    else res.status(400).send("Database does not exist!");
});
/*
    switch(req.params.id)
    {
        case 'txt:
            fileFormat='.txt';break;
        case 'json':
            fileForamt='.json';break;
        case default:
            res.send("File extension not found!");
    }
*/