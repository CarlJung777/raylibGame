#version 330 core

out vec4 FragColor;  // 替代 gl_FragColor，声明一个输出变量

void main()
{
    FragColor = vec4(1.0, 0.0, 0.0, 1.0);  // 将片段颜色设置为红色
}
