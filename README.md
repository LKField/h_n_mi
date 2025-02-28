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

### dance_visualization Folder 

| File/Folder Name          | Description                                                               |
| ------------------------- | ------------------------------------------------------------------------- |
| fourPressureSensors       | Arduino code to interface Arduino with 4 pressure sensors                 |
| media                     | Folder containing photos and videos of the process                        |
| Publish2Sheet             | Arduino code to publish generic data to a Google Sheet using the API      |
| publishData2Sheet         | Arduino code to publish pressure sensor data to Google Sheet              |
| OscTest_Send              | Arduino code to test sending OSC messages                                 |
| OscTest_Receive           | Processing code to test receiving OSC messages                            |
| circlePressure            | P5.js code to visualize sensor value - just one sensor                    |
| basicPressureVis          | Processing code to visualize all four sensor values                       |

The final files that we used are fourPressureSensors.ino and basicPressureVis.pde to read the 4 sensors to the Serial port and then visualize them using Processing. 

## Our Process 

### The sensors 

The sensors for the shoes were very similar to the sensor we made in class on the first day with Citlali. This included using copper tape as the conductive layers on the top and bottom of the insoles, adding a piezo resistive layer and creating connectors with the nylon conductive tape. For this we used two layers of piezo resistive material in an attempt to reduce the point at which the sensor saturated. While it is unclear if this helped at all, what did help was modifying the circuit. 

| Copper tape for sensor conductors | Adding the Piezo Resistive Material |
|-----------------------------------|-------------------------------------|
|![Making the Sensor Copper](dance_visualization/media/makeSensor_01.jpeg)| ![Making the Sensor with Piezo Resistive Material](dance_visualization/media/makeSensor_03.jpeg)|


### The circuit 

|                                   | New Circuit Diagram                 |
|-----------------------------------|-------------------------------------|
| By changing the resistor from 1kOhms to 100Ohms, the saturation point of the analog read pins was significantly reduced. Instead of relatively light pressure saturating the sensor, full body weight had to be placed on the sensor before it saturated at 4095. | ![The modified circuit](dance_visualization/media/circuit.jpg) |

### The protoboard 

To attempt to make the device wireless, the tenuous connections of the breadboard had to be made more secure. Therefore, once the circuit was complete, a perfboard was used to solder the resistors in place and make the connections more robust. 

TO DO: Add the video here 

### Attempts at wireless data transfer 

The first attempt to make the data transfer wireless was to use the Google Sheets API to send the data to a remote spreadsheet. While this worked, eventually, it was extremely slow. The data was only writing about every 0.5 seconds. This is likely due to the way that the array of data being sent was being created. Either way, it was far too slow to be useful for our purposes. 

The proposed code architecture was: 
- Read 4 pressure sensors (heel and ball of the foot in both feet)
- Write the values to a Google Sheet using the API 
- Read the data from the Google Sheet into P5.js and visualize the data 

The code can be found in the [publishData2Sheet](dance_visualization/publishData2Sheet) folder. To use this code, an *arduino_secrets.h* file would need to be created with your credentials in the following format:

``` c++
    #define SECRET_SSID "YOUR WIFI NAME"
    #define SECRET_PASS "YOUR WIFI PASSWORD"

    // Google Project ID
    #define SECRET_ID "YOUR GOOGLE SHEET API PROJECT ID"

    // Service Account's client email
    #define SECRET_EMAIL "YOUR SERVICE ACCOUNT EMAIL"

    // Service Account's private key
    #define SECRET_API "-----BEGIN PRIVATE KEY-----\nYOUR GOOGLE SHEET API KEY\n-----END PRIVATE KEY-----\n"

    // The ID of the spreadsheet where you'll publish the data
    #define SECRET_SHEET_ID "YOUR GOOGLE SHEET ID"
```

The next method was to try to use Open Sound Control to send the data wirelessly. We were able to get the Arduino sending a message and Processing receiving it, but it wasn't very clear how to send multiple data points and we eventually game up on the idea in favor of using a long cable to connect to the Barduino to allow for movement during the dance. 

Follow these links to find the [Arduino code](dance_visualization/OscTest_Send) and [Processing code](dance_visualization/OscTest_Receive). An *arduino_secrets.h* file will need to be created with the following format: 

``` c++
    #define SECRET_SSID "YOUR WIFI NAME"
    #define SECRET_PASS "YOUR WIFI PASSWORD"

    #define SECRET_PORT 172,0,0,0 // Your destination port 
```

### Visualization - P5.js 

We experimented with P5.js for visualization options. These included making a few circular visualizations and another one that acted more like a graph. ChatGPT was a helpful resource in coming up with the code for these visualizations. 

This code can be found in the [circlePressure](dance_visualization/circlePressure) folder. 

TODO: Ask for images of these visualizations 

### Visualization - Processing 

Unfortunately, we were only able to get P5.js to read in a single sensor value. Because we were using code provided by Lina and Citlali, we struggled to understand how to actually read and use the data. Eventually Citlali suggested we switch to Processing and use some example code she had. Eventually we were able to get the Arduino to print multiple values to the Serial port and to get Processing to read in all those values and display them (with the help of ChatGPT to understand Citlali's code). 

The Processing code can be found in the [basicPressureVis](dance_visualization/basicPressureVis) folder. 

We then started playing around with different colors, different visual representations, and different speeds. Because the window could only be a certain size, we had to reduce the speed at which the visualization expanded. We didn't want to send less data as this would reduce the resolution of the pressure we could measure. Instead we reduced the distance the visualization expanded every time. 

| 4 sensor visualization - first test | 4 sensor visualization - later test |
|-------------------------------------|-------------------------------------|
| ![First visualization method](dance_visualization/media/rapper_step.png) | ![Later visualization method](dance_visualization/media/rapper_step_02.png) |

### Presentation 

We were able to test a few different dance styles to see the different ways the visualization changed. 

Check out the videos of the dance styles and the resulting patterns that were created to see the differences. 

| Name of Step Type | Video of dance | Pattern Created |
|-------------------|----------------|-----------------|
| Rapper Stepping   |                | <img src="dance_visualization/media/rapper_step.png" width=45%>      |
| Strathspey Setting|                | <img src="dance_visualization/media/strathspey.png" width=45%>       |
| Pas de Basque     |                | <img src="dance_visualization/media/pasdebasque.png" width=45%>      |

|                   | Walking step pattern |
|-------------------|----------------------|
| In most of these types of dance, the heels are not supposed to touch, therefore it appears in many of these patterns that the heel sensors were not working despite them functioning just fine as can be seen in the pattern made from walking normally. | ![Walking step pattern](dance_visualization/media/walking.png) |

### Next steps 

If we were going to continue this project, there are some things we would like to work on next. 

- Make it actually wireless using OSC 
- Reduce the wires by putting the microcontroller closer to the feet, ideally not connected together
- Experiment more with the visualization to make different things clearer about the movement 
- Perhaps use machine learning to analyze the data of the different dance forms to find patterns 
- Perform more tests and create more visualizations 

## References 

- H-n-MI repository by Citlali Hernández and Lina Bautista: [https://github.com/TURBULENTE/H-n-MI](https://github.com/TURBULENTE/H-n-MI) 
- Fabacademy respositiory by Citlali Hernández: [https://github.com/TURBULENTE/Fabricademy/tree/main](https://github.com/TURBULENTE/Fabricademy/tree/main). 
- OSC repository by adrianfreed for Arduino: [https://github.com/CNMAT/OSC?tab=readme-ov-file](https://github.com/CNMAT/OSC?tab=readme-ov-file)
- OSC repository by sojamo for Processing: [https://github.com/sojamo/oscp5/tree/master](https://github.com/sojamo/oscp5/tree/master)
