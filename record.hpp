#pragma once
#include <iostream>
#include <string>
#include <array>
#include <vector>

enum sexType {
    male,
    female,
    intersex,
    notStated
};

typedef std::array<unsigned short int, 6> indexType;
typedef std::array<unsigned short int, 11> peselType;

class Record {
    public:
         Record(const std::string firstName, const std::string lastName, const std::string address, unsigned int indexNr, unsigned long int peselNr, sexType sex)
            : firstName_(firstName)
            , lastName_(lastName)
            , address_(address)
            , indexNr_(indexNr)
            , peselNr_(peselNr)
            , sex_(sex)
        {}

        Record()
            : Record("", "", "", 111111, 99999999999, notStated)
        {}

        bool operator< (const Record &sortedObj) const {
            return peselNr_ < sortedObj.getPeselNr();
        }

        std::string getFirstName() const {return firstName_;}
        std::string getLastName() const {return lastName_;}
        std::string getAddress() const {return address_;}
        unsigned int getIndexNr() const {return indexNr_;}
        unsigned long int getPeselNr() const {return peselNr_;}
        sexType getSex() const {return sex_;}

        std::string getSexString() const;

        void setFirstName(const std::string& firstName) {firstName_ = firstName;}
        void setLastName(const std::string& lastName) {lastName_ = lastName;}
        void setAddress(const std::string& address) {address_ = address;}
        void setIndexNr(unsigned int indexNr) {indexNr_ = indexNr;}
        void setPeselNr(unsigned long int peselNr) {peselNr_ = peselNr;}
        void setSex(sexType sex) {sex_ = sex;}

    private:
        std::string firstName_;
        std::string lastName_;
        std::string address_;
        unsigned int indexNr_;
        unsigned long int peselNr_;
        sexType sex_;
};

// implement polymorphism:

// class Record {}; - pure virtual class
// class Student : public Record {}; - derived class
// class Employee : public Record {}; - derived class