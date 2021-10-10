// Loading the environment variables..
if( process.env.NODE_ENV !== 'production'){     // If in development.. get that development dependency..
    require('dotenv').config()                  //  loads all the environment variables and configures it (sets then im `process.env`)
}
const express = require('express')
const app =  express()
const bcrypt = require('bcrypt')
const passport = require('passport')
const flash = require('express-flash')
const session = require('express-session')
const methodOverride = require('method-override')


// Initialize the passport..
const initializePassport = require('./passport-config')
const { request } = require('express')
initializePassport(
    passport,                                               // configuring the passport
    email => users.find(user => user.email === email),      // Finding the users based on their email
    id => users.find(user => user.id === id)
)

const users = []      // For testing, using local memory array instead of the database..
/**Set the viewing engine */
app.set('view-engine', 'ejs')

app.use(express.urlencoded({extended: false}))          // with this, can make use of the filled form-data via **request** parameters of callbacks.. (for POST methods)
app.use(flash())
app.use(session({
    secret: process.env.SESSION_SECRET,                 // A key which encrypts all our inf.. Will be getting from the environemen variables.
    resave: false,                                      // Shoule we re-save if nothing is changed in session
    saveUninitialized: false                            //  Do you want to save empty value in session? if there is no value.
}))
app.use(passport.initialize())                          // Set up the basics for it..
app.use(passport.session())                             // As would like to persist the variables for storing, across the entire session
app.use(methodOverride('_method'))                      // What we gonna override..// the method from html page. 
                                                           // used as: <form action="/logout?_method=DELETE"  method="POST"  -- understand as.. method POST is being overridden by _method(as DELETE)

/**Define the routes */
app.get("/", checkAuthenticated, (request, response)=>{
    response.render('index.ejs', {name: request.user.name})     // passport sets the current user in `request.user`..
})


app.get('/login',checkNotAuthenticated, (request, response)=>{
    response.render('login.ejs')
})
app.post('/login', checkNotAuthenticated, passport.authenticate(
    'local',                                            // local strategy
    { successRedirect: '/',                             // Where to go if success?
      failureRedirect: '/login',                        //                failure?
      failureFlash: true,                               // to display the message of failure, if any. Its the `@param-3 of done()` in passport-config.js
    }
))



app.get('/register', checkNotAuthenticated, (request, response)=>{
    console.log("[INFO] register...")
    response.render('register.ejs')
})
app.post('/register', checkNotAuthenticated, async (request, response)=>{
    try{
        // Creating the hashed password..
        const hashedPassword = await bcrypt.hash(request.body.password, 10)   // @param-2: How secure our hash to be. 10 is the good value
        users.push({
            id: Date.now().toString(),
            name: request.body.name,
            email: request.body.email,
            password: hashedPassword
        })  // Storing the details in the db..(in view..)
        console.log("[INFO] User registered successfully")
        // Now, after storing the details, re-direct to another page..
        response.redirect("/login")
    }
    catch{      // If any failure occured..
        response.redirect("/register")          
    }
    console.log("Registered users list:")
    console.log(users)
})


// For logging out..
app.delete('/logout', (request, response)=>{
    request.logOut()                                /// Will clear the session, and logs out the user
    response.redirect('/login')
})







/**Fixing some common issues */

// When any error is occured, its showing on the browser. We would like to protect in not showing info to all. For authenticated users its ok.... so..
function checkAuthenticated(request, response, next){   // a middle-ware
    if(request.isAuthenticated())       // will get true if authenticated..
        return next()
    // If failure..(not authenticated)
    response.redirect('/login');
}

// Even when the user is logged in successfully, they can still go-to the /login page... so let's avoid it..
function checkNotAuthenticated(request, response, next){   // a middle-ware
    if(request.isAuthenticated())       // will get true if authenticated..
        return response.redirect('/')          // If already logged in, get them to home page..
    // If failure..(not authenticated)
    next()                              // continue with the call..
}



const PORT = 3000
app.listen(PORT)
console.log(`[INFO] Listening on port ${PORT}`)