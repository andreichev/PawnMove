//
// Created by Admin on 17/05/2022.
//

#pragma once

class CubeRenderer : public Panda::Component, Panda::WindowSizeListener {
public:
    CubeRenderer(glm::vec3 translate, glm::vec3 size);
    void initialize() override;
    void update(double deltaTime) override;

private:
    void windowSizeChanged(Panda::GSize _size) override;

    glm::vec3 translate;
    glm::vec3 size;
    glm::mat4 view;
    glm::mat4 model;
    glm::mat4 projectionMatrix;

    double time;
    Panda::TextureHandle texture;
    Panda::ShaderHandle shader;
    Panda::IndexBufferHandle indexBuffer;
    Panda::VertexBufferHandle vertexBuffer;
};
