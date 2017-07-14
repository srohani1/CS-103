#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

// Global variable
unsigned char image[SIZE][SIZE];

// Draws rectangle
void draw_rectangle(int top, int left, int height, int width) 
{
   for (int j=left; j <= left + width; j++) 
   {
      if (j >= 0 && j < 255)
      {
         if (top >= 0 && top < 255)
         {
          image[top][j] = 0;
         }   
         if ( top + height >= 0 && top + height < 255)
         {
            image[top + height][j] = 0;  
         }  
      }
   } 
   
   for (int i=top; i <= top + height; i++)
   {
      if (i >= 0 && i < 255)
      {  
         if (left >= 0 && left < 255)
         {
            image[i][left] = 0;
         } 
         if (left + width >= 0 && left + width< 255)
         {
            image[i][left + width] = 0;
         }
      }
   }
}

// Draws ellipse
void draw_ellipse(int cy, int cx, int height, int width) 
{
   for (double i = 0;i < 2 * M_PI;i += 0.01) 
   {
       int x = (int)(width/2 * cos(i) + cx);
       int y = (int)(height/2 * sin(i) + cy);

      if (x >= 0 &&  x < 255 && y >= 0 && y < 255)
      {
      image[x][y] = 0;

      }
   }
}

int main() 
{
   // Initializes the image to all white pixels
   for (int i=0; i < SIZE; i++) 
   {
      for (int j=0; j < SIZE; j++) 
      {
         image[i][j] = 255;
      }
   }
   
   // Main program loop here
   int userinput = 0;
   while (userinput != 2)  
   {  
      cout << "To draw a rectangle, enter: 0" << endl;
      cout << "To draw an ellipse, enter: 1" << endl;
      cout << "To save your drawing as \"output.bmp\" and quit, enter: 2" << endl;
      cin >> userinput;
      if (userinput == 0)
      {
         int top = 0;
         int left = 0;
         int height = 0;
         int width = 0;
         cout << "Enter top, left, height, and width" << endl;
         cin >> top >> left >> height >> width;
         draw_rectangle(top, left, height, width);
      }
      else if (userinput == 1)
      {
         int cy = 0;
         int cx = 0;
         int height = 0;
         int width = 0;
         cout << "Enter cy, cx, height, and width" << endl;
         cin >> cy >> cx >> height >> width;
         draw_ellipse(cy, cx, height, width);
      }
      else if (userinput == 2)
      {
         // Write the resulting image to the .bmp file
       writeGSBMP("output.bmp", image);
      }
      else 
      {
         cout << "Invalid input try again ";
      }
   }
return 0;   
}
