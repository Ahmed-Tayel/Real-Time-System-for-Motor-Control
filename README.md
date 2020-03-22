# Real Time Induction Motor Control (Application: Vacuum Cleaner)
Designed a Vacuum Cleaner software with the following specifications:
1)	Three speeds: low – Medium – High, two switches for increasing and decreasing the speed.
2)	Seven segment display for speed monitoring.
3)	Induction Motor soft switching feature between speeds: firing angle shifts 10 degrees for every 40 ms.
4)	Induction Motor soft start up: on starting the machine, the firing angle softly shifts from 170 degrees to 90 degrees (low to medium speed).
5)	Induction Motor harmonics reduction: firing angle shifts by ± 5 degrees for every 20 ms round its constant speed.
6)	Overload safety: using a pressure sensor (simulated by a button), when the storage tank is nearly full the sensor is active, the pressure led will turn on, and the machine will automatically reduce its speed every 30 seconds till reaching its lowest speed.

## Static Behavior

## Modules
1) Rto  : System scheduler
2) SW   : Switch buttons controller
3) SSD  : Seven segment display controller
4) Motor: Motor controller
5) Led  : Over-pressure indicator led controller
6) Timer: PIC Controller timer driver
7) Display: Application logic for controlling seven segments using SSD controller
8) Vaccum_Cleaner: Application logic for reading switch values through SW Module and updates display module with the current speed for the indicators, updates motor for the new desired speed, and turn on the Led if over-pressure is detected.

The following figure illustrates the interaction between the modules:

<p align="center">
  <img src="Images/System_Description.PNG"/>
  <br/>
</p>



## Dynamic Behavior
The system main cycle is 20 ms and the scheduler interrupt comes every 10 ms and invoke the following cyclic functions
1) SSD_Update               : 10 ms
2) Motor_update             : 10 ms
3) SW_Update                : 20 ms
4) Vaccum_Cleaner_update    : 20 ms