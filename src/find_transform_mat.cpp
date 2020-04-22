#include "find_transform_mat.h"

//returns the translation matrix between two atoms
transform_mat get_translation_matrix(vector& atom1, vector& atom2)
{
    //initialize the translation matrix as an identity matrix
    transform_mat translation_mat = transform_mat(1.0);

    return translation_mat;
}

//returns the rotation matrix between two atoms about a given pivot
transform_mat get_rot_mat_about_an_axis(vector& atom1, vector& atom2, vector& pivot_atom)
{
    return transform_mat(1.0);
}
