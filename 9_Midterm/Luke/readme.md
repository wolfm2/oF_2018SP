Translation/Overview:

Mouse over each circle to get an expanded view of the popularity by hour.

Attribution:

Lines 27-31 of ofApp.cpp for getting the current time/date were taken from a source online.
I forgot to write down the exact page, but the same snippet is floating around many
stackoverflow posts.

The popularTimes.py script is a modified and pared down version of https://github.com/m-wrzr/populartimes

Requirements: 

1) Sound
2) 4 of (Movement, Easing, Shape changing, Alpha Channels, Matrix, FBO)
3) Drawing (images and/or shapes)
4) Fonts & Writing (a title screen at least)
5) An ofxAddon not covered in class (Arduino, Graphical effects, Device Drivers)
6) A Web API -or- non-superficial Arduino usage  
7) Interaction
8) A presentation

1) ofApp.cpp line 112
2) a) Easing, place.cpp lines 153-171
2) b) Shape Changing, place.cpp lines 153-171
2) c) Alpha Channels, ofApp.cpp lines 99 and 106
2) d) Matrix, place.cpp lines 120-124 and 142-146
3) place.cpp lines 113-148
4) place.cpp lines 123 and 145
5) No ofxAddon, but I used a python script for getting json data and web scraping
6) See PopularTimes.py, I use the requests module to make api calls and google searches
7) Mouseover interaction, ofApp.cpp line 76
8) Shared via google drive

Extra Work:

I used a python script for the web api and web scraping, since it's much easier to parse web pages that way

Questions/Comments:

Install the python requirements to a virtualenv, there's some redundant packages there.
Be careful when running the python script, Google doesn't like web scraping and may gate access behind a captcha,
which can't be solved from the script. It should be fine to run if you give it a couple of minutes between runs.

The populartimes.py script requires a google places api key (set the key on line 197). 
You can set the type of establishment you're looking for (bar, restaurant, store, etc) on line 198 (https://developers.google.com/places/supported_types). 
The location is hardcoded to center around D12.
Location can be modified by the lat/lng parameters on lines 17 and 18.

There's a bug where if you hover over two overlapping places they both expand. It's probably 
an issue with a conditional somewhere, but I haven't managed to track it down.

I would have liked to be able to call the python script using a system call, but I never got 
around to it due to the other features I needed to implement.