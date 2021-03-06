#pragma once
# include <iostream>
/*Classe Commande
  Structure de donnée utilisée pour transmettre les données de l'observé
  (VueGraphique) à l'observateur (Modèle).
  Le paramètre générique T de la template de la classe Observateur
  sera remplacé par notre type Commande. Ainsi une seule méthode void update(T) avec
  notre structure de donnée Commande en paramètre sera utlisée pour transférer toutes
  les données nécessaires à la vue graphique
*/

class Commande{

  public:

    typedef enum direction{FRONT_LEFT,FRONT_RIGHT,BACK_LEFT,BACK_RIGHT} dir;
    typedef enum command{MF,MFL,MB,MR,ML,ROT,CARRE,CIRCLE} cmd;

    void setCmd(cmd c){
      this->_cmd = c;
    }
    Commande::cmd getCmd() const{
      return this->_cmd;
    }

    void setLenght(int l){
      this->_lenght = l;
    }
    int getLenght() const{
      return this->_lenght;
    }

    void setAngle(int a){
      this->_angle = a;
    }
    int getAngle() const{
      return this->_angle;
    }

    void setValid(bool valid){
      this->_valid = valid;
    }
    int getValid() const{
      return this->_valid;
    }

    int getLongueurAbsciss() const{
      return this->_longeurAbsciss;
    }
    int getLongueurOrdinate() const{
      return this->_longueurOrdinate;
    }
    void setLongueurOrdinate(int y){
      this->_longueurOrdinate=y;
      
    }

    void setLongueurAbsciss(int x){
      this->_longeurAbsciss=x;
    }

    Commande::dir getDir() const{
      return this ->_dir;
    } 

    void setDir(Commande:: dir d) {
      this->_dir=d;
    }

    int getAbsCircle() const{
      return this->_absCircle;
    }
    int getOrdoCircle() const{
      return this->_ordCircle;
    }
    int getRayon() const{
      return this->_rayon;
    }
    void setRayon(int r){
      this->_rayon=r;
    }
    void setAbsCircle(int a){
      this->_absCircle=a;
    }
    void setOrdoCircle(int o){
      this->_ordCircle=o;
    }
    /*
    void afficher(std::ostream &flux) const {
      flux<< " la commande est "<< this->_cmd << " la longueur du trait est " << this->_lenght << " l'angle est " << this->_angle<< std::endl;
      if (this->getValid()){
        flux << " la commande est valide " ;
      }
      else 
        flux << " la commande n'est pas valide ";
    }
    */

  private:
    int _absCircle;
    int _ordCircle;
    int _rayon;
    cmd _cmd;
    dir _dir;
    int _lenght;
    int _angle;
    int _longeurAbsciss;
    int _longueurOrdinate;
    bool _valid;

};
/*
std::ostream &operator<<( std::ostream &flux,const Commande  & commande){
  commande.afficher(flux);
  return flux;
}
*/
