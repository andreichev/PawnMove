//
// Created by Admin on 16/05/2022.
//

#include "CheckersLevel.hpp"
#include "Components/CubeRenderer.hpp"

void CheckersLevel::start(Panda::World *world) {
    Panda::Shared<Panda::Entity> entity = world->instantiateEntity();
    Panda::Shared<CubeRenderer> cubeComponent = Panda::makeShared<CubeRenderer>(glm::vec3(0.0), glm::vec3(1.0));
    entity->addComponent(cubeComponent);
}
