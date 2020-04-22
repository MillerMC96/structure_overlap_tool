#include <glm/glm.hpp>

#define GLM_FORCE_CTOR_INIT //initialize matrix to 0

typedef glm::mat4 transform_mat;
typedef glm::vec4 vector;

//returns the translation matrix between two atoms
transform_mat get_translation_matrix(vector& atom1, vector& atom2);

//returns the rotation matrix between two atoms about a given pivot
transform_mat get_rot_mat_about_an_axis(vector& atom1, vector& atom2, vector& pivot_atom);
