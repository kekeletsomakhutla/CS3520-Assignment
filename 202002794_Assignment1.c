/*  Names:  Kekeletso Makhutla
    ID:     202002794
    description: Reversible Prime Squares
*/


#include<string.h>
#include <stdio.h>
#include <math.h>
#include  <stdbool.h>
//Prototypes
bool IsPrime(float a);                  // Checks if a number is prime and returns True if it is
float square(float a);                  // Squares
bool IsPalindrome(float a, char *r);   // Checks if a number is a palindrome and returns TRUE if it is
bool isSquareOfPrime(float a);          // Checks if a number id a square of a prime and returns TRUE if it is



bool IsPrime(float a)
{

	int num;
	long temp = a;

    if(temp >= 0 && temp < 10)
    {
        printf("In range 10\n");
        num = 2;
    }


	else if(temp >= 10 && temp < 100)
    {
         printf("In range 99");
        num = 3;
    }

    else if(temp >= 100 && temp < 500)
    {
        printf("In range 499");
        num = 4;
    }
    else if(temp >= 1000)
    {
    	printf("out of bounds\n");
    	num = 5;
	}

    char* buf[num];
    gcvt(a, num, buf);
    char decimalPoint = '.';
    bool decision;

	for(int i = 0; i < num ; i++)
    {
    	if(buf[i] == decimalPoint )
        {
            return decision;
        }
        else
        {
            continue;
        }

	}


	for(int z = 2; z < temp; z++)
	{
		if(temp % z == 0 )
		{
			decision = false;
		}
		else if(temp % z != 0 && z == temp - 1)
		{
			decision = true;
		}
	}
	return decision;
}

float square(float a)
{
	float answer;
	answer = a * a;
	return answer;
}


bool isSquareOfPrime(float a)
{

	float square_root = sqrt(a);

	if(IsPrime(square_root))
	{
		return true;
	}

	else
	{
		return false;
	}

}

bool IsPalindrome(float a, char *r)
{
    int _num;
    char* _buf[_num];
    int length = strlen(_buf);
	r = realloc(r, length * sizeof(char));
    long _temp = a;

    if(_temp >= 0 && _temp < 10)
    {
        _num = 2;
    }


	else if(_temp >= 10 && _temp < 100)
    {
         _num = 3;
    }

    else if(_temp >= 100 && _temp < 1000)
    {
        _num = 4;
    }
    else if(_temp >= 1000)
    {
    	_num = 5;
	}

    gcvt(a, _num, _buf);
    char tempArr[sizeof(_buf)];
    strcpy(tempArr, _buf);
    strrev(tempArr);
	bool decision = true;

	for(int i = 0; i < length; i++)
	{
	    r[i] = tempArr[i];
		if(r[i] != _buf[i])
		{
		    decision = false;
		}
    }
    return decision;
}

int main()
{
    char* r = malloc(sizeof(char));
    int count = 0;
    int input = 0;

	while (count < 10)
	{
		if(IsPrime(input))
		{
			if(!IsPalindrome(square(input), &r))
			{
				if(isSquareOfPrime(atof(&r)))
				{
					printf(" is reversible prime square\n");
					count = count + 1;
					input = input +1;
				}
				else
                {
                    printf("\nisSquareOfPrime didn't run");
                    input = input +1;
                }

			}
			else
            {
                input = input + 1;
            }
		}
		else
		{
			input = input + 1;
		}
	}
	return 0;
}
