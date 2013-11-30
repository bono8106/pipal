//
//  main.c
//  pipal
//
//  Created by Nikolay Botev on 10/17/13.
//  Copyright (c) 2013 Nikolay Botev. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

static int is_palindrome(char *x, int s, int len) {
    for (int i = 0; i < len/2; i++) {
        char c1 = x[s + i];
        char c2 = x[s + len - i - 1];
        if (c1 != c2) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, const char * argv[])
{
    // Inputs
    int ll = 13; // Length of palindrome we are looking for
    char *pi_file_name = "pi1000000.txt"; // File with pre-computed digits of pi
    // Source: http://www.angio.net/pi/digits.html

    printf("Loading pi...\n");

    // Open file with pi digits
    FILE *pi_fp = fopen(pi_file_name, "r");
    if (! pi_fp) {
        printf("%s (%s)\n", strerror(errno), pi_file_name);
        return 2;
    }

    // Determine the number of pi digits available
    fseek(pi_fp, 0, SEEK_END); // seek to end of file
    long digits = ftell(pi_fp); // get current file pointer
    fseek(pi_fp, 0, SEEK_SET); // seek back to beginning of file

    // Read pi digits into memory
    char *pi = malloc(digits + 1);
    fread(pi, digits, 1, pi_fp);
    fclose(pi_fp);
    pi[digits] = 0;

    // Look for palendrome
    printf("Looking for %d-digit palindrome...\n", ll);
    for (int i = 0; i < strlen(pi) - ll; i++) {
        if (is_palindrome(pi, i, ll)) {
            printf("Found %d-digit palindrome in pi at position %d\n", ll, i);
            char *pal = malloc(ll + 1);
            strncpy(pal, pi + i, ll);
            pal[ll] = 0;
            printf("Palindrome = %s\n", pal);
            return 0;
        }
    }
    return 1;
}
