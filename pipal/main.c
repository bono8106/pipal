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

char *pi = "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094330572703657595919530921861173819326117931051185480744623799627495673518857527248912279381830119491298336733624406566430860213949463952247371907021798609437027705392171762931767523846748184676694051320005681271452635608277857713427577896091736371787214684409012249534301465495853710507922796892589235420199561121290219608640344181598136297747713099605187072113499999983729780499510597317328160963185950244594553469083026425223082533446850352619311881710100031378387528865875332083814206171776691473035982534904287554687311595628638823537875937519577818577805321712268066130019278766111959092164201989";

int is_pal(char *x, int s, int len) {
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
    int ll = 13;
    int digits = 1000000;

    pi = malloc(digits + 1);

    FILE *pifile = fopen("/Users/nbotev/Downloads/pi1000000.txt", "r");
    fread(pi, digits, 1, pifile);
    fclose(pifile);
    pi[digits] = 0;

    for (int i = 800000; i < strlen(pi) - ll; i++) {
        if (is_pal(pi, i, ll)) {
            printf("found pal at pos %d\n", i);
            char *pal = malloc(ll + 1);
            strncpy(pal, pi + i, ll);
            pal[ll] = 0;
            printf("pal = %s\n", pal);
            return 1;
        }
    }
    printf("Hello, World!\n");
    return 0;
}
