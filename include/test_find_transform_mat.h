#include "find_transform_mat.h"
#include <cassert>

//testing get_translation_matrix
int test_get_translation_matrix(vector& atom1, vector& atom2);

//testing get_rot_mat_about_an_atom
int test_get_rot_mat_about_an_atom(vector& atom1, vector& atom2, vector& pivot_atom);

//testing get_rot_mat_about_an_axis
int test_get_rot_mat_about_an_axis(vector& atom1, vector& atom2, std::vector<vector>& axis_atoms);
