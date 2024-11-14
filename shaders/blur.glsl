#version 330 core

in vec2 fragTexCoord;
out vec4 fragColor;

uniform sampler2D texture0;
uniform float blurAmount; // 模糊强度控制

void main()
{
    vec4 color = vec4(0.0);
    float offset = blurAmount / 300.0;
    
    // 对四周的像素采样
    color += texture(texture0, fragTexCoord + vec2(-offset, -offset)) * 0.25;
    color += texture(texture0, fragTexCoord + vec2(offset, -offset)) * 0.25;
    color += texture(texture0, fragTexCoord + vec2(-offset, offset)) * 0.25;
    color += texture(texture0, fragTexCoord + vec2(offset, offset)) * 0.25;
    
    fragColor = color;
}
