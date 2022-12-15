//
//  Suite.hpp
//  7 cviko
//
//  Created by Julie Pražáková on 13.12.2022.
//

#ifndef Suite_hpp
#define Suite_hpp

#include <vector>
#include <stdexcept>
#include "Test.hpp"
using std::vector;
using std::logic_error;

namespace TestSuite {

class TestSuiteError : public logic_error {
public:
  TestSuiteError(const string& s = "")
  : logic_error(s) {}
};

class Suite {
  string name;
  ostream* osptr;
  vector<Test*> tests;
  void reset();
  // Disallowed ops:
  Suite(const Suite&);
  Suite& operator=(const Suite&);
public:
  Suite(const string& name, ostream* osptr = &cout)
  : name(name) { this->osptr = osptr; }
  string getName() const { return name; }
  long getNumPassed() const;
  long getNumFailed() const;
  const ostream* getStream() const { return osptr; }
  void setStream(ostream* osptr) { this->osptr = osptr; }
  void addTest(Test* t) noexcept(false);
  void addSuite(const Suite&);
  void run();  // Calls Test::run() repeatedly
  long report() const;
  void free();  // Deletes tests
};

} // namespace TestSuite
#endif /* Suite_hpp */
