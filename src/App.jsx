import { useEffect, useState } from 'react'
import './App.css'
import Logo from './assets/Logo.png'
import axios from 'axios'

function App() {
  const [waterData, setWaterData] = useState(null);
  const [cityColor, setCityColor] = useState('#36DB36');


  function checkStatus(cityStatus) {
    if (cityStatus == "vermelho"){
      setCityColor("red")
    }
    else if (cityStatus == "amarelo"){
      setCityColor("yellow")
    }else{
      setCityColor("#36DB36")
    }
  }

  useEffect(() =>{
    let intervalId
    const fetchWater = async () => {
      try {
        const config = {
          method: 'get',
          maxBodyLength: Infinity,
          url: 'http://52.237.23.203:1026/v2/entities/urn:ngsi-ld:Water:001/attrs/',
          headers: { 
            'fiware-service': 'smart', 
            'fiware-servicepath': '/', 
            'accept': 'application/json'
          }
        };

        const response = await axios.request(config);
        setWaterData(response.data);
        checkStatus(response.data.message.value);
      } catch (err) {
        console.log(err)
      }
    };
      fetchWater();
      intervalId = setInterval(fetchWater, 5000)

      return () => {
        if (intervalId) clearInterval(intervalId);
      };
  }, []); 
  
  return (
    <>
    <header>
      <img src={Logo} alt="" id='logo'/>
    </header>

    <section>
      <div className="map">
          <div className='ponto' style={{backgroundColor: cityColor}}>

          </div>
      </div>
    </section>

    </>
  )
}

export default App
