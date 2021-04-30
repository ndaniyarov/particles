#version 400

layout (location = 0) in vec3 vPos;

uniform vec3 uCameraPos;
uniform float uSize;
uniform vec3 uOffset;
uniform vec4 uColor;
uniform mat4 uVP;

out vec4 color;
out vec2 uv;

void main()
{
   color = uColor;
   //for (int i = 0; i < 4; i++){
    //  for (int j = 0; j < 8; j++){
         //uv = (vPos.xy + vec2(1,1))/vec2(4,8);
   uv = vPos.xy;
   vec3 cen = vPos + vec3(-0.5, -0.5, 0);
   cen.xyz = cen.xyz * uSize;
   vec3 x = cross(vec3(0,1,0), normalize(uCameraPos-cen));
   vec3 y = cross(normalize(uCameraPos-cen), normalize(x));
   vec3 z = normalize(uCameraPos-cen);
   mat3 t = mat3(normalize(x), normalize(y), z);

   gl_Position = uVP * vec4(t*cen+uOffset, 1.0); 
      //   }
   //}
}

