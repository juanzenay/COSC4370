
#version 330 core
out vec4 color;

in vec2 UV;
uniform sampler2D myTextureSampler;

void main()
{
    // TODO: pub with your code...
  color = texture(myTextureSampler, UV); //retrieves texture from myTextureSampler and puts in coordinates from UV
}
