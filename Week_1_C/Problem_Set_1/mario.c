#include <cs50.h>
#include <stdio.h>

int getHeight(void);
void print(int height);
void buildLine(int ln, int height);

int main(void)
{
    int height = getHeight();
    print(height);
}

int getHeight(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    return height;
}

void print(int height)
{
    for (int ln = 1; ln <= height; ln++)
    {
        buildLine(ln, height);
    }
}

void buildLine(int ln, int height)
{
    for (int i = height - ln; i > 0; i--)
    {
        printf(" ");
    }
    for (int i = ln; i > 0; i--)
    {
        printf("#");
    }
    printf("  ");
    for (int i = ln; i > 0; i--)
    {
        printf("#");
    }
    printf("\n");
}
