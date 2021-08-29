#ifndef ALLTYPE_H
#define ALLTYPE_H

/*#define DEBUG*/

#include <SDL2/SDL.h>
#define S_WIDTH 2560
#define S_HEIGHT 1440

#define DIGIT_WIDTH 430
#define DIGIT_PAD 50
#define ALL_DIGIT_WIDTH (DIGIT_WIDTH+DIGIT_PAD)*4
#define SCREEN_PAD_LEFT (S_WIDTH - ALL_DIGIT_WIDTH)/2

#define HL_CENTERX
#define HL_CENTERY
#define HR_CENTERX
#define HR_CENTERY
#define ML_CENTERX
#define ML_CENTERY
#define MR_CENTERX
#define MR_CENTERY

#define SIDE 9            /* размер прямоугольника */
#define SIDE_HALF SIDE/2
#define SIDE_PAD SIDE/2

#define DL_LENGTH 10
#define ZERO_LENGTH 300
#define ONE_LENGTH 108
#define TWO_LENGTH 234
#define THREE_LENGTH 234
#define FOUR_LENGTH 204
#define FIVE_LENGTH 234
#define SIX_LENGTH 288
#define SEVEN_LENGTH 150
#define EIGHT_LENGTH 342
#define NINE_LENGTH 288



typedef enum
{
        DIGIT_BACK,
        DIGIT_NORMAL
}digit_screen_pos_t;


typedef enum
{
        HOUR_LEFT,
        HOUR_RIGHT,
        MINUTE_LEFT,
        MINUTE_RIGHT
} digit_position_t;

typedef enum
{
        FILE_STATUS_OK,
        FILE_STATUS_ABORT
}file_status_t;

typedef enum
{
        AT_HOME,
        FAR_AWAY,
        GONE
} box_position_t;


typedef enum
{
  SDL_STATUS_OK,
  SDL_STATUS_ERROR_INIT,
  SDL_STATUS_ERROR_LINEARTEXTURE,
  SDL_STATUS_ERROR_WINDOWCREATION,
  SDL_STATUS_ERROR_RENDERCREATION,
  SDL_STATUS_ERROR_PNGLOADING,
  SDL_STATUS_ERROR_TTFLOADING
}sdl_statusType;

typedef struct
{
  SDL_Window* gWindow;
  SDL_Renderer* gRenderer;  
}sdlType;


typedef struct
{
        unsigned char red;
        unsigned char green;
        unsigned char blue;
        unsigned char alpha;
} color_t;

typedef struct
{
        int x;
        int y;
} plot_t;


typedef struct
{
        int count_step;
        box_position_t box_position;
        plot_t box_upleft;
        SDL_Rect box_rectangle;
        color_t box_color;
        plot_t* bezje_path_arr;
        plot_t p0, p1, p2, p3;
}box_t;

typedef struct
{
        box_t* back_digit_hl;
        box_t* back_digit_hr;
        box_t* back_digit_ml;
        box_t* back_digit_mr;
} back_digit_t;

typedef struct
{
        box_t* digit_hl;
        box_t* digit_hr;
        box_t* digit_ml;
        box_t* digit_mr;
} digit_t;

typedef struct
{
        digit_t one;
        digit_t two;
        digit_t three;
        digit_t four;
        digit_t five;
        digit_t six;
        digit_t seven;
        digit_t eight;
        digit_t nine;
        digit_t zero;
} all_digits_t;

typedef struct
{
        int length_hl;
        int length_hr;
        int length_ml;
        int length_mr;
} digit_lengths_t;

typedef struct
{
        int current_hour_left;
        int current_hour_right;
        int current_minute_left;
        int current_minute_right;
}times_t;



typedef enum
{
        TIME_THE_SAME,
        TIME_CHANGED
} time_changes_t;


typedef enum
{
        FLASHING,
        STOP_FLASH
}second_flash_t;

#endif
