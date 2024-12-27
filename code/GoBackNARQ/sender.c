#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define WINDOW_SIZE 5
#define PACKETS 10

void sender(){
    int base = 0;
    int next_sq = 0;
    int ack[PACKETS] = {0};

    printf("Sender started>>>>>\n");

    while(base<PACKETS){
        while(next_sq<base+WINDOW_SIZE-1 && next_sq < PACKETS){
            printf("sender sending packet: %d\n", next_sq);
            next_sq++;
        }

        for(int i = base; i < next_sq; i++){
            if(rand()%2==0) {
                printf("Sender: ACK %d received \n", i);
                ack[i] = true;
            }else{
                printf("Sender: ACK %d lost \n", i);
            }
        }

        while(ack[base] && base<PACKETS){
            base++;
        }

        if(base < next_sq){
            printf("Sender retransmitting from packet %d \n", base);
            next_sq = base;
        }

        sleep(1);
    }
    printf("All packets successfully sent \n ");
}

int main(){
    srand(time(NULL));
    sender();
    return 0;
}