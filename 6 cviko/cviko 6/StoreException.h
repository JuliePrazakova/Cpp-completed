//
//  StoreException.h
//  CPP_cviceni6_obchod
//
//  Created by David Prochazka on 06.11.12.
//  Copyright (c) 2012 David Prochazka. All rights reserved.
//

#ifndef CPP_cviceni6_obchod_StoreException_h
#define CPP_cviceni6_obchod_StoreException_h

#include <iostream>
#include <stdexcept>

class StoreException : public std::exception {
private:
    std::string m_description;
public:
    StoreException(std::string description) {
        m_description = description;
    }

    std::string getDescription() {
        return m_description;
    }
};

#endif
