/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** cave
*/

#include "my.h"

s_mob_t *init_mob()
{
    s_mob_t *s_mob = malloc(sizeof(s_mob_t));
    s_mob->pos_mob.x = 1600;
    s_mob->pos_mob.y = 500;
    s_mob->clock_mob = sfClock_create();
    s_mob->clock_mov = sfClock_create();
    s_mob->sprite_mob = sfSprite_create();
    s_mob->text_mob_l = sfTexture_createFromFile("Image/mouse_l.png", NULL);
    s_mob->text_mob_r = sfTexture_createFromFile("Image/mouse_r.png", NULL);
    sfSprite_setPosition(s_mob->sprite_mob , s_mob->pos_mob);
    s_mob->rect_mob.height = 41;
    s_mob->rect_mob.width = 150 / 3;
    sfSprite_setTexture(s_mob->sprite_mob, s_mob->text_mob_l, sfTrue);
    sfSprite_setTextureRect(s_mob->sprite_mob, s_mob->rect_mob);

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

    struct_cave->text_bubble_gc = sfTexture_createFromFile("Image/bubble_c.png", NULL);
    struct_cave->sprite_bubble_gc = sfSprite_create();
    sfSprite_setTexture(struct_cave->sprite_bubble_gc, struct_cave->text_bubble_gc, sfTrue);
    sfSprite_setPosition(struct_cave->sprite_bubble_gc , (sfVector2f) {1590, 590});

    struct_cave->up = 0;
    struct_cave->down = 0;
    struct_cave->right = 0;
    struct_cave->left = 0;
    return struct_cave;
}

// s_perso_t *movement_perso_c(s_perso_t *perso)
// {
//     if (perso->up == 1 && perso->pos_perso.y >= 350) {
//         perso->pos_perso.y -= 15;
//     }
//     if (perso->down == 1 && perso->pos_perso.y < 936) {
//         perso->pos_perso.y += 15;
//     }
//     if (perso->right == 1 && perso->pos_perso.x < 1700) {
//         perso->pos_perso.x += 15;
//     }
//     if (perso->left == 1 && perso->pos_perso.x > 1100) {
//         perso->pos_perso.x -= 15;
//     }
//     perso->up = 0;
//     perso->right = 0;
//     perso->left = 0;
//     perso->down = 0;
//     return perso;
// }

s_mob_t *movement_mob(s_mob_t *s_mob, sfRenderWindow* window)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(s_mob->clock_mob)) > 150) {
        s_mob->rect_mob.left += (150 / 3);
        if (s_mob->rect_mob.left >= 150) s_mob->rect_mob.left = 0;
        sfClock_restart(s_mob->clock_mob);
    }
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(s_mob->clock_mov)) < 500) {
        sfSprite_setTexture(s_mob->sprite_mob, s_mob->text_mob_l, sfTrue);
        s_mob->pos_mob.x -= 1;
    }
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(s_mob->clock_mov)) > 500)  {
        sfSprite_setTexture(s_mob->sprite_mob, s_mob->text_mob_r, sfTrue);
         s_mob->pos_mob.x += 1;
    }
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(s_mob->clock_mov)) > 1000)
         sfClock_restart(s_mob->clock_mov);
    sfSprite_setPosition(s_mob->sprite_mob ,s_mob->pos_mob);
    sfSprite_setTextureRect(s_mob->sprite_mob, s_mob->rect_mob);
    sfRenderWindow_drawSprite(window, s_mob->sprite_mob, NULL);
    return s_mob;
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

s_perso_t *cave(sfRenderWindow* window, s_perso_t *s_perso)
{
    s_my_cave_t *struct_cave = init_cave();
    s_cursor_t *cursor = init_cursor();
    s_mob_t *s_mob = init_mob();
    s_perso->pos_perso.x = 1555;
    s_perso->pos_perso.y = 900;
    sfClock_restart(struct_cave->cave_horloge);
    while (sfRenderWindow_isOpen(window)) {
        sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
        while (sfRenderWindow_pollEvent(window, &struct_cave->event_gc)) {
            if (struct_cave->event_gc.type == sfEvtClosed)//|| sfKeyboard_isKeyPressed(sfKeyQ))
                sfRenderWindow_close(window);
            if (struct_cave->event_gc.type == sfEvtMouseMoved) {
                sfVector2f cursor1 = sourissprite(sfMouse_getPositionRenderWindow(window));
                sfSprite_setPosition(cursor->cursorsprite, cursor1);
            }
            if (sfKeyboard_isKeyPressed(sfKeyRight)) {
                sfSprite_setTexture(s_perso->sprite_perso, s_perso->text_perso, sfTrue);
                struct_cave->right = 1;
            }
            else if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
                sfSprite_setTexture(s_perso->sprite_perso, s_perso->text_perso_l, sfTrue);
                struct_cave->left = 1;
            }
            if (sfKeyboard_isKeyPressed(sfKeyUp)) {
                sfSprite_setTexture(s_perso->sprite_perso, s_perso->text_perso_do, sfTrue);
                struct_cave->up = 1;
            }
            else if (sfKeyboard_isKeyPressed(sfKeyDown)) {
                sfSprite_setTexture(s_perso->sprite_perso, s_perso->text_perso_up, sfTrue);
                struct_cave->down = 1;
            }
            // if (struct_cave->event_gc.type == sfEvtMouseButtonPressed) {
            //     if ((mouse.x > 1300 && mouse.x < 1500) && (mouse.y > 350 && mouse.y < 500)) {
            //         m = 1;
            //         printf("i am gay online\n");
            //     }
            // }
        }
        if (struct_cave->pos_cave.y >= 700 && struct_cave->pos_cave.y <= 800)
            sfRenderWindow_drawSprite(window, struct_cave->sprite_bubble_gc, NULL);
        if ((struct_cave->pos_cave.y >= 790)) {
            s_perso->object = 1;
        }
        // s_perso = movement_perso_c(s_perso);
        struct_cave = movement_perso_cc(struct_cave, s_mob);
        if (((struct_cave->pos_cave.y <= 300) && struct_cave->pos_cave.x >= 1000 && struct_cave->pos_cave.x <= 1100) && sfTime_asSeconds(sfClock_getElapsedTime(struct_cave->cave_horloge)) > 1) {
            sfSprite_destroy(struct_cave->sprite_bg_gc);
            s_perso->ret = 1;
            return s_perso;
        }
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(s_perso->player_clock)) > 200) {
            s_perso->player_rect.left += (288 / 3);
            if (s_perso->player_rect.left >= 288) s_perso->player_rect.left = 0;
            sfClock_restart(s_perso->player_clock);
        }
        s_mob = movement_mob(s_mob, window);
        //lemob
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
    }
    sfSprite_destroy(struct_cave->sprite_bg_gc);
    return s_perso;
}