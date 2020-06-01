#include <string>


using namespace std;

class Rasytojas
{
  protected:
  string vardas;
};

class Knyga : public Rasytojas
{
  protected:
  string pavadinimas;
};

class Leidinys : public Knyga
{
  private:
  int leidimoMetai;
  string leidykla;
  double kaina;
  int tirazas;


  //konstruktorius
  public:
  Leidinys()
  {
    vardas="";
    pavadinimas="";
    leidimoMetai=0;
    leidykla="";
    kaina=0;
    tirazas=0;
  }
  //papildomas konstruktorius
  Leidinys(string var, string pav, int l, string leid, double k, int t)
  {
    vardas=var;
    pavadinimas=pav;
    leidimoMetai=l;
    leidykla=leid;
    kaina=k;
    tirazas=t;
  }
  //setteriai
  void setVardas(string var)
  {
    vardas=var;
  }
  void setPavadinimas(string pav)
  {
    pavadinimas=pav;
  }
  void setLeidimoMetai(int l)
  {
    leidimoMetai=l;
  }
  void setLeidykla(string leid)
  {
    leidykla=leid;
  }
  void setKaina(int k)
  {
    kaina=k;
  }
  void setTirazas(int t)
  {
    tirazas=t;
  }

  //getteriai
  string getVardas()
  {
    return vardas;
  }
  string getPavadinimas()
  {
    return pavadinimas;
  }
  int getLeidimoMetai()
  {
    return leidimoMetai;
  }
  string getLeidykla()
  {
    return leidykla;
  }
  double getKaina()
  {
    return kaina;
  }
  int getTirazas()
  {
    return tirazas;
  }
  
  //persidengimas operatoriu
  Leidinys& operator=(const Leidinys& proj);
  Leidinys& operator+(const Leidinys& proj);
  friend ostream& operator<<(ostream& os, const Leidinys& proj);
  friend istream& operator>>(istream& in, Leidinys& proj);
  //destruktorius
  ~Leidinys()
  {
    //cout<<"Pabaiga..."<<endl;
  }
};
void RodykLeidinys(vector<Leidinys> A);
double CountAverageK(vector<Leidinys> A, string autorius);
double CountAverageT(vector<Leidinys> A, string autorius);
bool SortBy(Leidinys Pirmas, Leidinys Antras);
