#include <graphics.h>
#include <stdio.h>
#include <conio.h>

// Function to draw the timer on the screen
void draw_timer(int hours, int minutes, int seconds) {
    char str[10];
    sprintf(str, "%02d:%02d:%02d", hours, minutes, seconds);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(200, 200, str);
}

int main() {
    int gd = DETECT, gm;
    int hours = 0, minutes = 0, seconds = 0;
    int mouse_x, mouse_y;

    initgraph(&gd, &gm, "");

    // Start and Stop button coordinates
    int start_btn_x1 = 50, start_btn_y1 = 50, start_btn_x2 = 150, start_btn_y2 = 100;
    int stop_btn_x1 = 200, stop_btn_y1 = 50, stop_btn_x2 = 300, stop_btn_y2 = 100;

    // Drawing initial buttons
    setcolor(WHITE);
    rectangle(start_btn_x1, start_btn_y1, start_btn_x2, start_btn_y2);
    rectangle(stop_btn_x1, stop_btn_y1, stop_btn_x2, stop_btn_y2);
    outtextxy(start_btn_x1 + 10, start_btn_y1 + 10, "Start");
    outtextxy(stop_btn_x1 + 10, stop_btn_y1 + 10, "Stop");

    while (!kbhit()) {
        // Check for mouse click events
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, mouse_x, mouse_y);

            // Check if Start button is clicked
            if (mouse_x >= start_btn_x1 && mouse_x <= start_btn_x2 && mouse_y >= start_btn_y1 && mouse_y <= start_btn_y2) {
                while (!ismouseclick(WM_LBUTTONDOWN)) {
                    cleardevice();
                    draw_timer(hours, minutes, seconds);
                    delay(1000); // 1 second delay
                    seconds++;
                    if (seconds == 60) {
                        seconds = 0;
                        minutes++;
                    }
                    if (minutes == 60) {
                        minutes = 0;
                        hours++;
                    }
                }
                clearmouseclick(WM_LBUTTONDOWN);
            }

            // Check if Stop button is clicked
            if (mouse_x >= stop_btn_x1 && mouse_x <= stop_btn_x2 && mouse_y >= stop_btn_y1 && mouse_y <= stop_btn_y2) {
                clearmouseclick(WM_LBUTTONDOWN);
                break; // Exit the loop on Stop button click
            }
        }
    }

    getch();
    closegraph();
    return 0;
}