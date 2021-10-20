import React from 'react';
import axios from 'axios';              // For the GET request of APIs

import './App.css';


class App extends React.Component{
    state = {                           // Contains all the global values realted to the App
        advice: ''                      // to storing the advice..
    }
    
    componentDidMount(){                // A React life-cycle model (thery are many such)
        console.log("COMPONENT DID MOUNT");
        this.fetchAdvice();
    }

    fetchAdvice = () =>{
        axios.get('https://api.adviceslip.com/advice')
        .then((response)=>{
            const {advice} = response.data.slip;
            this.setState({ advice})
            console.log(advice);
        })
        .catch((error)=>{
            console.log(error);
        });
    }

    render(){
        const {advice} = this.state;                        // De-structuring...
        return(
            <div className="app">
                <div className="card">
                    <div className="quote">{advice}</div>
                    {/* <button className="button" onClick={prompt("Enter some number: ")}>
                       Give an Advice..!!
                    </button> */}
                    {/* should be like  
                     <button onClick={()=>this.fetchAdvice} >Click</button>  -- Calling the function well, but getting the same quoute all the time*/}
                    <button onClick={()=>window.location.reload()} >Click</button>
                </div>
            </div>
        );
    }
};

export default App;