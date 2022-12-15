//
//  Kod.cpp
//  tahak
//
//  Created by Julie Pražáková on 09.10.2022.
//

#include "Kod.hpp"
#include <iostream>

//----------------------------------------------
//1. overeni ze je to int
//----------------------------------------------

    if(a == int(a)){}
    
    if (isdigit(x[i]))

//1.1 pretypovat na int
    double x = 54.999999999999943157;
    int y = (int) x;

//1.2 je to int and string?
    bool check_number(std::string str) {
       for (int i = 0; i < str.length(); i++)
       if (isdigit(str[i]) == false)
          return false;
          return true;
    }
    if (check_number(str))
      cout<<str<< " is an integer"<<endl;
    else
        cout<<str<< " is a string"<<endl;

//----------------------------------------------
//2. overeni char
//----------------------------------------------

    if(a == 'a') //musi byt '' zavorky!
    if(isalpha(a)) // je to pismeno?

//----------------------------------------------
//3. overeni string
//----------------------------------------------

    #include <typeinfo>
    if (typeid(variable) == typeid(std::string)) {
            std::cout << variable << " is a string" << std::endl;
        }
        else {
            std::cout << variable << " is not a string" << std::endl;
        }//you can do this for every type
    int a = 5;
    std::cout << typeid(a).name() << endl;

//----------------------------------------------
//4. vytvoreni mapy
//----------------------------------------------
    //hpp
        //tearoom
        static const int mapSize = 4;
        static const char defaultItem = 'F';

        private:
        //vektor tvorici mapu (map)
        std::array<std::array<char, mapSize>, mapSize> map;

        public:
        Map();
        
        //completed cviceni 4
        public:
            static const int mapSize = 6;
            static const char chargingStationSymbol = '+';
            static const char roadSymbol = '-';

        private:
            Tesla* tesla;
            std::array<std::array<char, mapSize>, mapSize> map;

        public:
            Map();

    //cpp
        Map::Map(){ //tearoom
            //nastaveni pole
            map = std::array<std::array<char, mapSize>, mapSize>();
            
            //vyplneni pole
            for (auto &row: map) {
                //bacha tady je uz ROW
                for(auto &col: row){
                    col = defaultItem;
                }
            }
        }
        Map::Map() { //tesla
            tesla = new Tesla();
            map = std::array<std::array<char, mapSize>, mapSize>();
        }
    //-----------------
    //4.1 vypsani mapy
    //-----------------
            void Map::print() const{ //tearoom
                
                //vyprintuje stoly
                for(int i = 0; i < mapSize; i++){
                    for(int j = 0; j < mapSize; j++){
                        
                        //vypise najite aktualni policko a potom mezeru
                        std::cout << map.at(i).at(j) << ' ';
                    }
                    std::cout << std::endl;
                }
            }
            void Map::print() const { //tesla
                for (int y = 0; y < map.size(); y++) {
                    for (int x = 0; x < map.at(y).size(); x++) {
                        if (tesla->getPosition().x == x and tesla->getPosition().y == y) {
                            std::cout << " " << Tesla::symbol << " ";
                        } else {
                            std::cout << " " << map.at(x).at(y) << " ";
                        }
                    }
                    std::cout << std::endl;
                }
            }
            void Maze::print(){//cviceni 1
                for(int i = 0; i < plan.size(); i++){
                    for(int j = 0; j < plan.size(); j++){
                        if(worm->getX() == i and worm->getY() == j){
                            std::cout << worm->getSymbol() << "  ";
                        }else {
                            std::cout << "_  ";
                        }
                    }
                    //novy radek
                    std::cout << std::endl;
                    
                }
            }


//----------------------------------------------
//5. tvorba structu
//----------------------------------------------
    struct Position { //hlavickovy soubor tesla
        int x;
        int y;
    };
    struct Position{ // hlavickovy soubor tearoom
        //pro ulozeni dvou propojenych udaju
        int row;
        int col;
    };

//----------------------------------------------
//6. tvorbu vektoru
//----------------------------------------------
    //hpp
        #include <vector>
        std::vector<Conversation> m_conversations; //chatbot

        std::vector<std::string> words; //cviceni 2
    //cpp
        m_conversations = loader.getConversations(filename); //chatbot

        Dictionary::Dictionary(){
            //vektor slov -> vektor je object takze tyto zavorky
            words = {"alfa","bravo"}; //cviceni 2
        }


//----------------------------------------------
//7. funkce omezeni pole
//----------------------------------------------
    //cpp
        bool Maze::checkDirection(int dir){ //cviceni 1
            //cisla rozlisuji smery
            if (dir == 1){//left
                //jestlize smer dolu tak je tato funkce true je pokud je souradnice Y > 0
                //jinak bude tato funkce false -> cerv se nepohne
                return (worm->getY() > 0);
            }else if (dir == 2){ //up
                return (worm->getX() > 0);
            }else if (dir == 3) {// right
                return (worm->getY() < 4);
            }else if (dir == 4) { // down
                return (worm->getX() < 4);
            }
            return false;
        }

//----------------------------------------------
//12. pohyb po mape
/*
1 - left
2 - up
3 - right
4 - down
*/
//----------------------------------------------

    void Maze::moveUpWorm(){
        if(Maze::checkDirection(2)){
            worm->move(worm->getX()-1, worm->getY());

        }
    }

    void Maze::moveLeftWorm(){
        if(Maze::checkDirection(1)){
            worm->move(worm->getX(), worm->getY()-1);
        }
    }

    void Maze::moveRightWorm(){
        if(Maze::checkDirection(3)){
            worm->move(worm->getX(), worm->getY()+1);
        }
    }
    void Maze::moveDownWorm(){
        if(Maze::checkDirection(4)){
            worm->move(worm->getX()+1, worm->getY());
        }
    }


//----------------------------------------------
//8. kontrola hodnot - pole nepretece
//----------------------------------------------
    position.row >= 0 //tearoom
    and position.row < mapSize
    //col je mezi 0 a velikosti mapy
    and position.col >= 0
    and position.col < mapSize


    //checkDirection pri pohybu
        bool Map::checkDirection(int x, int y){ //domaci ukol 3
            int newX = gap->getPosition().row + x;
            int newY = gap->getPosition().col + y;

            return (
                newX >= 0 and
                newX < map.at(0).size() and
                newY >= 0 and
                newY < map.size()
            );
            return true;
        }

//----------------------------------------------
//9. psani DO  txt souboru
//----------------------------------------------
    void Map::write(){ //tearoom
        //zapsat do souboru
        std::ofstream out;
        
        //jestli nefunguje nastavit schema souboru
        out.open("tables.txt");
        if(out.is_open()){
            for (auto row: map){
                for(auto element: row){
                    //vepsat data dovnitr
                    out << element;
                }
                //novy radek
                out << std::endl;
            }
            
            //nnezapomenout zavrit
            out.close();
        }else {
            throw std::invalid_argument("File cannot be opened");
        }
    }

//----------------------------------------------
//10. vypsani txt souboru
//----------------------------------------------
    void Map::loadFromFile(const std::string& fileName) {//completed 4
        std::ifstream in(fileName);
        std::string line;

        if (!in.is_open()) {
            throw std::invalid_argument("File " + fileName + " cannot be opened!");
        }

        int x = 0;

        while(getline(in, line)){
            int y = 0;

            if (x >= mapSize || line.size() != mapSize) {
                throw std::out_of_range("Map in file is not in expected size of " + std::to_string(mapSize) + "!");
            }

            for (auto &element: line) {
                map.at(x).at(y) = element;
                y++;
            }

            x++;
        }
    }


    std::vector<Conversation> Loader::getConversations(const std::string filename) const{//cviceni 3
        std::vector<Conversation> conversations;
        std::string line;
        
        std::ifstream chat("chat.txt");
        if(chat.is_open()){
        while(getline(chat, line)){
                
                //do promene conversation ktera ma typ Conversations (cely radek)
                //zkopirujeme cely radek
                //splitline ho rozdeli na key a response!!!
                Conversation conversation = splitLine(line);
                
                //cely radek pak pushnem do naseho vektoru
                conversations.push_back(conversation);
            }
            //==> mame cely soubor prekopirovany v nasem vektoru
        }else {
            //cerr je errorova hlaska
            std::cerr << "Zadny soubor se nepodarilo otevrit" << std::endl;
        }
        //returneme nas plny vektor rozdeleny na key a na response
        return conversations;
    }

//----------------------------------------------
//11. ukazatele *
//----------------------------------------------




//----------------------------------------------
//12. options rizeni WASD
//----------------------------------------------
    
    //tesla cviceni 4
    std::cout << "Enter W to go up" << std::endl;
    std::cout << "Enter A to go left" << std::endl;
    std::cout << "Enter S to go down" << std::endl;
    std::cout << "Enter D to go right" << std::endl;
    std::cout << "Enter Q to quit the game" << std::endl;


    void Game::processInput(char input) {
        if (input == 'W' or input == 'A' or input == 'S' or input == 'D' or input == 'Q'){
            if (input == 'W'){
                maze->moveTesla(0, -1);
            } else if (input == 'A'){
                maze->moveTesla(-1, 0);
            }else if (input == 'S'){
                maze->moveTesla(0, 1);
            }else if (input == 'D'){
                maze->moveTesla(1, 0);
            } else {
                setStatus(false);
                std::cout << "GAME OVER" << std::endl;
            }
        } else {
            std::cout << "You've entered wrong input, try again" << std::endl;
        }
    }
