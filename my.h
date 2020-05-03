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

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

sfVector2f sourissprite(sfVector2i vect2i);
char *nb_tochar(int i);

typedef struct s_menu_game {
    int music_state;
    int music_onoff;
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

typedef struct s_pause_game {
    sfSprite *sprite_pause;
    sfTexture *text_pause;
    sfVector2f pos_pause;
}s_pause_game_t;

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

    sfSprite *sprite_bubble_v;
    sfTexture *text_bubble_v;

    sfSprite *sprite_bubble_v1;
    sfTexture *text_bubble_v1;

    sfSprite *sprite_bubble_v2;
    sfTexture *text_bubble_v2;
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
    //pour la popo
    sfTexture *text_popo;
    sfSprite *sprite_popo;
    sfVector2f pos_popo;
    sfIntRect rect_popo;
    sfClock *clock_popo;
    sfMusic *music_popo;

    int item;
    int ret;
    int up;
    int down;
    int right;
    int left;
    int object;
    int our_life;
    int state_kit;
    int int_chest;
    int sword_yes;
    int less_hp;
    struct s_perso *next;
}s_perso_t;

typedef struct s_life {
    sfSprite *sprite_life;
    sfTexture *text_life;
    sfIntRect rect;

}s_life_t;

typedef struct s_wind {
    sfSprite *sprite_wind;
    sfTexture *text_wind;
    sfIntRect rect_w;
    sfClock *clock_w;
    struct s_wind *next;
}s_wind_t;

typedef struct s_my_cave {
    sfVector2f pos_cave;
    sfEvent event_gc;
    sfMusic *music;
    sfMusic *music_fight;
    sfSprite *sprite_bg_gc;
    sfTexture *text_bg_gc;
    sfClock *cave_horloge;
    sfClock *fight_clock;
    sfClock *tap;
    sfSprite *sprite_bubble_gc;
    sfTexture *text_bubble_gc;
    sfSprite *sprite_bu;
    sfTexture *text_bu;
    int fig_int;
    int healb;
    int go_in;
    int nb_touch;
    int up;
    int down;
    int right;
    int left;
    int need2fight;
}s_my_cave_t;

typedef struct s_leave {
    sfSprite *sprite_leave;
    sfTexture *text_leave;
}s_leave_t;

typedef struct s_cave_font {

    sfSprite *sprite_l;//la heal bar
    sfTexture *text_l;
    sfVector2f pos_l;
    sfIntRect rect_l;

    sfSprite *sprite_l2;//la heal bar us
    sfTexture *text_l2;
    sfVector2f pos_l2;
    sfIntRect rect_l2;

    sfSprite *sprite_vs;
    sfTexture *text_vs;
    sfTexture *text_vs_red;
    sfVector2f pos_vs;

    sfSprite *sprite_1c;
    sfTexture *text_1c;
    sfVector2f pos_1c;
    int nb;

}s_cave_font_t;

typedef struct s_fcave {
    sfFont* font_fight;
    sfText* texte_fight;
    sfText* texte_fight_nb;
    sfVector2f pos_f;
    struct s_fcave *next;
}s_fcave_t;

typedef struct s_mob {
    sfVector2f pos_mob;
    sfIntRect rect_mob;
    sfClock *clock_mob;
    sfClock *clock_mov;
    sfClock *clock_heal;//us clock

    sfSprite *sprite_mob;
    sfTexture *text_mob_l;
    sfTexture *text_mob_r;
    int mov_mob;
}s_mob_t;

typedef struct s_villager {
    int quest_state;
    int quest_accepted;
    int yannis;
    int wrong_key;
    int good_key;
    int end_game;

    sfVector2f pos_villager;
    sfIntRect rect_villager;
    sfClock *clock_villager;

    sfSprite *sprite_villager;
    sfTexture *text_villager;

    sfSprite *sprite_quest;
    sfTexture *text_quest;
    sfVector2f pos_quest;
    sfSprite *sprite_yes_button;
    sfSprite *sprite_no_button;
    sfTexture *text_yes_button;
    sfTexture *text_no_button;
    sfVector2f pos_yes_button;
    sfVector2f pos_no_button;
    sfVector2f pos_achievement;
    sfSprite *sprite_achievement;
    sfTexture *text_achievement;
    sfSprite *sprite_endquest;
    sfTexture *text_endquest;
    sfSprite *sprite_thanks;
    sfTexture *text_thanks;
    sfSprite *sprite_wrong_key;
    sfTexture *text_wrong_key;
    sfClock *clock_achievement;
}s_villager_t;

typedef struct s_villager1 {
    sfVector2f pos_villager;
    sfIntRect rect_villager;
    sfClock *clock_villager;
    sfSprite *sprite_villager;
    sfTexture *text_villager;
}s_villager1_t;

typedef struct s_villager2 {
    sfVector2f pos_villager;
    sfIntRect rect_villager;
    sfClock *clock_villager;
    sfSprite *sprite_villager;
    sfTexture *text_villager;
}s_villager2_t;

typedef struct s_chest {
    sfIntRect rect_chest;
    sfClock *clock_chest;
    sfSprite *sprite_chest;
    sfTexture *text_chest;
    struct s_chest *next;
}s_chest_t;

typedef struct s_my_game {
    sfEvent event_g;
    sfMusic *click_g;
    sfMusic *music;
    sfSprite *sprite_bg_g;
    sfTexture *text_bg_g;
    sfSprite *sprite_endscreen;
    sfTexture *text_endscreen;
    sfClock *clock_end_game;
    int pause;
}s_my_game_t;

typedef struct s_inventory {
    sfSprite *sprite_invent;
    sfSprite *sprite_sword;
    sfSprite *sprite_potion;
    sfSprite *sprite_sword_fx;
    sfSprite *sprite_sword_fx2;
    sfSprite *sprite_potion_fx;
    sfTexture *text_invent;
    sfTexture *text_invent_key;
    sfTexture *text_invent_2key;
    sfTexture *text_invent_sword;
    sfTexture *text_swordlvl_fx;
    sfTexture *text_swordlvl_fx2;
    sfTexture *text_potionlvl_fx;
    sfTexture *text_invent_potion;
    sfVector2f pos_sword_fx;
    sfVector2f pos_potion_fx;
    sfClock *clock_fx;
    sfTexture *text_fx_blue;
    sfSprite *sprite_fx_blue;
    sfVector2f pos_blue;

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
    sfVector2f pos_button4;
    sfVector2f pos_button_menu_end;
    sfVector2f pos_button3_h;
    sfSprite *sprite_button;
    sfSprite *sprite_button2;
    sfSprite *sprite_button3;
    sfSprite *sprite_button4;
    sfSprite *sprite_menu_end;
    sfTexture *text_button;
    sfTexture *text_button2;
    sfTexture *text_button3;
    sfTexture *text_button4;
    sfTexture *text_menu_end;
}s_button_t;

s_perso_t *movement_perso(s_perso_t *perso);
s_cursor_t *init_cursor(void);
s_perso_t *init_perso(void);

int my_game(s_menu_game_t *struct_menu, sfRenderWindow* window);
int menu_game(sfRenderWindow* window);
s_perso_t *cave(sfRenderWindow* window, s_perso_t *s_perso, s_menu_game_t *struct_menu, s_inventory_t *s_invent);
s_life_t *init_life();
void my_putchar(char c);
void my_putstr(char const *str);
int read_file(FILE *fp);
void draw_popo(sfRenderWindow* window, s_perso_t *s_perso);

#endif /* !MY_H_ */