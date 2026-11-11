#include <ctype.h>
#include <stddef.h>
#include<stdio.h>
#include <stdlib.h>

#define BUF_SIZE 4096

int main(int argc, char* argv[]){

    if(argc != 2){
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // OPEN FILE USING ARGV[1]
    FILE* fp;
    fp = fopen(argv[1], "rb"); 
    if(fp == NULL){
        perror("Error opening file.");
        return EXIT_FAILURE;
    }

    unsigned char buf[BUF_SIZE];
    size_t offset = 0, n;


    while((n = fread(buf, 1, BUF_SIZE, fp)) > 0){
        for(size_t i = 0; i<n; i++){
            // Print the offset at the start of every 16 byte line
            if(i%16 == 0){
                printf("%08zX  ", offset+i);
            }
            // print current byte as 2 hex digits
            printf("%02x ", buf[i]);

            if(i % 16 == 15 || i == n-1){
                /*
                 * If the line has fewer than 16 bytes
                 * print extra space for ascii to align
                 */
                size_t bytes_in_row = (i%16) +1;
                for(size_t pad = bytes_in_row; pad < 16; pad++){
                    printf("   ");
                }

                // Print the ASCII 
                printf(" |");

                size_t row_start = (i/16) * 16;

                for(size_t j = row_start; j<=i; j++){
                    // Print the character if its printable, otherwise a dot
                    if(isprint(buf[j])){
                        putchar(buf[j]);
                    }else{
                        putchar('.');
                    }
                }
                printf("|\n");
            }
        }  
        offset += n;
    }


    return 0;
}
