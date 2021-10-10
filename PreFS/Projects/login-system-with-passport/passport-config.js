/* Contains all the ""passport""" related  things..*/
// for the local related tasks of the passport..
const LocalStrategy = require('passport-local').Strategy
const bcrypt = require('bcrypt')


async function initialize(passport, getUserByEmail, getUserById){
    //. This will get calld from the "Login", to make sure that, email and password are valid...
    const authenticateUser = async (email, password, done)=>{     // @param-3, the function-name, which gets called when done authentication
        const user = getUserByEmail(email)                  // Returns the "name" from the email, stored in ``users`` as list. If couldn't (i.e., if not already in list), return ``null``
        // If couldn't find the user, with that email..
        if(user == null){
            console.log("No such user")
            // Call the call-back function..
            return done(null,       // Error if any on the server . Here no-error.
                        false,      // Returning the user we've found. Here, as no user found, returning false.
                        {message: 'No user found with that e-mail'}   // the error message, to be displayed on the screen
                        )

        }
        // Control here..  means we've found the user.. !!! But still entered password MAY or MAY not be the correct one. So..
        try{                // Using try-catch, as its asynchronous..
            //console.log("[INFO] Entered try block.."+user)
            // If the entered pwd is valid..
            if(await bcrypt.compare(password, user.password)){       // Checking the entered pwd(hashed) with the stored one(hashed)
                return done(null,       // As no error in the server..
                            user,       // Return the valid user
                            {message: "Welcome user..!!"}
                            )
            }
            else{   // If pwd didn't matched..
                return done(null,       // with no error..
                            false,      // As not a VALID USER to be returned, as bad password
                            {message: 'Password incorrect'}
                        )
            } 
        }
        catch(error){
            return done(e)              // Return the error..
        }
    }


    passport.use(new LocalStrategy({usernameField: "email", passwordField:"password"}, // for @param-1[default] username, for @param-2[default]: password. So if any different use in application specify it, else not.
    authenticateUser))        // The function-name as argument, Function which it calls...
    
    // To store the user-details in the session... /////////////Recollect the Java way of Serialization, said by Neil sir. -- its about storing the OBJECTS of a class in a file format, and can send over a network.
    passport.serializeUser((user, done)=> done(null, user.id))
    passport.deserializeUser((id, done)=> {
        return done(null, getUserById(id))
    })
}

module.exports = initialize