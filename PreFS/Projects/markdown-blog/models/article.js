/*Why this..?? To store the articles..**/

// Get the mongoose..
const mongoose = require('mongoose')
const marked = require('marked')        // for markdown
const slugify = require('slugify')
const createDomPurify = require('dompurify')
const { JSDOM } = require('jsdom')                            // Placed in {}, as need only that specific part..
const dompurify = createDomPurify(new JSDOM().window)       // Getting the HTML and purifying it.. refer docs for more
// Define the schema of the document..
const articleSchema = new mongoose.Schema({
    title: {
        type: String,
        required: true
    },
    description:{
        type: String
    },
    markdown:{
        type: String,
        required: true,
    },
    createdAt:{
        type: Date,
        default: () => Date.now()   // or simply, "Date.now"
    },
    slug:{                          // Storing thes slug in DB, so as to avoid re-calculate each time. But this need to be updated, if made any ""Edit""s
        type: String,
        required: true,
        unique: true,
    },
    sanitizedHTML:{
        type: String,
        required: true,
    }
})

// Update the "slug", before any changes(save, delete, update, create) are going to be **Appplied** on document..
articleSchema.pre('validate', function(next){
    // create the slug for title..
    if(this.title){
        this.slug = slugify(this.title, {
            lower: true,
            strict: true,                   // If any invalid characters(;, :, ?...) appears, it removes..
        })
    }

    if (this.markdown){
        this.sanitizedHTML = dompurify.sanitize(marked(this.markdown))          // Converting the markdown to HTML and purifying it..
    }

    next()
})

// Now to use this defined schema, export it..
module.exports = mongoose.model('Article', articleSchema)   // to put it simply: Table with the name "Article", its schema is hold by @param-2