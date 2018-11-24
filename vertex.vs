#version 330

in vec3 vPosition;

// Vertex and Fragment Shaders will both use this varying to communicate
//   interpolated color between vertices...
out vec4 color;
out vec2 vTexCoord;
out gl_PerVertex { vec4 gl_Position; };

void main (void)
{
    vTexCoord = vec2(512.0, 512.0);
    gl_Position = vec4 (vPosition, 1.0);
    color       = vec4 (vPosition.y, vPosition.y, 0, 1.0);
}