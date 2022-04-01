#include "physics.h"
#include <stdio.h>


void init(struct mass* ball, int* x_pos,int* y_pos,int*x_vel,int* y_vel,int* masses,int size);
void final_velocity(struct mass* ball,int size );
void KE_Calc(struct mass* ball,int size);
void x_vel_calc(struct mass* ball, int time,int size);
void y_vel_calc(struct mass* ball, int time, int size);

void x_pos_calc(struct mass* ball, int time,int size);
void y_pos_calc(struct mass* ball, int time, int size);

void init(struct mass* ball, int* x_pos,int* y_pos,int*x_vel,int* y_vel,int* masses,int size){
    for(int i = 0; i< size; i++){
        ball[i].x_init_pos = x_pos[i];
        ball[i].y_init_pos = y_pos[i];
        ball[i].x_init_vel = x_vel[i];
        ball[i].y_init_vel = y_vel[i];
        ball[i].mass = masses[i];
    }
}

void final_velocity(struct mass* ball,int size ){
    for(int i = 0; i< size; i++){
        ball[i].final_velocity = sqrt(ball[i].x_init_vel*ball[i].x_init_vel* + ball[i].y_init_vel*ball[i].y_init_vel);
    }   
}

void KE_Calc(struct mass* ball,int size){
    for(int i = 0; i< size; i++){
        ball[i].ke = 0.5*ball[i].mass*ball[i].final_velocity*ball[i].final_velocity;
    }
}
void x_vel_calc(struct mass* ball, int time,int size){
    for(int i = 0; i< size; i++){
       ball[i].x_init_vel =  ball[i].x_init_vel + ball[i].acceleration*time;
    }

}
void y_vel_calc(struct mass* ball, int time,int size){
    for(int i = 0; i< size; i++){
        ball[i].y_init_vel = ball[i].y_init_vel + ball[i].acceleration*time;
    }
}

void x_pos_calc(struct mass* ball, int time,int size){
    for(int i = 0; i< size; i++){
        ball[i].x_init_pos = ball[i].x_init_pos + (ball[i].x_init_vel*time+0.5*ball[i].acceleration*time*time)
    }

}
void y_pos_calc(struct mass* ball, int time ,int size){
    for(int i = 0; i< size; i++){
        ball[i].y_init_pos = ball[i].y_init_pos + (ball[i].y_init_vel*time+0.5*ball[i].acceleration*time*time)
    }
}