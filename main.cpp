#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <sstream>
#include "header.h"
using namespace std;

Leidinys &Leidinys::operator=(const Leidinys &proj)
{
  vardas = proj.vardas;
  pavadinimas = proj.pavadinimas;
  leidimoMetai = proj.leidimoMetai;
  leidykla = proj.leidykla;
  kaina = proj.kaina;
  tirazas = proj.tirazas;
  return *this;
};

Leidinys &Leidinys::operator+(const Leidinys &proj)
{
  vardas = vardas + proj.vardas;
  pavadinimas = pavadinimas + proj.pavadinimas;
  leidimoMetai = (leidimoMetai + proj.leidimoMetai) / 2;
  leidykla = leidykla + proj.leidykla;
  kaina = kaina + proj.kaina;
  tirazas = tirazas + proj.tirazas;
  return *this;
};

ostream &operator<<(ostream &os, const Leidinys &proj)
{
  os << proj.vardas << " " << proj.pavadinimas << " " << proj.leidimoMetai << " " << proj.leidykla << " " << proj.kaina << " " << proj.tirazas;
  return os;
}

istream &operator>>(istream &in, Leidinys &proj)
{
  in >> proj.vardas >> proj.pavadinimas >> proj.leidimoMetai >> proj.leidykla >> proj.kaina >> proj.tirazas;
  return in;
}

int main()
{
  vector<Leidinys> A;
  A.reserve(1000);
  ifstream fd("duom.txt");
  string v, p, leid;
  int l, t;
  double k;

  while (!fd.eof())
  {
    Leidinys *temp = new Leidinys;
    fd >> *temp;
    A.push_back(*temp);
  }

  fd.close();
  bool eiga = true;
  int temp; //pasirenkamas case
  while (eiga)
  {
    cout << "Jeigu norite pamatyti visa sarasa spauskite *1*" << endl;
    cout << "Jeigu norite pamatyti autoriaus vidutine knygos kaina ir tiraza spauskite *2*" << endl;
    cout << "Paieska pagal knygos autoriu ir leidykla spauskite *3*" << endl;
    cout << "Paieska pagal knygos autoriu, leidykla, kaina ir tiraza spauskite *4*" << endl;
    cout << "Pasirinktos leidyklos knygu rusiavimas pagal autoriu ir tiraza *5*" << endl;
    cout << "Jeigu norite irasyti nauja knyga spauskite *6* " << endl;
    cout << "Jeigu norite istrinti knyga spauskite *7*" << endl;
    cout << "Jeigu norite baigti programa spauskite *8*" << endl;
    cin >> temp;

    switch (temp)
    {
    case 1:
    {
      RodykLeidinys(A);
      break;
    }
    case 2:
    {
      string autorius;
      cout << "Iveskite ieskomo autorius varda ";
      cin >> autorius;
      cout << autorius << " knygu vidutine kaina ir tirazo skaicius: \n";
      cout << CountAverageK(A, autorius) << " " << CountAverageT(A, autorius) << "\n";
      break;
    }
    case 3:
    {
      int count = 0;
      string autorius, leidykla;
      cout << "Iveskite ieskomo autorius varda ";
      cin >> autorius;
      cout << "Iveskite ieskomos leidyklos pavadinima ";
      cin >> leidykla;

      for (int i = 0; i < A.size(); i++)
      {
        if (A[i].getVardas() == autorius && A[i].getLeidykla() == leidykla)
        {
          cout << setw(15) << A[i].getVardas() << "\t";
          cout << setw(15) << A[i].getPavadinimas() << "\t";
          cout << setw(10) << A[i].getLeidimoMetai() << "\t";
          cout << setw(10) << A[i].getLeidykla() << "\t";
          cout << setw(10) << A[i].getKaina() << "\t";
          cout << setw(10) << A[i].getTirazas() << endl;
          count++;
        }
      }
      if (count == 0)
      {
        cout << "Nepavyko rasti atitikmenu \n";
      }

      break;
    }
    case 4:
    {
      int count = 0;
      string autorius, leidykla;
      double kaina;
      int tirazas;
      cout << "Iveskite ieskomo autorius varda ";
      cin >> autorius;
      cout << "Iveskite ieskomos leidyklos pavadinima ";
      cin >> leidykla;
      cout << "Iveskite ieskomo kurinio kaina ";
      cin >> kaina;
      cout << "Iveskite ieskomo kurinio tiraza ";
      cin >> tirazas;

      for (int i = 0; i < A.size(); i++)
      {
        if (A[i].getVardas() == autorius && A[i].getLeidykla() == leidykla && A[i].getKaina() == kaina && A[i].getTirazas() == tirazas)
        {
          cout << setw(15) << A[i].getVardas() << "\t";
          cout << setw(15) << A[i].getPavadinimas() << "\t";
          cout << setw(10) << A[i].getLeidimoMetai() << "\t";
          cout << setw(10) << A[i].getLeidykla() << "\t";
          cout << setw(10) << A[i].getKaina() << "\t";
          cout << setw(10) << A[i].getTirazas() << endl;
          count++;
        }
      }
      if (count == 0)
      {
        cout << "Nepavyko rasti atitikmenu \n";
      }

      break;
    }
    case 5:
    {
      cout << "Sarasas pries isrykiavima: \n";
      RodykLeidinys(A);
      cout << A.size() << "\n";
      sort(A.begin(), A.end(), SortBy);
      cout << "Sarasas po isrykiavimo \n";
      RodykLeidinys(A);
      break;
    }
    case 6:
    {
      ofstream file;
      //is pradziu atsidarome faila append rezimu (pildymo rezimas)
      file.open("duom.txt", std::ofstream::out | std::ofstream::app);
      Leidinys *temp = new Leidinys;
      cout << "Iveskite norimo projekto metaduomenis. \n";
      cout << "Vardas | Pavadinimas | Leidimo metai | Leidykla | Kaina | Tirazas \n";
      cin >> *temp;
      A.push_back(*temp);
      file << "\n"
           << *temp;
      file.close();
      break;
    }
    case 7:
    {
      string failas = "duom.txt";
      ifstream file(failas);
      string line;
      string v1, p1, leid1;
      string l1, t1;
      string k1;
      cout << "Iveskite norimo istrinti projekto metaduomenis. \n";
      cout << "Vardas | Pavadinimas | Leidimo metai | Leidykla | Kaina | Tirazas \n";
      cin >> v1 >> p1 >> leid1 >> l1 >> k1 >> t1;
      stringstream stream;
      string deleteline = v1 + " " + p1 + " " + leid1 + " " + l1 + " " + k1 + " " + t1;
      ofstream temp("temp.txt");
      while (getline(file, line))
      {
        if (line != deleteline)
          temp << line << endl;
      }
      while (getline(file, line))
      {
        if (!line.empty())
        {
          temp << line << endl;
        }
      }
      for (int i = 0; i < A.size(); i++)
      {
        if (v1 == A.at(i).getVardas() && p1 == A.at(i).getPavadinimas())
        {
          Leidinys tempas;
          tempas = A[i];
          A[i] = A[A.size() - 1];
          A[A.size() - 1] = tempas;
          A.pop_back();
        }
      }
      temp.close();
      file.close(); 
      const char *p = failas.c_str();
      remove(p);
      rename("temp.txt", p);
      break;
    }
    case 8:
    {
      return 0;
    }
    }
  }
}
void RodykLeidinys(vector<Leidinys> A)
{
  if (A.size() == 0)
    cout << "Leidiniu sarasas tuscias.";
  else
  {
    cout << "Leidiniu sarasas: \n";
    for (int i = 0; i < A.size(); i++)
    {
      cout << setw(3) << i + 1;
      cout << setw(15) << A[i].getVardas() << "\t";
      cout << setw(15) << A[i].getPavadinimas() << "\t";
      cout << setw(10) << A[i].getLeidimoMetai() << "\t";
      cout << setw(10) << A[i].getLeidykla() << "\t";
      cout << setw(10) << A[i].getKaina() << "\t";
      cout << setw(10) << A[i].getTirazas() << endl;
    }
  }
}
double CountAverageK(vector<Leidinys> A, string autorius)
{
  double sumK = 0;
  double counter = 0;
  for (int i = 0; i < A.size(); i++)
  {
    if (A[i].getVardas() == autorius)
    {
      sumK += A[i].getKaina();
      counter++;
    }
  }
  return sumK / counter;
}
double CountAverageT(vector<Leidinys> A, string autorius)
{
  double sumT = 0;
  double counter = 0;
  for (int i = 0; i < A.size(); i++)
  {
    if (A[i].getVardas() == autorius)
    {
      sumT += A[i].getTirazas();
      counter++;
    }
  }
  return sumT / counter;
}
bool SortBy(Leidinys Pirmas, Leidinys Antras)
{
  if (Pirmas.getVardas() > Antras.getVardas() || Pirmas.getTirazas() < Antras.getTirazas())
  {
    return true;
  }

  return false;
}
