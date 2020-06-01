#include <bits/stdc++.h> // geriausia biblioteka apjungianti daug kitu biblioteku
using namespace std;

string ns; //sukuriame viena globalu kad lengviau veliau butu panaudoti

class knyga // aprasome kas bus klaseje
{
  private: // aprasome privacius kintamuosius
  string autorius;
  string pavadinimas;
  int metai;
  string leidykla;
  double kaina;
  double tirazas;

  public: // sukuriame settus 
  knyga():autorius(""), pavadinimas(""), metai(0), leidykla(""), kaina(0), tirazas(0){} //aprasome tuscia konstruktoriu
  knyga(string a, string p, int m, string l, double k, double t){ //aprasome pildyta konstruktoriu
    autorius=a;
    pavadinimas=p;
    metai=m;
    leidykla=l;
    kaina=k;
    tirazas=t;
  }
  void setAutorius(string a){autorius=a;}
  void setPavadinimas(string p){pavadinimas=p;}
  void setMetai(int m){metai=m;}
  void setLeidykla(string l){leidykla=l;}
  void setKaina(double k){kaina=k;}
  void setTirazas(double t){tirazas=t;}

  string getAutorius(){return autorius;} //kuriame getterius 
  string getPavadinimas(){return pavadinimas;}
  int getMetai(){return metai;}
  string getLeidykla(){return leidykla;}
  double getKaina(){return kaina;}
  double getTirazas(){return tirazas;}
};

void removeSpaces(string str) // komanda skirta panaikinti spacesus kurie yra virs 2, pamirsau kaip su setw tai sita padariau
{  
    for (int j = 0; str.length()-1; j++) //foras iki stringo ilgio
    {
        if(str[j]==' ')
        {
          if(str[j+1]==' ')
          {
            ns=str.erase(j, str.size()); // trinst pagal size()
            break;
          }
        }     
    }        
}

int main(void) {

  string testi="y"; //kintamasis kuris parodo ar naudotojas nori testo programa
  int o=5; //skaicius knygu sarase
  knyga K[100]; //klases irasymas
  char zodis1[20]=""; //zodziai skirti istraukti duomenis is failo
  char zodis2[14]="";
  char zodis3[19]="";
  double skaicius;
  double tempas;
  int a=1;
  int pradinist=0;

  while(testi=="y")
  {
    string V[o]; // gettinti masyvai duomenu
  string P[o];
  string L[o];
  int M[o];
  double Kaina[o];
  double Tirazas[o];
    cout<<"++++++++";
  ifstream fd; // sukuriama galimybe skaityti is failo
  fd.open("duom.txt");// atidarome faila
  for(int i=0; i<o; i++)
  {
    fd.read(zodis1, sizeof(zodis1)); // istraukiame pirmuosius stringus
    removeSpaces(zodis1);
    K[i].setAutorius(ns);
    V[i]=K[i].getAutorius();
    fd.read(zodis2, sizeof(zodis2));// istraukiame antruosius stringus
    removeSpaces(zodis2);
    K[i].setPavadinimas(ns);
    P[i]=K[i].getPavadinimas();
    fd.read(zodis3, sizeof(zodis3));// istraukiame treciuosius stringus
    removeSpaces(zodis3);
    K[i].setLeidykla(ns);
    L[i]=K[i].getLeidykla();
    fd>>skaicius;
    K[i].setMetai(skaicius);
    M[i]=K[i].getMetai(); // traukiame duomenis is failo(double)
    fd>>skaicius;
    K[i].setKaina(skaicius);
    Kaina[i]=K[i].getKaina();
    fd>>skaicius;
    K[i].setTirazas(skaicius);
    Tirazas[i]=K[i].getTirazas();
    fd.ignore(1, '\n');
    
  }
  fd.close(); // uzdarome faila
  int sk; //aprasome kintamuosius kurie pades rasant koda
  char pasirinktasA[20]="";
  char pasirinktasP[20]="";
  char pasirinktasL[20]="";
  char temp[20];
  double sumaK=0;
  double sumaT=0;
  double bendrasSK=0;
  double skaicius1=0, skaicius2=0;
  int metusk=0;
  int Pan1[o], Pan2[o], Pan3[o], Pan4[o]; //5case 4kriterijai
  int p=0;
  //rasome nepatogu user interface
  cout<<"Jeigu norite pamatyti visa sarasa spauskite *1*"<<endl;
  cout<<"Jeigu norite pamatyti autoriau vidutine knygos kaina ir tiraza spauskite *2*"<<endl;
  cout<<"Paieska pagal knygos autoriu ir leidykla spauskite *3*"<<endl;
  cout<<"Paieska pagal knygos autoriu, leidykla, kaina ir tiraza spauskite *4*"<<endl;
  cout<<"Pasirinktos leidyklos knygu rusiavimas pagal autoriu ir tiraza *5*"<<endl;
  cout<<"Jeigu norite irasyti nauja knyga spauskite *6* "<<endl;
  cout<<"Jeigu norite istrinti knyga spauskite *7*"<<endl;
  cin>>sk;
  //duodame naudotujui pasirinkimus
  switch(sk){
    case 1:
    for(int i=0; i<o; i++)//sitas pasirinkimas parodo visa lentele
    {
      cout<<V[i]<<" "<<P[i]<<" "<<L[i]<<" "<<M[i]<<" "<<Kaina[i]<<" "<<Tirazas[i]<<endl;
    }
    break;
    case 2: //sitas parodo vidutine kaina ir tiraza
    cin.ignore();//ivedamas antras cin.get(), nes \n islieka buffery
    cout<<"Prasau iveskite pasirinkta autoriu: "<<endl;
  cin.get(pasirinktasA, 80, '\n');
  cin.get();
  for(int i=0; i<o; i++)
  {
    if(pasirinktasA==V[i]) //tikriname ar pasirinktas autorius yra duom.txt
    {
      sumaK+=Kaina[i];
      sumaT+=Tirazas[i];
      bendrasSK++;
    }
  }
  cout<<pasirinktasA<<" knygu vidutine kaina: "<<sumaK/bendrasSK<<" , o tirazu skaicius: "<<sumaT/bendrasSK<<endl;
    break;
    case 3: //sitas pagal autoriu ir knyga parodo info
    cout<<"Prasau iveskite pasirinkta autoriu: "<<endl;
    cin.ignore();//ivedamas antras cin.get(), nes \n islieka buffery
  cin.get(pasirinktasA, 20, '\n');
  cin.get();  //ivedamas antras cin.get(), nes \n islieka buffery
  cout<<"Prasau iveskite pasirinkta knyga: "<<endl;
  cin.get(pasirinktasP, 20, '\n');
  
  for(int i=0; i<o; i++)
  {
    if(pasirinktasA==V[i]) //tikriname ar pasirinktas autorius yra duom.txt
    {
      for(int j=0; j<o; j++)
      {
        if(pasirinktasP==P[j]) //tikriname ar pasirinktas pavadinimas yra duom.txt
        {
          p=j;
        }
      }
    }
  }
  cout<<"************************"<<endl;//parodome kokia informacija turime
  cout<<"Autorius: "<<V[p]<<endl;
  cout<<"Knyga: "<<P[p]<<endl;
  cout<<"Leidykla: "<<L[p]<<endl;
  cout<<"Metai: "<<M[p]<<endl;
  cout<<"Kaina: "<<Kaina[p]<<endl;
  cout<<"Tirazas: "<<Tirazas[p]<<endl;
    break;
    case 4: //sitas irasant autoriu, leidykla, kaina ir tiraza parodo info
    
  cin.ignore();
  cout<<"Prasau iveskite pasirinkta autoriu: "<<endl;
  cin.get(pasirinktasA, 20, '\n');
  cin.get(); //ivedamas antras cin.get(), nes \n islieka buffery
  cout<<"Prasau iveskite pasirinkta leidykla: "<<endl;
  cin.get(pasirinktasL, 20, '\n');
  cin.get();  //ivedamas antras cin.get(), nes \n islieka buffery
  cout<<"Prasau iveskite knygos kaina: "<<endl;
  cin>>skaicius1;
  cout<<"Prasau iveskite knygos tirazas: "<<endl;
  cin>>skaicius2;
  for(int i=0; i<o; i++) //tikriname kiek sutampa kiekvienos duotos kategorijos duomenu
  {
    if(pasirinktasA==V[i])// visi P[]yra nunulinti todel prie ju pridedant gausime reikiamus skaicius veliau ieskant pagal kriterijus informacijos 
    {
      Pan1[i]++;
    }
    if(pasirinktasL==L[i])
    {
      Pan2[i]++;
      
    }
    if(skaicius1==Kaina[i])
    {
      Pan3[i]++;
    }
    if(skaicius2==Tirazas[i])
    {
      Pan4[i]++;
    }
  }
  for(int i=0; i<o; i++) //jeigu sutampa visi reikalngi gauname reikiama skaiciu, kuris leis suzinoti elemento numeri masyvuose kur yra duomenys
  {
    if(Pan1[i]+Pan2[i]+Pan3[i]+Pan4[i]==4)
    {
      p=i;
    }
  }

  
  if(p<5) 
  {
     cout<<"************************"<<endl;
     cout<<"Autorius: "<<V[p]<<endl;
     cout<<"Knyga: "<<P[p]<<endl;
     cout<<"Leidykla: "<<L[p]<<endl;
     cout<<"Metai: "<<M[p]<<endl;
     cout<<"Kaina: "<<Kaina[p]<<endl;
     cout<<"Tirazas: "<<Tirazas[p]<<endl;
  }
  else
  cout<<"Nerastas autorius ir jo duomenys"<<endl;//jeigu p gaunasi neegzistuojantis parodome kad jo nera
    break;
    case 5: //sitas isrikiuoja pagal tiraza pasirinkta leidykla ir autoriu
    cin.ignore();//ivedamas antras cin.get(), nes \n islieka buffery
    cout<<"Pasirinkite leidykla: "<<endl;
  cin.get(pasirinktasL, 20, '\n');
  for(int i=0; i<o; i++)
  {
    if(pasirinktasL==L[i]) //tikriname ar pasirinkta leidykla yra duom.txt ir skaiciuojame kiek ju yra
    {

      a=i; //galutinis taskas elementu
      pradinist++; //pradinis taskas nuo elementu pradzios
    }
  }
  a+=1;
  pradinist=a-pradinist;
  for(int i=pradinist; i<a-1; i++)
  {
    for(int j=i+1; j<a; j++)
    {
      if(Tirazas[i]<Tirazas[j]) //lyginame tirazus
      {
        int temp = Tirazas[i];  //apkeiciame tirazus
        Tirazas[i] = Tirazas[j];  
        Tirazas[j] = temp;

        swap(Kaina[i], Kaina[j]); //keiciame visus duomenis pagal tirazu eiliskuma
        swap(M[i], M[j]);
        swap(P[i], P[j]);
      }
    }
  }
  for(int i=pradinist; i<a; i++) //isvedame ussortinta informacija
  {
    cout<<V[i]<<" "<<P[i]<<" "<<L[i]<<" "<<M[i]<<" "<<Kaina[i]<<" "<<Tirazas[i]<<endl;
  }
    break;
    case 6:
    {
      o++; //didiname bendra skaiciu knygu
      ofstream fr("duom.txt", ios::app); // sukuriamae galimybe rasyti faile, appendui failo
      cin.ignore();
      cout<<"Prasau irasykite autoriu: "<<endl; //naudotojo ivestus duomenis dedame i faila
      cin.get(pasirinktasA, 20);
      cout<<"Prasau irasykite knygos pavadinimas: "<<endl;
      cin.get();
      cin.get(pasirinktasP, 14);
      cout<<"Prasau irasykite leidykla: "<<endl;
      cin.get();
      cin.get(pasirinktasL, 19);
      cout<<"Prasau irasykite metus: "<<endl;
      cin>>metusk;
      cout<<"Prasau irasykite kaina: "<<endl;
      cin>>skaicius1;
      cout<<"Prasau irasykite tiraza: "<<endl;
      cin>>skaicius2;
      fr<<endl;
      fr<<left<<setw(20)<<pasirinktasA;
      fr<<left<<setw(14)<<pasirinktasP;
      fr<<left<<setw(20)<<pasirinktasL;
      fr<<metusk<<" "<<skaicius1<<" "<<skaicius2;
      fr.close();
    }
    break;
    case 7:
    cin.ignore();
    cout<<"Prasau irasykite autoriu: "<<endl; //renkame duomenis apie knygos istrinima
    cin.get(pasirinktasA, 20);
    cout<<"Prasau irasykite knygos pavadinimas: "<<endl;
    cin.get();
    cin.get(pasirinktasP, 14);
    cout<<"Prasau irasykite leidykla: "<<endl;
    cin.get();
    cin.get(pasirinktasL, 19);
    cout<<"Prasau irasykite metus: "<<endl;
    cin>>metusk;
    cout<<"Prasau irasykite kaina: "<<endl;
    cin>>skaicius1;
    cout<<"Prasau irasykite tiraza: "<<endl;
    cin>>skaicius2;
    ifstream fd("duom.txt");
    ofstream fr1("newduom.txt"); 
    int Pa[100]={0};
    int kiekmazeso=0; //kiek kartu tures mazeti o(atskiru knygu skaicius)
    for(int i=0; i<o; i++)
    {
      if(pasirinktasA==V[i]) //skaiciuojame visus kriterijus ar sutampa
      {
        Pa[i]++;
       
      }
      if(pasirinktasP==P[i])
      {
        Pa[i]++;
        
      }
      if(pasirinktasL==L[i])
      {
        Pa[i]++;
      
      }
      if(metusk==M[i])
      {
        Pa[i]++;
      
      }
      if(skaicius1==Kaina[i])
      {
        Pa[i]++;
     
      }
      if(skaicius2==Tirazas[i])
      {
        Pa[i]++;
        
      }
    
      if(Pa[i]<6)//jeigu kriterijai nesutampa rasome i nauja faila
      {
        fr1<<left<<setw(20)<<V[i];
        fr1<<left<<setw(14)<<P[i];
        fr1<<left<<setw(20)<<L[i];
        fr1<<M[i]<<" "<<Kaina[i]<<" "<<Tirazas[i]<<endl;
      }   
      if(Pa[i]==6)
      {
        kiekmazeso++; //jeigu rastas kriterijus pridedame prie dydzio kuris nusako kiek mazes bendras skaicius knygu
      }
    }
    o-=kiekmazeso; // atemame is bendro skaiciaus knygu 
    if(kiekmazeso==0)
    {
      cout<<"Norimi duomenys nerasti....."<<endl; //pasakome kad neradome ko ieskojo naudotojas
    }
    fd.close();//uzdarome filus
    fr1.close();
    remove("duom.txt");//istriname pradini faila
    rename("newduom.txt", "duom.txt");//keiciame naujo failo varda pradiniu failu, kad galetu kiti case naudoti ji
    break;
  }
  cout<<"Ar norite testi? (Taip=y, Ne=n)"<<endl;//klausiame ar naudotojas nori testi programa
  cin>>testi;
  if(testi=="n")
  {
    cout<<"Programa baigta...."; // jeigu nenori uzbaigiame
  }
  }
  return 0;
}