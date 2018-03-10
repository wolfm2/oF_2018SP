Translation/Overview:

Use Dark Sky’s API to draw a sun that is responsive to the current time. The sun’s position and the background color change based on current time relative to sunrise/sunset. 

The printed text defaults to tomorrow’s summary and high temperature, but press keys 0-7 to view today through next 7 days. 



Requirements: 

1) Write "Hello World" on the canvas.
2) Draw the summary text and high temperature for tomorrow on the canvas.  
3) Use key presses 0-7 to print the above for each day in the forecast. 
4) Draw an orange circle on the screen at y=100 r=50.  Its X should be a map() using our current time, sunrise/sunset, and the width of the canvas.
5) Use this with the current time, sunrise, sunset to map a value between 0 - 1.
6) Using this, make the background a lerp between yellow (255,255,0) and black.


1) ofApp.cpp: 48
2) ofApp.cpp: 53-62 
3) ofApp.cpp: 81-106
4) ofApp.cpp: 66-72
5) ofApp.cpp: 37-41
6) ofApp.cpp: 42-46



