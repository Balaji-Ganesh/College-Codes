import React from 'react'

const MenuCard = ({menuData}) => {
    console.log(menuData);

    return (
        <>
        <section className="main-card--container">
        {menuData.map((menuItem)=>{
            const {id, image, name, author, description} = menuItem;       // De-Structuring the object...
            return (
            <>
                <div className="card-container">
                    <div className="card">
                        <div className="card-body">
                            <span className="card-number card-circle subtitle"> {id} </span>
                            <span className="card-author subtitle">{author}</span>
                            <h2 className="card-title">{name}</h2>
                            <span className="card-description subtitle">
                                {description}                                
                            </span>
                            <div className="card-read">Read</div>
                            <img src={image} alt="food-image" className="card-media"/>
                            <span className="card-tag subtitle">Order Now</span>
                        </div>
                    </div>
                </div>
            </>
            );
        })};
        </section> 
        </>
    )
};

export default MenuCard;
