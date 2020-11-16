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
        //D�placer le joueur
        joueur+=deplacement(joueur);
        //V�rification de l'emplacement
        joueur=checkPlacement(joueur);
        //Indication de la case actuelle
        printf("Case : %d\n", joueur);
        //Permettre de marquer un temps de pause
        if(joueur!=FINISHLINE){
            system("pause");
        }
    }
    //Afficher le r�sultat � la fin du jeu
    printf("Victoire");
    return 0;
}
//But: produire deux nombres randoms pour reproduire les deux d�s
int deplacement(int joueur) {
    int som=0;
    int dice1=0;
    int dice2=0;
    //V�rification que les nombres sont correctes
    while(((dice1<LOWROLE) || (dice1>HIGHROLE))&&((dice2<LOWROLE) || (dice2>HIGHROLE))){
        //Premier nombre
        dice1 = (rand()%(HIGHROLE - LOWROLE + 1)) + LOWROLE;
        //Deuxi�me nombre
        dice2 = (rand()%(HIGHROLE - LOWROLE + 1)) + LOWROLE;
    }
    //Affichage de la valeur des d�s
    printf("Dice 1 : %d\n", dice1);
    printf("Dice 2 : %d\n", dice2);
    //Additionner les deux valeurs
    som=dice1+dice2;
    //V�rification si le joueur se trouve sur une case sp�ciale, si oui on double la valeur
    if(((joueur+som)%9==0)&&(joueur+som<63)){
        som*=2;
        printf("Jet double!\n");
    }
    //Ajoute les d�placements au joueur
    return som;
}

//But: V�rification sur la zone ou se trouve le joueur
int checkPlacement(int joueur){
    int placement=joueur;
    //Si le joueur a d�pass� la derni�re case, on le fait recul�
    if(placement>FINISHLINE){
        placement=FINISHLINE-(placement-FINISHLINE);
    }
    //Si le joueur se trouve sur la case t�te de mort, il retourne � la case 0
    if(placement==DEADCASE){
        placement=0;
    }
    return placement;
}
