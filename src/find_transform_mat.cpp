#include "find_transform_mat.h"

//returns the translation matrix between two atoms
transform_mat get_translation_matrix(vector& atom1, vector& atom2)
{
    return transform_mat(1.0);
}

//returns the rotation matrix between two atoms about a given pivot
transform_mat get_rot_mat_about_an_axis(vector& atom1, vector& atom2, vector& pivot_atom)
{
    return transform_mat(1.0);
}
