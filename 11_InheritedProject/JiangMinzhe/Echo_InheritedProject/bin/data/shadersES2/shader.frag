
precision highp float;

void main()
{
    // gl_FragCoord contains the window relative coordinate for the fragment.
    // we use gl_FragCoord.x position to control the red color value.
    // we use gl_FragCoord.y position to control the green color value.
    // please note that all r, g, b, a values are between 0 and 1.
    
    float windowWidth = 1280;
    float windowHeight = 1024;
    
    float r = 1.0;
    float g = 1-gl_FragCoord.x / windowWidth;
    float b = 1-gl_FragCoord.y / windowHeight;
    float a = 1.0;
	gl_FragColor = vec4(r, g, b, a);
}
