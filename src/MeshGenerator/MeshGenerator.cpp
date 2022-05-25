//
// Created by Admin on 23/05/2022.
//

#include <Panda.hpp>
#include "MeshGenerator.hpp"

Panda::MeshData MeshGenerator::cube(glm::vec3 size) {
    auto vertices = new Vertex[]{
            // Front
            Vertex(-size.x / 2, -size.y / 2, size.z / 2, 0.0f, 1.0f, 1.0f), // 0
            Vertex(size.x / 2, -size.y / 2, size.z / 2, 1.0f, 1.0f, 1.0f),  // 1
            Vertex(size.x / 2, size.y / 2, size.z / 2, 1.0f, 0.0f, 1.0f),   // 2
            Vertex(-size.x / 2, size.y / 2, size.z / 2, 0.0f, 0.0f, 1.0f),  // 3
            // Back
            Vertex(-size.x / 2, -size.y / 2, -size.z / 2, 0.0f, 1.0f, 1.0f), // 4
            Vertex(-size.x / 2, size.y / 2, -size.z / 2, 1.0f, 1.0f, 1.0f),  // 5
            Vertex(size.x / 2, size.y / 2, -size.z / 2, 1.0f, 0.0f, 1.0f),   // 6
            Vertex(size.x / 2, -size.y / 2, -size.z / 2, 0.0f, 0.0f, 1.0f),  // 7
            // Top
            Vertex(-size.x / 2, size.y / 2, -size.z / 2, 0.0f, 1.0f, 1.0f), // 8
            Vertex(-size.x / 2, size.y / 2, size.z / 2, 1.0f, 1.0f, 1.0f),  // 11
            Vertex(size.x / 2, size.y / 2, size.z / 2, 1.0f, 0.0f, 1.0f),   // 10
            Vertex(size.x / 2, size.y / 2, -size.z / 2, 0.0f, 0.0f, 1.0f),  // 9
            // Bottom
            Vertex(-size.x / 2, -size.y / 2, -size.z / 2, 0.0f, 1.0f, 1.0f), // 12
            Vertex(size.x / 2, -size.y / 2, -size.z / 2, 1.0f, 1.0f, 1.0f),  // 13
            Vertex(size.x / 2, -size.y / 2, size.z / 2, 1.0f, 0.0f, 1.0f),   // 14
            Vertex(-size.x / 2, -size.y / 2, size.z / 2, 0.0f, 0.0f, 1.0f),  // 15
            // Left
            Vertex(-size.x / 2, -size.y / 2, -size.z / 2, 0.0f, 1.0f, 1.0f), // 16
            Vertex(-size.x / 2, -size.y / 2, size.z / 2, 1.0f, 1.0f, 1.0f),  // 17
            Vertex(-size.x / 2, size.y / 2, size.z / 2, 1.0f, 0.0f, 1.0f),   // 18
            Vertex(-size.x / 2, size.y / 2, -size.z / 2, 0.0f, 0.0f, 1.0f),  // 19
            // Right
            Vertex(size.x / 2, -size.y / 2, -size.z / 2, 0.0f, 1.0f, 1.0f), // 20
            Vertex(size.x / 2, size.y / 2, -size.z / 2, 1.0f, 1.0f, 1.0f),  // 23
            Vertex(size.x / 2, size.y / 2, size.z / 2, 1.0f, 0.0f, 1.0f),   // 22
            Vertex(size.x / 2, -size.y / 2, size.z / 2, 0.0f, 0.0f, 1.0f)   // 21
    };

    auto indices = new uint32_t[]{
            0, 1, 2, 2, 3, 0,       // Front
            4, 5, 6, 6, 7, 4,       // Back
            8, 9, 10, 10, 11, 8,    // Top
            12, 13, 14, 14, 15, 12, // Bottom
            16, 17, 18, 18, 19, 16, // Left
            20, 21, 22, 22, 23, 20  // Right
    };

    return Panda::MeshData(vertices, 24, indices, 36);
}

Panda::MeshData MeshGenerator::plane(glm::vec2 size) {
    auto vertices = new Vertex[]{
            Vertex(-size.x / 2, 0, -size.y / 2, 0.0f, 1.0f, 1.0f), // 8
            Vertex(-size.x / 2, 0, size.y / 2, 1.0f, 1.0f, 1.0f),  // 11
            Vertex(size.x / 2, 0, size.y / 2, 1.0f, 0.0f, 1.0f),   // 10
            Vertex(size.x / 2, 0, -size.y / 2, 0.0f, 0.0f, 1.0f),  // 9
    };

    auto indices = new uint32_t[]{0, 1, 2, 2, 3, 0};

    return Panda::MeshData(vertices, 4, indices, 6);
}