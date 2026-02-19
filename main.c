
#include <stdio.h>
#include <stdlib.h>

typedef struct Nod {
    int cheie;
    struct Nod* stang;
    struct Nod* drept;
} Nod;

Nod* creareNod(int cheie) {
    Nod* nou = (Nod*)malloc(sizeof(Nod));
    nou->cheie = cheie;//val c in nn
    nou->stang = nou->drept = NULL; ////Inițializează c si ci la n
    return nou; //nod
}

Nod* inserare(Nod* radacina, int cheie) {
    if (radacina == NULL) return creareNod(cheie);//gol ->nod nou
    if (cheie < radacina->cheie) // mică decât cheia nodului curent
        radacina->stang = inserare(radacina->stang, cheie);//subarbore
    else if (cheie > radacina->cheie)
        radacina->drept = inserare(radacina->drept, cheie);
    return radacina;
}

void afisareInordine(Nod* radacina) {
    if (radacina) {
        afisareInordine(radacina->stang);//parcurge sub s
        printf("%d ", radacina->cheie); //nod
        afisareInordine(radacina->drept);
    }
}

int adancimeArbore(Nod* radacina) {
    if (radacina == NULL) return 0; // Arbore gol → adâncime 0
    int st = adancimeArbore(radacina->stang); //cea mai lungă cale  r la frz
    int dr = adancimeArbore(radacina->drept); //calc adancime dr
    return 1 + (st > dr ? st : dr);
}
                                //
Nod* cautare(Nod* radacina, int cheie) {
    if (radacina == NULL || radacina->cheie == cheie) return radacina; //// Găsit sau arbore gol
    if (cheie < radacina->cheie) //<s
        return cautare(radacina->stang, cheie);
    return cautare(radacina->drept, cheie); //>d
}

int adancimeNod(Nod* radacina, int cheie, int nivel) {
    if (radacina == NULL) return -1; // Nu s-a găsit nodul
    if (radacina->cheie == cheie) return nivel; // Nod găsit → returnează n curent
    if (cheie < radacina->cheie)
        return adancimeNod(radacina->stang, cheie, nivel + 1);// cauta s
    return adancimeNod(radacina->drept, cheie, nivel + 1);//d
}

int inaltimeNod(Nod* radacina) {
    if (radacina == NULL) return 0; // Nod nul → înălțime 0
    int st = inaltimeNod(radacina->stang); //inaltime s
    int dr = inaltimeNod(radacina->drept); //d
    return 1 + (st > dr ? st : dr);
}

// if (st > dr) {
//     st
// } else {
//     dr
// }

void afisareFrunze(Nod* radacina) {
    if (radacina) {
        if (radacina->stang == NULL && radacina->drept == NULL)
            printf("%d ", radacina->cheie);
        afisareFrunze(radacina->stang);
        afisareFrunze(radacina->drept);
    }
}

void curatare(Nod** radacina) {
    if (*radacina) {
        curatare(&(*radacina)->stang);
        curatare(&(*radacina)->drept);
        free(*radacina);
        *radacina = NULL;
    }
}

int main() {
    Nod* radacina = NULL;
    int optiune, cheie;

    do {
        printf("\n--- Meniu ---\n");
        printf("1. Inserare nod\n");
        printf("2. Afisare arbore (inordine)\n");
        printf("3. Calcul adancime arbore\n");
        printf("4. Cautare nod\n");
        printf("5. Calcul adancime nod\n");
        printf("6. Calcul inaltime nod\n");
        printf("7. Afisare frunze\n");
        printf("8. Curatare arbore\n");
        printf("9. Iesire\n");
        printf("Optiune: ");
        scanf("%d", &optiune);

        switch (optiune) {
            case 1:
                printf("Cheia: ");
                scanf("%d", &cheie);
                radacina = inserare(radacina, cheie);
                break;
            case 2:
                printf("Arbore (inordine): ");
                afisareInordine(radacina);
                printf("\n");
                break;
            case 3:
                printf("Adancime arbore: %d\n", adancimeArbore(radacina));
                break;
            case 4:
                printf("Cheia: ");
                scanf("%d", &cheie);
                if (cautare(radacina, cheie))
                    printf("Nodul exista.\n");
                else
                    printf("Nodul NU exista.\n");
                break;
            case 5:
                printf("Cheia nodului: ");
                scanf("%d", &cheie);
                int ad = adancimeNod(radacina, cheie, 0);
                if (ad >= 0)
                    printf("Adancimea nodului: %d\n", ad);
                else
                    printf("Nodul nu exista.\n");
                break;
            case 6:
                printf("Cheia nodului: ");
                scanf("%d", &cheie);
                Nod* nodGasit = cautare(radacina, cheie);
                if (nodGasit)
                    printf("Inaltimea nodului: %d\n", inaltimeNod(nodGasit) - 1);
                else
                    printf("Nodul nu exista.\n");
                break;
            case 7:
                printf("Frunzele arborelui: ");
                afisareFrunze(radacina);
                printf("\n");
                break;
            case 8:
                curatare(&radacina);
                printf("Arborele a fost curatat.\n");
                break;
            case 9:
                curatare(&radacina);
                printf("Program incheiat.\n");
                break;
            default:
                printf("Optiune invalida.\n");
        }
    } while (optiune != 9);

    return 0;
}
