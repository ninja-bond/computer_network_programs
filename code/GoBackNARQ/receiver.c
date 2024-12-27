#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define PACKETS 10

void receiver(){
    int expect_sq = 0;

    printf("Receiving has started>>>>>>>>>\n");

    while(expect_sq <PACKETS){
        if(rand() % 2 == 0) {
            printf("Received packet: %d \n", expect_sq);
            expect_sq++;
        }else{
            printf("Receiver lost packet: %d \n", expect_sq);
        }

        sleep(1);
    }
    printf("REceiver: All packets received \n");
}

int main(){
    srand(time(NULL));
    receiver();
    return 0;
}