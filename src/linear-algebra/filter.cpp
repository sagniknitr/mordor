/*******************************************************************************
 * Program: median.c
 * Purpose: This program will apply a median filter to an image with a user
 * specified window size. The program is incomplete because the sort function
 * to find the median has not been provided. You must write the three functions
 * that have the following prototypes so they can be compiled with this code.
 * The functions must be written in another source code file (named mysort.c)
 * You must not modify the code in this program (median.c) at all!
 *
 *   void quick_sort(unsigned char *item, int left, int right);
 *   void counting_sort(unsigned char *item, int count);
 *   void insertion_sort(unsigned char *item, int count);
 *
 * When you demo your program to me I will compile your source code that you
 * sent to me by email with the following line using my copy of median.c,
 * imageio.h and imageio.c.
 *
 *    gcc -O2 -o median median.c mysort.c imageio.c
 *
 * Name: Michael Heath, University of South Florida
 * Date: 2/3/2000
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define COUNTING 1
#define QUICK 2
#define INSERTION 3

#if TEST
int main(int argc, char *argv[]) {
  char *inputfilename = NULL, *outputfilename = NULL;
  int n = 0, rows, cols, method = 0, i;
  unsigned char **image = NULL, **filteredimage = NULL;
  time_t t0, t1;
  clock_t starttime, endtime;

  void median_filter(unsigned char **image, int rows, int cols, int n,
                     unsigned char ***filteredimage, int method);

  /****************************************************************************
   * Get the command line parameters.
   ****************************************************************************/
  for (i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-n") == 0) {
      n = atoi(argv[i + 1]);
      i++;
    } else if (strcmp(argv[i], "-counting") == 0)
      method = COUNTING;
    else if (strcmp(argv[i], "-quick") == 0)
      method = QUICK;
    else if (strcmp(argv[i], "-insertion") == 0)
      method = INSERTION;
    else {
      if (inputfilename == NULL)
        inputfilename = argv[i];
      else
        outputfilename = argv[i];
    }
  }
  if ((n <= 0) || (method == 0) || (inputfilename == NULL) ||
      (outputfilename == NULL)) {

    printf("\n*****************************************************************"
           "***************\n");
    printf("This program will apply a median filter to an image. You need to "
           "specify the\n");
    printf("size of the window to use in median filtering the image (i.e. -n "
           "5), the method\n");
    printf("to use for sorting (i.e. -quick) the input image to process (i.e. "
           "enbnoisy.pgm)\n");
    printf("and the name of an output file in which the median filtered image "
           "will be\n");
    printf("written. Thus, you could run the program as follows:\n");
    printf("\n");
    printf("        median -n 5 -quick enbnoisy.pgm medianfiltered.pgm\n");
    printf("\n");
    printf("*******************************************************************"
           "*************\n");

    fprintf(stderr, "\n<USAGE> median -n # [-counting | -quick | -insertion] "
                    "inputPGMfile outputPGMfile\n\n");
    exit(1);
  }

  /****************************************************************************
   * printf("Inputfilename = %s\n", inputfilename);
   * printf("Outputfilename = %s\n", outputfilename);
   * printf("method = ");
   * if(method == COUNTING) printf("COUNTING\n");
   * else if(method == QUICK) printf("QUICK\n");
   * else if(method == INSERTION) printf("INSERTION\n");
   * printf("n = %d\n", n);
   ****************************************************************************/

  /****************************************************************************
   * Read in the PGM image from the file.
   ****************************************************************************/
  if (read_pgm_image(inputfilename, &image, &rows, &cols) == 0)
    exit(1);

  /****************************************************************************
   * Median filter the image.
   ****************************************************************************/
  starttime = clock();
  median_filter(image, rows, cols, n, &filteredimage, method);
  endtime = clock();

  /****************************************************************************
   * Print out the number of pixels in the window used to compute the median
   * and the time taken to do the median filtering.
   ****************************************************************************/
  printf("%d %f\n", n * n, (endtime - starttime) / (float)CLOCKS_PER_SEC);

  /****************************************************************************
   * Write the filtered image out to a file.
   ****************************************************************************/
  if ((write_pgm_image(outputfilename, filteredimage, rows, cols,
                       (unsigned char *)NULL, 255)) == 0)
    exit(1);

  free_image(image, rows);
  free_image(filteredimage, rows);
}
#endif

void median_filter(unsigned char **image, int rows, int cols, int n,
                   unsigned char ***filteredimage, int method) {
  unsigned char *pixel_values = NULL;
  int r, c, rr, cc, p;


  if ((pixel_values = (unsigned char *)calloc(n * n, sizeof(unsigned char))) ==
      NULL) {
    fprintf(stderr, "Error allocating an array in median_filter().\n");
    exit(1);
  }


  if (((*filteredimage) = allocate_image(rows, cols)) == NULL)
    exit(1);


  for (r = 0; r < rows; r++) {
    for (c = 0; c < cols; c++) {
      p = 0;
      for (rr = (r - (n / 2)); rr < (r - (n / 2) + n); rr++) {
        for (cc = (c - (n / 2)); cc < (c - (n / 2) + n); cc++) {
          if ((rr >= 0) && (rr < rows) && (cc >= 0) && (cc < cols)) {
            pixel_values[p] = image[rr][cc];
            p++;
          }
        }
      }

      ivp_sort(pixel_values, 0, p - 1);

      (*filteredimage)[r][c] = pixel_values[p / 2];
    }
  }

  free(pixel_values);
}