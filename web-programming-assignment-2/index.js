const getWeather = async (city) => {
  const API_KEY = process.env.API_KEY; // replace this with your API key from https://openweathermap.org/api

  const url = `https://api.openweathermap.org/data/2.5/weather?q=${city}&units=metric&appid=${API_KEY}`;
  const response = await fetch(url);
  const data = await response.json();
  const arrData = [data];

  const cityName = `${arrData[0].name}, ${arrData[0].sys.country}`;
  const wind = arrData[0].wind.speed;

  console.log('City:', cityName);
  console.log('Wind:', wind, 'm/s');
};

const city = process.argv[2];
getWeather(city);
