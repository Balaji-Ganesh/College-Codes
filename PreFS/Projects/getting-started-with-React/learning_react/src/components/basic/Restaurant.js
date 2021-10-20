import React from 'react';
import "./style.css";
import Menu from "./menuAPI";
import MenuCard from "./menuCard";
import NavBar from "./navBar";

const uniqueMenuItemCategories = [
    ... new Set(
        Menu.map((menuItem)=> {
            return menuItem.category;
        })
        ),       // Converting into a set (to avoid duplicates), flattening array, so as to get only the DATA..
        "All",

];
console.log(uniqueMenuItemCategories);

export const Restaurant = () => {
    // Using stateHooks -- alternative: Redux
    const [menuData, setMenuData] = React.useState(Menu);   // The first one holds the current data, the second is the function..
    //-----^^^^^^^ will get filtered upon calling the `setMenuData(<replaced_by_this>)..which done below..

    const [menuCategoriesList, setMenuCategoriesList] = React.useState(uniqueMenuItemCategories);



    const filterItems = (category) =>{
        
        if(category === "All"){
            setMenuData(Menu);      // Passing the whole list. In comparison at navBar.js, it gets searched with itself, so will get all the items.
            return;
        }

        const filteredMenuList = Menu.filter((menuItem)=>{
            return menuItem.category === category;                // Filtering only those categories, as required by the user.
        });
        // Now update the list...
        setMenuData(filteredMenuList);                             // When this gets called, changes the current state value (i.e, the menu list)
    };
    return (
        <>
            <NavBar filterItems={filterItems} menuList={menuCategoriesList}/>
            <MenuCard menuData={menuData}/>
        </>
    );
};

export default Restaurant;
