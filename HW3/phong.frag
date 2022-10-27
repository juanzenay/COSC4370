
#version 330 core
out vec4 color;

in vec3 FragPos;  
in vec3 Normal;  
  
uniform vec3 lightPos; 
uniform vec3 viewPos;
uniform vec3 lightColor;
uniform vec3 objectColor;

void main()
{
  // TODO: Replace with your code...
  // https://learnopengl.com/Lighting/Basic-Lighting used as reference

  //need diffuse, specular, and ambient lighting to create the proper shader

  //ambient light
  float ambientSt = 0.1; //how bright the ambient light will be
  vec3 ambientLight = ambientSt * lightColor; //the ambient lighting final value

  //diffuse light - to calc we need normal vector and directed light ray
  //diffusion
  vec3 directionLight = normalize(lightPos - FragPos);
  vec3 normal = normalize(Normal); //normalize 
  float diffuse = max(dot(normal, directionLight), 0.0); //how the light hits cube
  vec3 diffuseLight = diffuse * lightColor; //this is the diffusion lighting

  //calculate specular lighting- highlights, also needs lights direction and object normal vectors
  int shine = 50; //defines how much model will reflect light
  vec3 fromViewDirection = normalize(viewPos - FragPos);
  vec3 reflectionDirectionObj = reflect(-fromViewDirection, normal); //creates a proper reflection for specular calculations
  float specular = pow(max(dot(fromViewDirection, reflectionDirectionObj), 0.0), shine); //calculates specular value
  vec3 specularLight = 0.5 * specular * lightColor;// is specular light, final piece
  //spec
  
  color = vec4((ambientLight + diffuseLight + specularLight) * objectColor, 1.0f);

} 
