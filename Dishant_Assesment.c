#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a string
void reverseString(char str[]) {
    int length = strlen(str);
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

void concatenateStrings(char str1[], char str2[]) {
    char result[200]; // Assuming the combined length of both strings won't exceed 200 characters
    strcpy(result, str1); // Copy the first string to the result
    strcat(result, str2); // Concatenate the second string to the result
    printf("%s\n", result); // Print the concatenated string
}

// Function to check if a string is palindrome
int isPalindrome(char str[]) {
    int length = strlen(str);
    for (int i = 0; i < length/2; i++) {
        if (str[i] != str[length - i - 1]) {
            return 0;
        }
    }
    return 1;
}

// Function to copy a string
void copyString(char dest[], char src[]) {
    strcpy(dest, src);
    printf("%s\n", dest);
}

// Function to find the length of a string
int stringLength(char str[]) {
    return strlen(str);
}

// Function to find frequency of characters in a string
void charFrequency(char str[]) {
    int count[256] = {0};
    for (int i = 0; str[i] != '\0'; i++) {
        count[(int)str[i]]++;
    }
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            printf("'%c' : %d\n", (char)i, count[i]);
        }
    }
}

// Function to count number of vowels and consonants
void countVowelsConsonants(char str[]) {
    int vowels = 0, consonants = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
                str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    printf("Vowels: %d\nConsonants: %d\n", vowels, consonants);
}

// Function to count number of blank spaces and digits
void countBlankSpacesDigits(char str[]) {
    int blanks = 0, digits = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            blanks++;
        } else if (isdigit(str[i])) {
            digits++;
        }
    }
    printf("Blank Spaces: %d\nDigits: %d\n", blanks, digits);
}

int main() {
    char input[100];
    int choice;

    do {
        printf("\nString Operations Menu:\n");
        printf("1. Reverse a string\n");
        printf("2. Concatenate two strings\n");
        printf("3. Check if a string is palindrome\n");
        printf("4. Copy a string\n");
        printf("5. Length of the string\n");
        printf("6. Frequency of characters in a string\n");
        printf("7. Count vowels and consonants\n");
        printf("8. Count blank spaces and digits\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter a string: ");
                scanf(" %[^\n]", input); // corrected format specifier
                printf("Reversed string: ");
                reverseString(input);
                break;
            case 2:
                printf("Enter first string: ");
                scanf(" %[^\n]", input); // corrected format specifier
                printf("Enter second string: ");
                char str2[100];
                scanf(" %[^\n]", str2); // corrected format specifier
                printf("Concatenated string: ");
                concatenateStrings(input, str2);
                break;
            case 3:
                printf("Enter a string: ");
                scanf(" %[^\n]", input); // corrected format specifier
                if (isPalindrome(input)) {
                    printf("Palindrome!\n");
                } else {
                    printf("Not a palindrome!\n");
                }
                break;
            case 4:
                printf("Enter a string: ");
                scanf(" %[^\n]", input); // corrected format specifier
                printf("Copied string: ");
                char copy[100];
                copyString(copy, input);
                break;
            case 5:
                printf("Enter a string: ");
                scanf(" %[^\n]", input); // corrected format specifier
                printf("Length of the string: %d\n", stringLength(input));
                break;
            case 6:
                printf("Enter a string: ");
                scanf(" %[^\n]", input); // corrected format specifier
                printf("Frequency of characters:\n");
                charFrequency(input);
                break;
            case 7:
                printf("Enter a string: ");
                scanf(" %[^\n]", input); // corrected format specifier
                countVowelsConsonants(input);
                break;
            case 8:
                printf("Enter a string: ");
                scanf(" %[^\n]", input); // corrected format specifier
                countBlankSpacesDigits(input);
                break;
            case 9:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a number between 1 and 9.\n");
        }

        printf("Do you want to continue? (1 for Yes / 0 for No): ");
        scanf("%d", &choice);

    } while (choice != 0);

    return 0;
}

