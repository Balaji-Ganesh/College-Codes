import React from 'react'
import "./style.css";

const UseEffectTest = () => {
    const initialData = 10;
    const [data, setData] = React.useState(initialData);        // useState - to maintain the state

    React.useEffect(()=>{                   // useEffects -- To-do some task after the rendering of the page
        document.title = `Chats (${data})`;
    })                                      // by }, []) -- Treated as  the dependency, and doesn't reload each-time
    return (
        <>
            <div className="workspace">
                <p>{data}</p>
                <div className="controllers">
                    <div class="btn1" onClick={()=>setData(data+1)}>
                        Increment
                    </div>
                    <div class="btn2" onClick={()=>data > 0 ? setData(data-1) :setData(0)}>
                        Decrement
                    </div>
                </div>
                <p>Look the &lt;title&gt; section... for the change</p>
            </div>
        </>
    )
}

export default UseEffectTest;
