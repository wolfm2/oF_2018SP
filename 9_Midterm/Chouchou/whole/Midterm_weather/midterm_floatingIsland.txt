Concept:
Getting the inspiration from the penguin pile up game and going into the situation of rapidly melting iceberg. I started using floating iceberg to represent a stable mainland to stress the gloal warming issues  
Rather than making a serious environmental problem seems too serious 

Process:
1. Draw illustrations of the floating island, coal and gas company, grass, smoke and the sea weaves.
2. Getting use of the Carbon Intensity API (http://carbonintensity.org.uk/) from the U.K. government. 
	#The carbon intensity data is updated every half hour and to make it  in a real-time trend I fetch the data from 2018-Jan-01-00:00 till now and codinng it to change every 5 seconds to make it change faster. 
	#During the data fetching process I firstly use for loops in for loops in update() function to get data from minute, hour, day to month. But it shows out that nothing is showing up on the screen. I finally relized that the problem is that I run too much code in one frame that it doesn't have enough time to draw things. So I tried and changed another logic which basically creating different counts for minute, hour, day and month.
 	#Without any data earlier that 2017-10-26, I cannot creat a big trend of how carbon dioxide is increasing in the air
	#The sealeve
3. I use map to map the carbon intensity to island's height and the radius of smoke circle to make them changing along with data online.
4. For the interation part, I create a scenerio that whenever people click on the screen, there will grows up a plant and the smoke of the electricity supply company will decrease and drift away. 