import React from 'react'
import "./style.css";

const UseStateTest = () => {
    const initialData = 10;
    const [data, setData] = React.useState(initialData);
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
            </div>
        </>
    )
}

export default UseStateTest;
