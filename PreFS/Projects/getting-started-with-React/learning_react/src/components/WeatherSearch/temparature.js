import React from 'react';
import WeatherWidget from './weatherWidget';
import "./styles.css"


const Temparature = ()=>{ 

    const [searchedCity, setSearchedCity]                   = React.useState("Mumbai");  /// To keep track the cityname entered by the user..
    const [retrievedWeatherData, setRetrievedWeatherData]   = React.useState({});           // to keep track of the retrieved data from the API

    const getWeatherInfo= async()=>{
        try{
            let url=`https://api.openweathermap.org/data/2.5/weather?q=${searchedCity}&units=metric&appid=943bc1f2bde08c157ce81b7e9c4bf6c9`;
            // Get the responser from the URL.. 
            const response  = await fetch(url);
            const data      = await response.json();
            
            // extract the required parameters from the data.. 
            const {temp:temparature, humidity, pressure}    = data.main;
            const {main:weatherCondition, icon: iconID}     = data.weather[0];
            const {speed: windSpeed}                        = data.wind;  
            const {name: cityName, timezone}                = data;
            const {country, sunset }                        = data.sys;

            // Placing the extracted parameters in an object to use it further..
            const extractedWeatherData={
                temparature:temparature, humidity: humidity, pressure: pressure,
                weatherCondition: weatherCondition, iconID,
                windSpeed: windSpeed,
                cityName: cityName, timezone, 
                country: country, sunset: sunset,
            }
            // Store this in a state variable.. 
            console.log("From sender: "+timezone)
            setRetrievedWeatherData(extractedWeatherData);
            console.log(extractedWeatherData);
        }
        catch(error){
            console.log(error)
        }
    }

    // To do a task, as soon as the page loads..
    React.useEffect(()=>{
        getWeatherInfo();
    }, []);                 // Passing some empty array, so as to avoid unwanted updations once after loading..

    return (
        <>
             <div className="wrap">
                 <div className="search">
                    <input type="search" placeholder="Search for a city name.." autoFocus
                            id="search" className="searchTerm"
                            value={searchedCity}
                            onChange={(event)=>setSearchedCity(event.target.value)}/>
                    <button className="searchButton" type="button" 
                            onClick={()=>getWeatherInfo()}>Search</button>
                 </div>
             </div>

             {/* Displaying the Temparature card... */}
             <WeatherWidget weatherData={retrievedWeatherData}/>
        </>
    );
};

export default Temparature;

/**
 * 
 * Src: https://youtu.be/EHTWMpD6S_0
 *      Complete React JS Tutorial in Hindi with 5 Projects in 2021
*/