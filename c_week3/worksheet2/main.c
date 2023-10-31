#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    float x;
    float y;
} POINT;

float ManhattanDistance(POINT point1, POINT point2)
{
    float x = point1.x - point2.x;
    if (x < 0)
        x *= -1;
    float y = point2.y - point2.y;
    if (y < 0)
        y *= -1;
    return x + y;
}

double EuclideanDistance(POINT point1, POINT point2)
{
    float x = point1.x - point2.x;
    float y = point2.y - point2.y;
    double res = sqrt(x * x + y * y);
    return res;
}

int main()
{
    int arr_len = 10;
    float arr_len_float = arr_len;
    POINT Points[arr_len];

    // Bronze Task
    for (int i = 0; i < arr_len; i++)
    {
        Points[i].x = rand() % 50;
        Points[i].y = rand() % 50;
    }

    for (int i = 0; i < arr_len; i++)
    {
        printf("(%.0f, %.0f)\n", Points[i].x, Points[i].y);
    }

    // Silver Task
    float sum = 0;
    for (int i = 0; i < arr_len - 1; i++)
    {
        // printf("DIstance between (%.0f, %.0f) & (%.0f, %.0f) is %f!\n", Points[i].x, Points[i].y,
        // Points[i+1].x, Points[i+1].y, ManhattanDistance(Points[i], Points[i+1]));
        sum += ManhattanDistance(Points[i], Points[i + 1]);
    }
    float total = (1 / (arr_len_float + 1)) * sum;
    printf("The total distance is: %f\n", total);

    // Gold Task
    double closest_dist = 10000;
    POINT closest_point1, closest_point2; 
    for (int i = 0; i < arr_len - 1; i++)
    {
        double dist = EuclideanDistance(Points[i], Points[i+1]);
        if (dist < closest_dist) {
            closest_dist = dist;
            closest_point1 = Points[i];
            closest_point2 = Points[i+1];
        }
    }
    printf("The shortest distance is %f between (%0.f, %0.f) and (%0.f, %0.f)\n", closest_dist, closest_point1.x, closest_point1.y, closest_point2.x, closest_point2.y);

    return 0;
};
