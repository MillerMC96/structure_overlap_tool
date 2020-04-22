typedef glm::vec4 vector;

class atom
{
    public:
        atom(int atom_ID, int model_num,
             float x_coordinate, float y_coordinate, float z_coordinate)
        {
            coords[0] = x_coordinate;
            coords[1] = y_coordinate;
            coords[2] = z_coordinate;
            ID = atom_ID;
            model = model_num;
        }

        atom(void)
        {
            coords = vector(0.0);
            ID = 0;
            model = 0;
        }

        //coordinate in glm::vec4 format
        vector coords;
        int ID;
        int model;
};
