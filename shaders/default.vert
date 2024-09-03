#version 460 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

out vec3 out_color;

void main() {
    gl_Position = vec4(position, 1.0F);
    out_color = color;
}
