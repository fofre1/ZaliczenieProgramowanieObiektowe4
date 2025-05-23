#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <stdlib.h>
#include <conio.h>
#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

struct item {
	int id;
	char name[50];
	int durability;
	int item_type; // 0 - armor, 1 - weapon
	int slot; // 0 - head, 1 - body, 2 - legs, 3 - feet, 4 - weapon
	int slot_type; // 0 - left, 1 - right, 2 - oburęczna
	// bronie
	int dmg;
	// zbroje
	int hp;
	int armor;
};

struct backpack {
	item* items;
};

struct champion {
	char name[50];
	int hp;
	int xp;
	int armor;
	int stength;
	int posX;
	int posY;
	int inv_slots[9];
	// 0 - head, 1 - body, 2 - l_legs, 3 - r_leg, 4- l_feet,  5 - r_feet, 6 - l_hand, 7 - r_hand, 8 - weapon;
	item* head;
	item* chestplate;
	item* left_leggins;
	item* right_leggins;
	item* left_boot;
	item* right_boot;
	item* left_hand;
	item* right_hand;
	item* weapon;
	backpack** backpack;
};

struct skrytka {
	item* item;
	int chest_xp;
	int pos_x;
	int pos_y;
};

struct pulapka {
	int trap_dmg;
	int pos_x;
	int pos_y;
};
struct map {
	int width;
	int height;
	pulapka* traps;
	skrytka* chests;
	int** map;
};

champion* create_champion(int type, champion* current, int backpack_size_X, int backpack_size_Y, const char* name) {
	{
		// 0 -  human, 1 - orc, 2 - troll, 3 - dwarf;
		switch (type) {
		case 0: // Human
			current->hp = 100;
			current->xp = 0;
			current->armor = 5;
			current->stength = 5;
			break;
		case 1: // Orc
			current->hp = 110;
			current->xp = 0;
			current->armor = 3;
			current->stength = 8;
			break;
		case 2: // Goblin
			current->hp = 80;
			current->xp = 0;
			current->armor = 2;
			current->stength = 4;
			break;
		case 3: // Dwarf
			current->hp = 90;
			current->xp = 0;
			current->armor = 8;
			current->stength = 5;
			break;
		default: // Domyślnie human
			current->hp = 100;
			current->xp = 0;
			current->armor = 5;
			current->stength = 5;
			break;
		}
		strncpy(current->name, name, sizeof(current->name) - 1);
		current->name[sizeof(current->name) - 1] = '\0';
		for (int i = 0; i < 9; ++i) current->inv_slots[i] = 0;
		current->posX = 0;
		current->posY = 0;
		current->head = nullptr;
		current->chestplate = nullptr;
		current->left_leggins = nullptr;
		current->right_leggins = nullptr;
		current->left_boot = nullptr;
		current->right_boot = nullptr;
		current->left_hand = nullptr;
		current->right_hand = nullptr;
		current->weapon = nullptr;
		current->backpack = (backpack**)malloc(backpack_size_X * sizeof(backpack*));
		for (int i = 0; i < backpack_size_X; ++i) {
			current->backpack[i] = (backpack*)malloc(backpack_size_Y * sizeof(backpack));
			for (int j = 0; j < backpack_size_Y; ++j) {
				current->backpack[i][j].items = nullptr;
			}
		}
	}
	return current;
}

void get_unique_position(int* x, int* y, int width, int height, char** char_map) {
	do {
		*x = rand() % width;
		*y = rand() % height;
	} while (char_map[*y][*x] != '.');
}

map* generate(map* new_map, int width, int height) {
	new_map->width = width;
	new_map->height = height;
	new_map->map = (int**)malloc(height * sizeof(int*));
	for (int i = 0; i < height; ++i) {
		new_map->map[i] = (int*)malloc(width * sizeof(int));
		for (int j = 0; j < width; ++j) {
			new_map->map[i][j] = 'c';
		}
	}
	int num_traps = 10; // Losujemy liczbę pułapek
	new_map->traps = (pulapka*)malloc(num_traps * sizeof(pulapka));
	for (int i = 0; i < num_traps; ++i) {
		get_unique_position(&new_map->traps[i].pos_x, &new_map->traps[i].pos_y, width, height, (char**)new_map->map);
		new_map->traps[i].trap_dmg = rand() % 10 + 1; // Losujemy obrażenia pułapki
		new_map->map[new_map->traps[i].pos_y][new_map->traps[i].pos_x] = 'T'; // Zaznaczamy pułapkę na mapie
	}
	int num_chests = 12; // Losujemy liczbę skrytek
	new_map->chests = (skrytka*)malloc(num_chests * sizeof(skrytka));
	for (int i = 0; i < num_chests; ++i) {
		get_unique_position(&new_map->chests[i].pos_x, &new_map->chests[i].pos_y, width, height, (char**)new_map->map);
		new_map->chests[i].chest_xp = rand() % 10 + 1; // Losujemy doświadczenie skrytki
		new_map->map[new_map->chests[i].pos_y][new_map->chests[i].pos_x] = 'C'; // Zaznaczamy skrytkę na mapie
	}
	return new_map;
}

void print_char_map(char** char_map, int width, int height) {
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			printf("%c", char_map[y][x]);
		}
		printf("\n");
	}
}

// Funkcja do losowania unikalnych pozycji



void start(int& champion_type, int width, int height) {
	printf("########################################################################################################################");
	for (int i = 0; i < 29; i++) printf("b\n");
	printf("Skalibruj rozmiar okna, tak aby # było na samej górze ekranu, a b było po prawej stronie. \n");
	printf("Nacisnij dowolny przycisk aby kontynuować: ");
	getch();
	system("cls");
	// Górna krawędź
	printf("########################################################################################################################");
	printf("\n");

	// Środek ramki: 28 wierszy
	for (int i = 0; i < 28 - 5; ++i) {
		printf("#");
		if (i == 9)		  printf("	Witaj w grze RPG!                                                                                              ");
		else if (i == 10) printf("	Zacznijmy od wybrania postaci                                                                                  ");
		else if (i == 11) printf("	Każdy typ, posiada nieco inne statystyki początkowe:                                                           ");
		else if (i == 12) printf("		0 - człowiek    | HP: 100 | Siła: 5 | Pancerz: 5                                                       ");
		else if (i == 13) printf("		1 - orc         | HP: 110 | Siła: 8 | Pancerz: 3                                                       ");
		else if (i == 14) printf("		2 - goblin      | HP:  80 | Siła: 4 | Pancerz: 2                                                       ");
		else if (i == 15) printf("		3 - krasnolud   | HP:  90 | Siła: 5 | Pancerz: 8                                                       ");
		else {
			for (int j = 0; j < 118; ++j) printf(" ");
		}
		printf("#\n");
	}

	// Dolna krawędź
	printf("########################################################################################################################");
	printf("\n");

	// Teraz komunikaty i wybór typu postaci
	printf("\nWprowadź swój wybór, uwaga nie będzie można go zmienić.\n");
	printf("Wpisanie innej liczby przypisze automatycznie typ: człowiek.\n");
	printf("Wybrany typ postaci: ");
	scanf("%d", &champion_type);
	getchar();
	system("cls");

	switch (champion_type) {
	case 0:
		printf("           ______\n");
		printf("        .-\"      \"-.\n");
		printf("       /            \\\n");
		printf("      |              |\n");
		printf("      |,  .-.  .-.  ,|\n");
		printf("      | )(__/  \\__)( |\n");
		printf("      |/     /\\     \\|\n");
		printf("      (_     ^^     _)\n");
		printf("       \\__|IIIIII|__/\n");
		printf("        | \\IIIIII/ |\n");
		printf("        \\          /\n");
		printf("         `--------`\n");
		break;
	case 1:
		printf("        -'''''-\n");
		printf("     {           }\n");
		printf("   |\\{ - O | O - }/|\n");
		printf("   \\ \\   ),=,(  /  / \n");
		printf("   (_/\\         /\\_)\n");
		printf("      /_ V+++V _\\ \n");
		printf("       \\___,___/\n");
		break;

	case 2:
		printf("             ,      ,\n");
		printf("            /(.-\"\"-.)\\\n");
		printf("        |\\  \\/      \\/  /|\n");
		printf("        | \\ / =.  .= \\ / |\n");
		printf("        \\( \\   o\\/o   / )/\n");
		printf("         \\_, '-/  \\-' ,_/\n");
		printf("           /   \\__/   \\\n");
		printf("           \\ \\__/\\__/ /\n");
		printf("         ___\\ \\|--|/ /___\n");
		printf("       /`    \\      /    `\\\n");
		printf("      /       '----'       \\\n");
		break;

	case 3:
		printf("        _.._..,_,_\n");
		printf("       (          )\n");
		printf("        ]~,\"-.-~~[\n");
		printf("      .=])' (;  ([\n");
		printf("      | ]:: '    [\n");
		printf("      '=]): .)  ([\n");
		printf("        |:: '    |\n");
		printf("         ~~----~~\n");
		break;

	default:
		break;
	}
	printf("\n\n Teraz czas aby nazwać naszego bohatera: ");
}

int main() {
	srand((unsigned int)time(NULL));
	const int map_width = 30, map_height = 20;
	const int backpack_size_X = 10, backpack_size_Y = 10;
	int champion_type = 0;
	setlocale(LC_ALL, "Polish");
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	start(champion_type, map_width, map_height);
	// Wczytywanie imienia bohatera
	char input_name[50];
	fgets(input_name, sizeof(input_name), stdin);
	size_t len = strlen(input_name);
	if (len > 0 && input_name[len - 1] == '\n') {
		input_name[len - 1] = '\0';
	}
	champion* main_character = (champion*)malloc(sizeof(champion));
	create_champion(champion_type, main_character, backpack_size_X, backpack_size_Y, input_name);
	// Tworzenie mapy x1
	char** char_map = (char**)malloc(map_height * sizeof(char*));
	for (int i = 0; i < map_height; ++i) {
		char_map[i] = (char*)malloc(map_width * sizeof(char));
		for (int j = 0; j < map_width; ++j) {
			char_map[i][j] = '.';
		}
	}
	// Tworzenie mapy x2
	map* mapa = (map*)malloc(sizeof(map));
	mapa->width = map_width;
	mapa->height = map_height;

	// --- PUŁAPKI ---
	int num_traps = 10;
	mapa->traps = (pulapka*)malloc(num_traps * sizeof(pulapka));
	for (int i = 0; i < num_traps; ++i) {
		int x, y;
		get_unique_position(&x, &y, map_width, map_height, char_map);
		mapa->traps[i].pos_x = x;
		mapa->traps[i].pos_y = y;
		mapa->traps[i].trap_dmg = rand() % 10 + 1;
		char_map[y][x] = 'p';
	}

	// --- SKRYTKI ---
	int num_chests = 12;
	mapa->chests = (skrytka*)malloc(num_chests * sizeof(skrytka));
	for (int i = 0; i < num_chests; ++i) {
		int x, y;
		get_unique_position(&x, &y, map_width, map_height, char_map);
		mapa->chests[i].pos_x = x;
		mapa->chests[i].pos_y = y;
		mapa->chests[i].chest_xp = rand() % 10 + 1;
		mapa->chests[i].item = NULL;
		char_map[y][x] = 's';
	}

	// --- GRACZ ---
	int px, py;
	get_unique_position(&px, &py, map_width, map_height, char_map);
	main_character->posX = px;
	main_character->posY = py;
	char_map[py][px] = '@';

	// --- RUCH POSTACI ---
	char move_line[16];
	int turn = 0;
	while (1) {
		system("cls");
		print_char_map(char_map, map_width, map_height);
		printf("Sterowanie: W - góra, S - dół, A - lewo, D - prawo, Q - wyjście\n");
		printf("Imię: %s | Pozycja: (%d, %d) | Tura: %d\n", main_character->name, main_character->posX, main_character->posY, turn);
		printf("Wybierz kierunek ruchu (zatwierdź Enterem): ");

		if (!fgets(move_line, sizeof(move_line), stdin)) break;
		char move = move_line[0];
		if (move == '\n' || move == '\0') continue; // Enter bez znaku
		if (move == 'q' || move == 'Q') break;

		int new_x = main_character->posX;
		int new_y = main_character->posY;

		if (move == 'w' || move == 'W') new_y--;
		if (move == 's' || move == 'S') new_y++;
		if (move == 'a' || move == 'A') new_x--;
		if (move == 'd' || move == 'D') new_x++;

		// Sprawdzenie granic
		if (new_x >= 0 && new_x < map_width && new_y >= 0 && new_y < map_height) {
			char next_field = char_map[new_y][new_x];

			// Przesuń gracza
			char_map[main_character->posY][main_character->posX] = '.';
			main_character->posX = new_x;
			main_character->posY = new_y;
			char_map[main_character->posY][main_character->posX] = '@';
			turn++;

			if (next_field == 'p') {
				printf("\nWszedłeś na pułapkę!\n");
				// Usuwamy pułapkę z mapy logicznej
				for (int i = 0; i < num_traps; ++i) {
					if (mapa->traps[i].pos_x == new_x && mapa->traps[i].pos_y == new_y) {
						mapa->traps[i].pos_x = -1;
						mapa->traps[i].pos_y = -1;
						break;
					}
				}
				char_map[new_y][new_x] = '@';
				printf("Naciśnij Enter, aby kontynuować...");
				while (getchar() != '\n');
			}
			else if (next_field == 's') {
				printf("\nOto przedmioty w skrzynce:\n");
				int found = 0;
				for (int i = 0; i < num_chests; ++i) {
					if (mapa->chests[i].pos_x == new_x && mapa->chests[i].pos_y == new_y) {
						found = 1;
						if (mapa->chests[i].item) {
							item* it = mapa->chests[i].item;
							printf("Nazwa: %s, Wytrzymałość: %d, Typ: %d, Slot: %d, DMG: %d, HP: %d, Armor: %d\n",
								it->name, it->durability, it->item_type, it->slot, it->dmg, it->hp, it->armor);
							free(mapa->chests[i].item);
							mapa->chests[i].item = NULL;
						}
						else {
							printf("Brak przedmiotów w tej skrzynce.\n");
						}
						mapa->chests[i].pos_x = -1;
						mapa->chests[i].pos_y = -1;
						break;
					}
				}
				if (!found) printf("Brak skrytki na tym polu.\n");
				char_map[new_y][new_x] = '@';
				printf("Naciśnij Enter, aby kontynuować...");
				while (getchar() != '\n');
			}
		}
		else {
			printf("\nNieprawidłowy ruch. Naciśnij Enter, aby kontynuować...");
			while (getchar() != '\n');
		}
	}

	// Zwolnienie pamięci
	for (int i = 0; i < map_height; ++i) free(char_map[i]);
	free(char_map);
	free(mapa->traps);
	free(mapa->chests);
	free(mapa);
	free(main_character);

	return 0;
}