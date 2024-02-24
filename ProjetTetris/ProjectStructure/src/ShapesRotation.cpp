#include "ShapesRotation.h"

ShapesRotation* ShapesRotation::ShapesRotationInstance = nullptr;

/**
 * Static methods should be defined outside the class.
 */
ShapesRotation* ShapesRotation::getInstance()
{
    /**
     * This is a safer way to create an instance. instance = new Singleton is
     * dangeruous in case two instance threads wants to access at the same time
     */
    if(ShapesRotationInstance==nullptr){
        ShapesRotationInstance = new ShapesRotation();
    }
    return ShapesRotationInstance;
}

const std::vector<Position> &ShapesRotation::getShape(TypeShape kind, Orientation orientation) const {
    // Try to find the TypeShape in the first map
    auto it1 = shapes.find(kind);

    // If TypeShape is found
    if (it1 != shapes.end()) {
        // Try to find the Orientation in the second map
        auto it2 = it1->second.find(orientation);

        // If Orientation is found
        if (it2 != it1->second.end()) {
            // Return the corresponding vector of positions
            return it2->second;
        }
    }

    // Return an empty vector by default if TypeShape or Orientation is not found
    static const std::vector<Position> emptyVector;
    return emptyVector;
}



/*ShapesRotation::~ShapesRotation() {
        delete ShapesRotationinstance;
    }
*/

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


