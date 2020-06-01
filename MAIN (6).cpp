#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <sstream>
#include "header.h"

using namespace std;

Projektai& Projektai::operator=(const Projektai& proj)
{
    pavadinimas = proj.pavadinimas;
    pavarde = proj.pavarde;
    nariai = proj.nariai;
    biudzetas = proj.biudzetas;
    trukme = proj.trukme;
    return *this;
}

Projektai& Projektai::operator+(const Projektai& proj)
{
    pavadinimas = pavadinimas + proj.pavadinimas;
    pavarde = pavarde + proj.pavarde;
    nariai += proj.nariai;
    biudzetas += proj.biudzetas;
    trukme += proj.trukme;
    return *this;
}
ostream& operator<<(ostream& os, const Projektai& proj)
{
    os << proj.pavadinimas << " " <<  proj.pavarde << " " << proj.nariai << " " << proj.biudzetas << " " << proj.trukme;
    return os;
}

istream &operator>>( istream  &in, Projektai& proj )
{
    in >> proj.pavadinimas >> proj.pavarde >> proj.nariai >> proj.biudzetas >> proj.trukme;
    return in;
}

int main()
{
    vector<Projektai> A;
    A.reserve(1000);
    ifstream f("duomenys.txt");
    string pav, p;
    int n, b, t;
    int a;

    while (!f.eof())
    {
        Projektai *temp = new Projektai;
        f >> *temp;
        A.push_back(*temp);
    }

    f.close();
    bool eiga = true;
    int temp;
    while (eiga)
    {
        cout << "1 - Projektų vidutinės trukmės ir biudžetų vidurkio skaičiavimas.\n";
        cout << "2 - Paieška nurodžius projekto pavadinimą ir vadovo pavardę.\n";
        cout << "3 - Paieška nurodžius projekto pavadinimą, vadovo pavardę, komandos narių skaičių.\n";
        cout << "4 - Rikiavimas pagal projekto komandos narių skaičių ir biudžetą ir trukmę.\n";
        cout << "5 - Iterpti nauja projekta ir jo metaduomenis.\n";
        cout << "6 - Istrinti projekta ir saraso.\n";
        cout << "7 - nutraukiamas programos darbas.\n";
        cout << "Iveskite norima pasirinkima: \n";
        cin >> temp;

        switch (temp)
        {
        case 1:
        {
            RodykProjektai(A);
            cout << "\n";
            cout << "Vidutine projektu trukme: " << CountAverageTime(A) << endl;
            cout << "Vidutinis projektu biudzetas: " << CountAverageBudget(A) << endl;
            break;
        }

        case 2:
        {
            string pavad, pavarde;
            int count = 0;
            cout << "Iveskite ieskomo projekto pavadinima ";
            cin >> pavad;
            cout << "iveskite projekto vadovo pavardes paieska ";
            cin >> pavarde;
            for (int i = 0; i < A.size(); i++)
            {
                if (A[i].getPavadinimas() == pavad && A[i].getPavarde() == pavarde)
                {
                    cout << A[i].getPavadinimas() << "\t";
                    cout << A[i].getPavarde() << "\t";
                    cout << A[i].getNariai() << "\t";
                    cout << A[i].getBiudzetas() << "\t";
                    cout << A[i].getTrukme() << endl;
                    count++;
                }
            }
            if (count == 0)
            {
                cout << "Nepavyko rasti atitikmenu \n";
            }
            break;
        }

        case 3:
        {
            string pavad, pavarde;
            int skc;
            int count = 0;
            cout << "Iveskite ieskomo projekto pavadinima ";
            cin >> pavad;
            cout << "iveskite projekto vadovo pavardes paieska ";
            cin >> pavarde;
            cout << "iveskite projekto nariu skaiciu ";
            cin >> skc;
            for (int i = 0; i < A.size(); i++)
            {
                if (A[i].getPavadinimas() == pavad && A[i].getPavarde() == pavarde && A[i].getNariai() == skc)
                {
                    cout << A[i].getPavadinimas() << "\t";
                    cout << A[i].getPavarde() << "\t";
                    cout << A[i].getNariai() << "\t";
                    cout << A[i].getBiudzetas() << "\t";
                    cout << A[i].getTrukme() << endl;
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
            cout << "Sarasas pries isrykiavima: \n";
            RodykProjektai(A);
            cout << A.size() << "\n";
            sort(A.begin(), A.end(), SortBy);
            cout << "Sarasas po isrykiavimo \n";
            RodykProjektai(A);
            break;
        }
        case 5:
        {
            ofstream file;
            file.open("duomenys.txt", std::ofstream::out | std::ofstream::app); //append mode, output stream
            Projektai *temp = new Projektai;
            cout<< "Iveskite norimo projekto metaduomenis. \n";
            cout << "Pavadinimas | Pavarde | Nariu skc. | Biudzetas | Trukme (men) \n";
            cin >> *temp;
            A.push_back(*temp);
            file<<"\n"<<*temp;
            file.close();
            break;
        }
        case 6:
        {
            string failas = "duomenys.txt";
            ifstream file(failas);
            string line;
            string pav1, p1;
            string n1, b1, t1;
            cout << "Iveskite norimo istrinti projekto metaduomenis. \n";
            cout << "Pavadinimas | Pavarde | Nariu skc. | Biudzetas | Trukme (men) \n";
            cin >> pav1 >> p1 >> n1 >> b1 >> t1;
            stringstream stream;
            string deleteline = pav1 + " " + p1 + " " + n1 + " " + b1 + " " + t1;
            ofstream temp("temp.txt");
            while (getline(file, line))
            {
                if (line != deleteline)
                    temp << line << std::endl;
            }
            while (getline(file, line))
            {
                if (!line.empty())
                {
                    temp << line << endl;
                }
            }
            for(int i = 0; i< A.size(); i++)
            {
                if(pav1 == A.at(i).getPavadinimas() && p1 == A.at(i).getPavarde())
                {
                    Projektai tempas;
                    tempas = A[i];
                    A[i] = A[A.size()-1];
                    A[A.size()-1] = tempas;
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
        case 7:
        {
            return 0;
        }
        }
    }
    return 0;
}

//Functions
void RodykProjektai(vector<Projektai> A)
{
    if (A.size() == 0)
        cout << "Sarasas tuscias.";
    else
    {
        cout << "Projektu sarasas: \n";
        for (int i = 0; i < A.size(); i++)
        {
            cout << setw(3) << i + 1;
            cout << setw(15) << A[i].getPavadinimas() << "\t";
            cout << setw(15) << A[i].getPavarde() << "\t";
            cout << setw(10) << A[i].getNariai() << "\t";
            cout << setw(10) << A[i].getBiudzetas() << "\t";
            cout << setw(10) << A[i].getTrukme() << endl;
        }
    }
}
double CountAverageBudget(vector<Projektai> A)
{
    double tempSum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        tempSum += A[i].getBiudzetas();
    }
    return tempSum / A.size();
}
double CountAverageTime(vector<Projektai> A)
{
    double tempSum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        tempSum += A[i].getTrukme();
    }
    return tempSum / A.size();
}
bool SortBy(Projektai A, Projektai B)
{
    if (A.getNariai() > B.getNariai() || A.getBiudzetas() > B.getBiudzetas() || A.getTrukme() > B.getTrukme())
    {
        return true;
    }
    return false;
}
