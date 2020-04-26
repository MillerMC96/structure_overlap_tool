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
    float vec1_length, vec2_length;

    //rotation axis
    glm::vec3 axis = vector(0.0);
    float axis_length;

    //rotation angle
    float rotation_angle;

    //find the two vectors
    vec1 = atom1 - pivot_atom;
    vec2 = atom2 - pivot_atom;
    
    //two vectors in 3d format for cross product calculation
    glm::vec3 vec1_3d = glm::vec3(vec1);
    glm::vec3 vec2_3d = glm::vec3(vec2);

    //find the rotation axis and its length
    axis = glm::cross(vec1_3d, vec2_3d);
    axis_length = glm::length(axis);

    //homogenized unit vector of rotation axis
    vector axis_unit = vector(glm::normalize(axis), 1.0);

    //find the length of two vectors
    vec1_length = glm::length(vec1);
    vec2_length = glm::length(vec2);

    //find the rotation angle
    rotation_angle = std::asin(axis_length / (vec1_length * vec2_length));

    //find the final rotation matrix
    //magnitude of the projection of rotation axis onto the yz plane
    float yz_proj = sqrt(pow(axix_unit[1], 2) + pow(axis_unit[2], 2));
    //intialize all necessary matrices
    transform_mat T_inv = transform_mat(1.0);
    transform_mat Rx_inv = transform_mat(1.0);
    transform_mat Ry_inv = transform_mat(1.0);
    transform_mat Rz = transform_mat(1.0);
    transform_mat Ry = transform_mat(1.0);
    transform_mat Rx = transform_mat(1.0);
    transform_mat T = transform_mat(1.0);
    //first do T^-1
    T_inv[3] = -pivot_atom;
    //Rx^-1 and Rx
    //if the axis is not along with the x-axis
    if (yz_proj != 0) {
        Rx_inv[1] = vector(0, axis_unit[2] / yz_proj, -axis_unit[1] / yz_proj, 0);
        Rx_inv[2] = vector(0, axis_unit[1] / yz_proj, axis_unit[2] / yz_proj, 0);
        Rx[1] = vector(0, axis_unit[2] / yz_proj, axis_unit[1] / yz_proj, 0);
        Rx[2] = vector(0, -axis_unit[1] / yz_proj, axis_unit[2] / yz_proj, 0);
    }
    //Ry^-1 and Ry

    return rotation_mat;
}

//returns the rotation matrix between two atoms about a given axis
transform_mat get_rot_mat_about_an_axis(vector& atom1, vector& atom2, std::vector<vector>& axis_atoms)
{

    return transform_mat(1.0);
}
