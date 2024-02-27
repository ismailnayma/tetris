#ifndef ShapesRotation_H
#define ShapesRotation_H

#include "enum.hpp"
#include "position.hpp"
#include <vector>
#include <map>

class ShapesRotation {
private:
    /**
     * @brief The singleton instance of ShapesRotation.
     */
    static ShapesRotation* ShapesRotationInstance;

    /**
     * @brief A map that stores shapes and their rotations.
     * The outer map uses TypeShape as the key.
     * The inner map uses Orientation as the key.
     * The vector of Position represents the shape in a specific orientation.
     */
    std::map<TypeShape, std::map<Orientation, std::vector<Position>>> shapes;

    /**
     * @brief Private constructor to enforce singleton pattern.
     */
    ShapesRotation();

public:
    // Delete copy constructor and assignment operator to enforce singleton pattern
    ShapesRotation(const ShapesRotation&) = delete;
    ShapesRotation& operator=(const ShapesRotation&) = delete;

    /**
     * @brief Gets the singleton instance of ShapesRotation.
     * @return The instance of ShapesRotation.
     */
    static ShapesRotation* getInstance();

    /**
     * @brief Gets the vector of positions for a specific shape and orientation.
     * @param kind The type of shape.
     * @param orientation The orientation of the shape.
     * @return The vector of positions for the given shape and orientation.
     */
    const std::vector<Position> & getVectorPosition(TypeShape kind, Orientation orientation) const;

    // Destructor is not needed as we are using a singleton pattern
    // ~ShapesRotation();
};



#endif // ShapesRotation_H


