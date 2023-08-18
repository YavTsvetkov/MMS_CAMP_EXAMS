#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct Point {
    double x;
    double y;
    double z;
} Point;

typedef struct Human {
    double weight_kg;
    uint16_t height_cm;
} Human;

void* findMax(void* arr, size_t n, size_t elem_s, int (*cmp)(const void*, const void*));
int cmpBMid(const void*, const void*);
int cmp3Dpoints(const void*, const void*);
int cmpSetBitsCount(const void*, const void*);

int main(void)
{
    Human humans[] = {
        {60.5, 170.0},
        {75.0, 185.0},
        {80.0, 175.0},
        {65.0, 160.0},
    };
    size_t numHumans = sizeof(humans) / sizeof(humans[0]);

    Human *maxBMIHuman = findMax(humans, numHumans, sizeof(Human), cmpBMid);
    printf("Max BMI Human: weight = %.2f kg, height = %d cm\n", maxBMIHuman->weight_kg, maxBMIHuman->height_cm);

    Point points[] = {
        {2.0, 3.0, 1.0},
        {0.0, 0.0, 0.0},
        {1.0, 1.0, 1.0},
    };
    size_t numPoints = sizeof(points) / sizeof(points[0]);

    Point *farthestPoint = findMax(points, numPoints, sizeof(Point), cmp3Dpoints);
    printf("Farthest Point: x = %.2f, y = %.2f, z = %.2f\n", farthestPoint->x, farthestPoint->y, farthestPoint->z);

    float floats[] = {12.25f, 7.5f, 3.14f, 17.0f, 1353.2342f};
    size_t numFloats = sizeof(floats) / sizeof(floats[0]);

    float *maxSetBitsCount = findMax(floats, numFloats, sizeof(float), cmpSetBitsCount);
    printf("Float with Max Set Bits Count: %.2f\n", *maxSetBitsCount);

    return 0;
}

void* findMax(void* arr, size_t n, size_t elem_s, int (*cmp)(const void*, const void*))
{
    void *max_el = arr;                
    for(size_t i = 0; i < n; i++)
    {   
        arr = (char*)arr + elem_s;     

        if (cmp(max_el, arr) == 1){ 
            max_el = arr;
        }
    }

    return max_el;
}

int cmpBMid(const void* h1, const void* h2){
    Human *human1 = h1;
    Human *human2 = h2;

    double BM_1 = human1->weight_kg / (human1->height_cm * human1->height_cm);
    double BM_2 = human2->weight_kg / (human2->height_cm * human2->height_cm);

    return BM_1 > BM_2 ? -1 : 1;
}
                                 
int cmp3Dpoints(const void* p1, const void* p2)
{
    Point point;
    point.x = 0;
    point.y = 0;
    point.z = 0;

    Point *point1 = p1;
    Point *point2 = p2;

    double maxD = sqrt(pow((point1->x - point.x), 2) + pow((point1->y - point.y), 2) 
            + pow((point1->z - point.z), 2));
    double currentD = sqrt(pow((point2->x - point.x), 2) + pow((point2->y - point.y), 2) 
            + pow((point2->z - point.z), 2));

    return maxD > currentD ? -1 : 1;
}
                    
int cmpSetBitsCount(const void* f1, const void* f2)
{
   unsigned int f1_bit_count = 0;
   unsigned int f2_bit_count = 0;  

   uint32_t f1_to_int = 0;
   uint32_t f2_to_int = 0;

    memcpy(&f1_to_int, f1, sizeof(uint32_t));
    memcpy(&f2_to_int, f2, sizeof(uint32_t));

   for (size_t i = 0; i < sizeof(float); i++)
   {
     f1_bit_count += !!(f1_to_int & (i << (uint32_t)1)); 
     f2_bit_count += !!(f2_to_int & (i << (uint32_t)1)); 
   }

   return f1_bit_count > f2_bit_count ? -1 : 1;
}