#version 400

in vec2 uv;
in vec4 color;
uniform sampler2D image;
//uniform sampler2D image2

out vec4 FragColor;

void main()
{
   FragColor = color * texture(image, uv);
}
