
#include "physics.h"
int main(){
    struct mass ball[3];
    int x_init_pos[] = {20, 30, 40};
    int y_init_pos[] = {20, 20, 20};

    int x_init_vel[] = {5, 10, 15};
    int y_init_vel[] = {5, 15, 15};

    int mass[] = {1,2,3} ;
    int size = sizeof(x_init_pos) / sizeof(x_init_pos[0]);

    init(ball,x_init_pos,y_init_pos,x_init_vel,y_init_vel,size);
    final_velocity(ball,size);

    for (int i = 0 ; i<3;i++){
        assert(ball[i].mass == i+1);
    }
    return 0;
}