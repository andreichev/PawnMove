//
// Created by Admin on 17/05/2022.
//

#include "CubeRenderer.hpp"

CubeRenderer::CubeRenderer(glm::vec3 translate, glm::vec3 size)
    : translate(translate)
    , size(size) {}

void CubeRenderer::initialize() {
    auto vertices = new Vertex[]{
        // Front
        Vertex(-1.0f, -1.0f, 1.0f, 0.0f, 1.0f, 1.0f), // 0
        Vertex(1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f),  // 1
        Vertex(1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f),   // 2
        Vertex(-1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f),  // 3
        // Back
        Vertex(-1.0f, -1.0f, -1.0f, 0.0f, 1.0f, 1.0f), // 4
        Vertex(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 1.0f),  // 5
        Vertex(1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 1.0f),   // 6
        Vertex(1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f),  // 7
        // Top
        Vertex(-1.0f, 1.0f, -1.0f, 0.0f, 1.0f, 1.0f), // 8
        Vertex(-1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f),  // 11
        Vertex(1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f),   // 10
        Vertex(1.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f),  // 9
        // Bottom
        Vertex(-1.0f, -1.0f, -1.0f, 0.0f, 1.0f, 1.0f), // 12
        Vertex(1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 1.0f),  // 13
        Vertex(1.0f, -1.0f, 1.0f, 1.0f, 0.0f, 1.0f),   // 14
        Vertex(-1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f),  // 15
        // Left
        Vertex(-1.0f, -1.0f, -1.0f, 0.0f, 1.0f, 1.0f), // 16
        Vertex(-1.0f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f),  // 17
        Vertex(-1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f),   // 18
        Vertex(-1.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f),  // 19
        // Right
        Vertex(1.0f, -1.0f, -1.0f, 0.0f, 1.0f, 1.0f), // 20
        Vertex(1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 1.0f),  // 23
        Vertex(1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f),   // 22
        Vertex(1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f)   // 21
    };

    auto indices = new uint32_t[]{
        0, 1, 2, 2, 3, 0,       // Front
        4, 5, 6, 6, 7, 4,       // Back
        8, 9, 10, 10, 11, 8,    // Top
        12, 13, 14, 14, 15, 12, // Bottom
        16, 17, 18, 18, 19, 16, // Left
        20, 21, 22, 22, 23, 20  // Right
    };

    Panda::VertexBufferLayoutData layoutData;
    layoutData.pushVector();
    Panda::VertexLayoutHandle layoutHandle = Panda::Miren::createVertexLayout(layoutData);
    vertexBuffer = Panda::Miren::createVertexBuffer(vertices, 24 * sizeof(Vertex), layoutHandle);
    indexBuffer = Panda::Miren::createIndexBuffer(indices, 36);

    texture = Panda::Miren::createTexture("textures/arbuz1.png");
    shader = Panda::Miren::createShader("shaders/base/base_vertex.glsl", "shaders/base/base_fragment.glsl");
    Panda::Miren::setShader(shader);

    Panda::GSize windowSize = Panda::ApplicationContext::get().getInput().getWindowSize();
    Panda::ApplicationContext::get().getInput().addWindowSizeListener(this);
    view = glm::lookAt(glm::vec3(0.f, 0.f, 10.f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    projectionMatrix = glm::perspective(glm::radians(40.f), windowSize.width / windowSize.height, 0.1f, 1000.0f);
    model = glm::mat4(1.f);
    translate = glm::vec3(0.f, 0.f, 0.f);

    Panda::Miren::setUniform(shader, "projection", &projectionMatrix[0][0], sizeof(glm::mat4));
    Panda::Miren::setUniform(shader, "view", &view[0][0], sizeof(glm::mat4));
    time = 0;
}

void CubeRenderer::update(double deltaTime) {
    time += deltaTime;
    model = glm::mat4(1.f);
    model = glm::scale(glm::mat4(1.f), glm::vec3(abs(sin(time)) + 1.f, abs(sin(time)) + 1.f, 1.f));
    model = glm::translate(model, translate);
    model = glm::rotate(model, (float)time, glm::vec3(1.f, 1.f, 0.f));

    Panda::Miren::setShader(shader);
    Panda::Miren::setTexture(texture, 0);
    Panda::Miren::setUniform(shader, "model", &model[0][0], sizeof(glm::mat4));
    Panda::Miren::setUniform(shader, "view", &view[0][0], sizeof(glm::mat4));
    Panda::Miren::setUniform(shader, "projection", &projectionMatrix[0][0], sizeof(glm::mat4));

    Panda::Miren::setVertexBuffer(vertexBuffer);
    Panda::Miren::setIndexBuffer(indexBuffer, 36);
    Panda::Miren::submit();
}

void CubeRenderer::windowSizeChanged(Panda::GSize _size) {
    projectionMatrix = glm::perspective(glm::radians(40.f), _size.width / _size.height, 0.1f, 1000.0f);
    Panda::Miren::setUniform(shader, "projection", &projectionMatrix[0][0], sizeof(glm::mat4));
}
