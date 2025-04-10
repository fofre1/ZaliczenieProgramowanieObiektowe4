// test.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
//Itemy liczba co znaczy:
// 1 - weapon
// 2 - armor
// 3 - head_armor
// 4 - chestplate
// 5 - left hand
// 6 - right hand
// 7 - leggins
// 8 - left boot
// 9 - right boot
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <stdlib.h>

struct item {
    char name[50];
    int dmg;
    float penetracja;
    int wytrzymalosc;
    float weight;
    int slots;
    int hand_slot;
    int hp;
    float resist;
    int typeOfItem;
    int fire_attack;
    int poison_attack;
    int stun_attack;
    int hp_modifier;
    int armor_modifier;
    int dodge_modifier;
};

struct backpack2 {
    item* plecak_item;
    int weight;
    int current_item_slot = 0;
};

struct backpack {
    item* plecak_item;
    int weight;
    int current_item_slot=0;
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
    int inv_slots[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    item* right_hand;
    item* left_hand;
    item* head;
    item* chestplate;
    item* leggins;
    item* left_boot;
    item* right_boot;
    backpack* plecak;
    backpack2** plecak2;
};

champ generate(champ* current, int plecak_size, int plecak_rows, int plecak_collums) {

    current->hp = (15 + rand() % 45) ;
    current->resist = (1 + rand() % 3);
    current->sila= (1 + rand() % 4);
    current->plecak = (backpack*)malloc(sizeof(backpack) * plecak_size);
    current->plecak2 = (backpack2**)malloc(sizeof(backpack*) * plecak_rows);
    for (int i = 0; i < plecak_rows; i++) {
        current->plecak2[i] = (backpack2*)malloc(sizeof(backpack2) * plecak_collums);
    }
    return *current;
}

item generate(item* current) {
    current->dmg = (1 + rand() % 6);
    current->penetracja = (100 + rand() % 60)/100.0;
    current->wytrzymalosc = (169 + rand() % 345);
    current->weight = (2 + rand() % 6) / 2.0;
    current->hand_slot = (1 + rand() % 2);
    current->typeOfItem = 1;
    current->slots = 0;
    if ((1 + rand() % 5) == 1)
    {
        current->slots++;
        if ((1 + rand() % 15) == 1)
        {
            current->slots++;
        }
    }
    current->hp = (58 + rand() % 129);
    current->resist = (1 + rand() % 7);
    //current->typeOfItem = (1 + rand % 9); // Losowanie do jakiego slota wchodzi item, patrz samą górę, linijke 1 ^
    return *current;
}


/*float calc_hit_point(weapon bron, champ postac, champ przeciwnik)
{
    float hit_point = (pow(log(bron.dmg), 2) + 3) * 2 * bron.penetracja * przeciwnik.sila / postac.resist;
    return hit_point;
}*/

void add_item(champ* postac, item* current_item) {
    printf("%i", current_item->typeOfItem);
    if (postac->inv_slots[current_item->typeOfItem - 1] == 0) {
        switch (current_item->typeOfItem) {
        case 1:
            postac->left_hand = current_item;
            printf("a");
            break;
        case 2:
            postac->right_hand = current_item;
            printf("b");
            break;
        case 3:
            postac->head = current_item;
            printf("c");
            break;
        case 4:
            postac->chestplate = current_item;
            printf("d");
            break;
        case 5:
            postac->left_hand = current_item;
            printf("e");
            break;
        case 6:
            postac->right_hand = current_item;
            printf("f");
            break;
        case 7:
            postac->leggins = current_item;
            printf("g");
            break;
        case 8:
            postac->left_boot = current_item;
            printf("h");
            break;
        case 9:
            postac->right_boot = current_item;
            printf("i");
            break;
        default:
            printf("j");
            break;
        }
        postac->inv_slots[current_item->typeOfItem - 1]++;
    }
    else {
        printf("Slot jest zajety");
    }
}

/*void add_item_to_backpack(champ* postac, item* przedmiot) {
    postac->plecak->plecak_item[postac->plecak->current_item_slot] = przedmiot;
    postac->plecak->current_item_slot++;
}*/

void add_item_to_backpack2(champ* postac, item* przedmiot, int posX, int posY) {
    postac->plecak2[posX][posY].plecak_item = przedmiot;
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
    int plecak_size = 50;
    int plecak_collumns = 10, plecak_rows = 10, posX=1, posY=1;
    srand(time(NULL));
    backpack playerBackpack;
    item *przedmiot = (item*)malloc(sizeof(item)), *przedmiot2 = (item*)malloc(sizeof(item)), *przedmiot3 = (item*)malloc(sizeof(item));
    champ* postac = (champ*)malloc(sizeof(champ));
    generate(postac, plecak_size, plecak_rows, plecak_collumns);
    generate(przedmiot);
    add_item(postac, przedmiot);
    //add_item_to_backpack2(postac, przedmiot, posX, posY);
    //posX++;
    //posY++;
    generate(przedmiot2);
    add_item(postac, przedmiot2);
    //add_item_to_backpack2(postac, przedmiot2, posX, posY);
    //posX++;
    //posY++;
    generate(przedmiot3);
    add_item(postac, przedmiot3);
    //add_item_to_backpack2(postac, przedmiot3, posX, posY);

    /*add_item_weapon(postac, przedmiot);
    add_item_weapon(postac, przedmiot2);
    add_item_weapon(postac, przedmiot3);*/

    //add_item_weapon(&postac, &miecz);
    /*postac.hp += 15;
    postac.armor += 3;
    postac.sila += 3;
    przeciwnik = generate(przeciwnik);
    walka(postac, przeciwnik, miecz, miecz2);*/
    free(przedmiot);
    free(przedmiot2);
    free(przedmiot3);
    for (int i = 0; i < plecak_collumns; i++)
        if(postac->plecak2[i]!=NULL) free(postac->plecak2[i]);
    free(postac->plecak2);
    free(postac);

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
