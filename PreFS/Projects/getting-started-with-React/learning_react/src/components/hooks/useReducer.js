import React from 'react'
import "./style.css";

const reducer = (state, action) =>{     // This function's address is witht he `dispatch`. So this gets called when `dispatch` called
    if(action.type ==="INC")                 // Check the action..
        state+=1;
    if(state >0 &&action.type ==="DEC")
        state-=1;
    return state;                       // If no change, returning as received  
};

const UseReducerTest = () => {
    const initialData = 10;
    const [data, setData] = React.useState(initialData);        // useState - to maintain the state

    // React.useEffect(()=>{                   // useEffects -- To-do some task after the rendering of the page
    //     document.title = `Chats (${data})`;
    // })                                      // by }, []) -- Treated as  the dependency, and doesn't reload each-time

    const [state, dispatch] = React.useReducer(reducer, initialData);
    return (
        <>
            <div className="workspace">
                <p>{data}</p>
                <div className="controllers">
                    <div class="btn1" onClick={()=>dispatch({type: "INC"})}>
                        Increment
                    </div>
                    <div class="btn2" onClick={()=>dispatch({type: "DEC"})}>
                        Decrement
                    </div>
                </div>
            </div>
        </>
    )
}

export default UseReducerTest;
