/** Importing the dependencies **/
var express = require("express")   // A framework to write the server easily 
var bodyParser = require("body-parser") // body-parser     // Helps to parse the data which we get via POST methods into JSON
var mongoose = require("mongoose")// mongoose         // helps in creating models and iterface 
    // nodemon          // Autmatically restarts the server for any smal changes made in code.

// Creating the express app..
const app = express();

// Using dependecies to the app..
app.use(bodyParser.json())
app.use(express.static('public'))       // Static HTML files will be in the "public" directgory
app.use(bodyParser.urlencoded( {        // matches the type option, when got the request from server.
    extended:true
}));

// Connecting to database..
mongoose.connect('mongodb://localhost:27017/signupdb', {
    useNewUrlParser: true,
    useUnifiedTopology: true
});      // Even if the databased doesn't exist, it gets created..

// Initialize the connection...
var db = mongoose.connection;

// check for the connection status
db.on('error', ()=>console.log("[ERROR] Error in connecting to database"))  // If error..
db.once('open', ()=> console.log("[SUCCESS] Connected to database")) // If connection is open..means sucessful



/** Routes..  **/
var PORT = 3000
// listen-up for the signup .. its a POST request remember..!!
app.post("/signup", (request, response)=>{
    // Extract the data which we received..
    var name = request.body.name;
    var email = request.body.email;
    var phone = request.body.phone;
    var password = request.body.password;

    // store all these in the data-object to sotre in mongodb..
    var data={
        "name": name,
        "email":email,
        "phone": phone,
        "password": password
    }
    
    db.collection('users').insertOne(data, (error, collection)=>{
        if (error){
            throw error;
        }
        console.log("Record inserted successfully..!!")
    })//.then() // By now, the record(document) would have got inserted in db.
    // Now, when document got inserted in db, would like to redirect to a new page..
    return response.redirect('signup-success.html')
})

// listen home route
app.get("/", (request, response)=>{
    response.set({
        "Allow-access-Allow-Origin":"*"     // As running server from local host, it gets access -- but what accessesing..?
    })
    response.send("Hello from Server check!!");
    return response.redirect('index.html');
}).listen(PORT);
console.log(`Listening on ${PORT}`)
 

/**
 * 
 * 
 * Log-notes... as worked on 9th October, 2021 ~ Saturday_2
 * ==========================================================================================================================
 * 
 * Run the Mongodb.. as
 *     sudo mongod --dbpath /var/lib/mongo --logpath /var/log/mongodb/mongod.log --fork
 * Check the status..
 *     sudo cat /var/log/mongodb/mongod.log
 *     good response: 
 *          { .... "msg":"Waiting for connections","attr":{"port":27017, ...}}
 *
 *  Response on trying "localhost:27017"
 *      It looks like you are trying to access MongoDB over HTTP on the native driver port.
 * ---------------------------------------------------------------------------------------------------
 * $ nodemon index.js
 *  [nodemon] restarting due to changes...
    [nodemon] starting `node index.js`
    Listening on 3000
    [SUCCESS] Connected to database

 * Goto browser and try out..http://localhost:3000/, it displays a signup form. Fill some details, and click on submit, 
    then it navigates to: http://localhost:3000/signup-success.html
    and can see the """Record inserted successfully..!!""" printed on the console where nodemon started..

 * One can verify, is it worked or not...
 * Try out: 
 *  $mongo 
 *  > show dbs
    admin     0.000GB
    config    0.000GB
    local     0.000GB
    signupdb  0.000GB
    > use signupdb
    switched to db signupdb
    > db.users
    signupdb.users
    > db.users.find().pretty()
    {
        "_id" : ObjectId("6161c578c209a80272f493ab"),
        "name" : "Govinda",
        "email" : "govinda18@gita.org",
        "phone" : "8964245873",
        "password" : "AsdferegcEWT$#a34@"
    }
    ==========================================================================================================
    ==========================================================================================================
    src:  SignUp Form with HTML, Node JS, MongoDB | Vasanth Korada | INFY TECH
          https://youtu.be/_hfMmFx85KE
          Sir's git repo: for further reference: https://github.com/Vasanth-Korada/SignUpForm-HTML_NodeJS_MongoDB
 */