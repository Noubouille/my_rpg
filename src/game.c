/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** game
*/

#include "../my.h"

s_my_game_t *init_g_struct(void)
{
    s_my_game_t *struct_game = malloc(sizeof(s_my_game_t));
    struct_game->text_bg_g = sfTexture_createFromFile("Image/map.png", NULL);
    struct_game->sprite_bg_g = sfSprite_create();
    sfSprite_setTexture(struct_game->sprite_bg_g, struct_game->text_bg_g, sfTrue);
    struct_game->click_g = sfMusic_createFromFile("Music/click_music.ogg");
    struct_game->pause = 0;
    return struct_game;
}

s_object_t *init_objects(void)
{
    s_object_t *struct_object = malloc(sizeof(s_object_t));

    struct_object->text_tree = sfTexture_createFromFile("Image/tree.png", NULL);
    struct_object->sprite_tree = sfSprite_create();
    struct_object->tree_rect.height = 128;
    struct_object->tree_rect.width = 1024 / 8;
    sfSprite_setTexture(struct_object->sprite_tree, struct_object->text_tree, sfTrue);
    sfSprite_setTextureRect(struct_object->sprite_tree, struct_object->tree_rect);
    sfSprite_setPosition(struct_object->sprite_tree ,(sfVector2f) {920, 895});
    struct_object->horloge_tree = sfClock_create();

    struct_object->text_bubble = sfTexture_createFromFile("Image/bubble.png", NULL);
    struct_object->sprite_bubble = sfSprite_create();
    sfSprite_setTexture(struct_object->sprite_bubble, struct_object->text_bubble, sfTrue);
    sfSprite_setPosition(struct_object->sprite_bubble ,(sfVector2f) {1805, 135});
    return struct_object;
}

s_perso_t *init_perso(void)
{
    s_perso_t *struct_perso = malloc(sizeof(s_perso_t));
    struct_perso->up = 0;
    struct_perso->down = 0;
    struct_perso->left = 0;
    struct_perso->right = 0;
    struct_perso->pos_perso.x = 20;
    struct_perso->pos_perso.y = 815;
    struct_perso->player_clock = sfClock_create();
    struct_perso->text_perso = sfTexture_createFromFile("Image/vamp.png", NULL);
    struct_perso->text_perso_l = sfTexture_createFromFile("Image/vamp_l.png", NULL);
    struct_perso->text_perso_up = sfTexture_createFromFile("Image/vamp_up.png", NULL);
    struct_perso->text_perso_do = sfTexture_createFromFile("Image/vamp_do.png", NULL);
    struct_perso->sprite_perso = sfSprite_create();
    sfSprite_setTexture(struct_perso->sprite_perso, struct_perso->text_perso, sfTrue);
    struct_perso->player_rect.height = 48;
    struct_perso->player_rect.width = 288 / 3;
    sfSprite_setTextureRect(struct_perso->sprite_perso, struct_perso->player_rect);
    sfSprite_setPosition(struct_perso->sprite_perso ,struct_perso->pos_perso);
    //la maison
    struct_perso->sprite_house1 = sfSprite_create();
    sfSprite_setPosition(struct_perso->sprite_house1 , (sfVector2f) {1500, 725});

    struct_perso->font_obj = sfFont_createFromFile("Font/destroy.ttf");
    struct_perso->texte_obj = sfText_create();
    struct_perso->texte_int = sfText_create();
    sfText_setString(struct_perso->texte_obj, "OBJECT : ");
    struct_perso->object = 0;
    struct_perso->ret = 0;
    sfText_setString(struct_perso->texte_int, nb_tochar(struct_perso->object));
    sfText_setFont(struct_perso->texte_obj, struct_perso->font_obj);
    sfText_setFont(struct_perso->texte_int, struct_perso->font_obj);
    sfText_setCharacterSize(struct_perso->texte_obj, 50);
    sfText_setCharacterSize(struct_perso->texte_int, 50);
    sfText_setPosition(struct_perso->texte_obj, (sfVector2f) {1400, 0});
    sfText_setPosition(struct_perso->texte_int, (sfVector2f) {1750, 0});

    return struct_perso;
}

s_inventory_t *init_invent()
{
    s_inventory_t *s_invent = malloc(sizeof(s_inventory_t));
    s_invent->text_invent = sfTexture_createFromFile("Image/invent.png", NULL);
    s_invent->sprite_invent = sfSprite_create();
    sfSprite_setTexture(s_invent->sprite_invent, s_invent->text_invent, sfTrue);
    sfSprite_setPosition(s_invent->sprite_invent, (sfVector2f) {100, 100});
    return s_invent;
}

s_perso_t *poss_movement1(s_perso_t *perso)
{
    if (((perso->pos_perso.y >= sfSprite_getPosition(perso->sprite_house1).y && perso->pos_perso.y <= sfSprite_getPosition(perso->sprite_house1).y + 120) &&
        (perso->pos_perso.x >= sfSprite_getPosition(perso->sprite_house1).x && perso->pos_perso.x < sfSprite_getPosition(perso->sprite_house1).x + 170))) {
        perso->pos_perso.y = 800;
        perso->pos_perso.x = 1370;
    }
    else if ((perso->pos_perso.y >= 675 - 30 && perso->pos_perso.y <= 685) && (perso->pos_perso.x <= 1320)) {
        perso->pos_perso.y += 15;
    }
    else if ((perso->pos_perso.y >= 675 - 55 && perso->pos_perso.y <= 630) && (perso->pos_perso.x >= 1400)) {
        perso->pos_perso.y += 15;
    }
    else
        perso->pos_perso.y -= 15;
    return perso;
}

s_perso_t *poss_movement2(s_perso_t *perso)
{
    if (((perso->pos_perso.y >= sfSprite_getPosition(perso->sprite_house1).y && perso->pos_perso.y <= sfSprite_getPosition(perso->sprite_house1).y + 120) &&
        (perso->pos_perso.x >= sfSprite_getPosition(perso->sprite_house1).x && perso->pos_perso.x < sfSprite_getPosition(perso->sprite_house1).x + 170))) {
        perso->pos_perso.y = 800;
        perso->pos_perso.x = 1370;
    }
    else if ((perso->pos_perso.y >= 675 - 65 && perso->pos_perso.y <= 670) && (perso->pos_perso.x <= 1320)) {
        perso->pos_perso.y -= 15;
    }
    else if ((perso->pos_perso.y >= 675 - 100 && perso->pos_perso.y <= 590) && (perso->pos_perso.x >= 1400)) {
        perso->pos_perso.y -= 15;
    }
    else
        perso->pos_perso.y += 15;
    return perso;
}

s_perso_t *poss_movement3(s_perso_t *perso)
{
    if (((perso->pos_perso.y >= sfSprite_getPosition(perso->sprite_house1).y && perso->pos_perso.y <= sfSprite_getPosition(perso->sprite_house1).y + 120) &&
        (perso->pos_perso.x >= sfSprite_getPosition(perso->sprite_house1).x && perso->pos_perso.x < sfSprite_getPosition(perso->sprite_house1).x + 170))) {
        perso->pos_perso.y = 800;
        perso->pos_perso.x = 1370;
    }
    else
        perso->pos_perso.x += 15;
    return perso;
}

s_perso_t *poss_movement4(s_perso_t *perso)
{
    if (((perso->pos_perso.y >= sfSprite_getPosition(perso->sprite_house1).y && perso->pos_perso.y <= sfSprite_getPosition(perso->sprite_house1).y + 120) &&
        (perso->pos_perso.x >= sfSprite_getPosition(perso->sprite_house1).x && perso->pos_perso.x < sfSprite_getPosition(perso->sprite_house1).x + 170))) {
            perso->pos_perso.y = 800;
            perso->pos_perso.x = 1370;
    }
    else
        perso->pos_perso.x -= 15;
    return perso;
}

s_perso_t *movement_perso(s_perso_t *perso)
{
    if (perso->up == 1 && perso->pos_perso.y >= 100) {
        perso = poss_movement1(perso);
    }
    if (perso->down == 1 && perso->pos_perso.y < 955) {
        perso = poss_movement2(perso);
    }
    if (perso->right == 1 && perso->pos_perso.x < 1850) {
        perso = poss_movement3(perso);
    }
    if (perso->left == 1 && perso->pos_perso.x > 0) {
        perso = poss_movement4(perso);
    }
    perso->up = 0;
    perso->right = 0;
    perso->left = 0;
    perso->down = 0;
    return perso;
}

void print_bubble(s_object_t *s_object, s_perso_t *s_perso, sfRenderWindow* window)
{
    int i = 0;
    if (s_perso->pos_perso.x >= 1600 && s_perso->pos_perso.y <= 350) {
        i = 1;
    } else {
        i = 0;
    }
    if (i == 1) {
        sfRenderWindow_drawSprite(window, s_object->sprite_bubble, NULL);
    }
}

s_my_game_t *print_inventory(sfRenderWindow* window, s_my_game_t *struct_game, s_perso_t *s_perso, s_cursor_t *cursor, s_object_t *s_object)
{
    while (sfRenderWindow_isOpen(window) && struct_game->pause == 1) {
        sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
        while (sfRenderWindow_pollEvent(window, &struct_game->event_g)) {
            if (struct_game->event_g.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (struct_game->event_g.type == sfEvtMouseMoved) {
                sfVector2f cursor1 = sourissprite(sfMouse_getPositionRenderWindow(window));
                sfSprite_setPosition(cursor->cursorsprite, cursor1);
            }
            if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
                struct_game->pause = 0;
                return struct_game;
            }
        }
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(s_perso->player_clock)) > 200) {
            s_perso->player_rect.left += (288 / 3);
            if (s_perso->player_rect.left >= 288) s_perso->player_rect.left = 0;
            sfClock_restart(s_perso->player_clock);
        }
            sfRenderWindow_drawSprite(window, cursor->cursorsprite, NULL);
            sfRenderWindow_display(window);
            sfRenderWindow_clear(window, sfBlack);
            sfRenderWindow_drawSprite(window , struct_game->sprite_bg_g, NULL);

            sfSprite_setTextureRect(s_perso->sprite_perso, s_perso->player_rect);
            sfSprite_setPosition(s_perso->sprite_perso ,s_perso->pos_perso);
            sfRenderWindow_drawSprite(window, s_perso->sprite_perso, NULL);
            //l'arbre en rect
            if (sfTime_asMilliseconds(sfClock_getElapsedTime(s_object->horloge_tree)) > 200) {
                s_object->tree_rect.left += (1024 / 8);
                if (s_object->tree_rect.left >= 1024) s_object->tree_rect.left = 0;
                sfClock_restart(s_object->horloge_tree);
            }
        sfSprite_setTextureRect(s_object->sprite_tree, s_object->tree_rect);
        sfRenderWindow_drawSprite(window, s_object->sprite_tree, NULL);
    }
    return struct_game;
}

int my_game(sfRenderWindow* window)
{
    s_my_game_t *struct_game = init_g_struct();
    s_cursor_t *cursor = init_cursor();
    s_perso_t *s_perso = init_perso();
    s_object_t *s_object = init_objects();
    s_inventory_t *s_invent = init_invent();
    struct_game->music = sfMusic_createFromFile("Music/game_music.ogg");
    sfMusic_setLoop(struct_game->music, sfTrue);
    sfMusic_play(struct_game->music);
    sfMusic_setVolume(struct_game->music, 20);
    sfClock *pause_clock = sfClock_create();
    sfClock *invent_clock = sfClock_create();
    int invent_int = 0;

    while (sfRenderWindow_isOpen(window)) {
        sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
        while (sfRenderWindow_pollEvent(window, &struct_game->event_g)) {
            if (struct_game->event_g.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (struct_game->event_g.type == sfEvtMouseMoved) {
                sfVector2f cursor1 = sourissprite(sfMouse_getPositionRenderWindow(window));
                sfSprite_setPosition(cursor->cursorsprite, cursor1);
            }
            if (sfKeyboard_isKeyPressed(sfKeyEscape) && sfTime_asMilliseconds(sfClock_getElapsedTime(pause_clock)) > 100) {
                struct_game->pause = 1;
            }
            if ((sfKeyboard_isKeyPressed(sfKeyTab) && invent_int == 1) && sfTime_asMilliseconds(sfClock_getElapsedTime(invent_clock)) > 50) {
                invent_int = 0;
                sfClock_restart(invent_clock);
            }
            else if ((sfKeyboard_isKeyPressed(sfKeyTab) && invent_int == 0) && sfTime_asMilliseconds(sfClock_getElapsedTime(invent_clock)) > 50) {
                invent_int = 1;
                sfClock_restart(invent_clock);
            }
            if (sfMouse_isButtonPressed(sfMouseLeft))
                printf("x:%d\n, y:%d\n", mouse.x, mouse.y);
            if (sfKeyboard_isKeyPressed(sfKeyRight)) {
                sfSprite_setTexture(s_perso->sprite_perso, s_perso->text_perso, sfTrue);
                s_perso->right = 1;
            }
            else if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
                sfSprite_setTexture(s_perso->sprite_perso, s_perso->text_perso_l, sfTrue);
                s_perso->left = 1;
            }
            if (sfKeyboard_isKeyPressed(sfKeyUp)) {
                sfSprite_setTexture(s_perso->sprite_perso, s_perso->text_perso_do, sfTrue);
                s_perso->up = 1;
            }
            else if (sfKeyboard_isKeyPressed(sfKeyDown)) {
                sfSprite_setTexture(s_perso->sprite_perso, s_perso->text_perso_up, sfTrue);
                s_perso->down = 1;
            }
        }
        if (struct_game->pause == 1) {
            struct_game = print_inventory(window, struct_game, s_perso, cursor, s_object);
            sfClock_restart(pause_clock);
        }
        print_bubble(s_object, s_perso, window);
        if ((s_perso->pos_perso.x >= 1720 && s_perso->pos_perso.y <= 230)) {
            s_perso = cave(window, s_perso);
            if (s_perso->ret == 1) {
                s_perso->pos_perso.x = 1715;
                s_perso->pos_perso.y = 300;
            }
            else break;
        }
        // rect du perso
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(s_perso->player_clock)) > 200) {
            s_perso->player_rect.left += (288 / 3);
            if (s_perso->player_rect.left >= 288) s_perso->player_rect.left = 0;
            sfClock_restart(s_perso->player_clock);
        }
        //fin du rect du perso
        s_perso = movement_perso(s_perso);// fait bouger le sprite du perso
        //tous les draws
        sfRenderWindow_drawSprite(window, cursor->cursorsprite, NULL);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window , struct_game->sprite_bg_g, NULL);

        sfSprite_setTextureRect(s_perso->sprite_perso, s_perso->player_rect);
        sfSprite_setPosition(s_perso->sprite_perso ,s_perso->pos_perso);
        sfRenderWindow_drawSprite(window, s_perso->sprite_perso, NULL);
        //l'arbre en rect
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(s_object->horloge_tree)) > 200) {
            s_object->tree_rect.left += (1024 / 8);
            if (s_object->tree_rect.left >= 1024) s_object->tree_rect.left = 0;
            sfClock_restart(s_object->horloge_tree);
        }
        sfSprite_setTextureRect(s_object->sprite_tree, s_object->tree_rect);
        sfRenderWindow_drawSprite(window, s_object->sprite_tree, NULL);
        sfRenderWindow_drawText(window, s_perso->texte_obj, NULL);
        sfRenderWindow_drawText(window, s_perso->texte_int, NULL);
        if (invent_int == 1)
            sfRenderWindow_drawSprite(window, s_invent->sprite_invent, NULL);
    }
    //les destroys
    sfSprite_destroy(cursor->cursorsprite);
    sfSprite_destroy(struct_game->sprite_bg_g);
    sfSprite_destroy(s_perso->sprite_perso);
    sfMusic_destroy(struct_game->click_g);
    sfMusic_destroy(struct_game->music);
    return (0);
}