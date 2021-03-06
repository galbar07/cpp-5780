/**
 * Write a PPM image-file.
 * 
 * From RosettaCode:
 * http://rosettacode.org/wiki/Category:C
 */ 

#include <stdlib.h>
#include <stdio.h>
 
int main(void)
{
  const int dimx = 800, dimy = 800;
  int i, j;
  FILE *imageFile = fopen("c.ppm", "wb"); /* b - binary mode */
  (void) fprintf(imageFile, "P6\n%d %d\n255\n", dimx, dimy);
  for (j = 0; j < dimy; ++j)
  {
    for (i = 0; i < dimx; ++i)
    {
      static unsigned char color[3];
      color[0] = i % 256;  /* red */
      color[1] = j % 256;  /* green */
      color[2] = (i * j) % 256;  /* blue */
      (void) fwrite(color, 1, 3, imageFile);
    }
  }
  (void) fclose(imageFile);
  return EXIT_SUCCESS;
}