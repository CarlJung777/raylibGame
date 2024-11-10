#version 330 core

in vec2 fragTexCoord;
out vec4 fragColor;

uniform sampler2D texture0;

void main() {
    vec4 color = texture(texture0, fragTexCoord);
    
    float gray  = dot(color.rbg, vec3(0.299, 0.587, 0.114));
    
    fragColor = vec4(vec3(gray), color.a);
}