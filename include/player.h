#ifndef PLAYER_H
#define PLAYER_H
#include "case.h"
#include<time.h>
#include<iostream>
using namespace std;


class player
{
    public:
        Case m1[50][50];
        int score=0;
        int n;
        int lost=0;
        player() {cout<<"donnez la dimension de la matrice=";
cin>>n;

afficher_matrice(m1,n);
int nbr_mines;
while(nbr_mines>n*n || nbr_mines<0){
cout<<"tapez le nbres de mines=";
cin>>nbr_mines;}
for(int i=0;i<nbr_mines;i++){
    int g,h;

        g=((rand()%n));
        h=((rand()%n));
        m1[g][h].aff='#';
        m1[g][h].val='M';
        m1[g][h].dec=1;


}
afficher_matrice(m1,n);
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
        int s=0;
        if((i!=n-1)&&(m1[i+1][j].val=='M'))
            s++;
        if((i!=0&&(m1[i-1][j].val=='M')))
            s++;
        if((j!=(n-1)&&(m1[i][j+1].val=='M')))
            s++;
        if((i!=n-1)&&(j!=0)&&(m1[i+1][j-1].val=='M'))
            s++;
        if(i!=(n-1)&&j!=(n-1)&&(m1[i+1][j+1].val=='M'))
            s++;
        if( i!=0 && j!=0&&(m1[i-1][j-1].val=='M'))
            s++;
        if(i!=0&&j!=(n-1)&&(m1[i-1][j+1].val=='M'))
            s++;
        if(i!=(n-1)&&(j!=0)&&(m1[i][j-1].val=='M'))
            s++;
        if(m1[i][j].val!='M')
            m1[i][j].val=s+'0';
}
}


        }

void afficher_matrice(Case m[50][50],int n){
string ch;
    cout<<"   ";
    ch="  ";
    cout<<"                                            ";
     for(int i=0;i<n;i++){if(i<10)
                        cout<<i<<"  ";
     else
        cout<<i<<" ";
     }
    cout<<endl;
    for(int i=0;i<n;i++){
            cout<<"                                            ";
            if (i>=10)
                ch=" ";
            cout<<i<<ch;
    for(int j=0;j<n;j++){
            if(j<10)
            cout<<m[i][j].aff<<"  ";
            else
            cout<<m[i][j].aff<<"  ";


    }
    cout<<endl;
    }
}
friend int decouv(Case m1[50][50],int n){
    for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
        if(m1[i][j].dec==0)
            return 1;

}}
return 0;
    }
int aff_rec(Case m[50][50],int i,int j,int l=0){
       if((i!=n-1)&&(m1[i+1][j].val=='0')&& m1[i+1][j].dec!=1&&m1[i+1][j].aff!='D'){
        m1[i+1][j].aff='0';
         m1[i+1][j].dec=1;

            aff_rec(m1,i+1,j);
            }

            if((i!=n-1)&&(j!=0)&&(m1[i+1][j-1].val=='0')&&m1[i+1][j-1].dec!=1&&m1[i+1][j-1].aff!='D'){
            m1[i+1][j-1].aff='0';
            m1[i+1][j-1].dec=1;
                aff_rec(m1,i+1,j-1);}



            if((j!=(n-1)&&(m1[i][j+1].val=='0'))&&m1[i][j+1].dec!=1&&m1[i][j+1].aff!='D'){
            m1[i][j+1].aff='0';
            m1[i][j+1].dec=1;

                aff_rec(m1,i,j+1);}

            if(i!=(n-1)&&j!=(n-1)&&(m1[i+1][j+1].val=='0')&&m1[i+1][j+1].dec!=1&&m1[i+1][j+1].aff!='D'){
            m1[i+1][j+1].aff='0';
            m1[i+1][j+1].dec=1;
                aff_rec(m1,i+1,j+1);
            }

            if(i!=0&&j!=(n-1)&&(m1[i-1][j+1].val=='0')&&m1[i-1][j+1].dec!=1&&m1[i-1][j+1].aff!='D'){
            m1[i-1][j+1].aff='0';
            m1[i-1][j+1].dec=1;
                aff_rec(m1,i-1,j+1);}
            if(i!=(n-1)&&(j!=0)&&(m1[i][j-1].val=='0')&&m1[i][j-1].dec!=1&&m1[i][j-1].aff!='D'){
            m1[i][j-1].aff='0';
            m1[i][j-1].dec=1;
                aff_rec(m1,i,j-1);}
                 if((i!=0&&(m1[i-1][j].val=='0'))&&m1[i-1][j].dec!=1&&m1[i-1][j].aff!='D'){
            m1[i-1][j].aff='0';
            m1[i-1][j].dec=1;
                aff_rec(m1,i-1,j);}
      if( i!=0 && j!=0&&(m1[i-1][j-1].val=='0')&&m1[i-1][j-1].dec!=1&&m1[i-1][j-1].aff!='D'){
            m1[i-1][j-1].aff='0';
            m1[i-1][j-1].dec=1;
                aff_rec(m1,i-1,j-1);}




    }
void game(){cout<<"Pour marquez une case tapez le couple (-1,-1)"<<endl;
cout<<"Pour marquez une case tapez le couple (-2,-2)"<<endl;
     cout<<"tapez la case a decouvrir=";
    int i,j;
    i=-3;j=-3;
    while(i>n || j>n || i<-2 || j<-2){
    cin>>i>>j;}
    if(i==-1){
            cout<<"tapez la case a marquez=";
            cin>>i>>j;
            if(m1[i][j].aff!='#'){cout<<"cette case est deja decouverte"<<endl;}
            else{
            score++;
            m1[i][j].aff='D';
            afficher_matrice(m1,n);
            }

    }
      else if(i==-2){
            cout<<"tapez la case a enlever le marquage=";
            cin>>i>>j;
            score++;
            if(m1[i][j].aff!='D'){cout<<"cette case n'est pas marquée"<<endl;}
            else
               m1[i][j].aff='#';
            afficher_matrice(m1,n);

    }

    else if(m1[i][j].aff!='#'){cout<<"cette case est deja decouverte"<<endl;}
     else if(m1[i][j].val=='M'){cout<<"DEFAITE"<<endl;
    lost=1;}
    else{
            if(m1[i][j].aff!='D'){
            score++;
            m1[i][j].aff=m1[i][j].val;
            m1[i][j].dec=1;
            if((i!=n-1)&&(m1[i+1][j].val!='M')&&m1[i+1][j].dec!=1&&m1[i+1][j].aff!='D'){
        m1[i+1][j].aff=m1[i+1][j].val;
        m1[i+1][j].dec=1;
        if(m1[i+1][j].val=='0')
            aff_rec(m1,i+1,j);
            }

        if((i!=0&&(m1[i-1][j].val!='M'))&&m1[i-1][j].dec!=1&&m1[i-1][j].aff!='D'){
            m1[i-1][j].aff=m1[i-1][j].val;
            m1[i-1][j].dec=1;
            if(m1[i-1][j].val=='0')
                aff_rec(m1,i-1,j);}

            if((j!=(n-1)&&(m1[i][j+1].val!='M'))&&m1[i][j+1].dec!=1&&m1[i][j+1].aff!='D'){
            m1[i][j+1].aff=m1[i][j+1].val;
            m1[i][j+1].dec=1;
            if(m1[i][j+1].val=='0')
                aff_rec(m1,i,j+1);}

            if((i!=n-1)&&(j!=0)&&(m1[i+1][j-1].val!='M')&&m1[i+1][j-1].dec!=1&&m1[i+1][j-1].aff!='D'){
            m1[i+1][j-1].aff=m1[i+1][j-1].val;
            m1[i+1][j-1].dec=1;
            if(m1[i+1][j-1].val=='0')
                aff_rec(m1,i+1,j-1);}

            if(i!=(n-1)&&j!=(n-1)&&(m1[i+1][j+1].val!='M')&&m1[i+1][j+1].dec!=1&&m1[i+1][j+1].aff!='D'){
            m1[i+1][j+1].aff=m1[i+1][j+1].val;
            m1[i+1][j+1].dec=1;
            if(m1[i+1][j+1].val=='0')
                aff_rec(m1,i+1,j+1);
            }
            if( i!=0 && j!=0&&(m1[i-1][j-1].val!='M')&&m1[i-1][j-1].dec!=1&&m1[i-1][j-1].aff!='D'){
            m1[i-1][j-1].aff=m1[i-1][j-1].val;
            m1[i-1][j-1].dec=1;
            if(m1[i-1][j-1].val=='0')
                aff_rec(m1,i-1,j-1);}

            if(i!=0&&j!=(n-1)&&(m1[i-1][j+1].val!='M')&&m1[i-1][j+1].dec!=1&&m1[i-1][j+1].aff!='D'){
            m1[i-1][j+1].aff=m1[i-1][j+1].val;
            m1[i-1][j+1].dec=1;
            if(m1[i-1][j+1].val=='0')
                aff_rec(m1,i-1,j+1);}
            if(i!=(n-1)&&(j!=0)&&(m1[i][j-1].val!='M')&&m1[i][j-1].dec!=1&&m1[i][j-1].aff!='D'){
            m1[i][j-1].aff=m1[i][j-1].val;
            m1[i][j-1].dec=1;
            if(m1[i][j-1].val=='0')
                aff_rec(m1,i,j-1);}




    afficher_matrice(m1,n);
   /*cout<<"*************"<<endl;
        cout<<"  ";
     for(int i=0;i<n;i++){cout<<i<<" ";}
    cout<<endl;
    for(int i=0;i<n;i++){
            cout<<i<<" ";
    for(int j=0;j<n;j++){
            cout<<m1[i][j].val<<" ";
    }
    cout<<endl;
    }*/
    }
    else
        cout<<"cette case est marquée"<<endl;

    }
}
        virtual ~player() {}

    protected:

    private:
};

#endif // PLAYER_H
