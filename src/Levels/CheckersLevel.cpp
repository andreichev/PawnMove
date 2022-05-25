//
// Created by Admin on 16/05/2022.
//

#include "CheckersLevel.hpp"
#include "MeshGenerator/MeshGenerator.hpp"

void CheckersLevel::start(Panda::World *world) {
    Panda::TextureHandle texture = Panda::Miren::createTexture(
            "textures/ChessBoard.png"
            );
    Panda::ShaderHandle shader = Panda::Miren::createShader(
            "shaders/base/base_vertex.glsl",
            "shaders/base/base_fragment.glsl"
            );

    // Create camera
    Panda::Shared<Panda::Entity> cameraEntity = world->instantiateEntity();
    Panda::Camera *camera = new Panda::Camera();
    cameraEntity->addComponent(camera);
    camera->setFieldOfView(60.f);
    camera->setShader(shader);

    // Move camera
    cameraEntity->getTransform()->setPosition(0, 6, 7);
    cameraEntity->getTransform()->setRotation(45, 0, 0);

    // Create board
    Panda::Shared<Panda::Entity> boardEntity = world->instantiateEntity();
    Panda::MeshData boardMeshData = MeshGenerator::plane(glm::vec3(8, 8, 8));
    Panda::Mesh* boardMesh = new Panda::Mesh(boardMeshData, false, texture, shader);
    boardEntity->addComponent(boardMesh);
}
