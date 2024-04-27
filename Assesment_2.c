#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
// Function prototypes
void reverseString(char *str);
void concatenateStrings(char *str1, char *str2);
int isPalindrome(char *str);
void copyString(char *source, char *destination);
int stringLength(char *str);
int countFrequency(char *str, char ch);
void countVowelsConsonantsDigitsSpaces(char *str);
 
int main() {
    char inputString[100];
    char option;
    char another;
 
    do {
        printf("Enter a string: ");
        fgets(inputString, sizeof(inputString), stdin);
        inputString[strcspn(inputString, "\n")] = '\0'; // Removing the newline character
 
        printf("\nMenu:\n");
        printf("1. Reverse a string\n");
        printf("2. Concatenate strings\n");
        printf("3. Check if palindrome\n");
        printf("4. Copy a string\n");
        printf("5. Length of the string\n");
        printf("6. Frequency of a character\n");
        printf("7. Count vowels, consonants, digits, and spaces\n");
        printf("Choose an option: ");
        scanf(" %c", &option);
 
        switch (option) {
            case '1':
                reverseString(inputString);
                printf("Reversed string: %s\n", inputString);
                break;
            case '2': {
                char secondString[100];
                printf("Enter another string to concatenate: ");
                getchar(); // Clearing the input buffer
                fgets(secondString, sizeof(secondString), stdin);
                secondString[strcspn(secondString, "\n")] = '\0'; // Removing the newline character
                concatenateStrings(inputString, secondString);
                printf("Concatenated string: %s\n", inputString);
                break;
            }
            case '3':
                if (isPalindrome(inputString))
                    printf("The string is a palindrome.\n");
                else
                    printf("The string is not a palindrome.\n");
                break;
            case '4': {
                char copiedString[100];
                copyString(inputString, copiedString);
                printf("Copied string: %s\n", copiedString);
                break;
            }
            case '5':
                printf("Length of the string: %d\n", stringLength(inputString));
                break;
            case '6': {
                char ch;
                printf("Enter a character to find its frequency: ");
                scanf(" %c", &ch);
                printf("Frequency of '%c': %d\n", ch, countFrequency(inputString, ch));
                break;
            }
            case '7':
                countVowelsConsonantsDigitsSpaces(inputString);
                break;
            default:
                printf("Invalid option!\n");
                break;
        }
 
        printf("\nDo you want to perform another operation? (y/n): ");
        scanf(" %c", &another);
 
    } while (tolower(another) == 'y');
 
    return 0;
}
 
// Function to reverse a string
void reverseString(char *str) {
    int length = strlen(str);
    int i, j;
    char temp;
 
    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
 
// Function to concatenate two strings
void concatenateStrings(char *str1, char *str2) {
    strcat(str1, str2);
}
 
// Function to check if a string is palindrome
int isPalindrome(char *str) {
    int length = strlen(str);
    int i, j;
 
    for (i = 0, j = length - 1; i < j; i++, j--) {
        if (str[i] != str[j])
            return 0;
    }
 
    return 1;
}
 
// Function to copy a string
void copyString(char *source, char *destination) {
    strcpy(destination, source);
}
 
// Function to find length of a string
int stringLength(char *str) {
    return strlen(str);
}
 
// Function to count frequency of a character in a string
int countFrequency(char *str, char ch) {
    int count = 0;
    int i;
 
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch)
            count++;
    }
 
    return count;
}
 
// Function to count vowels, consonants, digits, and spaces in a string
void countVowelsConsonantsDigitsSpaces(char *str) {
    int vowels = 0, consonants = 0, digits = 0, spaces = 0;
    int i;
 
    for (i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (isalpha(ch)) {
            ch = tolower(ch); // Convert to lowercase for easier comparison
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        } else if (isdigit(ch)) {
            digits++;
        } else if (isspace(ch)) {
            spaces++;
        }
    }
 
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Digits: %d\n", digits);
    printf("Spaces: %d\n", spaces);
}
