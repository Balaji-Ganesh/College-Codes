/* Write a c++ prog to count vowels, consonants, numbers and Special charecters.
USE gets(str) function to read a string*/

#include <iostream>
#include <string.h>
using namespace std;

// Global declaration of functions..
int consonants_in_str(char* str);
int vowels_in_str(char* str);
int special_chars_in_str(char* str);
int numbers_in_str(char* str);

// Control starts from here..
int main()
{
    char str[20];
    cout << "Enter a string : ";
    scanf("%s", str);
    cout << str;
    
    cout << "Number of vowels : " << vowels_in_str(str) << endl;
    cout << "Number of consonants : " << consonants_in_str(str) << endl;
    cout << "Number of numbers :" << numbers_in_str(str) << endl;
    cout << "Number of special characters : " << special_chars_in_str(str) << endl;
}

// Definition of globally declared functions..
int consonants_in_str(char *str)
{
    int consonants_counted=0, length=strlen(str);
    for(int i=0; i<length; i++)
        if (((str[i]>=65 && str[i] <=90)||(str[i]>=90 && str[i] <=122)) && (str[i]!='a' && str[i]!='e' && str[i]!='i'&&str[i]!='o'&&str[i]!='u'))
            consonants_counted++;
    return consonants_counted;
}


int vowels_in_str(char *str){
    int vowels_counted=0;
    for(int i=0; i<strlen(str); i++)
        switch(str[i]){
            case 'a': 
            case 'e':
            case 'i':
            case 'o':
            case 'u': vowels_counted++;
                      break;
        }
    return vowels_counted;
}

int special_chars_in_str(char *str){
    int specials_counted=0;
    //str = strlwr(str); // Converting to small case so as to reduce the calculations..
    for(int i=0; i<strlen(str); i++)
        if((str[i] < 97 || str[i] > 122) && (str[i] <65 || str[i]>90) && (str[i] <48 || str[i] >57))
            specials_counted++;
    return specials_counted;
}

int numbers_in_str(char* str){
    int numbers_counted=0;
    for(int i=0; i<strlen(str); i++)
        if(str[i] >=48 && str[i] <=57)
            numbers_counted++;
            
    return numbers_counted;
}
