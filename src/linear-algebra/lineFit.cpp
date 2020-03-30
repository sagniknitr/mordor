



void hough_line(unsigned char image[],
                unsigned int width,
                unsigned int height)
{


    for(int i = 0; i < height ; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(image[i * step + j ] != 0)
            {
                int r = x * cos(t)  + y * sin(t);

            }
        }
    }
}