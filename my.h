/*
** EPITECH PROJECT, 2020
** directory
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Window/Export.h>
#include <stdio.h>

sfVector2f sourissprite(sfVector2i vect2i);
char *nb_tochar(int i);

typedef struct s_menu_game {
    sfEvent event;
    sfMusic *click;
    sfSprite *sprite_bg;
    sfTexture *text_bg;
    sfClock *horloge;

    sfVector2f pos_perso;
    sfIntRect player_rect;
    sfClock *player_clock;
    sfSprite *sprite_perso;
    sfTexture *text_perso;
    sfMusic *music;
}s_menu_game_t;

typedef struct s_object {
    sfSprite *sprite_tree;
    sfTexture *text_tree;
    sfIntRect tree_rect;
    sfClock *horloge_tree;

    sfSprite *sprite_mob;// a faire
    sfTexture *text_mob;
    sfIntRect mob_rect;
    sfClock *horloge_mob;

    sfSprite *sprite_bubble;
    sfTexture *text_bubble;
}s_object_t;

typedef struct s_perso {
    sfVector2f pos_perso;
    sfIntRect player_rect;
    sfClock *player_clock;
    sfSprite *sprite_perso;
    sfTexture *text_perso;
    sfTexture *text_perso_l;
    sfTexture *text_perso_up;
    sfTexture *text_perso_do;
    sfSprite *sprite_house1;
    sfFont* font_obj;
    sfText* texte_obj;
    sfText* texte_int;
    int item;
    int ret;
    int up;
    int down;
    int right;
    int left;
    int object;
    struct s_perso *next;
}s_perso_t;

typedef struct s_my_cave {
    sfVector2f pos_cave;
    sfEvent event_gc;
    sfMusic *click_gc;
    sfSprite *sprite_bg_gc;
    sfTexture *text_bg_gc;
    sfClock *cave_horloge;
    sfClock *fight_clock;
    sfClock *tap;
    sfSprite *sprite_bubble_gc;
    sfTexture *text_bubble_gc;

    int fig_int;
    int go_in;
    int nb_touch;
    int up;
    int down;
    int right;
    int left;
}s_my_cave_t;

typedef struct s_cave_font {
    sfFont* font_fight;
    sfText* texte_fight;
    sfText* texte_fight_nb;
    int nb;
}s_cave_font_t;

typedef struct s_mob {
    sfVector2f pos_mob;
    sfIntRect rect_mob;
    sfClock *clock_mob;
    sfClock *clock_mov;

    sfSprite *sprite_mob;
    sfTexture *text_mob_l;
    sfTexture *text_mob_r;
    int mov_mob;
}s_mob_t;

typedef struct s_villager {
    sfVector2f pos_villager;
    sfIntRect rect_villager;
    sfClock *clock_villager;

    sfSprite *sprite_villager;
    sfTexture *text_villager;
}s_villager_t;


typedef struct s_my_game {
    sfEvent event_g;
    sfMusic *click_g;
    sfMusic *music;
    sfSprite *sprite_bg_g;
    sfTexture *text_bg_g;
    int pause;
}s_my_game_t;

typedef struct s_inventory {
    sfSprite *sprite_invent;
    sfTexture *text_invent;
}s_inventory_t;


typedef struct s_cursor {
    sfVector2f curseur_posit;
    sfSprite *cursorsprite;
    sfTexture *cursortext;
}s_cursor_t;

typedef struct s_set_panel {
    int i;
    int k;
    int how_var;
    sfTexture *text_panel;
    sfTexture *text_audio_off;
    sfTexture *text_audio_on;
    sfTexture *text_close;
    sfTexture *text_but_howtoplay;
    sfTexture *text_howtoplay;
    sfTexture *text_but_howtoplay_close;
    sfSprite *sprite_panel;
    sfSprite *sprite_but_howtoplay;
    sfSprite *sprite_howtoplay;
    sfSprite *sprite_but_howtoplay_close;
    sfSprite *sprite_audio;
    sfSprite *sprite_close;
    sfVector2f pos_panel;
    sfVector2f pos_audio;
    sfVector2f pos_close;
    sfVector2f pos_but_howtoplay;
    sfVector2f pos_howtoplay;
    sfVector2f pos_but_howtoplay_close;
    sfVector2f pos_button_h;
    sfVector2f pos_button2_h;
    sfVector2f pos_button3_h;
    sfVector2f pos_audio_h;
    sfVector2f pos_but_howtoplay_h;
    sfVector2f pos_close_h;
}s_set_panel_t;

typedef struct s_button {
    sfVector2f pos_button;
    sfVector2f pos_button_h;
    sfVector2f pos_button2;
    sfVector2f pos_button3;
    sfSprite *sprite_button;
    sfSprite *sprite_button2;
    sfSprite *sprite_button3;
    sfSprite *sprite_button4;
    sfTexture *text_button;
    sfTexture *text_button2;
    sfTexture *text_button3;
}s_button_t;

s_perso_t *movement_perso(s_perso_t *perso);
s_cursor_t *init_cursor(void);
s_perso_t *init_perso(void);

int my_game(sfRenderWindow* window);
int menu_game(int ac, char **av, sfRenderWindow* window);
s_perso_t *cave(sfRenderWindow* window, s_perso_t *s_perso);

#endif /* !MY_H_ */

