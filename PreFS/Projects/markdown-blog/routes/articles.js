const express = require('express')
const Article = require('./../models/article')
const router = express.Router()     // Provides the functionality as the app.<method>('<route>, <call-back>) in server.js file, but in diff. flavour

router.get('/new', (request, response)=>{       // If its a new article, routed via this..
    response.render('articles/new', {article: new Article()})
})

router.get('/edit/:id', async(request, response)=>{
    const article = await Article.findById(request.params.id)
    response.render('articles/edit', {article: article})
})

router.get('/:slug', async (request, response)=>{       // If it is the older one..
    const article = await Article.findOne({
        slug:request.params.slug});    // async func
    if (article == null) 
        response.redirect('/')      // If not found any article, re-direct to home page of articles
    response.render('articles/show', {article: article})
})

// for creating a new Article..
router.post('/', async (request, response, next)=>{
    // Create the new article..
    request.article = new Article()
    next()                              // Calls the next function, i.e.,
}, saveArticleAndRedirect('new'))          //                               this one..

// for editiing..
router.post('/edit/:id', async (request, response, next)=>{             // refer notes.txt about the routing method... and the route..
    // Get the new article..
    request.article = await Article.findById(request.params.id)
    console.log("[INFO] Routed to (PUT) edit  method..");
    next()                              // Calls the next function, i.e.,
}, saveArticleAndRedirect('edit'))          //                               this one..

// for deletion of the articles..
router.post('/delete/:id', async( request, response)=>{                /////// The router should be like "router.delete".. (w/o '/delete')but not working, so, as using POST in <form of index.js, using POST -- but find the solution
    console.log("[INFO] Routed to delete method..");
    await Article.findByIdAndDelete(request.params.id);
    response.redirect("/");      // Re=direct to home page..
})

function saveArticleAndRedirect(path){  
    return async (request, response)=>{        // Returns to a middleware
            let article = request.article;
            article.title = request.body.title
            article.description = request.body.description
            article.markdown = request.body.markdown
        try{
            // Save the article..
            article = await article.save()              // !!! Its a sync func. If could save properly, returns the saved article (along with the saved "_id").
            // Redirect to another page..
            response.redirect(`/articles/${article.slug}`)
        }
        catch(error){                         // If any of the fields aren't specified..
            // If any error, render the same page..
            console.log("[ERROR]"+error)
            response.render('articles/${path}', {article: article})
        }
    }
}


module.exports = router