//
//  TicketState.h
//  cpp_exam
//
//  Created by Ivo Pisařovic on 08.01.2022.
//

#ifndef TicketState_h
#define TicketState_h

enum class TicketState {
    Bought, // a new purchcased ticket, not yet used
    Entered, // a ticket used to enter the ice skating rink
    Exited // a ticket used to leave the ice skating rink (once exited it cannot be reused to enter again)
};

#endif /* TicketState_h */

