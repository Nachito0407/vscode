#include <stdio.h>
#include <math.h>

#define width   30
#define height  30

int main(int argc, char const *argv[])
{
    float w= width;
    float h= height;

    for (int col = 0; col < height; ++col)
    {
        for ( int row = 0; row < width; ++row)
        {
            float x = col;
            float y = row;
            float cx = (2*x-w)/h;
            float cy = (2*y-h)/h;
            float d =sqrtf(cx*cx+cy*cy);;
            d -= 0.5;
            d += 0.1*h/(2*(x-y)+h-w);
            d = fabs(d);
            d = 0.1/d;
            char c = " -+=<@#"[(int)floorf(d/(1+d)*7)];
            printf("%c%c", c , c );
        }
        
    }
    return 0;
}