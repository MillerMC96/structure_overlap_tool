#include <iostream>
#include <glm/glm.hpp>

#define GLM_FORCE_CTOR_INIT //initialize matrix to 0

typedef glm::mat4 transform_mat
typedef glm::vec4 vector

class atom
{
    public:
        atom(int atom_ID, int model_num
             float x_coordinate, float y_coordinate, float z_coordinate)
        {
            x_coor = x_coordinate;
            y_coor = y_coordinate;
            z_coor = z_coordinate;
            ID = atom_ID;
            model = model_num;
        }

        atom(void)
        {
            x_coor = 0.0;
            y_coor = 0.0;
            z_coor = 0.0;
            ID = 0;
            model = 0;
        }

        float x_coor;
        float y_coor;
        float z_coor;
        int ID;
        int model;
}
