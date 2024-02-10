#include "TetrisShapes.h"

TetrisShapes* TetrisShapes::tetrisShapesinstance= nullptr;

/**
 * Static methods should be defined outside the class.
 */
TetrisShapes* TetrisShapes::getInstance()
{
    /**
     * This is a safer way to create an instance. instance = new Singleton is
     * dangeruous in case two instance threads wants to access at the same time
     */
    if(tetrisShapesinstance==nullptr){
        tetrisShapesinstance = new TetrisShapes();
    }
    return tetrisShapesinstance;
}

const std::array<std::array<int, TetrisShapes::SIZE>, TetrisShapes::SIZE>& TetrisShapes::getShape(int kind, int orientation) const {
    return shapes[kind][orientation];
}



/*TetrisShapes::~TetrisShapes() {
        delete tetrisShapesinstance;
    }
*/

std::array<std::array<std::array<std::array<int, TetrisShapes::SIZE>, TetrisShapes::SIZE>, TetrisShapes::NUM_ROTATIONS>, TetrisShapes::NUM_BRICK_TYPES> TetrisShapes::createShapes(){
    return {{
        // O
        {{
            {{
                {0, 0, 0, 0},
                {0, 1, 2, 0},
                {0, 1, 1, 0},
                {0, 0, 0, 0}
            }},
            {{
                {0, 0, 0, 0},
                {0, 1, 2, 0},
                {0, 1, 1, 0},
                {0, 0, 0, 0}
            }},
            {{
                {0, 0, 0, 0},
                {0, 1, 2, 0},
                {0, 1, 1, 0},
                {0, 0, 0, 0}
            }},
            {{
                {0, 0, 0, 0},
                {0, 1, 2, 0},
                {0, 1, 1, 0},
                {0, 0, 0, 0}
            }}
        }},
        // I
        {{
            {{
                {0, 0, 0, 0},
                {1, 1, 2, 1},
                {0, 0, 0, 0},
                {0, 0, 0, 0}
            }},
            {{
                {0, 0, 1, 0},
                {0, 0, 2, 0},
                {0, 0, 1, 0},
                {0, 0, 1, 0}
            }},
            {{
                {0, 0, 0, 0},
                {1, 1, 2, 1},
                {0, 0, 0, 0},
                {0, 0, 0, 0}
            }},
            {{
                {0, 0, 1, 0},
                {0, 0, 2, 0},
                {0, 0, 1, 0},
                {0, 0, 1, 0}
            }}
        }},
        // S
        {{
            {{
                {0, 0, 0, 0},
                {0, 0, 2, 1},
                {0, 1, 1, 0},
                {0, 0, 0, 0}
            }},
            {{
                {0, 0, 1, 0},
                {0, 0, 2, 1},
                {0, 0, 0, 1},
                {0, 0, 0, 0}
            }},
            {{
                {0, 0, 0, 0},
                {0, 0, 2, 1},
                {0, 1, 1, 0},
                {0, 0, 0, 0}
            }},
            {{
                {0, 0, 1, 0},
                {0, 0, 2, 1},
                {0, 0, 0, 1},
                {0, 0, 0, 0}
            }}
        }},
        // Z
        {{
            {{
                {0, 0, 0, 0},
                {0, 1, 2, 0},
                {0, 0, 1, 1},
                {0, 0, 0, 0}
            }},
            {{
                {0, 0, 0, 1},
                {0, 0, 2, 1},
                {0, 0, 1, 0},
                {0, 0, 0, 0}
            }},
            {{
                {0, 0, 0, 0},
                {0, 1, 2, 0},
                {0, 0, 1, 1},
                {0, 0, 0, 0}
            }},
            {{
                {0, 0, 0, 1},
                {0, 0, 2, 1},
                {0, 0, 1, 0},
                {0, 0, 0, 0}
            }}
        }},
        // L
        {{
            {{
                {0, 0, 0, 0},
                {0, 1, 2, 1},
                {0, 1, 0, 0},
                {0, 0, 0, 0}
            }},
            {{
                {0, 0, 1, 0},
                {0, 0, 2, 0},
                {0, 0, 1, 1},
                {0, 0, 0, 0}
            }},
            {{
                {0, 0, 0, 1},
                {0, 1, 2, 1},
                {0, 0, 0, 0},
                {0, 0, 0, 0}
            }},
            {{
                {0, 1, 1, 0},
                {0, 0, 2, 0},
                {0, 0, 1, 0},
                {0, 0, 0, 0}
            }}
        }},
        // J
        {{
            {{
                {0, 0, 0, 0},
                {0, 1, 2, 1},
                {0, 0, 0, 1},
                {0, 0, 0, 0}
            }},
            {{
                {0, 0, 1, 1},
                {0, 0, 2, 0},
                {0, 0, 1, 0},
                {0, 0, 0, 0}
            }},
            {{
                {0, 1, 0, 0},
                {0, 1, 2, 1},
                {0, 0, 0, 0},
                {0, 0, 0, 0}
            }},
            {{
                {0, 0, 1, 0},
                {0, 0, 2, 0},
                {0, 1, 1, 0},
                {0, 0, 0, 0}
            }}
        }},
        // T
        {{
            {{
                {0, 0, 0, 0},
                {0, 1, 2, 1},
                {0, 0, 1, 0},
                {0, 0, 0, 0}
            }},
            {{
                {0, 0, 1, 0},
                {0, 0, 2, 1},
                {0, 0, 1, 0},
                {0, 0, 0, 0}
            }},
            {{
                {0, 0, 1, 0},
                {0, 1, 2, 1},
                {0, 0, 0, 0},
                {0, 0, 0, 0}
            }},
            {{
                {0, 0, 1, 0},
                {0, 1, 2, 0},
                {0, 0, 1, 0},
                {0, 0, 0, 0}
            }}
        }}
    }};
}
;


