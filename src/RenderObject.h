#pragma once
#include <vector>
enum RenderMethod {
    TwoD = 2,
    ThreeD = 3
};

class RenderObject {
    public:
        std::vector<float> verticies
        {
            -0.5f, -0.5f,
             0.0f,  0.5f,
             0.5f, -0.5f
        };
        RenderMethod render_method;


};
