Translation/Overview: 

Move the mouse over the pink face mapping dots to make music. 


Requirements: 

Inherit a classmate's midterm code. Assess the original concept and how their execution related to it. Improve upon or offer an alternative take on the concept. 


Questions/Comments:

I inherited Young's midterm, which was divided across 2 Xcode files. One randomly draws tonal hot spots to the canvas. A particle cloud follows the cursor and grows bigger as you press any keyboard button. When these particles pass over the tonal hot spots en route to the cursor, the hot spots chime different piano notes. The sound gets interesting with lots of particles. 

The other Xcode file syphons the information captured from FaceOSC to draw a nodal map of my face to the canvas. At the bottom of the canvas is the image of piano keys. At the top of the canvas are instructions to press the directional arrows to trigger different sounds. 

Young’s intention was to merge these two sketches, making the nodal face mapping musical like the hot spots. 


My plan: 

Figure out how to achieve Young’s original goal of merging these functions. I failed at that, as such was too complex for my level of coding.  Alternatively, I did my best to achieve his concept: a face mapping that plays music. 

Instead of live syphoning the face mapping and turning it musical, I took a screenshot of my face mapping, and then loaded that into the tonal hot spot file. Instead of drawing the hotspots randomly, I drew them on top of the face nodes and the deleted my face mapping screenshot, leaving only the face-shaped hotspots. This drawing worked, and the particles played musical tones, but not in any way that directly related to their intersecting my face mapping nodes. I struggled for a long time to figure out to get this to work, but ultimately broke the code beyond understanding with all my futzing with it!   

At that point, I have to say, I started a clean Xcode file, drew the face to the canvas, and programmed musical notes to play upon nodal mouseover. 

I know I did this in a very tedious, long-form way. I should have used classes, vectors, and arrays, but after struggling so long with the original files and then not being able to get the arrays on this new file working right, I went long-form because I knew I could get the concept to work this way.

