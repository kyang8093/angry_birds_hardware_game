#include "assert.h"
#include "printf.h"
#include "gl.h"
#include "timer.h"
#include "uart.h"
#include "project-app.h"
#include "trig.h"
#include "image.h"

void test_trajectory_different_forces (void) {
    // Background is purple
    gl_clear(gl_color(0x55, 0, 0x55));

    // plot ground
    gl_plot_ground(GROUND_Y);


    for(int i = 1; i <= 10; i++) {
        double force = 1.0 / i;
        
        // plot trajectory of bird given angle and force
        gl_plot_trajectory(force, deg_to_rad(45));

        // plot initial velocity vector given angle and force
        gl_plot_initial_velocity_vector(force, deg_to_rad(45));

    }
    gl_swap_buffer();

}

void test_trajectory_different_angles (void) {
    // Background is purple
    gl_clear(gl_color(0x55, 0, 0x55));


    // plot ground
    gl_plot_ground(GROUND_Y);

    for(int i = 0; i < 10; i++) {
        // plot trajectory of bird given angle and force
        gl_plot_trajectory(1.0, deg_to_rad(i * 9));

        // plot initial velocity vector given angle and force
        gl_plot_initial_velocity_vector(1.0, deg_to_rad(i * 18));
    }

    // Show buffer with drawn contents
    // gl_swap_buffer();

}

void main(void)
{
    uart_init();
    angry_nerds_graphics_init();
    gl_init(SCREEN_WIDTH, SCREEN_HEIGHT, GL_DOUBLEBUFFER);

    gl_draw_image(0, 0  , 'j'); // julie
    gl_draw_image(0, 100, 'p'); // pat
    gl_draw_image(0, 200, 's'); // sean
    gl_draw_image(0, 300, 'e'); // peter
    gl_draw_image(0, 400, 'a'); // anna
    gl_draw_image(0, 500, 'l'); // liana

    test_trajectory_different_angles();
    test_trajectory_different_forces();

    uart_putchar(EOT);
}
