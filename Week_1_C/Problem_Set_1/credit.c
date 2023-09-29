#include <cs50.h>
#include <math.h>
#include <stdio.h>

long readCc(void);
bool isValid(long cc);
string getType(long cc);
int length (long cc);
int getFirstDigit(long cc);

int main(void)
{
    long cc = readCc();
    if (isValid(cc))
    {
        printf("%s", getType(cc));
    }
    else
    {
        printf("INVALID\n");
    }
}

long readCc(void)
{
    return get_long("CC number: ");
}

bool isValid(long cc)
{
    int checksum = 0;
    long aux = cc;
    for (int i = 1; i <= length(cc); i++){
        if (i % 2 == 0) {
            int temp = 2 * (aux % 10);
            if (temp > 9)
            {
                checksum += (temp / 10) + (temp % 10);
            }
            else
            {
                checksum += temp;
            }
        }
        else
        {
            checksum += aux % 10;
        }
        aux /= 10;
    }
    if (checksum != 0 && checksum % 10 == 0 && (length(cc) == 13 || length(cc) == 15 || length(cc) == 16))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int length (long cc)
{
    int length = 0;
    long aux = cc;
    for (int i = 1; aux >= 1; i++) {
        aux /= 10;
        length++;
    }
    return length;
}

string getType(long cc)
{
    if (getFirstDigit(cc) == 3)
    {
        return "AMEX\n";
    }
    else if (getFirstDigit(cc) == 4)
    {
        return "VISA\n";
    }
    else
    {
        return "MASTERCARD\n";
    }
}

int getFirstDigit(long cc)
{
    long temp = cc / pow(10, length(cc) - 1);
    return  temp % 10;
}
