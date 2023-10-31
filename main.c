#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define LONGUEUR 10
#define LARGEUR 20
int snoopyX=LONGUEUR-1;
int snoopyY=LARGEUR/2;
char snoopy=0xC;
int oiseau1X=0;
int oiseau1Y=0;
int oiseau2X=0;
int oiseau2Y=LARGEUR-1;
int oiseau3X=LONGUEUR-1;
int oiseau3Y=0;
int oiseau4X=LONGUEUR-1;
int oiseau4Y=LARGEUR-1;
char oiseau = 0x6;

void plateau(){
    int background=2 ;
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,background*16);
    for (int i = 0; i < LONGUEUR; ++i) {
        for (int j = 0; j <LARGEUR ; ++j) {

            if(i== snoopyX && j== snoopyY){
                printf("%c",snoopy);
            }
            else if(i==oiseau1X && j== oiseau1Y){
                printf("%c",oiseau);
            }
            else if(i==oiseau2X && j== oiseau2Y){
                printf("%c",oiseau);
            }
            else if(i==oiseau3X && j== oiseau3Y){
                printf("%c",oiseau);
            }
            else if(i==oiseau4X && j== oiseau4Y){
                printf("%c",oiseau);
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}

char trouver(){
    int nboiseaux;
        if(oiseau1X== snoopyX && oiseau1Y== snoopyY){
            printf("Vous avez un oiseau");
            nboiseaux++;
        }
        else if(oiseau2X== snoopyX && oiseau2Y== snoopyY){
            printf("Vous avez un oiseau");
            nboiseaux++;
        }
        else if(oiseau3X== snoopyX && oiseau3Y== snoopyY){
            printf("Vous avez un oiseau");
            nboiseaux++;
        }
        else if(oiseau4X== snoopyX && oiseau4Y== snoopyY){
            printf("Vous avez un oiseau");
            nboiseaux++;
        }
    if(nboiseaux==4){
        printf("Le niveau est fini.");
        return 0;
    }

}
void sauvegarde(){
    char nomFichier[50];
    printf("Entrez le nom du fichier de sauvegarde : ");
    scanf("%s", nomFichier);
    Sleep(500);
    FILE *fichier;
    fichier = fopen(nomFichier, "w");

    // Écriture des positions actuelles des éléments dans le fichier
    fprintf(fichier, "Snoopy : (%d, %d)\n", snoopyX, snoopyY);
    fprintf(fichier, "Oiseau1 : (%d, %d)\n", oiseau1X, oiseau1Y);
    fprintf(fichier, "Oiseau2 : (%d, %d)\n", oiseau2X, oiseau2Y);
    fprintf(fichier, "Oiseau3 : (%d, %d)\n", oiseau3X, oiseau3Y);
    fprintf(fichier, "Oiseau4 : (%d, %d)\n", oiseau4X, oiseau4Y);

    fclose(fichier);

    printf("Partie sauvegardee dans le fichier : %s\n", nomFichier);

}

void chargerPartie(const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "r");

    // Variables pour stocker les données lues depuis le fichier
    int sX, sY, o1X, o1Y, o2X, o2Y, o3X, o3Y, o4X, o4Y;

    // Lire les données du fichier pour restaurer l'état du jeu
    fscanf(fichier, "Snoopy : (%d, %d)\n", &sX, &sY);
    fscanf(fichier, "Oiseau1 : (%d, %d)\n", &o1X, &o1Y);
    fscanf(fichier, "Oiseau2 : (%d, %d)\n", &o2X, &o2Y);
    fscanf(fichier, "Oiseau3 : (%d, %d)\n", &o3X, &o3Y);
    fscanf(fichier, "Oiseau4 : (%d, %d)\n", &o4X, &o4Y);

    // Fermer le fichier après avoir lu les données
    fclose(fichier);

    // Restaurer les valeurs pour la partie en cours
    snoopyX = sX;
    snoopyY = sY;
    oiseau1X = o1X;
    oiseau1Y = o1Y;
    oiseau2X = o2X;
    oiseau2Y = o2Y;
    oiseau3X = o3X;
    oiseau3Y = o3Y;
    oiseau4X = o4X;
    oiseau4Y = o4Y;

    printf("Partie chargée depuis le fichier : %s\n", nomFichier);
}

char touches(char commande){
        switch (commande) {
            case 'r':{
                if(snoopyX>0){
                    snoopyX--;
                }
                break;
            }
            case 'f':{
                if(snoopyX<LONGUEUR-1){
                    snoopyX++;
                }
                break;
            }
            case 'd':{
                if(snoopyY >0){
                    snoopyY--;
                }
                break;
            }
            case 'g':{
                if(snoopyY<LARGEUR-1){
                    snoopyY++;
                }
                break;
            }
            case 's':{
                sauvegarde();
                break;
            }

        }
    }

void timer(){
    int temps = 120;
    int background = 4;
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,background*16);
    for (int i = 0; i < LARGEUR; ++i) {
        printf("%c",0x4);
    }
    Sleep(1000);
    temps--;
    if(temps%6 == 0 && temps<120){
        for (int i = temps; i <LARGEUR ;++i) {
            printf("  ");
        }
    }
}

void boucle(){
    while (1) {
        plateau();
        timer();
        printf("\n");
        trouver();
        if (_kbhit()) {
            char commande = _getch();
            touches(commande);
        }
        Sleep(2000);
    }
}

void menu(){
    int choix;
    printf("BIENVENUE DANS L'EXPEREINECE SNOOPY!!!\n\n");
    printf("1.Regles du jeu\n2.Lancer un nouveau Jeu\n3.Charger une partie\n4.Mot de passe\n5.Scores\n6.Quitter\n");
    scanf("%d",&choix);
    switch (choix) {
        case 1:{
            printf("Les regles du jeu sont les suivantes:\n");
            break;
        }
        case 2:{
            boucle();
            if (_kbhit()) {
                char commande = _getch();
                touches(commande);
            }
            break;

        }
        case 3:{
            char nomFichier[50];
            printf("Entrez le nom du fichier de sauvegarde à charger : ");
            scanf("%s", nomFichier);
            chargerPartie(nomFichier);
            boucle();
            break;

        }
        case 4:{

        }
        case 5:{

        }
        case 6:{
            printf("Vous avez fini");
            break;
        }
    }
}



int main() {
    menu();
    return 0;
}

