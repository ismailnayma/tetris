#include "ShapesRotation.h"

ShapesRotation* ShapesRotation::ShapesRotationInstance = nullptr;

ShapesRotation* ShapesRotation::getInstance() {
    if (ShapesRotationInstance == nullptr) {
        ShapesRotationInstance = new ShapesRotation();
    }

    return ShapesRotationInstance;
}

const std::vector<Position>& ShapesRotation::getBrickPositions(TypeShape typeShape,
                                                               Orientation orientation) const {
    // Try to find the typeShape in the first map
    auto shapeIter = shapes.find(typeShape);
    // If typeShape is found
    if (shapeIter != shapes.end()) {
        // Try to find the orientation in the second map
        auto orientationIter = shapeIter->second.find(orientation);
        // If orientation is found
        if (orientationIter != shapeIter->second.end()) {
            // Return the corresponding vector of positions
            return orientationIter->second;
        }
    }

    // Return an empty vector by default if typeShape or orientation is not found
    static const std::vector<Position> emptyVector;
    return emptyVector;
}

ShapesRotation::ShapesRotation(){
    // O Shape
    shapes[TypeShape::O_SHAPE] = {
        {Orientation::UP, {Position(0, 0), Position(-1, 0), Position(-1, 1), Position(0,1)}},
        {Orientation::RIGHT, {Position(0, 0), Position(-1, 0), Position(-1, 1), Position(0,1)}},
        {Orientation::DOWN, {Position(0, 0), Position(-1, 0), Position(-1, 1), Position(0,1)}},
        {Orientation::LEFT, {Position(0, 0), Position(-1, 0), Position(-1, 1), Position(0,1)}}
    };

    // I Shape
    shapes[TypeShape::I_SHAPE] = {
        {Orientation::UP, {{Position(0, 0), Position(0, -1), Position(0, 1), Position(0, 2)}}},
        {Orientation::LEFT, {{Position(0, 0), Position(-1, 0), Position(-2, 0), Position(1, 0)}}},
        {Orientation::DOWN, {{Position(0, 0), Position(0, -1), Position(0, 1), Position(0, 2)}}},
        {Orientation::RIGHT, {{Position(0, 0), Position(-1, 0), Position(-2, 0), Position(1, 0)}}}
    };

    // S Shape
    shapes[TypeShape::S_SHAPE] = {
        {Orientation::UP, {Position(0, 0), Position(0, -1), Position(1, 0), Position(1, 1)}},
        {Orientation::RIGHT, {Position(0, 0), Position(1, 0), Position(0, 1), Position(-1, 1)}},
        {Orientation::DOWN, {Position(0, 0), Position(0, -1), Position(1, 0), Position(1, 1)}},
        {Orientation::LEFT, {Position(0, 0), Position(1, 0), Position(0, 1), Position(-1, 1)}}
    };

    // Z Shape
    shapes[TypeShape::Z_SHAPE] = {
        {Orientation::UP, {Position(0, 0), Position(1, 0), Position(1, -1), Position(0, 1)}},
        {Orientation::RIGHT, {Position(0,0), Position(-1, 0), Position(0, 1), Position(1, 1)}},
        {Orientation::DOWN, {Position(0, 0), Position(1, 0), Position(1, -1), Position(0, 1)}},
        {Orientation::LEFT, {Position(0,0), Position(-1, 0), Position(0, 1), Position(1, 1)}}
    };

    // L Shape
    shapes[TypeShape::L_SHAPE] = {
        {Orientation::UP, {Position(0, 0), Position(0, -1), Position(0, 1), Position(1, 1)}},
        {Orientation::RIGHT, {Position(0, 0), Position(-1, 0), Position(1, 0), Position(-1, 1)}},
        {Orientation::DOWN, {Position(0, 0), Position(0, -1), Position(0, 1), Position(-1, -1)}},
        {Orientation::LEFT, {Position(0, 0), Position(-1, 0), Position(1, 0), Position(1, -1)}}
    };

    // J Shape
    shapes[TypeShape::J_SHAPE] = {
        {Orientation::UP, {Position(0, 0), Position(0, -1), Position(0, 1), Position(-1, 1)}},
        {Orientation::RIGHT, {Position(0, 0), Position(-1, 0), Position(1, 0), Position(-1, -1)}},
        {Orientation::DOWN, {Position(0, 0), Position(0, -1), Position(0, 1), Position(1, -1)}},
        {Orientation::LEFT, {Position(0, 0), Position(-1, 0), Position(1, 0), Position(1, 1)}}
    };

    // T Shape
    shapes[TypeShape::T_SHAPE] = {
        {Orientation::UP, {Position(0, 0), Position(-1, 0), Position(1, 0), Position(0, 1)}},
        {Orientation::RIGHT, {Position(0, 0), Position(0, -1), Position(0, 1), Position(-1, 0)}},
        {Orientation::DOWN, {Position(0, 0), Position(-1, 0), Position(1, 0), Position(0, -1)}},
        {Orientation::LEFT, {Position(0, 0), Position(0, -1), Position(0, 1), Position(1, 0)}}
    };
}
