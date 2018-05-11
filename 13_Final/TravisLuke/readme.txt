Video: https://www.dropbox.com/s/xmjs0aeubj1d0hf/video_presentation.mp4?dl=0
Slides: https://docs.google.com/presentation/d/1TVuA3isD7kFhUPBIV2XQRvh8u6-pTaUUlhS7Uc-5Rfs/edit?usp=sharing

Translation/Overview:

This project by default uses your microphone as input. Simply run the project and you 
will see the what the sound spectrum looks like.

If you use a virtual audio device like virtual audio cable (windows) or soundflower (mac), 
you can reroute the audio from your speakers to a microphone input and visualize any sound 
coming from your computer.

Attribution:

For this project I used the ofxFft addon and the ofxPostProcessing addon.

Requirements:

For the sound requirement I use sound as input.
For the nonlinear movement I ease out/low pass filter the histogram values to create a persistence effect.
For the new topic I used FFTs and postprocessing.

Questions/Comments:

Working with the FFT library was tricky due to all the array manipulation. I had to do a lot 
of thresholding and signal processing to get a clean and meaningful signal.

For drawing the circles I tried using a filled ofPath, but it seems like that slows things 
down a lot. 

If I had more time I would have liked to try to implement the constant Q algorithm. Constant 
Q is similar to the FFT, but it generates a log scale output. With the FFT each bin is the 
same distance from the next in terms of frequency, so there is a linear mapping from bins to 
frequency. This results in a much higher resolution for high frequencies than for low ones.