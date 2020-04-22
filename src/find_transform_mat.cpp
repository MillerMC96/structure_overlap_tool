#include "find_transform_mat.h"
#include "atom.h"

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
