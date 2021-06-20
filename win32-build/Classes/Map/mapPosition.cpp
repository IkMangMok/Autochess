#include"MapPosition.h"

mapPosition::mapPosition(int x, int y)
{
    x_in_map = x;
    y_in_map = y;
    map_to_origin();
}
mapPosition::mapPosition(Point point)
{
    x_in_origin = point.x;
    y_in_origin = point.y;
    origin_to_map();
}

void mapPosition::map_to_origin()
{
    x_in_origin = 1600.f * (21 + 3 * x_in_map) / 64;
    y_in_origin = 900.f * (4 + 3 * y_in_map) / 36;
}
void mapPosition::origin_to_map()
{
    x_in_map = int((x_in_origin * 64 / 1600.f - 21) / 3);
    y_in_map = int((y_in_origin * 36 / 900.f - 4) / 3);
    map_to_origin();
}
bool mapPosition::out_of_map()
{
    if (x_in_origin < 425 || x_in_origin > 1125 || y_in_map > 9 || y_in_map < 0)
        return true;
    else
        return false;
}