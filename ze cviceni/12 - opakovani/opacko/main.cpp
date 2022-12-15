//
//  main.cpp
//  opacko
//
//  Created by Julie Pražáková on 28.11.2022.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <map>


//pouzivame struct protoze bude vsechno PUBLIC + nepotrebuji funkce get a set, nic jineho nebudou umet delat
//nehodi se pokud je vysledkem objekt co neco ma delat
//hodi se na policko v mape, zamestnance, product v eshopu
struct Employee {
    int id;
    std::string name;
    float salary;
    std::vector<Employee*> team;  //pole co rika kdo jsou podrizeni tohoto zamestnance
    //musi tam byt hvezdicka portoze kopirujeme bosse pro ostatni zamestnance, aby se nevytvarely kopie pry pushbackovani = proto pouzivame ukazatele, aby byl vzdy jen jeden zamestnanec u tohoto bosse
};

int main(int argc, const char * argv[]) {
    //std::vector<Employee*>() vecotr of emplyee NEBO jen {}
    //Employee* jan = new Employee(1, "Jan", 60000, {});
    //ALE U STRUCTU neni konstruktor = pouzivame {} misto () pri new Employee{}

    std::vector<Employee*> team;
    Employee* jan = new Employee{1, "Jan", 60000, team}; //team se tu nakopirovava
    Employee* david = new Employee{2, "David", 70000, team};
    
    
    team.push_back(jan); //ted je bude mit Ivo v teamu
    team.push_back(david);
    Employee* ivo = new Employee{3, "Ivo", 120000, team};
    
    
    
    //jan nebude u nikoho, je v tymu ale neni v tymu bosse, protoze se vytvarely kopie v konstruktorech
    team.push_back(jan);

   
// ZKRACENE TO CELE:
//    Employee* jan = new Employee{1, "Jan", 60000, 70000, {}};
//    Employee* david = new Employee{2, "David", 70000, {}};
//    Employee* ivo = new Employee{3, "Ivo", 120000, {jan, david}};
    
    
    //------------------------------
    //vector je template classa a genericky typ je Employee
    std::vector<Employee*> employees = {jan, david, ivo};
    
    sort(employees.begin(), employees.end(), [](const Employee* a, const Employee* b){ //T& je nejaky typ =
        // = The types Type1 and Type2 must be such that an object of type RandomIt can be dereferenced and then implicitly converted to both of them. = musi byt Employee* misto T
//        if(a->name < b->name) { moc dlouhy zapis
//            return true;
//        }
//        return false; //bool
        return a->name < b->name; // bude true kdyz jo, kdyz ne atak false a prohodi je to
    });
    
    //-----------------------------
    auto a = employees.begin(); //iterator na prvni prvek: std::interator<Employee*>
    auto b = employees.front(); //reference = Employee*, primo zamestnanec
    
    //-----------------------------
    //COUNT_IF FUNKCE  //returnuje bool
    //-----------------------------
    
    //pocet zamestnancu s vysokym plkatem
    long count_with_high_salary = std::count_if(employees.begin(), employees.end(),
                                               [](const Employee* e) {
        return e->salary > 60000;
        
    });
    
    //pocet zamestnancu s nadprumernym platem
    float sum = 0; //sum musi byt v [sum] aby o ni vedel a musi mit & abych neupravovali jeho kopii
    std::for_each(employees.begin(), employees.end(), [&sum](const Employee* e){
        sum += e->salary;
    }); //soucet vyplat zamestnancu
    
    float averageSalary = sum / employees.size(); //vypocitame prumer
    long count_with_salary_above_average = std::count_if(employees.begin(), employees.end(),
                                               [averageSalary](const Employee* e) { //averageSalary nemusi mit &, nevadi mi kopie
        return e->salary > averageSalary;
        
    });
    //------------------------------------------
    // KOPIROVANI PRVKU- copy_if
    //nevraci nic zajimaveho, protoze ji jen chceme naplnit druhy vector
    //-----------------------------
    
    //chci kopirovat jen nektere prvky z pole = NADRIZENE PRACOVNIKY
    std::vector<Employee*> filteredEmployeesThatAreBoss;
    std::copy_if(employees.begin(), employees.end(),
                    std::back_inserter(filteredEmployeesThatAreBoss), //abychom tam nemuseli setovat size vecotur tak dame back_inserter = ten to udela sam nejak
                    [](const Employee* e) {
        return e->team.size() > 0; //jestli ma tym tohoto zamestnance nejakou velikost je BOSS a proto true abychom ho zkopirovali
        
    });
    
    auto findMyBoss = [employees](const Employee* me){ //pomocny lambda vyraz
        //musime projit zamestnance abychom zjistili jestli jsou  unekoho v tymu nebo ne
        //nejlip z toho udelat metodu
        for(auto otherEmployee: employees) {
            for( auto teamMember: otherEmployee-> team){
                if(teamMember->id == me->id){
                    return true;
                }
            }
        }
        return false; //nesmime to tu zapomenout jinak to nepojede!
    };
    
    //chci kopirovat jen PODRIZENE PRACOVNIKY dlouha verze
    std::vector<Employee*> filteredEmployeesThatAreNotBoss;
    std::copy_if(employees.begin(), employees.end(),
                    std::back_inserter(filteredEmployeesThatAreNotBoss),
                    [findMyBoss](const Employee* e) { //musi byt v [findMyBoss BEZ ZAVOREK JINAK SE HNED ZAVOLA]
       
        return findMyBoss(e); //nesmime to tu zapomenout jinak to nepojede!
    });
    
    //chci kopirovat jen PODRIZENE PRACOVNIKY kratka verze
    std::vector<Employee*> filteredEmployeesThatAreNotBoss2;
    std::copy_if(employees.begin(), employees.end(),
                    std::back_inserter(filteredEmployeesThatAreNotBoss2),
                 findMyBoss);
    //------------------------------------------
    // MAPY
    /*
     klic->Typ(jmeno typu)
     1-> Employee(ivo)
     30->Employee(david)
     13->Employee(jan)
     
     */
    //-----------------------------
    
    std::map<int, Employee*> employeeMap; //ma dve hodnoty KLIC A TYP
     // employeeMap.insert(ivo); NEJDE PROTOZE OCEKAVA DVOJICI
    std::pair<int, Employee*> pair = {1, ivo};
    employeeMap.insert(pair); //NEMA PUSH_BACK, vzdy jen insert
    employeeMap.insert({3, jan});
    Employee* employee = employeeMap.at(1);
    std::cout << employee->name << std::endl; //employeeMap.at(klic) = ocekava klic, ne index
    
    //iterator na std::pair co ma v sobe int a employee
    auto employee2 = employeeMap.begin(); //nefunguje protoze v auto je STD::pair
    
    //dvema sipkama rozbalime iterator
    std::cout << employee2->second->name <<std::endl; //musi byt second aby to vypsalo jmeno a ne klic
    
    for(auto p: employeeMap){
        std::cout << p.first << " : " << p.second->name << std::endl; //tu uz neni iterator uz je to rozbalene
    }
    std::for_each(employeeMap.begin(), employeeMap.end(), [](const std::pair<int, Employee*>& p){ // uz tu musi byt & protoze * je uvnitr schovana
        std::cout << p.first << " : " << p.second->name << std::endl;

    });
    
    //------------------------------------------
    // SOUBORY
    /*
     
     */
    //-----------------------------
    
    std::ofstream file; //instance open streamu
    file.open("soubor.txt"); //ocekava cestu k souboru
    //musime si nastavit working directory nebo uvest celou cestu k souboru
    //ta nadrazena slozka to musi byt
    
    if(file.is_open()){
        
        for(auto e: employees){
            //pri cteni pouzivat GETLINE - cte cely radek a pak s nim budem pracovat
            file << e->name << std::endl;
        }
        
        
    }else { //odchyceni vyjimky a vypsani chybove hlasky!!
        std::cerr << "Cannot open file." <<std::endl;
        
    }
    
    //------------------------------------------
    // UNIQUE POINTRY / kdyz nechci kopirovat mega obrosvke vectory a tak, chci jen delt ukazatele
    //-----------------------------
    
    //Employee* m = new Employee{10, "Test", 1, {}};
    
    //Employee* m2 = m; //kopiruje se ukazatel, oba ukazuji na instanci employeeho
    
    auto m = std::unique_ptr<Employee>(new Employee{10, "Test", 1, {}});
    
   // Employee* m2 = m; //uz to nejde
    auto m2 = std::move(m); //zrusil se ukazatel m a presunul se do ukazatele m2
    
   //funkce a metody musi byt prizpusobene pro uniwue_pointer nebo ho ani neprezvykaji
    
    return 0;
}

