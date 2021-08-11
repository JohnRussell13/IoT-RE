import axios from 'axios';

const url = 'https://iot-try.herokuapp.com/sensors';

export const fetchData = () => axios.get(url);