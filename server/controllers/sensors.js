import SensorModel from '../models/sensorModel.js';

export const getSensor = async (req, res) => {
    try {
        const sensorModel = await SensorModel.find().sort({createdAt:-1}).limit(1);
        res.status(200).json(sensorModel);
    } catch(error){
        res.status(404).json({ message: error.message });
    }
}
export const createSensor =  async(req, res) => {
    const sensor = req.body;
    const newSensor = new SensorModel(sensor);

    try {
        await newSensor.save();
        res.status(201).json(newSensor);
    } catch(error){
        res.status(409).json({ message: error.message });
    }
}