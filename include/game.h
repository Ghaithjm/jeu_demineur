#ifndef GAME_H
#define GAME_H
#include<algorithm>
#include<bits/stdc++.h>
class game:public player
{
    public:
        game() {}
        virtual ~game() {}
        friend void new_meilleurscore(int s){
            string ligne;
string ch;
string t[1000];int k=0;
ifstream fichier("test.txt");
     while(getline(fichier, ligne)&&ligne!="***")
      {int l=0;
          while(ligne[l]!=' '){
            l++;
          }
          ch+=ligne[l+1];
          ch+=ligne;
         t[k]=ch;

         k++;
         ch="";
      }
      t[k]=s+'0';
      sort(t,t+k+1);
      string ch2="";
      ch2+=s+'0';

      if(t[0]==ch2){ cout<<"BRAVO NOUVEAU MEILLEUR SCORE "<<endl;

      }

  else{
   cout<<"TAPEZ VOTRE NOM"<<endl;}
   fichier.close();
   cin>>ch;
  k=0;
  ligne="";
                 if(fichier)
   {


      while(getline(fichier, ligne)&&ligne!="***")
      {
         t[k]=ligne;

         k++;
      }

   }
   fichier.close();





   ch+=" ";
   ch+=s+'0';
   t[k+1]=ch;
   sort(t,t+k+1);


     string const nomFichier("test.txt");
  std::fstream f("test.txt", std::ios::in|std::ios::out);
  std::stringstream oss;
  oss<<ch<<"\n"<<f.rdbuf();
  f.seekp(0)<<oss.str();



        }

        friend void meilleur_score(){
         ifstream fichier("test.txt");
         int k=0;string t[1000];
         string ch;

   if(fichier)
   {

      string ligne;
      while(getline(fichier, ligne)&&ligne!="***")
      {int l=0;
          while(ligne[l]!=' '){
            l++;
          }
          ch+=ligne[l+1];
          ch+=ligne;
         t[k]=ch;

         k++;
         ch="";
      }
      sort(t,t+k);
    for(int j=0;j<k;j++){
            t[j]=t[j].substr(1);

        cout<<j+1<<")"<<t[j]<<endl;}
   }}
    protected:

    private:
};

#endif // GAME_H
