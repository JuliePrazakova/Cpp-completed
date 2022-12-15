# Cpp-completed

## **1. cvičení -**
    1. vypsani mapy v array
    2. overeni velikosti pole
    3. pohyb po poli
    4. std::cout << Worm::symbol - vypsani atributu aniz bychom ho volali z instance, protoze je public
    
## **2. cvičení -** 
    1. způsob zjištění **posledního a prvního písmene slova**
        1. **první**: return this->[word.at](http://word.at/)(0);
        2. **poslední**: return this->[word.at](http://word.at/)((this→word.size()) - 1);
    2. porovnání v jediné funkci: systemWord.isConnectedTo(word)
        1. return **getFirstCharacter() == anotherWord.getLastCharacter();**
        
## **3. cvičení -** 
    1. vypis ze souboru
    2. slova ze souboru do vektoru structů
    3. rozdelení řádků na slova
    4. regex = hledání výrazů ve větě
    
## **4. cvičení -**
    1. nedělat nic zbytečně složitě! = dobíjecí stanice jsou jen jiný znak na mapě = podle znaku rozeznáme, 
        kdy dobít a kdy ne, není potřeba dělat ani struct!!
    2. první testování! 
## **5. nebylo-**

## **6. cvičení -** 
    1. práce s časem = ukládání objednávek
    
## **7. cvičení -**    
    1. template třídy 
        - nema konstruktor
        - Před název třídy dáme slovo template
        - občas je lepší template třída (genericka sablona) než dědičnost
        - můžeme specializovat myčku konkrétně pro auto <v>
        - new Mycka<Auto>();
        - new Mycka<Autobus>();
        - i navratovy typ muze byt <v>
        - preskocime tim classu Vozidlo a proste poslem jednenkrat auto a podruhe autobus
        - Celá deklarace je v hlavičkovém souboru (i implementace tam je!)
        
    2. ukazatel
        - * a &
        - kdyz potrebujeme ziskat puvodni objekt vytvorime store pomoci *
        - hvezdicka rozbali ukazatel a ziska hodnotu k nam
        - diky toho pak muzeme pouzivat . teckovou notaci pro dosazeni vnitrnich funkci
        - pomoci & posleme staticky stor a je z toho ukazatel a pouzivame →
        - staticka instance vytvari kopie, dynamicka posila ukazatele
        - Store* store = new Store(); dynamicka
        Store= store = new Store(); staticka
        
     3. kdyz piseme testy pokazde, pokud chceme otestovat nejakou chybu musi tam byt exceptions = **try**{neprojde}**catch**{projde}
        - pokud testujeme neco kladneho, tak to udelame a napiseme k tomu v kodu funkci co nam vrati hodnoty 
            co muzeme porovnat, jestli se to fakt provedlo jinak zkontrolovat
