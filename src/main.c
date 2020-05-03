/*
** EPITECH PROJECT, 2020
** directory
** File description:
** main
*/

// #include <SFML/Audio.h>
// #include <SFML/Graphics.h>
// #include <stdlib.h>
// #include <SFML/Window/Export.h>
#include "../my.h"

sfVector2f sourissprite(sfVector2i vect2i)
{
    sfVector2f vect2f = {0, 0};
    vect2f.x = vect2i.x;
    vect2f.y = vect2i.y;
    return (vect2f);
}

s_menu_game_t *init_mg_struct(void)
{
    s_menu_game_t *struct_mg = malloc(sizeof(s_menu_game_t));
    struct_mg->text_bg = sfTexture_createFromFile("Image/mg.png", NULL);
    struct_mg->sprite_bg = sfSprite_create();
    sfSprite_setTexture(struct_mg->sprite_bg, struct_mg->text_bg, sfTrue);
    struct_mg->click = sfMusic_createFromFile("Music/click_music.ogg");
    struct_mg->horloge = sfClock_create();
    struct_mg->music_onoff = 0;
    struct_mg->pos_perso.x = 1110;
    struct_mg->pos_perso.y = 815;
    struct_mg->player_clock = sfClock_create();
    struct_mg->text_perso = sfTexture_createFromFile("Image/vamp.png", NULL);
    struct_mg->sprite_perso = sfSprite_create();
    sfSprite_setTexture(struct_mg->sprite_perso, struct_mg->text_perso, sfTrue);

    struct_mg->player_rect.height = 48;
    struct_mg->player_rect.width = 288 / 3;
    struct_mg->player_rect.top = 0;
    struct_mg->player_rect.left = 0;
    sfSprite_setTextureRect(struct_mg->sprite_perso, struct_mg->player_rect);
    sfSprite_setPosition(struct_mg->sprite_perso ,struct_mg->pos_perso);
    return struct_mg;
}

s_cursor_t *init_cursor(void)
{
    s_cursor_t *cursor = malloc(sizeof(s_cursor_t));
    cursor->cursorsprite = sfSprite_create();
    cursor->cursortext = sfTexture_createFromFile("Image/cursordef_menu.png", NULL);
    cursor->curseur_posit.x = 1000;
    cursor->curseur_posit.y = 500;
    sfSprite_setTexture(cursor->cursorsprite, cursor->cursortext, sfTrue);
    sfSprite_setPosition(cursor->cursorsprite, cursor->curseur_posit);
    return cursor;
}

s_button_t *init_button(void)
{
    s_button_t *button = malloc(sizeof(s_button_t));
    button->sprite_button = sfSprite_create();
    button->sprite_button2 = sfSprite_create();
    button->sprite_button3 = sfSprite_create();
    button->text_button = sfTexture_createFromFile("Image/but_play.png", NULL);
    button->text_button2 = sfTexture_createFromFile("Image/but_sett.png", NULL);
    button->text_button3 = sfTexture_createFromFile("Image/but_exit.png", NULL);
    button->pos_button.x = 20;
    button->pos_button.y = 460;
    button->pos_button2.x = 20;
    button->pos_button2.y = 670;
    button->pos_button3.x = 20;
    button->pos_button3.y = 875;
    sfSprite_setTexture(button->sprite_button, button->text_button, sfTrue);
    sfSprite_setTexture(button->sprite_button2, button->text_button2, sfTrue);
    sfSprite_setTexture(button->sprite_button3, button->text_button3, sfTrue);
    sfSprite_setPosition(button->sprite_button, button->pos_button);
    sfSprite_setPosition(button->sprite_button2, button->pos_button2);
    sfSprite_setPosition(button->sprite_button3, button->pos_button3);
    return button;
}

s_set_panel_t *init_panel(void)
{
    s_set_panel_t *setpanel = malloc(sizeof(s_set_panel_t));
    FILE *fp2 = fopen("settings.txt", "r");
    s_menu_game_t *struct_mg = init_mg_struct();
    struct_mg->music_onoff = read_file(fp2);
    setpanel->i = 0;
    setpanel->k = 0;
    setpanel->how_var = 0;
    setpanel->sprite_panel = sfSprite_create();
    setpanel->sprite_audio = sfSprite_create();
    setpanel->sprite_close = sfSprite_create();
    setpanel->sprite_but_howtoplay = sfSprite_create();
    setpanel->sprite_howtoplay = sfSprite_create();
    setpanel->sprite_but_howtoplay_close = sfSprite_create();
    setpanel->text_panel = sfTexture_createFromFile("Image/panel_sett.png", NULL);
    setpanel->text_audio_on = sfTexture_createFromFile("Image/audio_on.png", NULL);
    setpanel->text_audio_off = sfTexture_createFromFile("Image/audio_off.png", NULL);
    setpanel->text_close = sfTexture_createFromFile("Image/quit.png", NULL);
    setpanel->text_howtoplay = sfTexture_createFromFile("Image/howtoplay.png", NULL);
    setpanel->text_but_howtoplay = sfTexture_createFromFile("Image/but_howtoplay.png", NULL);
    setpanel->text_but_howtoplay_close = sfTexture_createFromFile("Image/howtoplay_close.png", NULL);
    setpanel->pos_panel.x = 1370;
    setpanel->pos_panel.y = 30;
    setpanel->pos_audio.x = 1432;
    setpanel->pos_audio.y = 135;
    setpanel->pos_but_howtoplay.x = 1430;
    setpanel->pos_but_howtoplay.y = 350;
    setpanel->pos_howtoplay.x = 0;
    setpanel->pos_howtoplay.y = 0;
    setpanel->pos_close.x = 1430;
    setpanel->pos_close.y = 560;
    setpanel->pos_but_howtoplay_close.x = 1700;
    setpanel->pos_but_howtoplay_close.y = 40;
    setpanel->pos_button_h.x = 20;
    setpanel->pos_button_h.y = 470;
    setpanel->pos_button2_h.x = 20;
    setpanel->pos_button2_h.y = 680;
    setpanel->pos_button3_h.x = 20;
    setpanel->pos_button3_h.y = 885;
    setpanel->pos_audio_h.x = 1432;
    setpanel->pos_audio_h.y = 145;
    setpanel->pos_but_howtoplay_h.x = 1430;
    setpanel->pos_but_howtoplay_h.y = 360;
    setpanel->pos_close_h.x = 1430;
    setpanel->pos_close_h.y = 570;
    sfSprite_setTexture(setpanel->sprite_panel, setpanel->text_panel, sfTrue);
    sfSprite_setPosition(setpanel->sprite_panel, setpanel->pos_panel);
    if (struct_mg->music_onoff == 0) {
        sfSprite_setTexture(setpanel->sprite_audio, setpanel->text_audio_on, sfTrue);
    } else if (struct_mg->music_onoff == 2) {
        sfSprite_setTexture(setpanel->sprite_audio, setpanel->text_audio_off, sfTrue);
    }
    sfSprite_setPosition(setpanel->sprite_audio, setpanel->pos_audio);
    sfSprite_setTexture(setpanel->sprite_close, setpanel->text_close, sfTrue);
    sfSprite_setPosition(setpanel->sprite_close, setpanel->pos_close);
    sfSprite_setTexture(setpanel->sprite_but_howtoplay, setpanel->text_but_howtoplay, sfTrue);
    sfSprite_setPosition(setpanel->sprite_but_howtoplay, setpanel->pos_howtoplay);
    sfSprite_setTexture(setpanel->sprite_howtoplay, setpanel->text_howtoplay, sfTrue);
    sfSprite_setPosition(setpanel->sprite_howtoplay, setpanel->pos_howtoplay);
    sfSprite_setTexture(setpanel->sprite_but_howtoplay_close, setpanel->text_but_howtoplay_close, sfTrue);
    sfSprite_setPosition(setpanel->sprite_but_howtoplay_close, setpanel->pos_but_howtoplay_close);
    return setpanel;
}

int read_file(FILE *fp2)
{
    struct stat oct;
    stat("settings.txt", &oct);
    int size = oct.st_size;
    char *tmp = malloc(sizeof(char) * size);
    int i;
    int egal = 0;
    fread(tmp, size, 1, fp2);
    for (int i = 0; tmp[i]; i++)
        if (tmp[i] == '=') egal++;
    if (egal == 0) return 0;

    for (i = 0; tmp[i] != '=' && (tmp[i] != '\0' || tmp[i] != '\n'); i++);
    i++;
    for (; (tmp[i] < 'a' || tmp[i] > 'z'); i++) {}
        if (tmp[i] == 'o' && tmp[i+1] == 'n') {
            return 0;
        }
        if (tmp[i] == 'o' && tmp[i+1] == 'f' && tmp[i+2] == 'f') {
            return 2;
        }
    return 0;
}

int menu_game(sfRenderWindow* window)
{
    FILE *fp2 = fopen("settings.txt", "r");
    if (fp2 == NULL) return 84;
    s_menu_game_t *struct_mg = init_mg_struct();
    s_cursor_t *cursor = init_cursor();
    s_button_t *button = init_button();
    s_set_panel_t *setpanel = init_panel();
    struct_mg->music_onoff = read_file(fp2);
    struct_mg->music = sfMusic_createFromFile("Music/menu_music.ogg");
    if (struct_mg->music_onoff == 0) {
        sfMusic_setLoop(struct_mg->music, sfTrue);
        sfMusic_play(struct_mg->music);
        sfMusic_setVolume(struct_mg->music, 20);
    }
    int launch_game = 0;
    struct_mg->music_state = 1;
    window = sfRenderWindow_create((sfVideoMode) {1920, 1080, 32}, "Azazyel's Adventure", 19 | sfClose, NULL);
    sfRenderWindow_setIcon(window, 61, 46, sfImage_getPixelsPtr(sfImage_createFromFile("Image/icon.png")));
    sfWindow_setMouseCursorVisible((sfWindow *) window, sfFalse);
    while (sfRenderWindow_isOpen(window)) {
        sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
        while (sfRenderWindow_pollEvent(window, &struct_mg->event)) {
            if (struct_mg->event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (struct_mg->event.type == sfEvtMouseMoved) {
                sfVector2f cursor1 = sourissprite(sfMouse_getPositionRenderWindow(window));
                sfSprite_setPosition(cursor->cursorsprite, cursor1);
                if ((mouse.x > sfSprite_getPosition(button->sprite_button).x && mouse.x <= sfSprite_getPosition(button->sprite_button).x + 512) &&
                (mouse.y > sfSprite_getPosition(button->sprite_button).y && mouse.y <= sfSprite_getPosition(button->sprite_button).y + 127)) {
                    sfSprite_setPosition(button->sprite_button, setpanel->pos_button_h);
                } else {
                    sfSprite_setPosition(button->sprite_button, button->pos_button);
                }
                if ((mouse.x > sfSprite_getPosition(button->sprite_button2).x && mouse.x <= sfSprite_getPosition(button->sprite_button2).x + 512) &&
                (mouse.y > sfSprite_getPosition(button->sprite_button2).y && mouse.y <= sfSprite_getPosition(button->sprite_button2).y + 127)) {
                    sfSprite_setPosition(button->sprite_button2, setpanel->pos_button2_h);
                } else {
                    sfSprite_setPosition(button->sprite_button2, button->pos_button2);
                }
                if ((mouse.x > sfSprite_getPosition(button->sprite_button3).x && mouse.x <= sfSprite_getPosition(button->sprite_button3).x + 512) &&
                (mouse.y > sfSprite_getPosition(button->sprite_button3).y && mouse.y <= sfSprite_getPosition(button->sprite_button3).y + 127)) {
                    sfSprite_setPosition(button->sprite_button3, setpanel->pos_button3_h);
                } else {
                    sfSprite_setPosition(button->sprite_button3, button->pos_button3);
                }
                if (((mouse.x > sfSprite_getPosition(setpanel->sprite_audio).x && mouse.x <= sfSprite_getPosition(setpanel->sprite_audio).x + 400) &&
                    (mouse.y > sfSprite_getPosition(setpanel->sprite_audio).y && mouse.y <= sfSprite_getPosition(setpanel->sprite_audio).y + 98)) && setpanel->k == 0) {
                    sfSprite_setPosition(setpanel->sprite_audio, setpanel->pos_audio_h);
                } else {
                    sfSprite_setPosition(setpanel->sprite_audio, setpanel->pos_audio);
                }
                if (((mouse.x > sfSprite_getPosition(setpanel->sprite_close).x && mouse.x <= sfSprite_getPosition(setpanel->sprite_close).x + 512) &&
                    (mouse.y > sfSprite_getPosition(setpanel->sprite_close).y && mouse.y <= sfSprite_getPosition(setpanel->sprite_close).y)) + 127) {
                        sfSprite_setPosition(setpanel->sprite_close, setpanel->pos_close_h);
                } else {
                    sfSprite_setPosition(setpanel->sprite_close, setpanel->pos_close);
                }
                if ((mouse.x > sfSprite_getPosition(setpanel->sprite_but_howtoplay).x && mouse.x <= sfSprite_getPosition(setpanel->sprite_but_howtoplay).x + 400) &&
                (mouse.y > sfSprite_getPosition(setpanel->sprite_but_howtoplay).y && mouse.y <= sfSprite_getPosition(setpanel->sprite_but_howtoplay).y + 98)) {
                    sfSprite_setPosition(setpanel->sprite_but_howtoplay, setpanel->pos_but_howtoplay_h);
                } else {
                    sfSprite_setPosition(setpanel->sprite_but_howtoplay, setpanel->pos_but_howtoplay);
                }
            }
            if (struct_mg->event.type == sfEvtMouseButtonPressed) {
                if ((mouse.x > sfSprite_getPosition(button->sprite_button).x && mouse.x <= sfSprite_getPosition(button->sprite_button).x + 512) &&
                (mouse.y > sfSprite_getPosition(button->sprite_button).y && mouse.y <= sfSprite_getPosition(button->sprite_button).y + 127)) {
                    sfMusic_stop(struct_mg->click);
                    sfMusic_play(struct_mg->click);
                    sfClock_restart(struct_mg->horloge);
                    launch_game = 1;
                }
                if ((mouse.x > sfSprite_getPosition(setpanel->sprite_but_howtoplay).x && mouse.x <= sfSprite_getPosition(setpanel->sprite_but_howtoplay).x + 400) &&
                (mouse.y > sfSprite_getPosition(setpanel->sprite_but_howtoplay).y && mouse.y <= sfSprite_getPosition(setpanel->sprite_but_howtoplay).y + 98)) {
                    sfMusic_stop(struct_mg->click);
                    sfMusic_play(struct_mg->click);
                    setpanel->i = 0;
                    setpanel->how_var = 1;
                }
                if ((mouse.x > sfSprite_getPosition(setpanel->sprite_but_howtoplay_close).x && mouse.x <= sfSprite_getPosition(setpanel->sprite_but_howtoplay_close).x + 93) &&
                (mouse.y > sfSprite_getPosition(setpanel->sprite_but_howtoplay_close).y && mouse.y <= sfSprite_getPosition(setpanel->sprite_but_howtoplay_close).y + 90) && setpanel->how_var == 1) {
                    sfMusic_stop(struct_mg->click);
                    sfMusic_play(struct_mg->click);
                    setpanel->how_var = 0;
                }
                if (((mouse.x > sfSprite_getPosition(button->sprite_button2).x && mouse.x <= sfSprite_getPosition(button->sprite_button2).x + 512) &&
                (mouse.y > sfSprite_getPosition(button->sprite_button2).y && mouse.y <= sfSprite_getPosition(button->sprite_button2).y + 127)) && setpanel->i == 0) {
                    sfMusic_stop(struct_mg->click);
                    sfMusic_play(struct_mg->click);
                    setpanel->i = 1;
                } else if (((mouse.x > sfSprite_getPosition(button->sprite_button2).x && mouse.x <= sfSprite_getPosition(button->sprite_button2).x + 512) &&
                (mouse.y > sfSprite_getPosition(button->sprite_button2).y && mouse.y <= sfSprite_getPosition(button->sprite_button2).y + 127)) && setpanel->i == 1) {
                    sfMusic_stop(struct_mg->click);
                    sfMusic_play(struct_mg->click);
                    setpanel->i = 0;
                }
                if (((mouse.x > sfSprite_getPosition(setpanel->sprite_audio).x && mouse.x <= sfSprite_getPosition(setpanel->sprite_audio).x + 400) &&
                    (mouse.y > sfSprite_getPosition(setpanel->sprite_audio).y && mouse.y <= sfSprite_getPosition(setpanel->sprite_audio).y + 98)) && setpanel->k == 0) {
                    sfMusic_stop(struct_mg->click);
                    sfMusic_play(struct_mg->click);
                    sfSprite_setTexture(setpanel->sprite_audio, setpanel->text_audio_off, sfTrue);
                    struct_mg->music_state = 0;
                    setpanel->k = 1;
                    sfMusic_stop(struct_mg->music);
                } else if (((mouse.x > sfSprite_getPosition(setpanel->sprite_audio).x && mouse.x <= sfSprite_getPosition(setpanel->sprite_audio).x + 400) &&
                    (mouse.y > sfSprite_getPosition(setpanel->sprite_audio).y && mouse.y <= sfSprite_getPosition(setpanel->sprite_audio).y + 98 )) && setpanel->k == 1) {
                    sfMusic_stop(struct_mg->click);
                    sfMusic_play(struct_mg->click);
                    sfSprite_setTexture(setpanel->sprite_audio, setpanel->text_audio_off, sfTrue);
                    setpanel->k = 0;
                    sfMusic_stop(struct_mg->click);
                }
                if ((mouse.x > sfSprite_getPosition(setpanel->sprite_close).x && mouse.x <= sfSprite_getPosition(setpanel->sprite_close).x + 400) &&
                    (mouse.y > sfSprite_getPosition(setpanel->sprite_close).y && mouse.y <= sfSprite_getPosition(setpanel->sprite_close).y + 98 && setpanel->i == 1)) {
                    sfMusic_stop(struct_mg->click);
                    sfMusic_play(struct_mg->click);
                    setpanel->i = 0;
                }
                if (mouse.x > sfSprite_getPosition(setpanel->sprite_audio).x && mouse.x <= sfSprite_getPosition(setpanel->sprite_audio).x + 400 &&
                    (mouse.y > sfSprite_getPosition(setpanel->sprite_audio).y && mouse.y <= sfSprite_getPosition(setpanel->sprite_audio).y + 98 && setpanel->i == 1 && setpanel->k == 0)) {
                    sfMusic_stop(struct_mg->click);
                    sfMusic_play(struct_mg->click);
                    sfSprite_setTexture(setpanel->sprite_audio, setpanel->text_audio_on, sfTrue);
                    struct_mg->music_state = 1;
                    struct_mg->music_onoff = 0;
                    setpanel->k = 0;
                    sfMusic_play(struct_mg->music);
                }
                if ((mouse.x > sfSprite_getPosition(button->sprite_button3).x && mouse.x <= sfSprite_getPosition(button->sprite_button3).x + 512) &&
                (mouse.y > sfSprite_getPosition(button->sprite_button3).y && mouse.y <= sfSprite_getPosition(button->sprite_button3).y + 127)) {
                    sfRenderWindow_close(window);
                }
            }
        }

        if (sfTime_asMilliseconds(sfClock_getElapsedTime(struct_mg->player_clock)) > 200) {
            struct_mg->player_rect.left += (288 / 3);
            if (struct_mg->player_rect.left == 288)
                struct_mg->player_rect.left = 0;
            sfClock_restart(struct_mg->player_clock);
        }

        if (launch_game == 1) {
            while (sfRenderWindow_isOpen(window) && sfTime_asSeconds(sfClock_getElapsedTime(struct_mg->horloge)) <= 4) {
                while (sfRenderWindow_pollEvent(window, &struct_mg->event)) {
                    if (struct_mg->event.type == sfEvtClosed)
                        sfRenderWindow_close(window);
                    if (struct_mg->event.type == sfEvtMouseMoved) {
                        sfVector2f cursor1 = sourissprite(sfMouse_getPositionRenderWindow(window));
                        sfSprite_setPosition(cursor->cursorsprite, cursor1);
                    }
                }
                if (sfTime_asMilliseconds(sfClock_getElapsedTime(struct_mg->player_clock)) > 200) {
                    struct_mg->player_rect.left += (288 / 3);
                    if (struct_mg->player_rect.left == 288)
                        struct_mg->player_rect.left = 0;
                    sfClock_restart(struct_mg->player_clock);
                }
                sfSprite_setTextureRect(struct_mg->sprite_perso, struct_mg->player_rect);
                sfSprite_setPosition(struct_mg->sprite_perso ,struct_mg->pos_perso);
                sfRenderWindow_drawSprite(window, struct_mg->sprite_perso, NULL);
                if (struct_mg->pos_perso.x < 2000) struct_mg->pos_perso.x += 1;

                sfRenderWindow_drawSprite(window, cursor->cursorsprite, NULL);
                sfRenderWindow_display(window);
                sfRenderWindow_clear(window, sfBlack);
                sfRenderWindow_drawSprite(window, struct_mg->sprite_bg, NULL);

                sfSprite_setTextureRect(struct_mg->sprite_perso, struct_mg->player_rect);
                sfSprite_setPosition(struct_mg->sprite_perso ,struct_mg->pos_perso);
                sfRenderWindow_drawSprite(window, struct_mg->sprite_perso, NULL);
            }
            if (sfTime_asSeconds(sfClock_getElapsedTime(struct_mg->horloge)) >= 1) {
                sfMusic_stop(struct_mg->music);
                my_game(struct_mg, window);
            }
        }
        if (setpanel->i == 1) {
            sfRenderWindow_drawSprite(window, setpanel->sprite_panel, NULL);
            sfRenderWindow_drawSprite(window, setpanel->sprite_audio, NULL);
            sfRenderWindow_drawSprite(window, setpanel->sprite_but_howtoplay, NULL);
            sfRenderWindow_drawSprite(window, setpanel->sprite_close, NULL);
        }
        if (setpanel->how_var == 1) {
            sfRenderWindow_drawSprite(window, setpanel->sprite_howtoplay, NULL);
            sfRenderWindow_drawSprite(window, setpanel->sprite_but_howtoplay_close, NULL);
        }
        sfRenderWindow_drawSprite(window, cursor->cursorsprite, NULL);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, struct_mg->sprite_bg, NULL);
        if (setpanel->how_var == 0) {
            sfRenderWindow_drawSprite(window, button->sprite_button, NULL);
            sfRenderWindow_drawSprite(window, button->sprite_button2, NULL);
            sfRenderWindow_drawSprite(window, button->sprite_button3, NULL);
        }
        sfSprite_setTextureRect(struct_mg->sprite_perso, struct_mg->player_rect);
        sfSprite_setPosition(struct_mg->sprite_perso ,struct_mg->pos_perso);
        sfRenderWindow_drawSprite(window, struct_mg->sprite_perso, NULL);
    }
    sfSprite_destroy(cursor->cursorsprite);
    sfSprite_destroy(struct_mg->sprite_bg);
    sfSprite_destroy(struct_mg->sprite_perso);
    sfSprite_destroy(button->sprite_button);
    sfSprite_destroy(button->sprite_button2);
    sfSprite_destroy(button->sprite_button3);
    sfSprite_destroy(setpanel->sprite_panel);
    sfSprite_destroy(setpanel->sprite_audio);
    sfSprite_destroy(setpanel->sprite_but_howtoplay);
    sfSprite_destroy(setpanel->sprite_howtoplay);
    sfSprite_destroy(setpanel->sprite_but_howtoplay_close);
    sfSprite_destroy(setpanel->sprite_close);
    sfMusic_destroy(struct_mg->click);
    sfMusic_destroy(struct_mg->music);
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("\n- Azazyel's Adventure -\n\n");
        my_putstr("-  Keybinds \n\n");
        my_putstr("   Press F to fight\n");
        my_putstr("   Press directional arrows to move in the map\n");
        my_putstr("   Press E to interact with NPC\n\n");
        my_putstr("   Press R to interact with the potion\n\n");
        my_putstr("   Good luck and have fun :)\n\n");
        return (0);
    }

    sfRenderWindow* window = NULL;
    menu_game(window);
    return 0;
}