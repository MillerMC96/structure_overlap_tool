#include "find_transform_mat.h"

//returns the translation matrix between two atoms
transform_mat get_translation_matrix(vector& atom1, vector& atom2)
{
    //initialize the translation matrix as an identity matrix
    transform_mat translation_mat = transform_mat(1.0);
    //delta x y and z
    float delta_x, delta_y, delta_z;

    delta_x = atom2[0] - atom1[0];
    delta_y = atom2[1] - atom1[1];
    delta_z = atom2[2] - atom1[2];

    translation_mat = glm::translate(glm::mat4(1.0), glm::vec3(delta_x, delta_y, delta_z));

    return translation_mat;
}

//returns the rotation matrix between two atoms about a given pivot
transform_mat get_rot_mat_about_an_atom(vector& atom1, vector& atom2, vector& pivot_atom)
{
    //initialize the rotation matrix as an identity matrix
    transform_mat rotation_mat = transform_mat(1.0);
    //two vectors that determine the rotation axis
    vector vec1 = vector(0.0);
    vector vec2 = vector(0.0);
    //rotation axis
    glm::vec3 axis = vector(0.0);

    //find the two vectors
    vec1 = atom1 - pivot_atom;
    vec2 = atom2 - pivot_atom;
    
    //two vectors in 3d format for cross product calculation
    glm::vec3 vec1_3d = glm::vec3(vec1);
    glm::vec3 vec2_3d = glm::vec3(vec2);

    //find the rotation axis
    axis = glm::cross(vec1_3d, vec2_3d);

    //find the final rotation matrix

    return rotation_mat;
}

//returns the rotation matrix between two atoms about a given axis
transform_mat get_rot_mat_about_an_axis(vector& atom1, vector& atom2, std::vector<vector>& axis_atoms)
{

    return transform_mat(1.0);
}
