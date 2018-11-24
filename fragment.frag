#version 330
precision highp float;
/* This takes the place of the old *gl_Color*, but it does not handle
 *   polygon side. If you _really_ do need a different color for
 *     front and back, then you will have to do things a little
 *       differently (SEE BELOW).
 */
in vec4 color;
uniform float time;
uniform sampler2D imageTexture;
in vec2 vTexCoord;
layout(location = 0) out vec4 diffuseColor;

#define M_PI 3.1415926535897932384626433832795

void main(void)
{
    diffuseColor = color;
}