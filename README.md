# H(n)MI Class - MDEF

Group Members: [Lucretia Field](https://lkfield.github.io/mdef/), [Maria Vittoria Colombo](https://colombomariavittorias-organizati.gitbook.io/maria-vittoria-colombo-mdef), [Ramon Prat Gibert](https://ramon-prat-gibert.gitbook.io/ramon-prat-mdef-website/crea/final-project)

This repository collects the work of our group for the "Small Data" project during the H(n)MI class. 

## 11_02_experiments Folder 

This folder contains the experiments from the first day of H(n)MI when we worked with Arduino and Processing to connect a soft pressure sensor that we made from a piezo resistive material between two layers of conductive material. 

| Folder Name               | Description                                                               |
| ------------------------- | ------------------------------------------------------------------------- |
| code_pressure             | Arduino code to interface with the Arduino and the soft pressure sensor   |
| pressure_connect          | Processing code to interface with the Arduino                             |

## 13_02_experiments Folder

This folder contains the experiments from the second day of H(n)MI when we worked with P5.js 

| File Name                 | Description                                                               |
| ------------------------- | ------------------------------------------------------------------------- |
| keystroke_experiment.js   | Initial experiment with keystroke input to move shapes with keystrokes    |
| keystroke_experiment.mov  | Screen recording of first keystroke experiment                            |
| keystroke_experiment_2.js | Second experiment with keystroke input                                    |
| keystroke_experiment_2.mov| Screen recording of second keystroke experiment                           |
| mic_experiment.js         | Initial experiment with microphone input                                  |
| mic_experiment.mov        | Video of microphone experiment                                            |
| p5_test.png               | Photo of initial P5.js test with drawing                                  |
| processing.png            | Photo of the initial Processing connection 'hello world' test             |


## 14_02_experiments Folder

This folder contains the experiments from the third day of H(n)MI

| File/Folder Name          | Description                                                               |
| ------------------------- | ------------------------------------------------------------------------- |
| pressure_day3             | Arduino code to interface Arduino with sensor and slow framerate for P5   |
| TimeDots                  | P5 Folder with code to show dots on screen every 1 second & save data     |
| WebSerial_to_Arduino      | P5 Folder with code to connect Arduino with P5.js                         |
| pressure.mov              | Video of pressure sensor working with P5.js                               |


## Small Data - Dance Visualization 

The idea for this project is to put pressure sensors in Lucretia's dance shoes and then to test a few different dance steps and visualize what the different dance forms look like in terms of pressure on the feet to check for patterns and see how the movement manifests. 

Proposed code architecture: 
- Read 4 pressure sensors (heel and ball of the foot in both feet)
- Write the values to a Google Sheet using the API 
- Read the data from the Google Sheet into P5.js and visualize the data 


### dance_visualization Folder 

| File/Folder Name          | Description                                                               |
| ------------------------- | ------------------------------------------------------------------------- |
| fourPressureSensors       | Arduino code to interface Arduino with 4 pressure sensors                 |
| media                     | Folder containing photos and videos of the process                        |
| Publish2Sheet             | Arduino code to publish generic data to a Google Sheet using the API      |
|               |                        |

## References 
Some of the code can be found in the repository by Citlali Hernández and Lina Bautista for the course: [https://github.com/TURBULENTE/H-n-MI](https://github.com/TURBULENTE/H-n-MI)