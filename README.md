# Camera_Position_Converter
Convert the camera position from body coordinate to global coordinate ( LLA coordinate)

## Usage
1. Include coordinate_converter.h
2. set the GPS antenna position. (origin is camera chip, follow the body frame defination, X: frone, Y: right, Z: Down )
3. update attitue(rad) and GPS position(in LLA, Lat and Lon is deg times E+7(int), Alt is meter (float))
4. execute convert function.
5. got camera position in Camera_Lat, Camera_Lon, Camera_Alt.

## Example
execute the following command in main.cpp directory

    g++ -o main main.cpp
