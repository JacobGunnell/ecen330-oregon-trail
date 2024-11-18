#include "board7.h"
#include "lcd.h"
#include "joy.h"
#include <math.h>
#include <stdio.h>

#define X_ORIGIN_RI 3*LCD_W/4
#define Y_ORIGIN_RI LCD_H/4

float t=0;
float t1=0;

int32_t my_x=0;
int32_t my_y=0;
float my_w=0;

int x_pos = LCD_W/2;


void board_init(void){
    //lcd_fillScreen(CONFIG_COLOR_BACK_GROUND);
    lcd_fillRect(3*LCD_W/4-1,LCD_H/16,2,3*LCD_H/8,CONFIG_COLOR_GRID_LINES);
    lcd_fillRect(((float)9/16)*LCD_W,LCD_H/4-1,((float)3/8)*LCD_W,2, CONFIG_COLOR_GRID_LINES);

    lcd_fillRect(LCD_W/2-1,9*LCD_H/16,2,3*LCD_H/8,CONFIG_COLOR_GRID_LINES);
    lcd_fillRect(((float)1/8)*LCD_W,3*LCD_H/4-1,((float)6/8)*LCD_W,2, CONFIG_COLOR_GRID_LINES);

    char message[10] = "real";
    lcd_drawString(((float)15/16)*LCD_W-5,Y_ORIGIN_RI+5,message, WHITE);
    char message2[20] = "imaginary";
    lcd_drawString(((float)6/8)*LCD_W+5, ((float)1/16)*LCD_H-5, message2, WHITE);

    draw_cos_w();
}

void trace_cos_RI(float w){

    double x = (cos(t)*cos(-w*t)*LCD_H/5)+X_ORIGIN_RI;
    double y = ((cos(t)*sin(-w*t))*LCD_H/5)+Y_ORIGIN_RI;
    //printf("x: %f\ny: %f\n", x, y);
    lcd_drawPixel(x,y,BLUE);
    
    t=t+.01;
}

void draw_cos_RI(float w){
    double x_RI;
    double y_RI;
    while(t<50){
        x_RI = (cos(t)*cos(-w*t)*LCD_H/5)+X_ORIGIN_RI;
        y_RI = ((cos(t)*sin(-w*t))*LCD_H/5)+Y_ORIGIN_RI;
        //printf("x: %f\ny: %f\n", x, y);
        lcd_drawPixel(x_RI,y_RI,RED);
    
        t=t+.01;
    }
}

void draw_cos_w(){
    lcd_fillRect(((float)1/8)*LCD_W,3*LCD_H/4-2,((float)6/8)*LCD_W, 1, RED);
    lcd_fillRect(((float)2/5)*LCD_W,5*LCD_H/8,1,LCD_H/8,RED);
    lcd_fillRect(((float)3/5)*LCD_W,5*LCD_H/8,1,LCD_H/8,RED);
}


void board_tick(){
    //getposition of x cursor

    joy_get_displacement(&my_x,&my_y);
    if(my_x>20||my_x<-20){
        printf("x displacement: %ld\nx_pos: %d\n",my_x, x_pos);
        lcd_fillScreen(CONFIG_COLOR_BACK_GROUND);
        board_init();
        if(my_x>0){
            x_pos = x_pos + 1;
        }
        else{
            x_pos = x_pos - 1;
        }
        lcd_fillCircle(x_pos,3*LCD_H/4-2 , 2, YELLOW);
        t=0;
        my_w= (float)(x_pos-(LCD_W/2))/(LCD_W/10);
        printf("my_w: %f", my_w);
        draw_cos_RI((float)(x_pos-(LCD_W/2))/(LCD_W/10));
        t=0;
    }
    lcd_fillCircle(x_pos,3*LCD_H/4-2 , 2, YELLOW);
    trace_cos_RI((float)(x_pos-(LCD_W/2))/(LCD_W/10));
}