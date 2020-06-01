//headeris
#include <string>


using namespace std;

class Imone
{
    protected:
    string pavadinimas;
    int nariai;
};

class Zmogus : public Imone
{
    protected:
    string vardas;
    string pavarde;
};

class Projektai : public Zmogus
{
private:
    int nariai;
    int biudzetas;
    int trukme; // menesiais

public:
    //base constructor
    Projektai()
    {
        pavadinimas = " ";
        pavarde = " ";
        nariai = 0;
        biudzetas = 0;
        trukme = 0;
    }
    //additional constructor
    Projektai(string pav, string p, int n, int b, int t)
    {
        pavadinimas = pav;
        pavarde = p;
        nariai = n;
        biudzetas = b;
        trukme = t;
    }
    //setters
    void setPavadinimas(string pav)
    {
        pavadinimas = pav;
        
    }
    void setPavarde(string p)
    {
        pavarde = p;
    }
    void setNariai(int n)
    {
        nariai = n;
    }
    void setBiudzetas(int b)
    {
        biudzetas = b;
    }
    void setTrukme(int t)
    {
        trukme = t;
    } 
        
    //getters
    string getPavadinimas()
    {
        return pavadinimas;
    }
    string getPavarde()
    {
        return pavarde;
    }
    int getNariai()
    {
        return nariai;
    }
    int getBiudzetas()
    {
        return biudzetas;
    }
    int getTrukme()
    {
        return trukme;
    }
    //persidengimas operatoriu
    Projektai& operator=(const Projektai& proj);
    Projektai& operator+(const Projektai& proj);
    friend ostream& operator<<(ostream& os, const Projektai& proj);
    friend istream &operator>>( istream  &in, Projektai& proj );
    //destructor
    ~Projektai()
    {
        
    }

};

void RodykProjektai(vector<Projektai> A);
double CountAverageBudget(vector<Projektai> A);
double CountAverageTime(vector<Projektai> A);
bool SortBy(Projektai A, Projektai B);