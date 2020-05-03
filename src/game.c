/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** game
*/

#include "../my.h"

s_button_t *init_buttons(void)
{
    s_button_t *struct_buttons = malloc(sizeof(s_button_t));
    struct_buttons->sprite_button3 = sfSprite_create();
    struct_buttons->text_button3 = sfTexture_createFromFile("Image/but_exit.png", NULL);
    sfSprite_setTexture(struct_buttons->sprite_button3, struct_buttons->text_button3, sfTrue);
    struct_buttons->pos_button3.x = 710;
    struct_buttons->pos_button3.y = 600;
    struct_buttons->pos_button3_h.x = 710;
    struct_buttons->pos_button3_h.y = 610;
    sfSprite_setPosition(struct_buttons->sprite_button3, struct_buttons->pos_button3);
    struct_buttons->sprite_button4 = sfSprite_create();
    struct_buttons->text_button4 = sfTexture_createFromFile("Image/but_menu.png", NULL);
    sfSprite_setTexture(struct_buttons->sprite_button4, struct_buttons->text_button4, sfTrue);
    struct_buttons->pos_button4.x = 710;
    struct_buttons->pos_button4.y = 400;
    sfSprite_setPosition(struct_buttons->sprite_button4, struct_buttons->pos_button4);
    struct_buttons->sprite_menu_end = sfSprite_create();
    struct_buttons->text_menu_end = sfTexture_createFromFile("Image/but_menu_end.png", NULL);
    sfSprite_setTexture(struct_buttons->sprite_menu_end, struct_buttons->text_menu_end, sfTrue);
    struct_buttons->pos_button_menu_end.x = 705;
    struct_buttons->pos_button_menu_end.y = 885;
    sfSprite_setPosition(struct_buttons->sprite_menu_end, struct_buttons->pos_button_menu_end);
    return struct_buttons;
}

s_villager_t *init_villager(void)
{
    s_villager_t *struct_villager = malloc(sizeof(s_villager_t));
    struct_villager->text_villager = sfTexture_createFromFile("Image/vil2.png", NULL);
    struct_villager->sprite_villager = sfSprite_create();
    struct_villager->rect_villager.height = 74;
    struct_villager->rect_villager.width = 518 / 7;
    struct_villager->rect_villager.top = 0;
    struct_villager->rect_villager.left = 0;
    sfSprite_setTexture(struct_villager->sprite_villager, struct_villager->text_villager, sfTrue);
    sfSprite_setTextureRect(struct_villager->sprite_villager, struct_villager->rect_villager);
    struct_villager->pos_villager.x = 1180;
    struct_villager->pos_villager.y = 805;
    sfSprite_setPosition(struct_villager->sprite_villager, struct_villager->pos_villager);
    struct_villager->clock_villager = sfClock_create();
    struct_villager->text_quest = sfTexture_createFromFile("Image/gui_v.png", NULL);
    struct_villager->sprite_quest = sfSprite_create();
    sfSprite_setTexture(struct_villager->sprite_quest, struct_villager->text_quest, sfTrue);
    struct_villager->pos_quest.x = 0;
    struct_villager->pos_quest.y = 0;
    sfSprite_setPosition(struct_villager->sprite_quest, struct_villager->pos_quest);
    struct_villager->text_yes_button = sfTexture_createFromFile("Image/yes_quest.png", NULL);
    struct_villager->sprite_yes_button = sfSprite_create();
    sfSprite_setTexture(struct_villager->sprite_yes_button, struct_villager->text_yes_button, sfTrue);
    struct_villager->pos_yes_button.x = 1420;
    struct_villager->pos_yes_button.y = 650;
    sfSprite_setPosition(struct_villager->sprite_yes_button, struct_villager->pos_yes_button);
    struct_villager->text_no_button = sfTexture_createFromFile("Image/no_quest.png", NULL);
    struct_villager->sprite_no_button = sfSprite_create();
    sfSprite_setTexture(struct_villager->sprite_no_button, struct_villager->text_no_button, sfTrue);
    struct_villager->pos_no_button.x = 1250;
    struct_villager->pos_no_button.y = 650;
    sfSprite_setPosition(struct_villager->sprite_no_button, struct_villager->pos_no_button);
    struct_villager->sprite_achievement = sfSprite_create();
    struct_villager->text_achievement = sfTexture_createFromFile("Image/achivement.png", NULL);
    sfSprite_setTexture(struct_villager->sprite_achievement, struct_villager->text_achievement, sfTrue);
    struct_villager->pos_achievement.x = 1600;
    struct_villager->pos_achievement.y = 0;
    sfSprite_setPosition(struct_villager->sprite_achievement, struct_villager->pos_achievement);
    struct_villager->text_endquest = sfTexture_createFromFile("Image/end_quest.png", NULL);
    struct_villager->sprite_endquest = sfSprite_create();
    sfSprite_setTexture(struct_villager->sprite_endquest, struct_villager->text_endquest, sfTrue);
    sfSprite_setPosition(struct_villager->sprite_endquest, (sfVector2f) {1180, 700});
    struct_villager->text_thanks = sfTexture_createFromFile("Image/thanks.png", NULL);
    struct_villager->sprite_thanks = sfSprite_create();
    sfSprite_setTexture(struct_villager->sprite_thanks, struct_villager->text_thanks, sfTrue);
    sfSprite_setPosition(struct_villager->sprite_thanks, (sfVector2f) {1180, 700});
    struct_villager->text_wrong_key = sfTexture_createFromFile("Image/wrong_key.png", NULL);
    struct_villager->sprite_wrong_key = sfSprite_create();
    sfSprite_setTexture(struct_villager->sprite_wrong_key, struct_villager->text_wrong_key, sfTrue);
    sfSprite_setPosition(struct_villager->sprite_wrong_key, (sfVector2f) {1180, 700});
    struct_villager->clock_achievement = sfClock_create();
    struct_villager->yannis = 0;
    return struct_villager;
}

s_villager1_t *init_villager1(void)
{
    s_villager1_t *struct_villager1 = malloc(sizeof(s_villager1_t));
    struct_villager1->sprite_villager = sfSprite_create();
    struct_villager1->text_villager = sfTexture_createFromFile("Image/man_idle.png", NULL);
    struct_villager1->clock_villager = sfClock_create();
    sfSprite_setTexture(struct_villager1->sprite_villager, struct_villager1->text_villager, sfTrue);
    struct_villager1->rect_villager.height = 100;
    struct_villager1->rect_villager.width = 100;
    struct_villager1->rect_villager.top = 0;
    struct_villager1->rect_villager.left = 0;
    sfSprite_setTextureRect(struct_villager1->sprite_villager, struct_villager1->rect_villager);
    struct_villager1->pos_villager.x = 1400;
    struct_villager1->pos_villager.y = 350;
    sfSprite_setPosition(struct_villager1->sprite_villager, struct_villager1->pos_villager);
    return struct_villager1;
}

s_villager2_t *init_villager2(void)
{
    s_villager2_t *struct_villager2 = malloc(sizeof(s_villager2_t));
    struct_villager2->sprite_villager = sfSprite_create();
    struct_villager2->text_villager = sfTexture_createFromFile("Image/sprite_vil.png", NULL);
    struct_villager2->clock_villager = sfClock_create();
    sfSprite_setTexture(struct_villager2->sprite_villager, struct_villager2->text_villager, sfTrue);
    struct_villager2->rect_villager.height = 85;
    struct_villager2->rect_villager.width = (340 / 4);
    struct_villager2->rect_villager.top = 0;
    struct_villager2->rect_villager.left = 0;
    sfSprite_setTextureRect(struct_villager2->sprite_villager, struct_villager2->rect_villager);
    struct_villager2->pos_villager.x = 230;
    struct_villager2->pos_villager.y = 300;
    sfSprite_setPosition(struct_villager2->sprite_villager, struct_villager2->pos_villager);
    return struct_villager2;
}

s_pause_game_t *init_pause(void)
{
    s_pause_game_t *struct_pause = malloc(sizeof(s_pause_game_t));
    struct_pause->sprite_pause = sfSprite_create();
    struct_pause->text_pause = sfTexture_createFromFile("Image/pause_sprite.png", NULL);
    sfSprite_setTexture(struct_pause->sprite_pause, struct_pause->text_pause, sfTrue);
    struct_pause->pos_pause.x = 0;
    struct_pause->pos_pause.y = 0;
    sfSprite_setPosition(struct_pause->sprite_pause, struct_pause->pos_pause);
    return struct_pause;
}

s_my_game_t *init_g_struct(void)
{
    s_my_game_t *struct_game = malloc(sizeof(s_my_game_t));
    struct_game->text_bg_g = sfTexture_createFromFile("Image/map.png", NULL);
    struct_game->sprite_bg_g = sfSprite_create();
    sfSprite_setTexture(struct_game->sprite_bg_g, struct_game->text_bg_g, sfTrue);
    struct_game->clock_end_game = sfClock_create();
    struct_game->click_g = sfMusic_createFromFile("Music/click_music.ogg");
    struct_game->text_endscreen = sfTexture_createFromFile("Image/end_screen.png", NULL);
    struct_game->sprite_endscreen = sfSprite_create();
    sfSprite_setTexture(struct_game->sprite_endscreen, struct_game->text_endscreen, sfTrue);
    sfSprite_setPosition(struct_game->sprite_endscreen, (sfVector2f) {0, -40});
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
    struct_object->tree_rect.left = 0;
    struct_object->tree_rect.top = 0;
    sfSprite_setTexture(struct_object->sprite_tree, struct_object->text_tree, sfTrue);
    sfSprite_setTextureRect(struct_object->sprite_tree, struct_object->tree_rect);
    sfSprite_setPosition(struct_object->sprite_tree ,(sfVector2f) {920, 895});
    struct_object->horloge_tree = sfClock_create();

    struct_object->text_bubble = sfTexture_createFromFile("Image/bubble.png", NULL);
    struct_object->sprite_bubble = sfSprite_create();
    sfSprite_setTexture(struct_object->sprite_bubble, struct_object->text_bubble, sfTrue);
    sfSprite_setPosition(struct_object->sprite_bubble ,(sfVector2f) {1805, 135});

    struct_object->text_bubble_v = sfTexture_createFromFile("Image/bubble_v.png", NULL);
    struct_object->sprite_bubble_v = sfSprite_create();
    sfSprite_setTexture(struct_object->sprite_bubble_v, struct_object->text_bubble_v, sfTrue);
    sfSprite_setPosition(struct_object->sprite_bubble_v, (sfVector2f) {1180, 700});

    struct_object->text_bubble_v1 = sfTexture_createFromFile("Image/dialogue_sword.png", NULL);
    struct_object->sprite_bubble_v1 = sfSprite_create();
    sfSprite_setTexture(struct_object->sprite_bubble_v1, struct_object->text_bubble_v1, sfTrue);
    sfSprite_setPosition(struct_object->sprite_bubble_v1, (sfVector2f) {1250, 220});

    struct_object->text_bubble_v2 = sfTexture_createFromFile("Image/strange.png", NULL);
    struct_object->sprite_bubble_v2 = sfSprite_create();
    sfSprite_setTexture(struct_object->sprite_bubble_v2, struct_object->text_bubble_v2, sfTrue);
    sfSprite_setPosition(struct_object->sprite_bubble_v2, (sfVector2f) {70, 210});

    return struct_object;
}

s_perso_t *init_perso(void)
{
    s_perso_t *struct_perso = malloc(sizeof(s_perso_t));
    struct_perso->up = 0;
    struct_perso->down = 0;
    struct_perso->left = 0;
    struct_perso->right = 0;
    struct_perso->int_chest = 0;
    struct_perso->our_life = 0;
    struct_perso->less_hp = 0;
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
    struct_perso->player_rect.top = 0;
    struct_perso->player_rect.left = 0;
    sfSprite_setTextureRect(struct_perso->sprite_perso, struct_perso->player_rect);
    sfSprite_setPosition(struct_perso->sprite_perso ,struct_perso->pos_perso);
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
    sfText_setCharacterSize(struct_perso->texte_obj, 20);
    sfText_setCharacterSize(struct_perso->texte_int, 20);
    sfText_setPosition(struct_perso->texte_obj, (sfVector2f) {10, 0});
    sfText_setPosition(struct_perso->texte_int, (sfVector2f) {140, 0});

    struct_perso->clock_popo = sfClock_create();
    struct_perso->rect_popo.height = 96;
    struct_perso->rect_popo.width = 768 / 8;
    struct_perso->rect_popo.top = 0;
    struct_perso->rect_popo.left = 0;
    struct_perso->sprite_popo = sfSprite_create();
    struct_perso->text_popo = sfTexture_createFromFile("Image/fx.png", NULL);
    sfSprite_setTexture(struct_perso->sprite_popo, struct_perso->text_popo, sfTrue);
    sfSprite_setTextureRect(struct_perso->sprite_popo, struct_perso->rect_popo);

    struct_perso->pos_popo.x = -100;
    struct_perso->pos_popo.y = -100;
    sfSprite_setPosition(struct_perso->sprite_popo , struct_perso->pos_popo);
    struct_perso->music_popo = sfMusic_createFromFile("Music/glass_s.ogg");
    struct_perso->next = NULL;
    return struct_perso;
}

void init_perso2(s_perso_t *s_perso)
{
    s_perso_t *struct_perso2 = s_perso;
    for(; struct_perso2->next != NULL; struct_perso2 = struct_perso2->next);
    struct_perso2->next = malloc(sizeof(s_perso_t));

    struct_perso2->next->pos_perso.x = 200;
    struct_perso2->next->pos_perso.y = 200;
    struct_perso2->next->player_clock = sfClock_create();
    struct_perso2->next->text_perso = sfTexture_createFromFile("Image/vamp2/vamp.png", NULL);
    struct_perso2->next->text_perso_l = sfTexture_createFromFile("Image/vamp2/vamp_l.png", NULL);
    struct_perso2->next->text_perso_up = sfTexture_createFromFile("Image/vamp2/vamp_up.png", NULL);
    struct_perso2->next->text_perso_do = sfTexture_createFromFile("Image/vamp2/vamp_do.png", NULL);
    struct_perso2->next->sprite_perso = sfSprite_create();
    sfSprite_setTexture(struct_perso2->next->sprite_perso, struct_perso2->next->text_perso, sfTrue);
    struct_perso2->next->player_rect.height = 143;
    struct_perso2->next->player_rect.width = 855 / 3;
    struct_perso2->next->player_rect.left = 0;
    struct_perso2->next->player_rect.top = 0;
    sfSprite_setTextureRect(struct_perso2->next->sprite_perso, struct_perso2->next->player_rect);
    sfSprite_setPosition(struct_perso2->next->sprite_perso ,struct_perso2->next->pos_perso);
    struct_perso2->next->next = NULL;
}

s_chest_t *init_chest()
{
    s_chest_t *s_chest = malloc(sizeof(s_chest_t));

    s_chest->clock_chest = sfClock_create();
    s_chest->text_chest = sfTexture_createFromFile("Image/chest.png", NULL);

    s_chest->sprite_chest = sfSprite_create();
    sfSprite_setTexture(s_chest->sprite_chest, s_chest->text_chest, sfTrue);
    s_chest->rect_chest.height = 44;
    s_chest->rect_chest.width = 48;
    s_chest->rect_chest.left = 0;
    s_chest->rect_chest.top = 0;
    sfSprite_setTextureRect(s_chest->sprite_chest, s_chest->rect_chest);
    sfSprite_setPosition(s_chest->sprite_chest, (sfVector2f) {185, 328});
    s_chest->next = malloc(sizeof(s_chest_t));
    s_chest->next->clock_chest = sfClock_create();
    s_chest->next->text_chest = sfTexture_createFromFile("Image/chest.png", NULL);

    s_chest->next->sprite_chest = sfSprite_create();
    sfSprite_setTexture(s_chest->next->sprite_chest, s_chest->next->text_chest, sfTrue);
    s_chest->next->rect_chest.height = 44;
    s_chest->next->rect_chest.width = 48;
    s_chest->next->rect_chest.left = 0;
    s_chest->next->rect_chest.top = 0;
    sfSprite_setTextureRect(s_chest->next->sprite_chest, s_chest->next->rect_chest);
    sfSprite_setPosition(s_chest->next->sprite_chest, (sfVector2f) {725, 328});
    s_chest->next->next = NULL;
    return s_chest;
}

s_inventory_t *init_invent(void)
{
    s_inventory_t *s_invent = malloc(sizeof(s_inventory_t));
    s_invent->text_invent = sfTexture_createFromFile("Image/invent.png", NULL);
    s_invent->text_invent_key = sfTexture_createFromFile("Image/invent_key.png", NULL);
    s_invent->text_invent_2key = sfTexture_createFromFile("Image/invent_2key.png", NULL);
    s_invent->text_invent_sword = sfTexture_createFromFile("Image/sword.png", NULL);
    s_invent->text_swordlvl_fx = sfTexture_createFromFile("Image/+1.png", NULL);
    s_invent->text_potionlvl_fx = sfTexture_createFromFile("Image/+1_potion.png", NULL);
    s_invent->text_fx_blue = sfTexture_createFromFile("Image/+1_keyb.png", NULL);
    s_invent->text_swordlvl_fx2 = sfTexture_createFromFile("Image/Sword+lvl.png", NULL);
    s_invent->text_invent_potion = sfTexture_createFromFile("Image/potion.png", NULL);
    s_invent->sprite_invent = sfSprite_create();
    s_invent->sprite_sword = sfSprite_create();
    s_invent->sprite_potion = sfSprite_create();
    s_invent->sprite_potion_fx = sfSprite_create();
    s_invent->sprite_sword_fx = sfSprite_create();
    s_invent->sprite_sword_fx2 = sfSprite_create();
    s_invent->sprite_sword_fx2 = sfSprite_create();
    s_invent->sprite_fx_blue = sfSprite_create();
    sfSprite_setTexture(s_invent->sprite_invent, s_invent->text_invent, sfTrue);
    sfSprite_setTexture(s_invent->sprite_sword, s_invent->text_invent_sword, sfTrue);
    sfSprite_setTexture(s_invent->sprite_potion, s_invent->text_invent_potion, sfTrue);
    sfSprite_setTexture(s_invent->sprite_potion_fx, s_invent->text_potionlvl_fx, sfTrue);
    sfSprite_setTexture(s_invent->sprite_sword_fx, s_invent->text_swordlvl_fx, sfTrue);
    sfSprite_setTexture(s_invent->sprite_sword_fx2, s_invent->text_swordlvl_fx2, sfTrue);
    sfSprite_setTexture(s_invent->sprite_fx_blue, s_invent->text_fx_blue, sfTrue);
    sfSprite_setPosition(s_invent->sprite_invent, (sfVector2f) {70, 40});
    sfSprite_setPosition(s_invent->sprite_sword, (sfVector2f) {235, 645});
    sfSprite_setPosition(s_invent->sprite_potion, (sfVector2f) {290, 645});
    sfSprite_setPosition(s_invent->sprite_sword_fx2, (sfVector2f) {1600, 0});
    sfSprite_setPosition(s_invent->sprite_potion_fx, (sfVector2f) {500, 0});
    s_invent->pos_sword_fx.x = 1420;
    s_invent->pos_sword_fx.y = 300;
    s_invent->pos_potion_fx.x = 750;
    s_invent->pos_potion_fx.y = 250;
    s_invent->clock_fx = sfClock_create();
    sfSprite_setPosition(s_invent->sprite_sword_fx, s_invent->pos_sword_fx);
    sfSprite_setPosition(s_invent->sprite_potion_fx, s_invent->pos_potion_fx);
    s_invent->pos_blue.x = 100;
    s_invent->pos_blue.y = 250;
    sfSprite_setPosition(s_invent->sprite_fx_blue, s_invent->pos_blue);
    return s_invent;
}

s_life_t *init_life()
{
    s_life_t *s_life = malloc(sizeof(s_life_t));
    s_life->sprite_life = sfSprite_create();
    s_life->text_life = sfTexture_createFromFile("Image/barhealus.png", NULL);
    sfSprite_setTexture(s_life->sprite_life, s_life->text_life, sfTrue);
    s_life->rect.height = 112;
    s_life->rect.width = 584;
    s_life->rect.top = 0;
    s_life->rect.left = 0;
    sfSprite_setTextureRect(s_life->sprite_life, s_life->rect);
    sfSprite_setPosition(s_life->sprite_life, (sfVector2f) {110, 500});
    sfSprite_setScale(s_life->sprite_life, (sfVector2f) {0.8, 1});
    return s_life;
}

s_wind_t *init_wind()
{
    s_wind_t *s_wind = malloc(sizeof(s_wind_t));
    s_wind->sprite_wind = sfSprite_create();
    s_wind->text_wind = sfTexture_createFromFile("Image/wind.png", NULL);
    sfSprite_setTexture(s_wind->sprite_wind, s_wind->text_wind, sfTrue);
    s_wind->rect_w.height = 98;
    s_wind->rect_w.width = 1500 / 15;
    s_wind->rect_w.top = 0;
    s_wind->rect_w.left = 0;
    sfSprite_setTextureRect(s_wind->sprite_wind, s_wind->rect_w);
    sfSprite_setPosition(s_wind->sprite_wind, (sfVector2f) {700, 480});
    s_wind->clock_w = sfClock_create();
    s_wind->next = malloc(sizeof(s_wind_t));
    s_wind->next->sprite_wind = sfSprite_create();
    s_wind->next->text_wind = sfTexture_createFromFile("Image/wind.png", NULL);
    sfSprite_setTexture(s_wind->next->sprite_wind, s_wind->next->text_wind, sfTrue);
    s_wind->next->rect_w.height = 98;
    s_wind->next->rect_w.width = 1500 / 15;
    s_wind->next->rect_w.top = 0;
    s_wind->next->rect_w.left = 200;
    sfSprite_setTextureRect(s_wind->next->sprite_wind, s_wind->next->rect_w);
    sfSprite_setPosition(s_wind->next->sprite_wind, (sfVector2f) {1630, 900});
    s_wind->next->clock_w = sfClock_create();
    s_wind->next->next = NULL;
    return s_wind;
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
    else if ((perso->pos_perso.y >= 300 - 55 && perso->pos_perso.y <= 260) && (perso->pos_perso.x <= 1700) && (perso->pos_perso.x >= 1100)) {
        perso->pos_perso.y += 15;
    }
    else if ((perso->pos_perso.y >= 450 && perso->pos_perso.y <= 470) && (perso->pos_perso.x > -100) && (perso->pos_perso.x <= 800)) {
        perso->pos_perso.y += 15;
    } else {
        perso->pos_perso.y -= 15;
    }
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
    else if ((perso->pos_perso.y >= 420 && perso->pos_perso.y <= 440) && (perso->pos_perso.x > -100) && (perso->pos_perso.x <= 800)) {
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
    else if ((perso->pos_perso.y >= 200 && perso->pos_perso.y <= 460) && (perso->pos_perso.x >= 1050 && perso->pos_perso.x <= 1109)) {
        perso->pos_perso.x -= 30;
    }
    else if ((perso->pos_perso.y >= 200 && perso->pos_perso.y <= 490) && (perso->pos_perso.x >= 1780 && perso->pos_perso.x <= 1920)) {
        perso->pos_perso.x -= 30;
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
    else if ((perso->pos_perso.y >= 200 && perso->pos_perso.y <= 460) && (perso->pos_perso.x >= 1110 && perso->pos_perso.x <= 1120)) {
        perso->pos_perso.x += 20;
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

void less_hp_fct(s_perso_t *s_perso, s_life_t *s_life)
{
    s_life->rect.width -= (73 * s_perso->less_hp);
    sfSprite_setTextureRect(s_life->sprite_life, s_life->rect);
}

void print_bubble(s_object_t *s_object, s_perso_t *s_perso, s_villager_t *struct_villager, sfRenderWindow* window)
{
    if (s_perso->pos_perso.x >= 1600 && s_perso->pos_perso.y <= 350)
        sfRenderWindow_drawSprite(window, s_object->sprite_bubble, NULL);

    if (s_perso->pos_perso.x >= 1000 && s_perso->pos_perso.x <= 1320 && s_perso->pos_perso.y >= 720 && struct_villager->quest_accepted == 0)
        sfRenderWindow_drawSprite(window, s_object->sprite_bubble_v, NULL);

    if (s_perso->pos_perso.x >= 1300 && s_perso->pos_perso.x <= 1500 && s_perso->pos_perso.y <= 450 && s_perso->pos_perso.y >= 300)
        sfRenderWindow_drawSprite(window, s_object->sprite_bubble_v1, NULL);

    if (s_perso->pos_perso.x >= 100 && s_perso->pos_perso.x <= 300 && s_perso->pos_perso.y <= 400 && s_perso->pos_perso.y >= 300)
        sfRenderWindow_drawSprite(window, s_object->sprite_bubble_v2, NULL);
}

s_my_game_t *print_pause(sfRenderWindow* window, s_my_game_t *struct_game, s_perso_t *s_perso, s_cursor_t *cursor, s_button_t *struct_buttons, s_menu_game_t *struct_menu)
{
    s_pause_game_t *s_pause = init_pause();
    s_button_t *s_buttons = init_buttons();
    while (sfRenderWindow_isOpen(window) && struct_game->pause == 1) {
        sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
        while (sfRenderWindow_pollEvent(window, &struct_game->event_g)) {
            if (struct_game->event_g.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (struct_game->event_g.type == sfEvtMouseMoved) {
                sfVector2f cursor1 = sourissprite(sfMouse_getPositionRenderWindow(window));
                sfSprite_setPosition(cursor->cursorsprite, cursor1);
                if ((mouse.x > sfSprite_getPosition(s_buttons->sprite_button3).x && mouse.x <= sfSprite_getPosition(s_buttons->sprite_button3).x + 512) &&
                (mouse.y > sfSprite_getPosition(s_buttons->sprite_button3).y && mouse.y <= sfSprite_getPosition(s_buttons->sprite_button3).y + 127)) {
                    sfSprite_setPosition(s_buttons->sprite_button3, s_buttons->pos_button3_h);
                } else {
                    sfSprite_setPosition(s_buttons->sprite_button3, s_buttons->pos_button3);
                }
            }
            if (struct_game->event_g.type == sfEvtMouseButtonPressed) {
                if ((mouse.x > sfSprite_getPosition(s_buttons->sprite_button3).x && mouse.x <= sfSprite_getPosition(s_buttons->sprite_button3).x + 512) &&
                (mouse.y > sfSprite_getPosition(s_buttons->sprite_button3).y && mouse.y <= sfSprite_getPosition(s_buttons->sprite_button3).y + 127)) {
                    sfRenderWindow_close(window);
                }
                if ((mouse.x > sfSprite_getPosition(s_buttons->sprite_button4).x && mouse.x <= sfSprite_getPosition(s_buttons->sprite_button4).x + 512) &&
                (mouse.y > sfSprite_getPosition(s_buttons->sprite_button4).y && mouse.y <= sfSprite_getPosition(s_buttons->sprite_button4).y + 127)) {
                    sfRenderWindow_close(window);
                    if (struct_menu->music_state == 1 && struct_menu->music_onoff == 0) {
                    sfMusic_stop(struct_game->music);
                    }
                    menu_game(window);
                }
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
        sfRenderWindow_drawSprite(window, s_pause->sprite_pause, NULL);
        sfRenderWindow_drawSprite(window, struct_buttons->sprite_button3, NULL);
        sfRenderWindow_drawSprite(window, struct_buttons->sprite_button4, NULL);
    }
    return struct_game;
}

void draw_popo(sfRenderWindow* window, s_perso_t *s_perso)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(s_perso->clock_popo)) > 150) {
        s_perso->rect_popo.left += (768 / 8);
        if (s_perso->rect_popo.left >= 768) {
            s_perso->rect_popo.left = 0;
            s_perso->pos_popo.y = - 100;
            sfSprite_setPosition(s_perso->sprite_popo ,s_perso->pos_popo);
        }
        sfClock_restart(s_perso->clock_popo);
    }
    sfSprite_setTextureRect(s_perso->sprite_popo, s_perso->rect_popo);
    sfRenderWindow_drawSprite(window, s_perso->sprite_popo, NULL);
}

int my_game(s_menu_game_t *struct_menu, sfRenderWindow* window)
{
    s_my_game_t *struct_game = init_g_struct();
    s_cursor_t *cursor = init_cursor();
    s_perso_t *s_perso = init_perso();
    s_object_t *s_object = init_objects();
    s_life_t *s_life = init_life();
    s_wind_t *s_wind = init_wind();
    s_inventory_t *s_invent = init_invent();
    s_villager_t *struct_villager = init_villager();
    s_button_t *struct_buttons = init_buttons();
    s_villager1_t *struct_villager1 = init_villager1();
    s_villager2_t *struct_villager2 = init_villager2();
    s_chest_t *struct_chest = init_chest();
    if (struct_menu->music_state == 1 && struct_menu->music_onoff == 0) {
        struct_game->music = sfMusic_createFromFile("Music/game_music.ogg");
        sfMusic_setLoop(struct_game->music, sfTrue);
        sfMusic_play(struct_game->music);
        sfMusic_setVolume(struct_game->music, 20);
    }
    sfClock *pause_clock = sfClock_create();
    sfClock *invent_clock = sfClock_create();
    int invent_int = 0, quest_cave = 0, popo = 0;
    struct_villager->quest_state = 0;
    struct_villager->quest_accepted = 0;
    struct_villager->wrong_key = 0;
    s_perso->state_kit = 0;
    struct_villager->good_key = 0;
    struct_villager->end_game = 0;
    init_perso2(s_perso);

    while (sfRenderWindow_isOpen(window)) {
        sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
        while (sfRenderWindow_pollEvent(window, &struct_game->event_g)) {
            if (struct_game->event_g.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (struct_game->event_g.type == sfEvtMouseMoved) {
                sfVector2f cursor1 = sourissprite(sfMouse_getPositionRenderWindow(window));
                sfSprite_setPosition(cursor->cursorsprite, cursor1);
            }
            if (struct_game->event_g.type == sfEvtMouseButtonPressed) {
                if ((mouse.x > sfSprite_getPosition(struct_villager->sprite_yes_button).x && mouse.x <= sfSprite_getPosition(struct_villager->sprite_yes_button).x + 142) &&
                (mouse.y > sfSprite_getPosition(struct_villager->sprite_yes_button).y && mouse.y <= sfSprite_getPosition(struct_villager->sprite_yes_button).y + 58) && struct_villager->quest_state == 1) {
                    struct_villager->quest_state = 0;
                    struct_villager->quest_accepted = 1;
                    quest_cave = 1;
                }
                if ((mouse.x > sfSprite_getPosition(struct_villager->sprite_no_button).x && mouse.x <= sfSprite_getPosition(struct_villager->sprite_no_button).x + 142) &&
                (mouse.y > sfSprite_getPosition(struct_villager->sprite_no_button).y && mouse.y <= sfSprite_getPosition(struct_villager->sprite_no_button).y + 58) && struct_villager->quest_state == 1) {
                    struct_villager->quest_state = 0;
                }
                if ((mouse.x >= sfSprite_getPosition(struct_buttons->sprite_menu_end).x && mouse.x <= sfSprite_getPosition(struct_buttons->sprite_menu_end).x + 512) &&
                (mouse.y > sfSprite_getPosition(struct_buttons->sprite_menu_end).y && mouse.y <= sfSprite_getPosition(struct_buttons->sprite_menu_end).y + 127) && struct_villager->end_game == 1 ) {
                    sfRenderWindow_close(window);
                    if (struct_menu->music_state == 1 && struct_menu->music_onoff == 0) {
                    sfMusic_stop(struct_game->music);
                    }
                    menu_game(window);
                }
            }
            if ((s_perso->pos_perso.x < 250 && s_perso->pos_perso.x > 100 && s_perso->pos_perso.y < 400) && sfKeyboard_isKeyPressed(sfKeyE) && s_perso->object == 1) {
                s_perso->int_chest = 1;
            }

            if ((s_perso->pos_perso.x < 800 && s_perso->pos_perso.x > 600 && s_perso->pos_perso.y < 400) && sfKeyboard_isKeyPressed(sfKeyE) && popo == 0) {
                popo = 1;
                s_perso->next->int_chest = 1;
            }

            if (s_perso->pos_perso.x >= 1000 && s_perso->pos_perso.x <= 1320 && s_perso->pos_perso.y >= 720 && sfKeyboard_isKeyPressed(sfKeyE) && s_perso->object == 0 && struct_villager->quest_accepted == 0) {
                struct_villager->quest_state = 1;
            }

            if (s_perso->pos_perso.x >= 1000 && s_perso->pos_perso.x <= 1320 && s_perso->pos_perso.y >= 720 && sfKeyboard_isKeyPressed(sfKeyE) && s_perso->object == 1) {
                struct_villager->wrong_key = 1;
            }

            if (s_perso->pos_perso.x >= 1000 && s_perso->pos_perso.x <= 1320 && s_perso->pos_perso.y >= 720 && sfKeyboard_isKeyPressed(sfKeyE) && struct_villager->good_key == 1 && s_perso->object == 0) {
                struct_villager->end_game = 1;
                sfSprite_setTexture(s_invent->sprite_invent, s_invent->text_invent_key, sfTrue);
                sfClock_restart(struct_game->clock_end_game);
                s_perso->object = 0;
            }

            if (s_perso->pos_perso.x >= 1300 && s_perso->pos_perso.x <= 1500 && s_perso->pos_perso.y <= 450 && s_perso->pos_perso.y >= 300 && sfKeyboard_isKeyPressed(sfKeyE)) {
                s_perso->state_kit = 1;
            }
            if (sfKeyboard_isKeyPressed(sfKeyEscape) && sfTime_asMilliseconds(sfClock_getElapsedTime(pause_clock)) > 100) {
                struct_game->pause = 1;
            }
            if ((sfKeyboard_isKeyPressed(sfKeyTab) && invent_int == 1) && sfTime_asMilliseconds(sfClock_getElapsedTime(invent_clock)) > 50) {
                invent_int = 0;
                sfClock_restart(invent_clock);
            } else if ((sfKeyboard_isKeyPressed(sfKeyTab) && invent_int == 0) && sfTime_asMilliseconds(sfClock_getElapsedTime(invent_clock)) > 50) {
                invent_int = 1;
                sfClock_restart(invent_clock);
            }
            if (sfKeyboard_isKeyPressed(sfKeyRight)) {
                sfSprite_setTexture(s_perso->sprite_perso, s_perso->text_perso, sfTrue);
                s_perso->right = 1;
            } else if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
                sfSprite_setTexture(s_perso->sprite_perso, s_perso->text_perso_l, sfTrue);
                s_perso->left = 1;
            }
            if (sfKeyboard_isKeyPressed(sfKeyUp)) {
                sfSprite_setTexture(s_perso->sprite_perso, s_perso->text_perso_do, sfTrue);
                s_perso->up = 1;
            } else if (sfKeyboard_isKeyPressed(sfKeyDown)) {
                sfSprite_setTexture(s_perso->sprite_perso, s_perso->text_perso_up, sfTrue);
                s_perso->down = 1;
            }
        }
        if (struct_game->pause == 1) {
            struct_game = print_pause(window, struct_game, s_perso, cursor, struct_buttons, struct_menu);
            sfClock_restart(pause_clock);
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
            if (struct_menu->music_state == 1 && struct_menu->music_onoff == 0) {
            sfMusic_stop(s_perso->music_popo);
            sfMusic_play(s_perso->music_popo);
            }
        }
        print_bubble(s_object, s_perso, struct_villager, window);
        if ((s_perso->pos_perso.x >= 1720 && s_perso->pos_perso.y <= 230) && quest_cave == 1) {
            if (struct_menu->music_state == 1 && struct_menu->music_onoff == 0)
            sfMusic_stop(struct_game->music);
            s_perso = cave(window, s_perso, struct_menu, s_invent);
            if (struct_menu->music_state == 1 && struct_menu->music_onoff == 0) {
                sfMusic_play(struct_game->music);
            }
            less_hp_fct(s_perso, s_life);
            if (s_perso->ret == 1) {
                s_perso->pos_perso.x = 1715;
                s_perso->pos_perso.y = 300;
            }
            else break;
        }
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(s_wind->clock_w)) > 250) {
            s_wind->rect_w.left += (1500 / 15);
            if (s_wind->rect_w.left >= 1500) s_wind->rect_w.left = 0;
            sfClock_restart(s_wind->clock_w);
        }
        sfSprite_setTextureRect(s_wind->sprite_wind, s_wind->rect_w);

        if (sfTime_asMilliseconds(sfClock_getElapsedTime(s_wind->next->clock_w)) > 250) {
            s_wind->next->rect_w.left += (1500 / 15);
            if (s_wind->next->rect_w.left >= 1500) s_wind->next->rect_w.left = 0;
            sfClock_restart(s_wind->next->clock_w);
        }
        sfSprite_setTextureRect(s_wind->next->sprite_wind, s_wind->next->rect_w);
        if (struct_villager->quest_state == 1) {
            sfRenderWindow_drawSprite(window, struct_villager->sprite_quest, NULL);
            sfRenderWindow_drawSprite(window, struct_villager->sprite_yes_button, NULL);
            sfRenderWindow_drawSprite(window, struct_villager->sprite_no_button, NULL);
        }
        if (invent_int == 1) {
            if (s_perso->object == 1 && s_perso->int_chest == 0)
                sfSprite_setTexture(s_invent->sprite_invent, s_invent->text_invent_key, sfTrue);
            sfRenderWindow_drawSprite(window, s_invent->sprite_invent, NULL);
            sfRenderWindow_drawSprite(window, s_life->sprite_life, NULL);
            if (sfTime_asMilliseconds(sfClock_getElapsedTime(s_perso->next->player_clock)) > 200) {
                s_perso->next->player_rect.left += (855 / 3);
                if (s_perso->next->player_rect.left >= 855)
                    s_perso->next->player_rect.left = 0;
                sfClock_restart(s_perso->next->player_clock);
            }
            if (s_perso->left == 1) {
                sfSprite_setTexture(s_perso->next->sprite_perso, s_perso->next->text_perso_l, sfTrue);
            }
            if (s_perso->right == 1) {
                sfSprite_setTexture(s_perso->next->sprite_perso, s_perso->next->text_perso, sfTrue);
            }
            if (s_perso->up == 1) {
                sfSprite_setTexture(s_perso->next->sprite_perso, s_perso->next->text_perso_do, sfTrue);
            }
            if (s_perso->down == 1) {
                sfSprite_setTexture(s_perso->next->sprite_perso, s_perso->next->text_perso_up, sfTrue);
            }
            sfSprite_setTextureRect(s_perso->next->sprite_perso, s_perso->next->player_rect);
            sfSprite_setPosition(s_perso->next->sprite_perso ,s_perso->next->pos_perso);
            sfRenderWindow_drawSprite(window, s_perso->next->sprite_perso, NULL);
        }
        if (s_perso->state_kit == 1 && invent_int == 1) {
            sfRenderWindow_drawSprite(window, s_invent->sprite_sword, NULL);
        }
        if (invent_int == 1 && s_perso->next->int_chest == 1) {
            sfRenderWindow_drawSprite(window, s_invent->sprite_potion, NULL);
        }
        if (s_perso->state_kit == 1) {
            if (s_invent->pos_sword_fx.y > - 100) {
                s_invent->pos_sword_fx.y -= 0.8;
                sfClock_restart(s_invent->clock_fx);
            }
            sfSprite_setPosition(s_invent->sprite_sword_fx ,s_invent->pos_sword_fx);
            sfRenderWindow_drawSprite(window, s_invent->sprite_sword_fx, NULL);
            if ((sfTime_asMilliseconds(sfClock_getElapsedTime(s_invent->clock_fx)) < 3))
                sfRenderWindow_drawSprite(window, s_invent->sprite_sword_fx2, NULL);
        }

        if (s_perso->next->int_chest == 1) {
            sfSprite_setPosition(s_invent->sprite_sword_fx2, (sfVector2f) {1600, -100});
            if (s_invent->pos_potion_fx.y > - 100) {
                s_invent->pos_potion_fx.y -= 0.8;
                sfClock_restart(s_invent->clock_fx);
            }
            sfSprite_setPosition(s_invent->sprite_potion_fx , s_invent->pos_potion_fx);
            sfRenderWindow_drawSprite(window, s_invent->sprite_potion_fx, NULL);
        }

        s_perso = movement_perso(s_perso);
        if (struct_villager->quest_accepted == 1 && (struct_villager->yannis == 0)) {
            sfClock_restart(struct_villager->clock_achievement);
            struct_villager->yannis = 1;
        }
        if ((sfTime_asMilliseconds(sfClock_getElapsedTime(struct_villager->clock_achievement)) < 3000) && struct_villager->quest_accepted == 1) {
            sfRenderWindow_drawSprite(window, struct_villager->sprite_achievement, NULL);
        }
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(s_perso->player_clock)) > 200) {
            s_perso->player_rect.left += (288 / 3);
            if (s_perso->player_rect.left >= 288) s_perso->player_rect.left = 0;
            sfClock_restart(s_perso->player_clock);
        }
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(struct_villager->clock_villager)) > 150) {
            struct_villager->rect_villager.left += (518 / 7);
            if (struct_villager->rect_villager.left >= 518) struct_villager->rect_villager.left = 0;
            sfClock_restart(struct_villager->clock_villager);
        }
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(struct_villager1->clock_villager)) > 150) {
            struct_villager1->rect_villager.left += (100);
            if (struct_villager1->rect_villager.left >= 1600) struct_villager1->rect_villager.left = 0;
            sfClock_restart(struct_villager1->clock_villager);
        }
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(struct_villager2->clock_villager)) > 400) {
            struct_villager2->rect_villager.left += (340 / 4);
            if (struct_villager2->rect_villager.left >= 340) struct_villager2->rect_villager.left = 0;
            sfClock_restart(struct_villager2->clock_villager);
        }

        sfRenderWindow_drawSprite(window, cursor->cursorsprite, NULL);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, struct_game->sprite_bg_g, NULL);
        sfRenderWindow_drawSprite(window, struct_chest->sprite_chest, NULL);
        sfRenderWindow_drawSprite(window, struct_chest->next->sprite_chest, NULL);
        sfRenderWindow_drawSprite(window, s_wind->sprite_wind, NULL);
        sfRenderWindow_drawSprite(window, s_wind->next->sprite_wind, NULL);
        if (struct_villager->good_key == 1)
            sfRenderWindow_drawSprite(window, struct_villager->sprite_endquest, NULL);
        if (struct_villager->end_game == 1) {
            sfSprite_setTexture(s_invent->sprite_invent, s_invent->text_invent, sfTrue);
            sfRenderWindow_drawSprite(window, struct_villager->sprite_thanks, NULL);
        }

        if ((s_perso->pos_perso.x < 800 && s_perso->pos_perso.y < 400) && s_perso->int_chest == 1 && s_perso->object == 1) {
            sfSprite_setTextureRect(struct_chest->sprite_chest, struct_chest->rect_chest);
            sfSprite_setTexture(s_invent->sprite_invent, s_invent->text_invent, sfTrue);
            if ((sfTime_asMilliseconds(sfClock_getElapsedTime(struct_chest->clock_chest)) > 150) && struct_chest->rect_chest.left < 300) {
                struct_chest->rect_chest.left += (432 / 9);
                sfClock_restart(struct_chest->clock_chest);
            }
        }

        if ((s_perso->pos_perso.x < 800 && s_perso->pos_perso.y < 400) && s_perso->next->int_chest == 1) {
            sfSprite_setTextureRect(struct_chest->next->sprite_chest, struct_chest->next->rect_chest);
            sfSprite_setTexture(s_invent->sprite_invent, s_invent->text_invent, sfTrue);
            if ((sfTime_asMilliseconds(sfClock_getElapsedTime(struct_chest->next->clock_chest)) > 150) && struct_chest->next->rect_chest.left < 300) {
                struct_chest->next->rect_chest.left += (432 / 9);
                sfClock_restart(struct_chest->next->clock_chest);
            }
        }
        if ((sfTime_asSeconds(sfClock_getElapsedTime(struct_chest->clock_chest)) > 1) && s_perso->int_chest == 1) {
            sfSprite_setTexture(s_invent->sprite_invent, s_invent->text_invent_2key, sfTrue);
            s_perso->object = 0;
            struct_villager->good_key = 1;
            struct_villager->wrong_key = 0;
        }
        if (struct_villager->good_key == 1) {
            if (s_invent->pos_blue.y > - 100) s_invent->pos_blue.y -= 0.6;
            sfSprite_setPosition(s_invent->sprite_fx_blue , s_invent->pos_blue);
            sfRenderWindow_drawSprite(window, s_invent->sprite_fx_blue, NULL);
        }
        if (struct_villager->wrong_key == 1) {
            sfRenderWindow_drawSprite(window, struct_villager->sprite_wrong_key, NULL);
        }
        sfSprite_setTextureRect(s_perso->sprite_perso, s_perso->player_rect);
        sfSprite_setPosition(s_perso->sprite_perso ,s_perso->pos_perso);
        sfRenderWindow_drawSprite(window, s_perso->sprite_perso, NULL);
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(s_object->horloge_tree)) > 200) {
            s_object->tree_rect.left += (1024 / 8);
            if (s_object->tree_rect.left >= 1024) s_object->tree_rect.left = 0;
            sfClock_restart(s_object->horloge_tree);
        }
        sfSprite_setTextureRect(s_object->sprite_tree, s_object->tree_rect);
        sfRenderWindow_drawSprite(window, s_object->sprite_tree, NULL);
        sfRenderWindow_drawText(window, s_perso->texte_obj, NULL);
        sfRenderWindow_drawText(window, s_perso->texte_int, NULL);

        s_perso = movement_perso(s_perso);
        sfSprite_setTextureRect(struct_villager->sprite_villager, struct_villager->rect_villager);
        sfSprite_setPosition(struct_villager->sprite_villager, struct_villager->pos_villager);
        sfRenderWindow_drawSprite(window, struct_villager->sprite_villager, NULL);
        sfSprite_setTextureRect(struct_villager1->sprite_villager, struct_villager1->rect_villager);
        sfSprite_setPosition(struct_villager1->sprite_villager, struct_villager1->pos_villager);
        sfRenderWindow_drawSprite(window, struct_villager1->sprite_villager, NULL);
        sfSprite_setTextureRect(struct_villager2->sprite_villager, struct_villager2->rect_villager);
        sfSprite_setPosition(struct_villager2->sprite_villager, struct_villager2->pos_villager);
        sfRenderWindow_drawSprite(window, struct_villager2->sprite_villager, NULL);
        draw_popo(window, s_perso);

        if (struct_villager->end_game == 1 && sfTime_asMilliseconds(sfClock_getElapsedTime(struct_game->clock_end_game)) > 3000) {
            sfRenderWindow_drawSprite(window, struct_game->sprite_endscreen, NULL);
            sfRenderWindow_drawSprite(window, struct_buttons->sprite_menu_end, NULL);
        }
    }
    sfSprite_destroy(cursor->cursorsprite);
    sfSprite_destroy(struct_game->sprite_bg_g);
    sfSprite_destroy(s_perso->sprite_perso);
    sfMusic_destroy(struct_game->click_g);
    if (struct_menu->music_state == 1 && struct_menu->music_onoff == 0) {
        sfMusic_destroy(struct_game->music);
    }

    return (0);
}