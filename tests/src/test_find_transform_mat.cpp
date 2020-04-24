#include <iostream>
#include <vector>
#include "find_transform_mat.h"
#include "atom.h"

//testing get_translation_matrix
int test_get_translation_matrix(void)
{
    vector atom1 = vector(1.0, 1.0, 1.0, 1.0);
    vector atom2 = vector(2.0, 2.0, 2.0, 1.0);
    vector atom3 = vector(2.0, 2.0, 2.0, 1.0);
    vector atom4 = vector(1.0, 1.0, 1.0, 1.0);

    transform_mat result = get_translation_matrix(atom1, atom2);
    transform_mat result_neg = get_translation_matrix(atom3, atom4);
    
    //positive translation
    assert(result[3][0] == 1.0);
    assert(result[3][1] == 1.0);
    assert(result[3][2] == 1.0);
    assert(result[3][3] == 1.0);

    //negative translation
    assert(result_neg[3][0] == -1.0);
    assert(result_neg[3][1] == -1.0);
    assert(result_neg[3][2] == -1.0);
    assert(result_neg[3][3] == 1.0);

    return 0;
}

//testing get_rot_mat_about_an_atom
int test_get_rot_mat_about_an_atom(void)
{

    return 0;
}

//testing get_rot_mat_about_an_axis
int test_get_rot_mat_about_an_axis(void)
{

    return 0;
}

int main(int argc, char* argv[])
{
    test_get_translation_matrix();
}
