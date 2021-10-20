import React from 'react';

function calcTime(offset) {
    // create Date object for current location
    var d = new Date();

    // convert to msec
    // subtract local time zone offset
    // get UTC time in msec
    var utc = d.getTime() + (d.getTimezoneOffset() * 60000);

    // create new Date object for different city
    // using supplied offset
    //var newDate = new Date(utc + (3600000*offset));

    // return time as a string
    //return "The local time for city"+ city +" is "+ newDate.toLocaleString();
    //return newDate;
    return new Date(utc + (3600000*offset));
}

const WeatherWidget = ({weatherData, special})=>{
    // States to hold the data related to the weather-condition..  in order to reflect the same on icons..
    const [weatherConditionCode, setWeatherConditionCode ] = React.useState("");  
    const [today, setDate] = React.useState(new Date()); // Save the current date to be able to trigger an update
    //const [timeZone, setTimeZone] = React.useState(0);

    // Can extract the values from the object received here... but currently moving on..
    const { temparature, humidity, pressure,
            weatherCondition,// iconID,
            windSpeed,
            cityName, timezone, 
            country, sunset} = weatherData;
        console.log(special);
    //setTimeZone(timezone);
    // For the appropriate icon based on the weater conditon... 
    React.useEffect(()=>{
        if(weatherCondition)
            switch(weatherCondition){   // Add cases, depending on the data...
                case "Clouds":  setWeatherConditionCode("wi-day-cloudy");
                                break;
                case "Haze":    setWeatherConditionCode("wi-fog");
                                break;
                case "Clear":   setWeatherConditionCode("wi-day-sunny");
                                break;
                case "Smoke":   setWeatherConditionCode("wi-smoke");
                                break;        
                case "Rain":    setWeatherConditionCode("wi-rain");
                                break;
                case "Mist":    setWeatherConditionCode("wi-dust");
                                break;
                default:        setWeatherConditionCode("wi-day-sunny");
            }
    }, [weatherCondition]);                 /// Mr, React, get triggered, only when changed the value of ``weatherCondition``
    
    //console.log(timezone);
    React.useEffect(() => {
        //console.log(weatherData);
        const timer = setInterval(() => { // Creates an interval which will update the current data every minute
        // This will trigger a rerender every component that uses the useDate hook.

        setDate( new Date());
        //setDate( new Date(utc + (3600000*offset)));
        //setTimeZone(timeZone);
      }, 1000);
    //   return () => {
    //     clearInterval(timer); // Return a funtion to clear the timer so that it will stop being called on unmount
    //   }
    }, []);
  


    // convert the sunset time to a understandble format from a number.. 
    var sunsetTime = new Date(sunset*1000);          // * 1000: so as to get the time in milli-secs
    var sunsetTimeStr = `${sunsetTime.getHours()}:${sunsetTime.getMinutes()}:${sunsetTime.getSeconds()}`;


    return (
        <>
            <article className="widget">
                <div className="weatherIcon">
                    <i className={`wi ${weatherConditionCode}`}></i> 
                    {/* <img src={`http://openweathermap.org/img/wn/${iconID}@2x.png`}/>     -- Use this way if to get the required image from their website via their iconID */}
                </div>

                <div className="weatherInfo">
                    <div className="temparature">
                        <span>{temparature}&deg;</span>
                    </div>

                    <div className="description">
                        <div className="weatherCo/10/2021, 4:07:24 pmndition">{weatherCondition}</div>
                        <div className="place">{cityName}, {country}</div>
                    </div>
                </div>
                <div className="date">{calcTime(timezone/3600).toLocaleString()}</div>
                <div className="extra-temp">
                    <div className="temp-info-minmax">
                        <div className="two-sided-section">
                            <p><i className={"wi wi-sunset"}></i></p>
                            <p className="extra-info-leftside">{sunsetTimeStr}<br/>
                                                                Sunset</p>
                        </div>
                        <div className="two-sided-section">
                            <p><i className={"wi wi-humidity"}></i></p>
                            <p className="extra-info-leftside">{humidity}<br/>
                                                                Humidity</p>
                        </div>
                    </div>
                    <div className="weather-extra-info">
                        <div className="two-sided-section">
                            <p><i className={"wi wi-barometer"}></i></p>
                            <p className="extra-info-leftside">{pressure}<br/>
                                                                Pressure</p>
                        </div>
                        <div className="two-sided-section">
                            <p><i className={"wi wi-day-windy"}></i></p>
                            <p className="extra-info-leftside">{windSpeed}<br/>
                                                                Wind</p>
                        </div>
                    </div>
                </div>
             </article>
        </>
    );
};

export default WeatherWidget;

/**
 * Addtional References taken:
 *  for Updating tme of the entered city (and keep it updating)
 *      src: https://stackoverflow.com/questions/8207655/get-time-of-specific-timezone
 *      for even more explanation of .. why that numbers..?? https://www.techrepublic.com/article/convert-the-local-time-to-another-time-zone-with-this-javascript/
 * 
 * 
 */