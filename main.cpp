#include<bits/stdc++.h>
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include "player.h"
#include "case.h"
#include "game.h"
using namespace std;
#define TAILLE_MAX 1000


int decouv(Case m1[50][50],int n);
void meilleur_score();
void new_meilleurscore(int s);


int main()
{

    FILE* fichier = NULL;
    char k;k='a';
    while(k!='j' && k!='q'){
     if(k=='m'){
    meilleur_score();
}

cout<<"                              j:JOUER"<<endl;
cout<<"                              m:VOIR MEILLEURS SCORES"<<endl;
cout<<"                              q:QUITER"<<endl;




cin>>k;}
if(k=='j'){

player p;
while(decouv(p.m1,p.n)==1 && p.lost==0)
  p.game();


if(p.lost==0){

    cout<<"BRAVO"<<endl;
    cout<<"your score="<<p.score<<endl;
    new_meilleurscore(p.score);
}
}



else if(k=='q')
    return 0;


}
