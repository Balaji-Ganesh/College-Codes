import React from 'react';
import "./styles.css"

const Todo = () => {
    // Get the todos from the localStorage..
    const getTodosFromLocalStorage = ()=>{
        const retrievedTodos = localStorage.getItem("added-todo-lists"); // this is the name, with which its is stored.. so retrieving by same name..
        if(retrievedTodos)                                      // If existing..
            return JSON.parse(retrievedTodos)
        else   
            return []                                           // return empty list, when not..
        
    };
    
    const [inputData, setInputData]       = React.useState("");         // To track what the user is typing..
    const [todos, setTodos]               = React.useState(getTodosFromLocalStorage());              // to add and store the todos in the list..
    const [editTodoItemID, setEditTodoItemID] = React.useState("");         // To keep track of the item which need to be edited..
    const [onEditMode, setOnEditMode]     = React.useState(false);      // To set the "edit-icon" on the text box accordingly..
    
    // Add a todo item to the list && and also updated for: to update an existing todo item..
    const addToTodos = ()=>{
        //console.log("addToTodos called");
        if(!inputData)          // If string is empty.. Warn the user..
            alert("Please fill item name to add");
        else if(inputData && onEditMode){
            setTodos(
                todos.map((todoItem)=>{
                    if(todoItem.id === editTodoItemID){
                        return {...todoItem, todo_name: inputData}; // REturn, by making necessary changes..
                    }
                    return todoItem;                            // Return it, as received... 
                })
            );
            setInputData("")
            setOnEditMode(false);                               // As by now, the job of editing has done.. toggle it.
            setEditTodoItemID(null);
            //setInputData("");                                   // Clear the board to write the new todo..
        }
        else{
            const todoItem = {
                id : new Date().getTime().toString(),
                todo_name: inputData,
            }
            setTodos([todoItem, ...todos]);
            //console.log(todos);
            setInputData("");           // Clearing the entered text
        }
    };

    // edit Specific todos... 
    const editTodo = (todo_id)=>{
        const editedTodoItem = todos.find((todoItem)=>{      // Get that todo-item name, whose id matched..
            return todoItem.id === todo_id;               
        });

        setInputData(editedTodoItem.todo_name);                  // Place that todo-item in the txtBox.. to edit.. 
        setEditTodoItemID(todo_id);                         // Store its ID, so as to edit..
        setOnEditMode(true);                                // As om the edit mode, and need to update the icon accordingly..
        console.log(editedTodoItem);
    };


    // Delete specific todos
    const deleteElement = (todo_id)=>{ 
        const updatedTodos = todos.filter((todo)=>{
            return todo.id !== todo_id;
        })
        setTodos(updatedTodos);
        //console.log(todo_id);
    }
    // Delete all the todos
    const deleteAllTodos = ()=>{
        setTodos([]);
    }

    // Stage the todos to the "localStorage"
    React.useEffect(() =>{
        localStorage.setItem("added-todo-lists", JSON.stringify(todos))     // Storing all the todos under the key-name of 'added-todo-lists
    }, [todos]);                            // Mr., React, Please respond only to the changes of "todos"

    return(
        <>
            <div className="main-div">
                <div className="child-div">
                    <figure>
                        <img src="./todo-images/todo.svg" alt="todo-image"></img>
                        <figcaption> List your tasks here..!!</figcaption>
                    </figure>
                    
                    {/*Area where the user could able to add the todo-tasks*/}
                    {console.log(onEditMode)}
                    <div className="addItems">
                        <input type="text" 
                               placeholder=" ✍️  a todo" 
                               className="form-control"
                               value = {inputData}
                               onChange={(event)=>setInputData(event.target.value)}></input>
                        {/* Conditional Rendering..  the icon to be placed (editOn */}
                        { onEditMode ? <i className="far fa-edit add-btn" onClick={()=>addToTodos()}></i>
                                     : <i className="fa fa-plus add-btn" onClick={()=>addToTodos()}></i>} 
                    </div>
                    
                    {/*Area where all the todos are displayed in stack (FIFO) manner*/} 
                    <div className="showItems">
                        
                            {todos.map((todo_item, index)=>{
                                return (
                                    <>
                                        <div className="eachItem" key={index}>
                                            <h3>{todo_item.todo_name}</h3>
                                            <div className="todo-btn">
                                                <i className="far fa-edit add-btn" 
                                                   onClick={()=>editTodo(todo_item.id)}></i>
                                                <i className="far fa-trash-alt add-btn"
                                                   onClick={()=> deleteElement(todo_item.id)}></i>
                                            </div>
                                        </div>
                                    </>
                                )
                            })  
                            }
                    </div>


                    {/*Button to remove all the todos*/}
                    <div className="show-items">
                        <button className="btn effect04" data-sm-link-text="Cleared All" onClick={deleteAllTodos}><span>Check List</span></button>
                    </div>
                </div>
            </div>
        </>
    );
};

export default Todo;