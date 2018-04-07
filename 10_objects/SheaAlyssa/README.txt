Translation/Overview: 

Move the mouse around the canvas to make the rectangles follow.  


Requirements: 

Identify all the variables and functions required to make the square move.
1)Write a class that encapsulates all the above variables, with an update and draw method in a class declaration.
2)The class should include two other methods: setCUSpeed, and setColor.  Both should be called only once from the constructor. 
3)Make 5 objects of this class each initialized with a different catchUpSpeed and color. 
Each should start at a random x,y within the canvas.
The ONLY globals should be your 5 objects.


1) ofApp.h: 15 - 26
2) ofApp.h: 22 - 23 
3) ofApp.cpp: 4 - 21



Questions/Comments:

I cannot seem to get this right. Initializing the catch up speed and color to vary between all rectangles isn't working. I just kept the catch up speed to 0.01 for now because that visually works better in the current state. I feel like I'm close but not really able to work it out. 