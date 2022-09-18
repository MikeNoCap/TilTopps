const express = require("express");
const app = express();
const ejs = require("ejs");
const bodyParser = require("body-parser");
const { exec } = require("child_process");

app.set("view engine", "ejs");
app.use(express.static("public"))
app.use(bodyParser.json())

app.get("/", (req, res) => {
    res.render("index")
})

app.post("/calc", (req, res) => {
    console.log(req.body)
    exec(`.\\main.exe ${req.body.n1} ${req.body.n2} ${req.body.n3} ${req.body.n4} ${req.body.n5}`, (error, stdout, stderr) => {
        res.json({svar: stdout.split("\r\n").slice(0, 100)})
    });
})


app.listen(3000, () => {
    console.log("Listening on port 3000!")
})