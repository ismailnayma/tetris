#ifndef ShapesRotation_H
#define ShapesRotation_H

#include "enum.hpp"
#include "position.hpp"
#include <vector>
#include <map>

class ShapesRotation {
private:
    static ShapesRotation* ShapesRotationInstance;

    std::map<TypeShape, std::map<Orientation, std::vector<Position>>> shapes;
    ShapesRotation();

public:
    ShapesRotation(const ShapesRotation&) = delete;
    ShapesRotation& operator=(const ShapesRotation&) = delete;
    static ShapesRotation* getInstance();
    const std::vector<Position> & getShape(TypeShape kind, Orientation orientation) const;
    // ~ShapesRotation();
};



#endif // ShapesRotation_H


