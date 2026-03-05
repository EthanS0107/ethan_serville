#include "personne.h"

using namespace std;

Personne::Personne(const string& n, const string& p, int a) :
    nom(n),
    prenom(p),
    age(a),
    ami(nullptr)
{}

int Personne::getAge() const {
    return this->age;
}

string Personne::getNom() const {
    return this->nom;
}

string Personne::getPrenom() const {
    return this->prenom;
}

void Personne::setAge(int age) {
    this->age = age;
}

void Personne::setNom(const string & nom) {
    this->nom = nom;
}

void Personne::setPrenom( const string & p) {
    this->prenom = p;
}

Personne* Personne::getAmi() const {
    return ami;
}

void Personne::setAmi(Personne* a) {
    ami = a;
}

ostream& operator<<(ostream& os, const Personne& pers) {
    os << "     nom : " << pers.getNom() << endl
      << "  prenom : " << pers.getPrenom() << endl
      << "     age : " << pers.getAge() << endl;
    if (pers.getAmi() != nullptr)
        os << "     ami : " << pers.getAmi()->getNom() << " " << pers.getAmi()->getPrenom() << endl;
    return os;
}

// fonction de test
void testPersonne() {
    // les constructeurs
    Personne p1 ("Dupont", "Gaston", 36);
    Personne p2(p1);

    // l'affichage
    cout << p1;
    cout << p2;

    // accesseurs et modificateurs
    p1.setAge(20);
    cout << p1.getAge() << endl;
}