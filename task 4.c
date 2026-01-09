#include <stdio.h>
#include <string.h>

// Function to compress using RLE
void compress(char input[], char output[]) {
    int count = 1, k = 0;

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == input[i + 1]) {
            count++;
        } else {
            output[k++] = input[i];
            output[k++] = count + '0'; // converting count to character
            count = 1;
        }
    }
    output[k] = '\0';
}

// Function to decompress RLE data
void decompress(char input[], char output[]) {
    int k = 0;

    for (int i = 0; i < strlen(input); i += 2) {
        char ch = input[i];
        int count = input[i + 1] - '0';

        for (int j = 0; j < count; j++) {
            output[k++] = ch;
        }
    }
    output[k] = '\0';
}

int main() {
    char text[100], compressed[100], decompressed[100];

    printf("Enter text to compress: ");
    scanf("%s", text);

    compress(text, compressed);
    printf("\nCompressed Data: %s", compressed);

    decompress(compressed, decompressed);
    printf("\nDecompressed Data: %s", decompressed);

    return 0;
}
