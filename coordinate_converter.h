#include <math.h>

class coordinate_converter
{
private:
    float ant_x, ant_y, ant_z;
    float ant_bias_n, ant_bias_e, ant_bias_d;
    float M11, M12, M13, M21, M22, M23, M31, M32, M33; //i2b

public:
    coordinate_converter(float pos_x, float pos_y, float pos_z);
    ~coordinate_converter();

    //variable
    float att_x, att_y, att_z;
    int Ant_Lat, Ant_Lon;
    float Ant_Alt;
    int Camera_Lat, Camera_Lon;
    float Camera_Alt;

    //Functions
    void convert(void);
};

coordinate_converter::coordinate_converter(float pos_x, float pos_y, float pos_z)
{
    ant_x = pos_x;
    ant_y = pos_y;
    ant_z = pos_z;
}

coordinate_converter::~coordinate_converter()
{
    //todo...
}

void coordinate_converter::convert(void)
{
    //1. Calculate Direct Cosine Matrix(X-Y-Z)
    M11 = cos(att_y) * cos(att_z);
    M12 = cos(att_y) * sin(att_z);
    M13 = -sin(att_y);
    M21 = -cos(att_x) * sin(att_z) + cos(att_z) * sin(att_x) * sin(att_y);
    M22 = cos(att_x) * cos(att_z) + sin(att_x) * sin(att_y) * sin(att_z);
    M23 = cos(att_y) * sin(att_x);
    M31 = cos(att_x) * cos(att_z) * sin(att_y) + sin(att_x) * sin(att_z);
    M32 = cos(att_x) * sin(att_y) * sin(att_z) - cos(att_z) * sin(att_x);
    M33 = cos(att_x) * cos(att_y);

    //2. find the offset of the Ant pos from body to inertial coordinate
    ant_bias_n = M11 * ant_x + M21 * ant_y + M31 * ant_z;
    ant_bias_e = M12 * ant_x + M22 * ant_y + M32 * ant_z;
    ant_bias_d = M13 * ant_x + M23 * ant_y + M33 * ant_z;

    //3. calculation
    Camera_Lat = Ant_Lat - (int)(ant_bias_n * 90.4371732957);
    Camera_Lon = Ant_Lon - (int)(ant_bias_e * 89.8311174991 / cos(Ant_Lat / 10000000 * 0.017453292519943f));
    Camera_Alt = Ant_Alt + ant_bias_d; // = +(-Ant_Alt - ant_bias_d);
}