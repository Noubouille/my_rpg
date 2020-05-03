/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** cave
*/

#include "my.h"

int generaterandom(int max, int min)
{
    int nb = 0;
    nb = rand() % (max - min + 1) + min;
    return (nb);
}

s_mob_t *init_mob()
{
    s_mob_t *s_mob = malloc(sizeof(s_mob_t));
    s_mob->pos_mob.x = 1600;
    s_mob->pos_mob.y = 500;
    s_mob->clock_heal = sfClock_create();
    s_mob->clock_mob = sfClock_create();
    s_mob->clock_mov = sfClock_create();
    s_mob->sprite_mob = sfSprite_create();
    s_mob->text_mob_l = sfTexture_createFromFile("Image/mouse_l.png", NULL);
    s_mob->text_mob_r = sfTexture_createFromFile("Image/mouse_r.png", NULL);
    sfSprite_setPosition(s_mob->sprite_mob , s_mob->pos_mob);
    s_mob->rect_mob.height = 41;
    s_mob->rect_mob.width = 50;
    s_mob->rect_mob.top = 0;
    s_mob->rect_mob.left = 0;
    sfSprite_setTexture(s_mob->sprite_mob, s_mob->text_mob_l, sfTrue);
    sfSprite_setTextureRect(s_mob->sprite_mob, s_mob->rect_mob);
    s_mob->mov_mob = 1;

    return s_mob;
}

s_my_cave_t *init_cave()
{
    s_my_cave_t *struct_cave = malloc(sizeof(s_my_cave_t));
    struct_cave->text_bg_gc = sfTexture_createFromFile("Image/cave_map.png", NULL);
    struct_cave->sprite_bg_gc = sfSprite_create();
    sfSprite_setTexture(struct_cave->sprite_bg_gc, struct_cave->text_bg_gc, sfTrue);
    struct_cave->pos_cave.x = 1100;
    struct_cave->pos_cave.y = 330;
    sfSprite_setPosition(struct_cave->sprite_bg_gc , struct_cave->pos_cave);
    struct_cave->cave_horloge = sfClock_create();
    struct_cave->fight_clock = sfClock_create();
    struct_cave->tap = sfClock_create();
    struct_cave->text_bubble_gc = sfTexture_createFromFile("Image/bubble_c.png", NULL);
    struct_cave->sprite_bubble_gc = sfSprite_create();
    sfSprite_setTexture(struct_cave->sprite_bubble_gc, struct_cave->text_bubble_gc, sfTrue);
    sfSprite_setPosition(struct_cave->sprite_bubble_gc , (sfVector2f) {1590, 590});
    struct_cave->music = sfMusic_createFromFile("Music/cave_water.ogg");
    struct_cave->music_fight = sfMusic_createFromFile("Music/tambour.ogg");
    sfMusic_setVolume(struct_cave->music_fight, 5);
    struct_cave->sprite_bu = sfSprite_create();
    struct_cave->text_bu = sfTexture_createFromFile("Image/sp_owto.png", NULL);
    sfSprite_setTexture(struct_cave->sprite_bu, struct_cave->text_bu, sfTrue);
    sfSprite_setPosition(struct_cave->sprite_bu , (sfVector2f) {0, 0});

    struct_cave->healb = 0;
    struct_cave->go_in = 0;
    struct_cave->nb_touch = 0;
    struct_cave->fig_int = 0;
    struct_cave->up = 0;
    struct_cave->down = 0;
    struct_cave->right = 0;
    struct_cave->left = 0;
    struct_cave->need2fight = 0;
    return struct_cave;
}

s_mob_t *movement_mob(s_mob_t *s_mob, sfRenderWindow* window)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(s_mob->clock_mob)) > 150) {
        s_mob->rect_mob.left += 50;
        if (s_mob->rect_mob.left >= 150) s_mob->rect_mob.left = 0;
        sfClock_restart(s_mob->clock_mob);
    }
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(s_mob->clock_mov)) <= 1000) {
        sfSprite_setTexture(s_mob->sprite_mob, s_mob->text_mob_l, sfTrue);
        s_mob->pos_mob.x -= s_mob->mov_mob;
    }
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(s_mob->clock_mov)) >= 1000) {
        sfSprite_setTexture(s_mob->sprite_mob, s_mob->text_mob_r, sfTrue);
         s_mob->pos_mob.x += s_mob->mov_mob;
    }
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(s_mob->clock_mov)) > 2000)
         sfClock_restart(s_mob->clock_mov);
    if (s_mob->pos_mob.x > 1770 || s_mob->pos_mob.x < 825)
        s_mob->pos_mob.x = 1450;
    sfSprite_setPosition(s_mob->sprite_mob ,s_mob->pos_mob);
    sfSprite_setTextureRect(s_mob->sprite_mob, s_mob->rect_mob);
    sfRenderWindow_drawSprite(window, s_mob->sprite_mob, NULL);
    return s_mob;
}

s_cave_font_t *init_font()
{
    s_cave_font_t *s_cav2 = malloc(sizeof(s_cave_font_t));

    s_cav2->text_l = sfTexture_createFromFile("Image/heal.png", NULL);
    s_cav2->sprite_l = sfSprite_create();
    s_cav2->rect_l.height = 112;
    s_cav2->rect_l.width = 584;
    s_cav2->rect_l.top = 0;
    s_cav2->rect_l.left = 0;
    sfSprite_setTexture(s_cav2->sprite_l, s_cav2->text_l, sfTrue);
    sfSprite_setTextureRect(s_cav2->sprite_l, s_cav2->rect_l);
    s_cav2->pos_l.x = 50;
    s_cav2->pos_l.y = 500;
    sfSprite_setPosition(s_cav2->sprite_l, s_cav2->pos_l);

    s_cav2->text_l2 = sfTexture_createFromFile("Image/barhealus.png", NULL);
    s_cav2->sprite_l2 = sfSprite_create();
    s_cav2->rect_l2.height = 112;
    s_cav2->rect_l2.width = 584;
    s_cav2->rect_l2.top = 0;
    s_cav2->rect_l2.left = 0;
    sfSprite_setTexture(s_cav2->sprite_l2, s_cav2->text_l2, sfTrue);
    sfSprite_setTextureRect(s_cav2->sprite_l2, s_cav2->rect_l2);
    s_cav2->pos_l2.x = 800;
    s_cav2->pos_l2.y = 500;
    sfSprite_setPosition(s_cav2->sprite_l2, s_cav2->pos_l2);

    s_cav2->pos_vs.x = 10;
    s_cav2->pos_vs.y = 30;
    s_cav2->text_vs = sfTexture_createFromFile("Image/vs.png", NULL);
    s_cav2->text_vs_red = sfTexture_createFromFile("Image/vs_red.png", NULL);
    s_cav2->sprite_vs = sfSprite_create();
    sfSprite_setTexture(s_cav2->sprite_vs, s_cav2->text_vs, sfTrue);
    sfSprite_setPosition(s_cav2->sprite_vs , s_cav2->pos_vs);
    s_cav2->nb = 0;

    s_cav2->pos_1c.x = 1600;
    s_cav2->pos_1c.y = 800;
    s_cav2->text_1c = sfTexture_createFromFile("Image/+1key.png", NULL);
    s_cav2->sprite_1c = sfSprite_create();
    sfSprite_setTexture(s_cav2->sprite_1c, s_cav2->text_1c, sfTrue);
    sfSprite_setPosition(s_cav2->sprite_1c , s_cav2->pos_1c);
    return s_cav2;
}

s_fcave_t *init_fcave()
{
    s_fcave_t *s_cave = malloc(sizeof(s_fcave_t));

    s_cave->pos_f.x = - 100;
    s_cave->pos_f.y = - 100;
    s_cave->font_fight = sfFont_createFromFile("Font/destroy.ttf");
    s_cave->texte_fight = sfText_create();
    sfText_setString(s_cave->texte_fight, "F");
    sfText_setFont(s_cave->texte_fight, s_cave->font_fight);
    sfText_setCharacterSize(s_cave->texte_fight, 50);
    sfText_setPosition(s_cave->texte_fight, s_cave->pos_f);
    s_cave->next = NULL;
    return s_cave;
}

s_leave_t *init_leave()
{
    s_leave_t *s_leave = malloc(sizeof(s_leave_t));
    s_leave->text_leave = sfTexture_createFromFile("Image/leavefight.png", NULL);
    s_leave->sprite_leave = sfSprite_create();
    sfSprite_setTexture(s_leave->sprite_leave, s_leave->text_leave, sfTrue);
    sfSprite_setPosition(s_leave->sprite_leave , (sfVector2f) {0, 0});
    return s_leave;
}

void add_nodes_cave(s_fcave_t *s_cave)
{
    s_fcave_t *tmp = s_cave;
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = malloc(sizeof(s_fcave_t));

    tmp->next->pos_f.x = generaterandom(1800, 100);
    tmp->next->pos_f.y = generaterandom(700, 100);
    tmp->next->font_fight = sfFont_createFromFile("Font/destroy.ttf");
    tmp->next->texte_fight = sfText_create();
    sfText_setString(tmp->next->texte_fight, "F");
    sfText_setFont(tmp->next->texte_fight, tmp->next->font_fight);
    sfText_setCharacterSize(tmp->next->texte_fight, 50);
    sfText_setPosition(tmp->next->texte_fight, tmp->pos_f);

    tmp->next->next = NULL;
}

void print_thef(s_fcave_t *s_cave, sfRenderWindow* window)
{
    s_fcave_t *tmp = s_cave;
    for (; tmp; tmp = tmp->next) {
        if (tmp->pos_f.y > -100) tmp->pos_f.y -= 7;
        sfRenderWindow_drawText(window, tmp->texte_fight, NULL);
        sfText_setPosition(tmp->texte_fight, tmp->pos_f);
    }
}

s_my_cave_t *movement_perso_cc(s_my_cave_t *struct_cave, s_mob_t *s_mob)
{
    if (struct_cave->up == 1 && struct_cave->pos_cave.y < 880) {
        struct_cave->pos_cave.y += 15;
        s_mob->pos_mob.y += 15;
    }
    if (struct_cave->down == 1 && struct_cave->pos_cave.y >= 300) {
        struct_cave->pos_cave.y -= 15;
        s_mob->pos_mob.y -= 15;
    }
    if (struct_cave->right == 1 && struct_cave->pos_cave.x > 925) {
        struct_cave->pos_cave.x -= 15;
        s_mob->pos_mob.x -= 15;
    }
    if (struct_cave->left == 1 && struct_cave->pos_cave.x < 1570) {
        struct_cave->pos_cave.x += 15;
        s_mob->pos_mob.x += 15;
    }
    sfSprite_setPosition(s_mob->sprite_mob ,s_mob->pos_mob);
    struct_cave->up = 0;
    struct_cave->right = 0;
    struct_cave->left = 0;
    struct_cave->down = 0;
    return struct_cave;
}

int fight(sfRenderWindow* window, s_my_cave_t *struct_cave, s_mob_t *s_mob, s_cave_font_t *s_font, s_menu_game_t *struct_menu, int supp, s_perso_t *s_perso, s_life_t *s_life)
{
    if (struct_cave->pos_cave.y >= 730 && struct_cave->go_in == 0) {
        struct_cave->fig_int = 1;
        struct_cave->go_in = 1;
        struct_cave->healb = 1;
        s_mob->mov_mob = 2;
        sfClock_restart(struct_cave->fight_clock);
        sfClock_restart(s_mob->clock_heal);
    }
    if (struct_cave->healb == 1) {
        sfRenderWindow_drawSprite(window, s_font->sprite_l, NULL);
        sfRenderWindow_drawSprite(window, s_font->sprite_l2, NULL);
        sfRenderWindow_drawSprite(window, s_font->sprite_vs, NULL);
    }
    if ((sfTime_asMilliseconds(sfClock_getElapsedTime(s_mob->clock_heal)) >= 1000) && struct_cave->go_in == 1 && supp < 8) {
        sfSprite_setTexture(s_font->sprite_vs, s_font->text_vs, sfTrue);
        s_font->rect_l2.width -= 73;
        sfSprite_setTextureRect(s_font->sprite_l2, s_font->rect_l2);
        sfClock_restart(s_mob->clock_heal);
        s_perso->less_hp++;
        s_life->rect.width -= 73;
        sfSprite_setTextureRect(s_life->sprite_life, s_life->rect);
    }

    if (struct_cave->fig_int == 1) {
        if ((sfTime_asSeconds(sfClock_getElapsedTime(struct_cave->fight_clock)) > 8) && supp < 8) {
            if (struct_menu->music_state == 1 && struct_menu->music_onoff == 0) {
                sfMusic_stop(struct_cave->music_fight);
                sfMusic_destroy(struct_cave->music);
            }
            my_game(struct_menu, window);
            return 12;
        }
        if (((sfTime_asSeconds(sfClock_getElapsedTime(struct_cave->fight_clock)) > 8) && supp >= 8)) {
            if (struct_menu->music_state == 1 && struct_menu->music_onoff == 0)
                sfMusic_stop(struct_cave->music_fight);
            s_mob->pos_mob.y = - 1000;
            s_font->pos_l2.y = - 1000;
            s_font->pos_l.y = - 1000;
            s_font->pos_vs.y = - 1000;
            sfSprite_setPosition(s_font->sprite_vs , s_font->pos_vs);
            sfSprite_setPosition(s_font->sprite_l2 , s_font->pos_l2);
            sfSprite_setPosition(s_font->sprite_l , s_font->pos_l);
            struct_cave->need2fight = 1;
        }
    }
    return 0;
}

void print_inv(sfRenderWindow* window, s_perso_t *s_perso, int invent_int, s_inventory_t *s_invent, s_life_t *s_life)
{
    if (invent_int == 1) {
        if (s_perso->object == 1 && s_perso->int_chest == 0)
            sfSprite_setTexture(s_invent->sprite_invent, s_invent->text_invent_key, sfTrue);
        sfRenderWindow_drawSprite(window, s_invent->sprite_invent, NULL);
        if (s_perso->next->int_chest == 1) {
            sfRenderWindow_drawSprite(window, s_invent->sprite_potion, NULL);
        }
        if (s_perso->state_kit == 1)
            sfRenderWindow_drawSprite(window, s_invent->sprite_sword, NULL);
        sfRenderWindow_drawSprite(window, s_life->sprite_life, NULL);
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(s_perso->next->player_clock)) > 200) {
            s_perso->next->player_rect.left += (855 / 3);
            if (s_perso->next->player_rect.left >= 855)
                s_perso->next->player_rect.left = 0;
            sfClock_restart(s_perso->next->player_clock);
        }
        if (s_perso->left == 1)
            sfSprite_setTexture(s_perso->next->sprite_perso, s_perso->next->text_perso_l, sfTrue);
        if (s_perso->right == 1)
            sfSprite_setTexture(s_perso->next->sprite_perso, s_perso->next->text_perso, sfTrue);
        if (s_perso->up == 1)
            sfSprite_setTexture(s_perso->next->sprite_perso, s_perso->next->text_perso_do, sfTrue);
        if (s_perso->down == 1)
            sfSprite_setTexture(s_perso->next->sprite_perso, s_perso->next->text_perso_up, sfTrue);
        sfSprite_setTextureRect(s_perso->next->sprite_perso, s_perso->next->player_rect);
        sfSprite_setPosition(s_perso->next->sprite_perso ,s_perso->next->pos_perso);
        sfRenderWindow_drawSprite(window, s_perso->next->sprite_perso, NULL);
    }
    s_perso->up = 0;
    s_perso->right = 0;
    s_perso->left = 0;
    s_perso->down = 0;
}

int fct_leave(sfRenderWindow* window, s_leave_t *s_leave, s_my_cave_t *s_cave, s_cursor_t *cursor)
{
    int ret = 0;
    while (sfRenderWindow_isOpen(window)) {
        sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
        while (sfRenderWindow_pollEvent(window, &s_cave->event_gc)) {
            if (s_cave->event_gc.type == sfEvtClosed) {
                sfRenderWindow_close(window);
                return 12;
            }
            if (s_cave->event_gc.type == sfEvtMouseMoved) {
                sfVector2f cursor1 = sourissprite(sfMouse_getPositionRenderWindow(window));
                sfSprite_setPosition(cursor->cursorsprite, cursor1);
            }
            if ((sfMouse_isButtonPressed(sfMouseLeft)) && mouse.x > 1120 && mouse.x < 1380 && mouse.y > 860 && mouse.y < 990) {
                ret = 1;
                return ret;
            }
            if ((sfMouse_isButtonPressed(sfMouseLeft)) && mouse.x > 1320 && mouse.x < 1680 && mouse.y > 860 && mouse.y < 990) {
                ret = 0;
                return ret;
            }
        }
        sfRenderWindow_drawSprite(window, cursor->cursorsprite, NULL);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, s_leave->sprite_leave, NULL);
    }
    return 12;
}

s_perso_t *cave(sfRenderWindow* window, s_perso_t *s_perso, s_menu_game_t *struct_menu, s_inventory_t *s_invent)
{
    s_my_cave_t *struct_cave = init_cave();
    s_cursor_t *cursor = init_cursor();
    s_mob_t *s_mob = init_mob();
    s_cave_font_t *s_font = init_font();
    s_fcave_t *s_fcave = init_fcave();
    s_leave_t *s_leave = init_leave();
    s_life_t *s_life = init_life();
    s_perso->pos_perso.x = 1555;
    s_perso->pos_perso.y = 900;
    sfClock *red = sfClock_create();
    sfClock *invent_clock = sfClock_create();

    if (struct_menu->music_state == 1 && struct_menu->music_onoff == 0) {
        sfMusic_setLoop(struct_cave->music, sfTrue);
        sfMusic_play(struct_cave->music);
        sfMusic_setVolume(struct_cave->music, 20);
    }
    sfClock_restart(s_mob->clock_mov);
    sfClock_restart(struct_cave->cave_horloge);
    int supp = 0, bubble = 0, fight_go = 0, invent_int = 0, goin = 0, attak = 6;
    if (s_perso->state_kit == 1) attak = 4;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &struct_cave->event_gc)) {
            if (struct_cave->event_gc.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (struct_cave->event_gc.type == sfEvtMouseMoved) {
                sfVector2f cursor1 = sourissprite(sfMouse_getPositionRenderWindow(window));
                sfSprite_setPosition(cursor->cursorsprite, cursor1);
            }
            if ((sfKeyboard_isKeyPressed(sfKeyF) && sfTime_asMilliseconds(sfClock_getElapsedTime(struct_cave->tap)) > 80) && fight_go != 0 && supp < 8) {
                struct_cave->nb_touch++;
                s_font->nb++;
                if (s_font->nb % attak == 0 && supp < 8) {
                    s_font->rect_l.width -= 73;
                    supp++;
                    s_perso->our_life = supp;
                    sfSprite_setTextureRect(s_font->sprite_l, s_font->rect_l);
                }
                sfClock_restart(red);
                sfClock_restart(struct_cave->tap);
                add_nodes_cave(s_fcave);
            }
            if (sfKeyboard_isKeyPressed(sfKeyReturn)) bubble++;
            if (sfKeyboard_isKeyPressed(sfKeyRight)) {
                sfSprite_setTexture(s_perso->sprite_perso, s_perso->text_perso, sfTrue);
                struct_cave->right = 1;
                s_perso->right = 1;
            } else if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
                sfSprite_setTexture(s_perso->sprite_perso, s_perso->text_perso_l, sfTrue);
                struct_cave->left = 1;
                s_perso->left = 1;
            }
            if (sfKeyboard_isKeyPressed(sfKeyUp)) {
                sfSprite_setTexture(s_perso->sprite_perso, s_perso->text_perso_do, sfTrue);
                struct_cave->up = 1;
                s_perso->up = 1;
            } else if (sfKeyboard_isKeyPressed(sfKeyDown)) {
                sfSprite_setTexture(s_perso->sprite_perso, s_perso->text_perso_up, sfTrue);
                struct_cave->down = 1;
                s_perso->down = 1;
            }
            if ((sfKeyboard_isKeyPressed(sfKeyTab) && invent_int == 1) && sfTime_asMilliseconds(sfClock_getElapsedTime(invent_clock)) > 50) {
                invent_int = 0;
                sfClock_restart(invent_clock);
            } else if ((sfKeyboard_isKeyPressed(sfKeyTab) && invent_int == 0) && sfTime_asMilliseconds(sfClock_getElapsedTime(invent_clock)) > 50) {
                invent_int = 1;
                sfClock_restart(invent_clock);
            }
        }
        if (sfKeyboard_isKeyPressed(sfKeyR) && invent_int == 1 && s_perso->next->int_chest == 1) {
            s_life->rect.width = 584;
            sfSprite_setTextureRect(s_life->sprite_life, s_life->rect);
            s_perso->pos_popo.x = s_perso->pos_perso.x;
            s_perso->pos_popo.y = s_perso->pos_perso.y - 10;
            sfSprite_setPosition(s_perso->sprite_popo , s_perso->pos_popo);
            sfClock_restart(s_perso->clock_popo);
            s_perso->next->int_chest = 0;
            s_perso->rect_popo.left = 0;
            s_perso->less_hp = 0;
        }
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(struct_cave->tap)) < 80) {
            sfSprite_setTexture(s_font->sprite_vs, s_font->text_vs_red, sfTrue);
            s_font->pos_l.y = 495;
        } else {
            sfSprite_setTexture(s_font->sprite_vs, s_font->text_vs, sfTrue);
            s_font->pos_l.y = 500;
        }
        sfSprite_setPosition(s_font->sprite_l, s_font->pos_l);

        if (struct_cave->pos_cave.y >= 700 && struct_cave->pos_cave.y <= 800)
            sfRenderWindow_drawSprite(window, struct_cave->sprite_bubble_gc, NULL);
        if ((struct_cave->pos_cave.y >= 790) && struct_cave->need2fight == 1)
            s_perso->object = 1;
        if (struct_cave->pos_cave.y >= 680) fight_go = 1;
        if (struct_cave->pos_cave.y >= 480) bubble = 1;
        struct_cave = movement_perso_cc(struct_cave, s_mob);
        if (((struct_cave->pos_cave.y <= 300) && struct_cave->pos_cave.x >= 1000 && struct_cave->pos_cave.x <= 1100) && sfTime_asSeconds(sfClock_getElapsedTime(struct_cave->cave_horloge)) > 1) {
            sfSprite_destroy(struct_cave->sprite_bg_gc);
            s_perso->ret = 1;
            if (struct_menu->music_state == 1 && struct_menu->music_onoff == 0) {
            sfMusic_stop(struct_cave->music);
            sfMusic_stop(struct_cave->music_fight);
            }
            return s_perso;
        }
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(s_perso->player_clock)) > 200) {
            s_perso->player_rect.left += (288 / 3);
            if (s_perso->player_rect.left >= 288) s_perso->player_rect.left = 0;
            sfClock_restart(s_perso->player_clock);
        }
        s_mob = movement_mob(s_mob, window);
        if (fight(window, struct_cave, s_mob, s_font, struct_menu, supp, s_perso, s_life) == 12) {
            sfSprite_destroy(struct_cave->sprite_bg_gc);
            sfRenderWindow_close(window);
            if (struct_menu->music_state == 1 && struct_menu->music_onoff == 0) {
            sfMusic_stop(struct_cave->music);
            sfMusic_stop(struct_cave->music_fight);
            }
            return s_perso;
        }
        if (sfKeyboard_isKeyPressed(sfKeyR) && invent_int == 1 && s_perso->next->int_chest == 1) {
            s_life->rect.width = 584;
            sfSprite_setTextureRect(s_life->sprite_life, s_life->rect);
        }
        if (struct_cave->pos_cave.y >= 350 && bubble == 0 && struct_cave->pos_cave.y <= 480)
            sfRenderWindow_drawSprite(window, struct_cave->sprite_bu, NULL);
        if (struct_cave->pos_cave.y >= 550 && goin == 0) {
            goin++;
            if (fct_leave(window, s_leave, struct_cave, cursor) == 0) {
                sfSprite_destroy(struct_cave->sprite_bg_gc);
                s_perso->ret = 1;
                return s_perso;
            }
            else if (fct_leave(window, s_leave, struct_cave, cursor) == 12) {
                sfRenderWindow_close(window);
                return s_perso;
            }
            else {
                if (struct_menu->music_state == 1 && struct_menu->music_onoff == 0) {
                    sfMusic_play(struct_cave->music_fight);
                }
            }
        }
        sfRenderWindow_drawSprite(window, cursor->cursorsprite, NULL);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, struct_cave->sprite_bg_gc, NULL);
        sfSprite_setPosition(s_perso->sprite_perso ,s_perso->pos_perso);
        sfSprite_setTextureRect(s_perso->sprite_perso, s_perso->player_rect);
        sfRenderWindow_drawSprite(window, s_perso->sprite_perso, NULL);
        sfSprite_setPosition(struct_cave->sprite_bg_gc ,struct_cave->pos_cave);
        sfRenderWindow_drawText(window, s_perso->texte_obj, NULL);
        sfRenderWindow_drawText(window, s_perso->texte_int, NULL);
        sfText_setString(s_perso->texte_int, nb_tochar(s_perso->object));
        print_thef(s_fcave, window);
        print_inv(window, s_perso, invent_int, s_invent, s_life);
        if (s_font->pos_1c.y > - 100 && s_perso->object == 1) {
            sfRenderWindow_drawSprite(window, s_font->sprite_1c, NULL);
            sfSprite_setPosition(s_font->sprite_1c ,s_font->pos_1c);
            s_font->pos_1c.y -= 1;
        }
        draw_popo(window, s_perso);
    }
    sfSprite_destroy(struct_cave->sprite_bg_gc);
    sfMusic_stop(struct_cave->music);
    if (struct_menu->music_state == 1 && struct_menu->music_onoff == 0)
        sfMusic_destroy(struct_cave->music);

    return s_perso;
}