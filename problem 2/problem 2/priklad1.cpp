#include "priklad1.h"
#include <fstream>
#include <regex>

/// Konstruktor, ktery zavola nacteni dat ze souboru a naplneni vektoru zaznamu
/// pokud je pri nacteni vyhozena vyjimka, je zpracovana a je vypsaha hlaska
/// na chybovy vystup - 2b
BallotList::BallotList(){
    //vytvorim m_orders
    try {
        loadFile("votes.txt");      // zavolame nacteni dat ze souboru -> v nich se zavola insertBallots
    } catch(std::invalid_argument) {
        std::cerr << "Soubor nenacten" << std::endl;
    }
}

/// metoda nacitajici vsechny zaznamy ze souboru - 5b
/// pozor: jmeno ma vice slov
/// v pripade, ze soubor neexistuje je vyhozena vyjimka, pouzije vkladaci metodu nize
void BallotList::loadFile(const std::string fileName){
    std::string row;
    
    // otevru soubor
    std::ifstream in(fileName);
    
       // kontrola otevreni
       if (in.is_open()){
           
           // nactu radek
           while(getline(in, row)){
               std::vector<std::string> vote;
               
               // rozdelim radek
               for (int i = 0; i < 4; i++){
                   long gap = row.find(" ");
                   
                   // prvni udaj po prvni mezeru
                   std::string word(row.substr(0, gap));
                   
                   row = row.substr(gap+1, row.size()-gap-1);
                   
                   // ulozim do vektoru
                   vote.push_back(word);         //vote.push_back(id, state, date, name);
               }
               insertBallot(vote.at(1), vote.at(3), vote.at(2), vote.at(0));        // az je vektor plny zavolam insertBallot
           }
           in.close();
       } else {
           std::cerr << "Pozor, nenacetli jsme soubor" << std::endl;
       }
    
}


/// metoda vlozi zaznam, provede transformaci pomoci labda vyrazu
/// ze stringu na dany typ vyctu - 6b
void BallotList::insertBallot(const std::string state, const std::string person,
                  const std::string date, const std::string counter){
    
    // LAMBDA VYRAZY
    auto enum_state = [] (std::string word) {
        std::map<std::string, State> string2state = {
            { "Accepted", State::Accepted },
            { "Invalid", State::Invalid },
            { "Damaged", State::Damaged },
            { "Faked", State::Faked }
        };
        return string2state.find(word)->second;
    };
    
    auto enum_candidate = [] (std::string word) {
        std::map<std::string, Candidate> string2candidate = {
           { "Trump", Candidate::DonaldTrump },
           { "Biden", Candidate::JoeBiden }
         };
        return string2candidate.find(word)->second;
    };
    
    Ballot ballot = {enum_state(state), enum_candidate(person), date};
    
    m_orders.insert({counter, ballot});
   
    
//    // POMOCI MAP FUNKCE
//    static const std::map<std::string, State> string2state = {
//       { "Accepted", State::Accepted },
//       { "Invalid", State::Invalid },
//       { "Damaged", State::Damaged },
//       { "Faked", State::Faked }
//     };
//    static const std::map<std::string, Candidate> string2candidate = {
//       { "Trump", Candidate::DonaldTrump },
//       { "Biden", Candidate::JoeBiden }
//     };
//    Ballot billot = {string2state.find(state)->second, string2candidate.find(person)->second, date};
//
//    m_orders.insert( m_orders.end(), {counter, billot});
// ----------------------------------------------------------------------------------------------------
//      POMOCI SWITCH A CHAR
//    // nastaveni datumu
//    newBallot.date = vote.at(2);
//
//    // nastaveni state
//    char state = vote.at(1)[0]; //berreme pouze prvni pismeno aby switch fungoval
//    switch(state) //funguje pouze s charem! string nepodporuje
//    {
//        case 'A' : newBallot.state = State::Accepted;   break;
//        case 'I' : newBallot.state = State::Invalid; break;
//        case 'D' : newBallot.state = State::Damaged;  break;
//        case 'F' : newBallot.state = State::Faked;  break;
//    }
//
//    // nastaveni person
//    char candidate = vote.at(3)[0];
//    switch(candidate) //funguje pouze s charem! string nepodporuje
//    {
//        case 'T' : newBallot.person = Candidate::DonaldTrump;   break;
//        case 'B' : newBallot.person = Candidate::JoeBiden;   break;
//    }
//  std::pair<std::string, Ballot> pair = {vote.at(0), newBallot};

}


/// vraci pocty hlasu daneho typu pro jednotlive kandidaty. Tj. vyberu napr. ze chci neplatne listky a vrati se map
/// se dvema zaznamy: neplatne pro Trumpa a neplatne pro Bidena - 6b
// HOTOVO
std::map<Candidate, long> BallotList::getBallotsCount(const State state){
    //vytvorim kandidaty
    Candidate trump = Candidate::DonaldTrump;
    Candidate biden = Candidate::JoeBiden;
    
    //nasetuju merice kandidatama
    std::pair<Candidate, long> donald = {trump, 0};
    std::pair<Candidate, long> joe = {biden, 0};
    
    std::map<std::string, Ballot> votes_with_state;
    
    for_each(m_orders.begin(), m_orders.end(), [state, &votes_with_state](const std::pair<std::string, Ballot> &p){
        if(p.second.state == state){
            votes_with_state.insert({p.first, p.second});
        }
    });
    if(votes_with_state.empty()){
        throw std::invalid_argument("There are no ballots of this state!");
    }
    for_each(votes_with_state.begin(), votes_with_state.end(), [&donald, &joe](const std::pair<std::string, Ballot> &p){
        if(p.second.person == Candidate::DonaldTrump){
            donald.second +=1;
        }else{
            joe.second +=1;
        }
    });
    
    
    std::map<Candidate, long> count;
    count.insert(donald);
    count.insert(joe);
    
    if(count.empty()){
        throw std::invalid_argument("There are no votes for candidates!");
    }
    return count;
   
}

/// metoda vraci listky daneho typu: platne, neplatne...
/// pokud zaznam neni zadny zaznam nalezen, je vyhozena vyjimka - 6b
// HOTOVO
std::vector<Ballot> BallotList::getBallots(const State state) {
    std::vector<Ballot> group;
    
    for_each(m_orders.begin(), m_orders.end(), [state, &group](const std::pair<std::string, Ballot> &p){
        if(p.second.state == state){
            group.push_back(p.second); // bereme jen balloty
        }
    });
    
    if(group.empty()){
        throw std::invalid_argument("There are no ballots of this state!");
    }
    return group;
}
std::vector<Ballot> BallotList::getCandidatesBallots(const Candidate can){
    std::vector<Ballot> group;
    
    for_each(m_orders.begin(), m_orders.end(), [can, &group](const std::pair<std::string, Ballot> &p){
        if(p.second.person == can){
            group.push_back(p.second); // bereme jen balloty
        }
    });
    
    if(group.empty()){
        throw std::invalid_argument("There are no ballots of this candidate!");
    }
    return group;
}
