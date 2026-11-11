#include<stdio.h>
#include<stdlib.h>

void print_clear(char* buf, int len){
    for(int i = 0; i<len; i++){
        if (buf[i] <= 0x20 || buf[i] >= 0x7e){
            printf(".");
        }else{
            printf("%c", buf[i]);
        }
    }
}

int main(){

    int c;
    int mem_i = 0; // Keeps track of how many bytes has been processed.
    char* buf = (char *)calloc(0x10, sizeof(char));
    while ((c = getchar()) != EOF){

        buf[mem_i % 0x10] = c;

        if(mem_i % 0x10 == 0x0){
            printf("%08x ", mem_i);
        }

        printf("%02x ", c);
        mem_i++;

        if(mem_i % 0x10 == 0x0){
            printf(" | ");
            // At 16th byte boundary 
            print_clear(buf, 0x10);
            printf("\n");
        }
    }
    int x = mem_i % 0x10;
    if(buf[mem_i % 0x10] != 0x0){
        for(int i = 0; i<16-x; i++){
            printf("   ");
        }
        printf(" | ");
        print_clear(buf, 0x10);
    }
    printf("\n");

    return 0;
}
