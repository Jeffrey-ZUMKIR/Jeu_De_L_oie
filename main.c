#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LOWROLE 1
#define HIGHROLE 6
#define FINISHLINE 66
#define DEADCASE 58

int deplacement(int joueur);
int checkPlacement(int joueur);

int main()
{
    srand(time(0));
    int joueur=0;
    //Lancer une boucle pour continuer le jeu tant qu'il n'est pas finit
    while (joueur!=FINISHLINE){
        //Déplacer le joueur
        joueur+=deplacement(joueur);
        //Vérification de l'emplacement
        joueur=checkPlacement(joueur);
        //Indication de la case actuelle
        printf("Case : %d\n", joueur);
        //Permettre de marquer un temps de pause
        if(joueur!=FINISHLINE){
            system("pause");
        }
    }
    //Afficher le résultat à la fin du jeu
    printf("Victoire");
    return 0;
}
//But: produire deux nombres randoms pour reproduire les deux dés
int deplacement(int joueur) {
    int som=0;
    int dice1=0;
    int dice2=0;
    //Vérification que les nombres sont correctes
    while(((dice1<LOWROLE) || (dice1>HIGHROLE))&&((dice2<LOWROLE) || (dice2>HIGHROLE))){
        //Premier nombre
        dice1 = (rand()%(HIGHROLE - LOWROLE + 1)) + LOWROLE;
        //Deuxième nombre
        dice2 = (rand()%(HIGHROLE - LOWROLE + 1)) + LOWROLE;
    }
    //Affichage de la valeur des dés
    printf("Dice 1 : %d\n", dice1);
    printf("Dice 2 : %d\n", dice2);
    //Additionner les deux valeurs
    som=dice1+dice2;
    //Vérification si le joueur se trouve sur une case spéciale, si oui on double la valeur
    if(((joueur+som)%9==0)&&(joueur+som<63)){
        som*=2;
        printf("Jet double!\n");
    }
    //Ajoute les déplacements au joueur
    return som;
}

//But: Vérification sur la zone ou se trouve le joueur
int checkPlacement(int joueur){
    int placement=joueur;
    //Si le joueur a dépassé la dernière case, on le fait reculé
    if(placement>FINISHLINE){
        placement=FINISHLINE-(placement-FINISHLINE);
    }
    //Si le joueur se trouve sur la case tête de mort, il retourne à la case 0
    if(placement==DEADCASE){
        placement=0;
    }
    return placement;
}
