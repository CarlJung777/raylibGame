#version 330

// in <数据类型> <变量名>;
in vec2 fragTexCoord;
in vec4 fragColor;


// uniform <数据类型> <变量名>;    定义全局常量（uniform 变量）
uniform sampler2D texture0;
uniform vec4 colDiffuse;

// out <数据类型> <变量名>;
out vec4 finalColor;


void main()
{

    vec4 texelColor = texture(texture0, fragTexCoord);
    // 反转颜色
    texelColor.rgb = 1.0 - texelColor.rgb;
    
    finalColor = texelColor * colDiffuse;
    
}
