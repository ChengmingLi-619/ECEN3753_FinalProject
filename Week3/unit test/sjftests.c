#include <stdlib.h>
#include "ctest.h"
#include "sjf.h"
#include <time.h>

CTEST_DATA(shortestjobfirst) {
    struct mass ball[3];
    int size;
};

CTEST_SETUP(shortestjobfirst) {
    int x_init_pos[] = {20, 30, 40};
    int y_init_pos[] = {20, 20, 20};

    int x_init_vel[] = {5, 10, 15};
    int y_init_vel[] = {5, 15, 15};

    int mass[] = {1,2,3} 
    data->size = sizeof(x_init_pos) / sizeof(x_init_pos[0]);

    init(data->ball,x_init_pos,y_init_pos,x_init_vel,y_init_vel,data->size);
    final_velocity(data->ball,data->size);
}

CTEST2(shortestjobfirst, test_process) {
    for (int i = 0 ; i<3;i++){
        ASSERT_EQUAL(data->ball[i].mass,i+1);
    }
}

// TODO add additional tests to help debug
