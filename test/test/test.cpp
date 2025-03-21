// test.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <stdlib.h>

struct special_item {
    int fire_attack;
    int poison_attack;
    int stun_attack;
    int hp_modifier;
    int armor_modifier;
    int dodge_modifier;
};

struct weapon {
    char name[50];
    int dmg;
    float penetracja;
    int wytrzymalosc;
    float weight;
    int slots;
    int hand_slot;
    special_item modifier1;
    special_item modifier2;
};

struct armor {
    int hp;
    float resist;
    special_item modifier1;
    special_item modifier2;
};

struct backpack {
    int size = 50;
    special_item* plecak_special_items = (special_item*)malloc(sizeof(special_item) * size);
    armor* plecak_armor = (armor*)malloc(sizeof(armor) * size);
    weapon* plecak_miecz = (weapon*)malloc(sizeof(weapon) * size);
    int weight;
    int current_weapon_slot=0;
 
};

struct champ{
    float hp;
    int exp;
    float resist;
    float sila;
    int pozX;
    int pozY;
    float weight;
    int poison_resistance;
    int fire_resistance;
    float dodge;
    int free_left_hand_slot;
    int free_right_hand_slot;
    weapon* right_hand;
    weapon* left_hand;
    armor* head;
    armor* chestplate;
    backpack* plecak;
};




champ generate(champ current) {
    current.hp = (15 + rand() % 45);
    current.resist = (1 + rand() % 3);
    current.sila= (1 + rand() % 4);
    current.free_left_hand_slot = 0;
    current.free_right_hand_slot = 0;
    return current;
}

special_item generate(special_item current) {
    int los1 = rand() % 5, los2 = rand() % 15, los3 = rand()%160;
    if (los1 == 1) {
        current.fire_attack = 1;
    }
    if (los1 == 2) {
        current.poison_attack = 1;
    }
    if (los2 = 10) {
        current.stun_attack = 1;
    }
    if (los1 == 3 && los2 == 1)
    {
        current.fire_attack = 2;
        current.stun_attack = 1;
    }
    if (los1 == 3 && los2 == 11)
    {
        current.poison_attack = 2;
        current.stun_attack = 1;
    }
    if (los1 == 3 && los2 == 5)
    {
        current.poison_attack = 2;
        current.fire_attack = 2;
    }

    if (los3 == 1)
    {
        current.stun_attack = 2;
        current.poison_attack = 1;
        current.fire_attack = 1;
    }

    if (los1 == 1 && los2 == 2 && los3 == 3)
    {
        current.stun_attack = 4;
        current.poison_attack = 4;
        current.fire_attack = 4;
    }


    return current;
}

weapon generate(weapon current) {
    current.dmg = (1 + rand() % 6);
    current.penetracja = (100 + rand() % 60)/100.0;
    current.wytrzymalosc = (169 + rand() % 345);
    current.weight = (2 + rand() % 6) / 2.0;
    current.hand_slot = (1 + rand() % 2);
    current.slots = 0;
    if ((1 + rand() % 5) == 1)
    {
        current.slots++;
        if ((1 + rand() % 15) == 1)
        {
            current.slots++;
        }
    }
    return current;
}

armor generate(armor current) {
    current.hp = (58 + rand() % 129);
    current.resist = (1 + rand() % 7);
    return current;
}

float calc_hit_point(weapon bron, champ postac, champ przeciwnik)
{
    float hit_point = (pow(log(bron.dmg), 2) + 3) * 2 * bron.penetracja * przeciwnik.sila / postac.resist;
    return hit_point;
}

void add_item_weapon(champ* postac, weapon* current_item) {
    printf("1");
    if (current_item->hand_slot == 1 && postac->free_left_hand_slot == 0) {
        postac->left_hand = current_item;
        postac->free_left_hand_slot++;
        printf("a");
    }
    else if(current_item->hand_slot == 2 && postac->free_right_hand_slot==0){
        postac->right_hand = current_item;
        postac->free_right_hand_slot++;
        printf("b");
    }
    else {
    }
    printf("2");
}

void add_weapon_backpack(champ* postac, weapon* bron) {
    postac->plecak->plecak_miecz[postac->plecak->current_weapon_slot] = bron;
    postac->plecak->current_weapon_slot++;
}

/*void walka(champ postac, champ przeciwnik, weapon bron_champ, weapon bron_przeciwnik) {
    float my_dmg, enemy_dmg;
    char wybor;
    while (1)
    {
        printf("HP twoje:%f.0 \nHP przeciwnika: %f.0\n", postac.hp, przeciwnik.hp);
        my_dmg = calc_hit_point(bron_champ, przeciwnik, postac);
        enemy_dmg = calc_hit_point(bron_przeciwnik, postac, przeciwnik)-(1 + rand() % 3);
        postac.hp -= enemy_dmg;
        przeciwnik.hp -= my_dmg;
        printf("Zdales:%f dmg\nOtrzymales:%f dmg\n", my_dmg, enemy_dmg);
        if (przeciwnik.hp <= 0) {
            printf("Gratulacje, pokonales przeciwnika");
            break;
        }
        if (postac.hp <= 0) {
            printf("Niestety przegrales");
            break;
        }
        printf("Kontynuuj walke: 1\nUcieknij: 2");
        scanf("%c", &wybor);
        if (wybor != '1') break;
        else {
            system("CLS");
        }
    }
}
*/

int main()
{
    srand(time(NULL));
    backpack playerBackpack;
    weapon miecz = { 0,0 }, miecz2 = { 0,0 }, miecz3 = { 0,0 };
    special_item wzmocnienie = { 0,0 };
    champ postac = { 0,0 }, przeciwnik = { 0,0 };
    miecz=generate(miecz);
    miecz2 = generate(miecz2);
    miecz3 = generate(miecz3);
    wzmocnienie = generate(wzmocnienie);
    postac = generate(postac);
    add_item_weapon(&postac, &miecz);
    /*postac.hp += 15;
    postac.armor += 3;
    postac.sila += 3;
    przeciwnik = generate(przeciwnik);
    walka(postac, przeciwnik, miecz, miecz2);*/
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
