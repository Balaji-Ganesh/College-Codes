import React from 'react'

const NavBar = ({filterItems, menuList}) => {
    return (
        <>
            <nav className="navbar">
                <div className="btn-group">

                    {
                        menuList.map((menuCategory)=>{
                            return (
                                <button className="btn-group__item" 
                                        onClick={()=> filterItems(menuCategory)}>
                                        {menuCategory}
                                        </button>
                            );
                        })
                    }
                </div>
            </nav>
        </>
    )
}

export default NavBar;
