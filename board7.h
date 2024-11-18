#define CONFIG_COLOR_ENEMY_MISSILE  RED
#define CONFIG_COLOR_BACK_GROUND BLACK
#define CONFIG_COLOR_GRID_LINES  WHITE
#define CONFIG_GAME_TIMER_PERIOD 10.0E-3f

void board_init(void);

void draw_cos_RI(float w);

void draw_cos_w();

void board_tick();
