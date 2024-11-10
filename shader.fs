#version 330

in vec2 fragTexCoord;
in vec4 fragColor;

uniform sampler2D texture0;
uniform vec4 colDiffuse;

out vec4 finalColor;

void main()
{
    vec4 texelColor = texture(texture0, fragTexCoord);
    // 反转颜色
    texelColor.rgb = 1.0 - texelColor.rgb;
    finalColor = texelColor * colDiffuse;
}