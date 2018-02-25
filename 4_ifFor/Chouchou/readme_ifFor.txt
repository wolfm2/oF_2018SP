Steps:
1. I use the equation x*x + y*y <= radius*radius to set the circle outside the mouse so that the circle space is free of colorful circles
2. to set the color changing with the mouse position, I map the x, y position of mouse to 0 to 255 to change the r and g. So that the whole cnavas' color go from blue to pink to purple.
3. use frame buffer to create the fade effect.