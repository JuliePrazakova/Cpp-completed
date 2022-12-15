//
//  CustomerException.h
//  CPP_cviceni6_obchod
//
//  Created by David Prochazka on 06.11.12.
//  Copyright (c) 2012 David Prochazka. All rights reserved.
//

#ifndef CPP_cviceni6_obchod_CustomerException_h
#define CPP_cviceni6_obchod_CustomerException_h

#include <iostream>
#include "StoreException.h"

class CustomerException : public StoreException {
private:
    int m_memberId;
public:
    CustomerException(std::string description, int memberId) : StoreException(description) {
        m_memberId = memberId;
    }

    int getMemberId() const {
        return m_memberId;
    }
};

#endif
