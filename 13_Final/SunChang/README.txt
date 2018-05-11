
Youtube link: https://youtu.be/2l9QrT6FcaI
Presentation Slides Link: https://docs.google.com/presentation/d/1UMPATEr0nSg_dvZfGXZGexXTRHJ4Dww8SBI7xEnkSkM/edit?usp=sharing


This is my final, <Visual Rain>, a audio responsive and sound visualization project created with OpenFramework. 
I visualized the music <Raniny Blood> by artist Hot Sugar. 


- My design concept is:
    If a song has emotion and personality, how can I visualize it?

I find it really interesting to do the sound visualization for some psychedelic & abstract songs. 



For the creation of this project, I created a class named 'Ball' to define the properties of the main visual components in my 
sketch. I defined the scale of transtion, the level of transition and the positions of transition; mainly with 3 main functions
in this class: setup(), update(), draw().I used ofSignedNoise() function to control the position of the balls, the scale size of 
the balls with the parameter of current time. For an organic and smooth occurence of the balls pop up on my screen.Then I used
fft in my main sketch. I use fft to control the intensity change of the background color according to the song.
I also did a perlin noise line in the background represent the heartbeats. 




* I FULFILL THE REQUIREMENTS:

-Sound file loading & playing;
-Nonlinear movement  (Perlin)
-Matrix functions (Translate & scaling)
-A new (to you) topic from openframeworks (book?) not covered in class:Sound FFTs
-A presentation (Google slides)
-0 Borrowed Code (I write and learnt and create all by myself. Truely 0 borrow)


