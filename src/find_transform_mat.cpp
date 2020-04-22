#include <iostream>
#include <glm/glm.hpp>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>

#define GLM_FORCE_CTOR_INIT //initialize matrix to 0

typedef glm::mat4 transform_mat;
typedef glm::vec4 vector;

class atom
{
    public:
        atom(int atom_ID, int model_num,
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
};

int main(int argc, char* argv[])
{
    //array of atoms
    std::vector<atom> atom_arr;
    //file containing atoms of interest
    std::ifstream atom_file;
    atom_file.open(argv[1]);

    //every line of file
    std::string line_of_data;
    
    //atom ID and model number
    int atom_ID, model_number;
    //coordinates of an atom
    float x_coor, y_coor, z_coor;
        
    while (std::getline(atom_file, line_of_data)) {
        //skip the comments
        if (line_of_data[0] == '#')
            continue;
        //parse input
        std::stringstream iss(line_of_data);
        iss >> atom_ID >> model_number >> x_coor >> y_coor >> z_coor;
        atom_arr.push_back(atom(atom_ID, model_number, x_coor, y_coor, z_coor));
    }
}
