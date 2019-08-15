#include "./player/player.h"

#include <stdio.h>
#include <unistd.h>


int main(){
    for(int i=0; i<5; i++){
        sleep(2);
        daddy();
    }
    return 0;
}