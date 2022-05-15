#pragma once
#include <iostream>
#include <string>
#include <array>
#include <vector>

enum class SexType {
    Male,
    Female,
    Other,
    NotStated
};

enum class Occupation {
    Student,
    Employee,
    Null
};

class Record {
    public:
         Record(const Occupation occupation,
                const std::string firstName,
                const std::string lastName,
                const std::string address,
                unsigned long int peselNr,
                SexType sex
               )
            : occupation_(occupation)
            , firstName_(firstName)
            , lastName_(lastName)
            , address_(address)
            , peselNr_(peselNr)
            , sex_(sex)
        {}

        // bool operator< (const Record &sortedObj) const {
        //     return peselNr_ < sortedObj.getPeselNr();
        // }

        Occupation getOccupation() const {return occupation_;}
        std::string getFirstName() const {return firstName_;}
        std::string getLastName() const {return lastName_;}
        std::string getAddress() const {return address_;}
        unsigned long int getPeselNr() const {return peselNr_;}
        SexType getSex() const {return sex_;}
        virtual unsigned int getIndexNr() const = 0;
        virtual unsigned int getSalary() const = 0;

        std::string getSexString() const;

        void setOccupation(Occupation occupation) {occupation_ = occupation;}
        void setFirstName(const std::string& firstName) {firstName_ = firstName;}
        void setLastName(const std::string& lastName) {lastName_ = lastName;}
        void setAddress(const std::string& address) {address_ = address;}
        void setPeselNr(unsigned long int peselNr) {peselNr_ = peselNr;}
        void setSex(SexType sex) {sex_ = sex;}
        virtual void setIndexNr(unsigned int indexNr) = 0;
        virtual void setSalary(unsigned int) = 0;

        virtual void printRecord() = 0;
    private:
        Occupation occupation_;
        std::string firstName_;
        std::string lastName_;
        std::string address_;
        unsigned int indexNr_;
        unsigned long int peselNr_;
        SexType sex_;
};

class Student : public Record {
public:
    Student(const std::string firstName,
            const std::string lastName,
            const std::string address,
            unsigned long int peselNr,
            SexType sex,
            unsigned int indexNr
           ) : Record(Occupation::Student, firstName, lastName, address, peselNr, sex)
             , indexNr_(indexNr)
           {}

    unsigned int getIndexNr() const override;
    unsigned int getSalary() const override;
    void setIndexNr(unsigned int) override;
    void setSalary(unsigned int) override;

    void printRecord() override;
private:
    unsigned int indexNr_;
};

class Employee : public Record {
public:
    Employee(const std::string firstName,
             const std::string lastName,
             const std::string address,
             unsigned long int peselNr,
             SexType sex,
             unsigned int salary
            ) : Record(Occupation::Student, firstName, lastName, address, peselNr, sex)
              , salary_(salary)
            {}

    unsigned int getIndexNr() const override;
    unsigned int getSalary() const override;
    void setIndexNr(unsigned int) override;
    void setSalary(unsigned int) override;

    void printRecord() override;
private:
    unsigned int salary_;
};

class NullRecord : public Record {
public:
    NullRecord() : Record(Occupation::Null, "", "", "", 0, SexType::NotStated) {}

    unsigned int getIndexNr() const override;
    unsigned int getSalary() const override;
    void setIndexNr(unsigned int) override;
    void setSalary(unsigned int) override;

    void printRecord() override;
};