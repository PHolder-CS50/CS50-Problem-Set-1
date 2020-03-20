#include <cs50.h>
#include <stdio.h>

void outputPyramids(int height);
void outputPyramidLeft(int height, int size);
void outputPyramidRight(int size);
void outputBlocks(int size);

// Make a pair of Mario style pyramids side by size, of the
// size requested by the user, from 1 to 8 high
int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    outputPyramids(height);
}

// Output two pyramids (of the requested size) side by side
// with two spaces between them
void outputPyramids(int height)
{
    for (int i = 1; i <= height; i++)
    {
        outputPyramidLeft(height, i);
        printf("  ");
        outputPyramidRight(i);
        printf("\n");
    }
}

// Output the left side pyramid.  This needs to have the total height
// so it can calculate the correct number of spaces to put in front
void outputPyramidLeft(int height, int size)
{
    // Spaces first
    for (int i = 0; i < height - size; i++)
    {
        printf(" ");
    }

    // Then blocks
    outputBlocks(size);
}

// Output the right side pyramid. It doesn't need to know the total
// height because there is no padding on the right side
void outputPyramidRight(int size)
{
    outputBlocks(size);
    // no spaces needed on the right side
}

// Output a line of blocks of the requested size
void outputBlocks(int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("#");
    }
}
