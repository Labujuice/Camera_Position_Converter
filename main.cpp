#include <cstdio>
#include "coordinate_converter.h"


int main()
{
    //Usage
    coordinate_converter CameraConv(1, 0, -0.2); //Antenna Pos shift in body frame XYZ: Front, Right, Down (unit: Meter)
    
    //update attitude
    CameraConv.att_x = 3.14/2;
    CameraConv.att_y = 3.14/2;
    CameraConv.att_z = -3.14/2;

    //update Antenna position in LLA (Pos: int, Deg*E+7; Alt: float, meter) 
    CameraConv.Ant_Lat = 248404540; 
    CameraConv.Ant_Lon = 1219528270;
    CameraConv.Ant_Alt = 20.3;
    CameraConv.convert();

    //Get Result
    printf("%d, %d, %f \n",CameraConv.Camera_Lat, CameraConv.Camera_Lon, CameraConv.Camera_Alt );
    printf("%d, %d, %f \n",CameraConv.Ant_Lat, CameraConv.Ant_Lon, CameraConv.Ant_Alt );
    printf("%d, %d, %f \n",CameraConv.Camera_Lat - CameraConv.Ant_Lat, CameraConv.Camera_Lon - CameraConv.Ant_Lon, CameraConv.Camera_Alt - CameraConv.Ant_Alt );


    return 0;
}