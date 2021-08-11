import React from 'react';
import { CircularProgress } from '@material-ui/core';
import { useSelector } from 'react-redux';

import Sensor from './Sensor/Sensor';
//import useStyles from './styles';

const Sensors = () => {
    const sensors = useSelector((state) => state.sensors);
    //const classes = useStyles();
    return(
        !sensors.length ? <CircularProgress /> : (
            <>
              {sensors.map((sensor) => (
                  <Sensor sensor={ sensor } />
              ))}
            </>
        )
    );
}

export default Sensors;