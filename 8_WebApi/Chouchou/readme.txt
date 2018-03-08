Steps:
1. load a font to use for drawing string
2. draw summary text and tomorrow's high temperature means we should navigate the info in this direction: 
	tomorrow's summary text: ["daily"]["data"][1]["summary"]
	tomorrow's high temperature: ["daily"]["data"][1]["temperatureHigh"]
3. declare an int type dayMark to store the key we press. In keypressed() function, I used switch-case to store the key in dayMark, so that I can pass this dayMark to json as the array number I need, like json["daily"]["data"][dayMark]["temperatureHigh"]
4. to set the circle's x position, I used map function. I mapped current time from sunrise time-sunset time to 0-canvas width so that x position is changing along with the current time which gives a visual explanation for current time in the day
5. to set the background color, I still used map function. I mapped current time from sunrise time-sunset time to 0-1 so that background color can change from yellow to black as the current time approaching sunset time.


new things learned: 
How to draw strings in the center:
	use float fontWidth = myFont.stringWidth(string); to calculate the string's width
	draw the string at the position (ofGetWidth()/2-fontWidth/2,y);

