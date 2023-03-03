/* Matea Marian - 263
C-LION
Comanescu Octavian*/

#include <bits/stdc++.h>
#include <iostream>

//clasa pura virtuala de unde o sa avem functia print si operatorul de afisare
class IOStream {
public:
    virtual void Print(std::ostream&) const = 0;
};
std::ostream& operator<<(std::ostream& os, const IOStream& obj) {
    obj.Print(os);
    return os;
}   ///supraincarcare operator pt afisare

// clasa de baza abstracta din care o sa se mosteneasca fiecare tip de unealta
class Unelte : public IOStream
{
    std::string nume;
    std::string serie;
    int nrserie;

public:
    void Print(std::ostream &ostream) const override;
 virtual int GetTimpDezapezire()const=0;
 virtual int GetConsumEnergie()const=0;

    Unelte(const std::string &nume, const std::string &serie, int nrserie);
    virtual ~Unelte();

    const std::string &getNume() const;

    void setNume(const std::string &nume);

    const std::string &getSerie() const;

    void setSerie(const std::string &serie);

    int getNrserie() const;

    void setNrserie(int nrserie);

};

Unelte::Unelte(const std::string &nume, const std::string &serie, int nrserie) : nume(nume), serie(serie),
                                                                                 nrserie(nrserie) {}

const std::string &Unelte::getNume() const {
    return nume;
}

void Unelte::setNume(const std::string &nume) {
    Unelte::nume = nume;
}

const std::string &Unelte::getSerie() const {
    return serie;
}

void Unelte::setSerie(const std::string &serie) {
    Unelte::serie = serie;
}

int Unelte::getNrserie() const {
    return nrserie;
}

void Unelte::setNrserie(int nrserie) {
    Unelte::nrserie = nrserie;
}

Unelte::~Unelte() =default;

void Unelte::Print(std::ostream &os) const {
    os<<"Nume "<<nume<<" "<<"SERIE "<<serie<<" nrserie "<<nrserie;
}
class Lopataelec : public Unelte
{
    int supfaras;
    int capbat;
    int supcuratata;
public:
    void Print(std::ostream &os)const override;

    Lopataelec(const std::string &nume, const std::string &serie, int nrserie, int supfaras, int capbat,
               int supcuratata);

    int GetTimpDezapezire()const override;

    int GetConsumEnergie()const override;

    int getSupfaras() const;

    void setSupfaras(int supfaras);

    int getCapbat() const;

    void setCapbat(int capbat);

    int getSupcuratata() const;

    void setSupcuratata(int supcuratata);
};
int Lopataelec::getSupfaras() const {
    return supfaras;
}

void Lopataelec::setSupfaras(int supfaras) {
    Lopataelec::supfaras = supfaras;
}

int Lopataelec::getCapbat() const {
    return capbat;
}

void Lopataelec::setCapbat(int capbat) {
    Lopataelec::capbat = capbat;
}

void::Lopataelec::Print(std::ostream &os)const
{
    ///// REVIN
}
int Lopataelec::GetTimpDezapezire() const {
    return getSupcuratata()/std::sqrt(getSupfaras());
}////////////////////////////
Lopataelec::Lopataelec(const std::string &nume, const std::string &serie, int nrserie, int supfaras, int capbat,
                       int supcuratata) : Unelte(nume, serie, nrserie), supfaras(supfaras), capbat(capbat),
                                          supcuratata(supcuratata) {}

int Lopataelec::GetConsumEnergie() const {
    return std::pow(getSupcuratata(),2)*getCapbat();
} ////////////////

int Lopataelec::getSupcuratata() const {
    return supcuratata;
}

void Lopataelec::setSupcuratata(int supcuratata) {
    Lopataelec::supcuratata = supcuratata;
}


class Drone : public Unelte
{
    int altmax;
    int nrmotoare;
    int supcuratataa;


public:
    int GetTimpDezapezire()const override;

    int GetConsumEnergie()const override;

    Drone(const std::string &nume, const std::string &serie, int nrserie, int altmax, int nrmotoare, int supcuratataa);

    int getAltmax() const;

    void setAltmax(int altmax);

    int getNrmotoare() const;

    void setNrmotoare(int nrmotoare);

    int getSupcuratataa() const;

    void setSupcuratataa(int supcuratataa);


};



int Drone::getAltmax() const {
    return altmax;
}

void Drone::setAltmax(int altmax) {
    Drone::altmax = altmax;
}

int Drone::getNrmotoare() const {
    return nrmotoare;
}

void Drone::setNrmotoare(int nrmotoare) {
    Drone::nrmotoare = nrmotoare;
}

int Drone::getSupcuratataa() const {
    return supcuratataa;
}

void Drone::setSupcuratataa(int supcuratataa) {
    Drone::supcuratataa = supcuratataa;
}
///////////
int Drone::GetConsumEnergie() const {
    return getSupcuratataa() * std::pow(getNrmotoare(),3);
}
///////////
int Drone::GetTimpDezapezire() const {
    return std::log(getSupcuratataa())*std::tanh(getAltmax());
}

Drone::Drone(const std::string &nume, const std::string &serie, int nrserie, int altmax, int nrmotoare,
             int supcuratataa) : Unelte(nume, serie, nrserie), altmax(altmax), nrmotoare(nrmotoare),
                                 supcuratataa(supcuratataa) {}


class Prototip : public Unelte
{
    int nrturbine;
    int nrinjectoare;

public:
    int GetTimpDezapezire()const override;

    int GetConsumEnergie()const override;

    Prototip(const std::string &nume, const std::string &serie, int nrserie, int nrturbine, int nrinjectoare);

    int getNrturbine() const;

    void setNrturbine(int nrturbine);

    int getNrinjectoare() const;

    void setNrinjectoare(int nrinjectoare);
};

Prototip::Prototip(const std::string &nume, const std::string &serie, int nrserie, int nrturbine, int nrinjectoare)
        : Unelte(nume, serie, nrserie), nrturbine(nrturbine), nrinjectoare(nrinjectoare) {}

int Prototip::getNrturbine() const {
    return nrturbine;
}

void Prototip::setNrturbine(int nrturbine) {
    Prototip::nrturbine = nrturbine;
}

int Prototip::getNrinjectoare() const {
    return nrinjectoare;
}

void Prototip::setNrinjectoare(int nrinjectoare) {
    Prototip::nrinjectoare = nrinjectoare;
}

int Prototip::GetTimpDezapezire() const {
    return getNrinjectoare()/getNrturbine();
}
int Prototip::GetConsumEnergie() const {
    return std::pow(getNrturbine(),2);
}


class Echipa
{
   std::string nume;
   std::string motto;
   std::vector<std::shared_ptr<Unelte>> unelte;

public:

    void Print();

    void addunealta(std::shared_ptr<Unelte> uni);
    Echipa(const std::string &nume, const std::string &motto, const std::vector<std::shared_ptr<Unelte>> &unelte);

    const std::string &getNume() const;

    void setNume(const std::string &nume);

    const std::string &getMotto() const;

    void setMotto(const std::string &motto);

    const std::vector<std::shared_ptr<Unelte>> &getUnelte() const;

    void setUnelte(const std::vector<std::shared_ptr<Unelte>> &unelte);
};

Echipa::Echipa(const std::string &nume, const std::string &motto, const std::vector<std::shared_ptr<Unelte>> &unelte)
        : nume(nume), motto(motto), unelte(unelte) {}

const std::string &Echipa::getNume() const {
    return nume;
}

void Echipa::setNume(const std::string &nume) {
    Echipa::nume = nume;
}

const std::string &Echipa::getMotto() const {
    return motto;
}

void Echipa::setMotto(const std::string &motto) {
    Echipa::motto = motto;
}

const std::vector<std::shared_ptr<Unelte>> &Echipa::getUnelte() const {
    return unelte;
}

void Echipa::setUnelte(const std::vector<std::shared_ptr<Unelte>> &unelte) {
    Echipa::unelte = unelte;
}

void Echipa::Print() {
    std::cout<<"nume "<<nume<<"motto "<<motto;
    std::cout<<"Uneltele ";
    for(const auto &un : unelte)
    {
        std::cout<<un->getNume()<<",";
        std::cout<<std::endl;
    }
}
void Echipa::addunealta(std::shared_ptr<Unelte> uni) {
    unelte.push_back(uni);
}
//exceptie unealta
class OutofRange : public std::exception
{
public:
    const char *what() const noexcept override {
        return "Unealta nu e buna";
    }
};

class Echipa {
private:
    string nume;
    int punctaj;
public:
    Echipa(string nume): nume(nume), punctaj(0) {}
    string get_nume() const {
        return nume;
    }
    int get_punctaj() const {
        return punctaj;
    }
    void adauga_punctaj(int puncte) {
        punctaj += puncte;
    }
};

class Competitie {
private:
    vector<Echipa> echipe;
public:
    Competitie() {}
    void adauga_echipa(Echipa echipa) {
        echipe.push_back(echipa);
    }
    void sterge_echipa(string nume_echipa) {
        for (auto it = echipe.begin(); it != echipe.end(); ++it) {
            if (it->get_nume() == nume_echipa) {
                echipe.erase(it);
                return;
            }
        }
    }
    void afiseaza_clasament() const {
        vector<Echipa> echipe_copy = echipe;
        sort(echipe_copy.begin(), echipe_copy.end(), [](const Echipa& e1, const Echipa& e2) {
            return e1.get_punctaj() > e2.get_punctaj();
        });
        cout << "Clasament: " << endl;
        for (auto& echipa : echipe_copy) {
            cout << echipa.get_nume() << " - " << echipa.get_punctaj() << " puncte" << endl;
        }
    }
};

int main() {
    Competitie competitie;
    while (true) {
        cout << "1. Adauga echipa" << endl;
        cout << "2. Sterge echipa" << endl;
        cout << "3. Afiseaza clasament" << endl;
        cout << "0. Iesire" << endl;
        int optiune;
        cin >> optiune;
        switch (optiune) {
            case 1: {
                string nume_echipa;
                cout << "Nume echipa: ";
                cin >> nume_echipa;
                competitie.adauga_echipa(Echipa(nume_echipa));
                break;
            }
            case 2: {
                string nume_echipa;
                cout << "Nume echipa: ";
                cin >> nume_echipa;
                competitie.sterge_echipa(nume_echipa);
                break;
            }
            case 3: {
                competitie.afiseaza_clasament();
                break;
            }
            case 0: {
                return 0;
            }
            default: {
                cout << "Optiune invalida!" << endl;
                break;
            }
        }
    }
}
