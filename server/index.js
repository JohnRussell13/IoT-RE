import express from 'express';
import mongoose from 'mongoose';
import cors from 'cors';
import dotenv from 'dotenv';

import sensorRoutes from './routes/sensors.js';

const app = express();
dotenv.config();

app.use(express.json()); //bodyParser
app.use(express.urlencoded({ extended: true }));
app.use(cors());
app.use('/sensors', sensorRoutes);

app.get('/', (req,res) => {
    res.send('Hello');
});

const PORT = process.env.PORT || 5000;
const HOST = '0.0.0.0'

mongoose.connect(process.env.CONNECTION_URL, { useNewUrlParser: true, useUnifiedTopology: true })
    .then(() => app.listen(PORT, HOST, () => console.log(`Server running on port: ${PORT}`)))
    .catch((error) => console.log(error.message));

mongoose.set('useFindAndModify', false);
