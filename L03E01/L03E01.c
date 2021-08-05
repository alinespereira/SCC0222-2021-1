#include <stdio.h>

#define ROTORSIZE 26

void readRotor(int rotor[]);
void showRotor(int rotor[]);
int charToCode(char);
char codeToChar(int, char);

int main()
{
    int rotor1[ROTORSIZE], rotor2[ROTORSIZE], rotor3[ROTORSIZE];
    int rotor1State = 0, rotor2State = 0, rotor3State = 0;
    char currentChar;
    int currentCharCode;

    scanf("%*[^\r\n]s");
    scanf("%*[\r\n]s");

    readRotor(rotor1);
    readRotor(rotor2);
    readRotor(rotor3);

    scanf("%*[^\r\n]s");
    scanf("%*[\r\n]s");
    scanf("%*[^\r\n]s");
    scanf("%*[\r\n]s");

    while (scanf("%c", &currentChar) != EOF)
    {
        currentCharCode = charToCode(currentChar);
        if (currentCharCode > -1)
        {
            currentCharCode = rotor1[(currentCharCode + rotor1State) % ROTORSIZE];
            currentCharCode = rotor2[(currentCharCode + rotor2State) % ROTORSIZE];
            currentCharCode = rotor3[(currentCharCode + rotor3State) % ROTORSIZE];
            printf("%c", codeToChar(currentCharCode, currentChar));
            rotor1State++;
            rotor2State = rotor1State / ROTORSIZE;
            rotor3State = rotor2State / ROTORSIZE;
        }
        else
            printf("%c", currentChar);
    }

    return 0;
}

void readRotor(int rotor[])
{
    for (int i = 0; i < ROTORSIZE; i++)
    {
        scanf("%d", &rotor[i]);
    }
}

void showRotor(int rotor[])
{
    for (int i = 0; i < ROTORSIZE; i++)
    {
        printf("%3d", rotor[i]);
    }
    printf("\n");
}

int charToCode(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a';
    else if (c >= 'A' && c <= 'Z')
        return c - 'A';
    else
        return -1;
}

char codeToChar(int code, char original)
{
    if (original >= 'a' && original <= 'z')
        return 'a' + code;
    else if (original >= 'A' && original <= 'Z')
        return 'A' + code;
    else
        return original;
}
