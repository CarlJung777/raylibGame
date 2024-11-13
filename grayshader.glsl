#version 330 core

// 关键字 in  out
in vec2 fragTexCoord;
out vec4 fragColor;

// uniform 关键字表示该变量的值在整个着色器执行过程中是常量
// sampler2D 一个二维纹理的采样器。它允许着色器从纹理中提取颜色数据
uniform sampler2D texture0; 


void main() {
    // texture 函数从纹理 texture0 中采样颜色，fragTexCoord 是输入的纹理坐标。
    vec4 color = texture(texture0, fragTexCoord);
    
    // 点积操作，计算输入颜色的加权平均值，即生成灰度值。 权重向量:vec3(0.299, 0.587, 0.114)
    float gray  = dot(color.rbg, vec3(0.299, 0.587, 0.114));
    
    fragColor = vec4(vec3(gray), color.a);
}