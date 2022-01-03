#version 330 core
out vec4 FragColor;
in vec2 texCoord;
in vec3 normal;

uniform sampler2D uTexture;

void main() {
    float shading = max(dot(normalize(normal), normalize(vec3(1.0,5.0,3.0))), 0.2);
    FragColor = texture(uTexture, texCoord) * shading;
    //FragColor = vec4(normal, 1.0);
}