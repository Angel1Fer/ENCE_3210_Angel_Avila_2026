//Global variables//
#include <math.h>

//Local Varible//
#define DEG_MAX 360
#define PI 3.14

//make array with cos
void fill_cos_array(double arr[], int max_deg) 
{
    for (int deg = 0; deg <= max_deg; deg++) {
        double rad = deg * (PI / 180.0); //degrees to radians//
        arr[deg] = cos(rad);// results of deg to rad stored// 
    }
}

int main(void)//prints results//
{
    double cos_vals[DEG_MAX + 1]; //stores values from 0-360//
    fill_cos_array(cos_vals, DEG_MAX); //calls func from top//
    
    //prints the values @ 60, 90, 180, 270, 360//
    printf("cos(60) = %.6f\n", cos_vals[60]);
    printf("cos(90) = %.6f\n", cos_vals[90]);
    printf("cos(180) = %.6f\n", cos_vals[180]);
    printf("cos(270) = %.6f\n", cos_vals[270]);
    printf("cos(360) = %.6f\n", cos_vals[360]);

    return 0;
}