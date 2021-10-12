const express = require("express")
const mongoose = require('mongoose')
const Article = require('./models/article')
const articleRouter = require('./routes/articles')         /// All the ""routes""  are defined here..!!
const methodOverride = require('method-override')
const app = express()           // Create the app




mongoose.connect('mongodb://localhost:27017/markdown_blog', {
    useNewUrlParser: true,
    useUnifiedTopology: true,
    //useCreateIndex: true,
})


/** Setting the view engine..**/
app.set('view engine', 'ejs')

/** Use the routers defined in "./routes/*" **/
app.use(express.urlencoded({extended: false}))      // !!! This should be first than usage in `articles`
app.use('/articles', articleRouter)     // All other routes defined, will get the prefix as "/articles", as cessing via this "./routes/articles"
app.use(methodOverride('_method'))       // Used, as form only supports GET and POST. So w're overriding it. At 
                                        //   At performed as <form action="/articles/<%= article.id%>_method=DELETE" method="POST">
                                        // So, this replaces method with DELETE, so can use in routing...

/** Routes... */
app.get("/", async (request, response)=>{
    const articles = await Article.find().sort({createdAt: 'desc'})                 // Gets all the articles.. as passed emty filter
    response.render('articles/index', {articles: articles})
})





const PORT = 5000
app.listen(PORT)
console.log(`[INFO] Listening at port ${PORT}`)