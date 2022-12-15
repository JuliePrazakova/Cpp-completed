#include "priklad1.h"

/// Konstruktor, ktery zavola nacteni dat ze souboru a naplneni vektoru zaznamu
/// pokud je pri nacteni vyhozena vyjimka, je zpracovana a je vypsaha hlaska
/// na chybovy vystup - 2b
BallotList::BallotList(){
    try {
        loadFile("votes.txt");
    } catch(std::invalid_argument) {
        std::cerr << "Soubor nenacten" << std::endl;
    }
}

/// metoda nacitajici vsechny zaznamy ze souboru - 5b
/// pozor: jmeno ma vice slov
/// v pripade, ze soubor neexistuje je vyhozena vyjimka, pouzije vkladaci metodu nize
void BallotList::loadFile(const std::string fileName) throw (std::invalid_argument){
    std::string line;
    std::ifstream in(fileName);

    if (in.is_open()){
        int col = 0;
        while(getline(in, line)){

            std::vector<std::string> subLine;
            std::string tmpLine = line;

            while (subLine.size() < 4){
                long position = tmpLine.find(" ");
                std::string word = tmpLine.substr(0, position);
                subLine.push_back(word);
                tmpLine.erase(0, position+1);
            }
            insertBallot(subLine.at(1), subLine.at(3), subLine.at(2), subLine.at(0));
        }
        in.close();
    } else {
        std::cerr << "Soubor nebyl otevren." << std::endl;
    }
}

/// metoda vlozi zaznam, provede transformaci pomoci labda vyrazu
/// ze stringu na dany typ vyctu - 6b
void BallotList::insertBallot(const std::string state, const std::string person,
                  const std::string date, const std::string counter){

    Ballot ballot{};
    if (state == "Accepted"){
        ballot.state = State::Accepted;
    } else if(state == "Invalid"){
        ballot.state = State::Invalid;
    } else if (state == "Faked"){
        ballot.state = State::Faked;
    } else {
        ballot.state = State::Damaged;
    }

    ballot.date = date;

    if (person == "Trump"){
        ballot.person = Candidate::DonaldTrump;
    } else {
        ballot.person = Candidate::JoeBiden;
    }

    m_orders.insert({counter, ballot});
}

/// vraci pocty hlasu daneho typu pro jednotlive kandidaty. Tj. vyberu napr. ze chci neplatne listky a vrati se map
/// se dvema zaznamy: neplatne pro Trumpa a neplatne pro Bidena - 6b
std::map<Candidate, long> BallotList::getBallotsCount(const State state){
    throw std::exception();
}

/// metoda vraci listky daneho typu: platne, neplatne...
/// pokud zaznam neni zadny zaznam nalezen, je vyhozena vyjimka - 6b
std::vector<Ballot> BallotList::getBallots(const State state) throw (std::invalid_argument){
    throw std::exception();
}