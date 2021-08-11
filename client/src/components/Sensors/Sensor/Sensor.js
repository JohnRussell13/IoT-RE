import React from 'react';
import { Card, Typography, Grid, } from '@material-ui/core/';                                                                                                                             

import useStyles from './styles';

const Sensor = ({ sensor }) => {
    const classes = useStyles();
    return(
      <Grid container spacing={10}>
        <Grid item xs>
          <Card xs={12} sm={6} md={6} className={classes.card} align="center">
            <Typography className={classes.title} variant="h5" component="h2">Moisture sensor</Typography>
            <Typography className={classes.details} gutterBottom variant="h3" component="h2">{sensor.moist}%</Typography>
          </Card>
        </Grid>
        <Grid item xs>
          <Card xs={12} sm={6} md={6} className={classes.card} align="center">
            <Typography className={classes.title} variant="h5" component="h2">Light intensity sensor</Typography>
            <Typography className={classes.details} gutterBottom variant="h3" component="h2">{sensor.light}%</Typography>
          </Card>
        </Grid>
        <Grid item xs>
          <Card xs={12} sm={6} md={6} className={classes.card} align="center">
            <Typography className={classes.title} variant="h5" component="h2">Temperature sensor</Typography>
            <Typography className={classes.details} gutterBottom variant="h3" component="h2">{sensor.temp}°C</Typography>
          </Card>
        </Grid>
      </Grid>
    );
}

export default Sensor;