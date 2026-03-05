#ifndef __PERSONNE_H__
#define __PERSONNE_H__

#include <string>
#include <iostream>

class Personne {
private:
  std::string nom;
  std::string prenom;
  int age;
  Personne* ami;
public:
  Personne(const std::string&, const std::string&, int);
  int getAge() const;
  std::string getNom() const;
  std::string getPrenom() const;
  Personne* getAmi() const;
  void setAge(int);
  void setNom(const std::string&);
  void setPrenom(const std::string&);
  void setAmi(Personne*);
};

std::ostream& operator<<(std::ostream&,const Personne&);

#endif