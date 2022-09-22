#include <iostream>
#include "BMP.h"
#include <cmath>
//+800 to center image vertically
int main() {
  int offset = 400; //centers ellipse
  BMP ellipse(800,800,false);
  
  int xR = 768; //radius x
  int x = 0;
  int Xx = 2;
  int yR = 384; //radius y
  int y = 384; 
  int Xy = 768 * pow(xR,2);
  //region amd loops referenced from geeks for geeks
  int q1 = pow(yR,2) + (.25 * pow(xR,2)) - ((pow(xR,2) * yR)); //region 1
  while(Xx < Xy){
    //first loop for region 1
    ellipse.set_pixel(x, y + offset, 255, 255, 255, 0); //sets pixels on top right
    ellipse.set_pixel(x, -y + offset, 255, 255, 255, 0); //sets pixels on bottom right
    if(q1 < 0){
      ++x;
      Xx = Xx + (2 * pow(yR,2));
      q1 = q1 + Xx + pow(yR,2);
    }
    else{ //<=0
      ++x;
      --y;
      Xy = Xy - (2 * pow(xR,2));
      Xx = Xx + (2 * pow(yR,2));
      q1 = q1 + Xx - Xy + pow(yR,2);
    }
  }
  int q2 = (pow(yR,2) * pow(x+.5,2)) + (pow(xR,2) * pow(y-1,2)) - (pow(xR,2) * pow(yR,2)); //region 2
  while(y){
    //first loop for region 2
    ellipse.set_pixel(x, y + offset, 255, 255, 255, 0); //sets pixels on top right
    ellipse.set_pixel(x, -y + offset, 255, 255, 255, 0); //sets pixels on bottom right
    if(q2 > 0){
      --y;
      Xy = Xy - (pow(xR,2) * 2);
      q2 = q2 + pow(xR,2) - Xy;
    }
    else{ //<= 0
      ++x;
      --y;
      Xy = Xy - ( 2*pow(xR,2));
      Xx = Xx + (2*pow(yR,2));
      q2 = q2 + Xx - Xy + pow(xR,2);
    }
  }
  ellipse.write("output.bmp");
  return 0;
}