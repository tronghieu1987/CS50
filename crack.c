//The logic here is to loop through all possible combinations of a 4-char array, for example, (from "AAAA" to "zzzz"), and then check if the hash resulted from "crypt" function matches with the input hash. Same logic applies to 2-char and 3-char arrays.
//For the purpose of testing the code, only the hash of "50fkUxYHbnXGw" is checked with the actual password being "rofl".

#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>

string hack2(string hash, string salt);
string hack3(string hash, string salt);
string hack4(string hash, string salt);

int main(void)
{
    string hash = "50fkUxYHbnXGw";
    string salt = "50";
    printf("result2 is %s, result3 is %s, and result 4 is %s\n", hack2(hash, salt), hack3(hash, salt), hack4(hash, salt));
    // printf("result is %s\n", hack4(hash, salt));
}



//define hack2 function
char x[2];
string hack2(string hash, string salt)
{
    x[0] = 'A';
    while (x[0] <= 122  && strcmp(hash, crypt(x, salt)) !=0)
    {
        x[0]++;
        x[1] = 'A';
        while (x[1] <= 122 && strcmp(hash, crypt(x, salt)) !=0)
        {
            x[1]++;
        }
    }
    return x;
}

// define hack3 function
char y[3];
string hack3(string hash, string salt)
{
    y[0] = 'A';
    while (y[0] <= 122  && strcmp(hash, crypt(y, salt)) !=0)
    {
        y[0]++;
        y[1] = 'A';
        while (y[1] <= 122 && strcmp(hash, crypt(y, salt)) !=0)
        {
            y[1]++;
            y[2] = 'A';
            while (y[2] <= 122 && strcmp(hash, crypt(y, salt)) !=0)
            {
                y[2]++;
            }
        }
    }
    return y;
}

//define hack4 function
char z[4];
string hack4(string hash, string salt)
{
    z[0] = 'A';
    while (z[0] <= 122  && strcmp(hash, crypt(z, salt)) !=0)
    {
        z[0]++;
        z[1] = 'A';
        while (z[1] <= 122 && strcmp(hash, crypt(z, salt)) !=0)
        {
            z[1]++;
            z[2] = 'A';
            while (z[2] <= 122 && strcmp(hash, crypt(z, salt)) !=0)
            {
                z[2]++;
                z[3] = 'A';
                while (z[3] <= 122 && strcmp(hash, crypt(z, salt)) !=0)
                {
                    z[3]++;
                }
            }
        }
    }
    return z;
}
