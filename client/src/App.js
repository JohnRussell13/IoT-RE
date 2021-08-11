import React, { useEffect } from 'react';
import { Container, AppBar, Typography, Grow } from '@material-ui/core';
import { useDispatch } from 'react-redux';
import CssBaseline from "@material-ui/core/CssBaseline";
import { ThemeProvider, createTheme } from "@material-ui/core/styles";

import Sensors from './components/Sensors/Sensors';
import { getSensors } from './actions/sensors';
import useStyles from './styles';

const themeDark = createTheme({
    palette: {
      background: {
        default: "#050505"
      }
    }
  });

const App = () => {
    const dispatch = useDispatch();
    const classes = useStyles();

    useEffect(() => {
      dispatch(getSensors());
    }, [dispatch]);

    return(
        <ThemeProvider theme={themeDark}>
            <CssBaseline />
            <Container maxwidth="lg">
                <AppBar className={classes.appBar} position="static">
                    <Typography className={classes.heading} variant="h2" align="center">Smart plant pot</Typography>
                </AppBar>
                <Grow in>
                    <Container>
                        <Sensors />
                    </Container>
                </Grow>
            </Container>
        </ThemeProvider>
    )
}

export default App;