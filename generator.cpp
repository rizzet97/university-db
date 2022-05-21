#include "generator.hpp"

bool Generator::getCoinFlipResult() {
    return (generateNumber<unsigned short int>(0, 1) == 1);
}
bool Generator::getResultWithSetProbability(unsigned int probabilityPercent) {
    return (generateNumber<unsigned short int>(0, 99) < probabilityPercent);
}

std::string Generator::generateFirstName(SexType nameList) {
    auto randomInt = generateNumber<unsigned int>(0, 49);
    std::set<std::string>::iterator it;
    if(nameList == SexType::Female) {
        it = firstNameFemale.begin();
    } else {
        it = firstNameMale.begin();
    }
    std::advance(it, randomInt);
    return *it;
}
std::string Generator::generateLastName(SexType nameList) {
    auto randomInt = generateNumber<size_t>(0, 49);
    std::set<std::string>::iterator it;
    if(nameList == SexType::Female) {
        it = lastNameFemale.begin();
    } else {
        it = lastNameMale.begin();
    }
    std::advance(it, randomInt);
    return *it;
}
std::string Generator::generateAddress() {
    auto randomInt = generateNumber<size_t>(0, 132);
    auto it = streetName.begin();
    std::advance(it, randomInt);
    auto address = "ul. " + *it;
    randomInt = generateNumber<size_t>(1, 99);
    address += ' ';
    address += std::to_string(randomInt);
    randomInt = generateNumber<size_t>(1, 30);
    if(randomInt == 18) {address += 'a';}
    if(randomInt == 19) {address += 'b';}
    if(randomInt == 20) {address += 'c';}
    randomInt = generateNumber<size_t>(1, 5);
    if(randomInt > 2) {
         address += "/";
        randomInt = generateNumber<size_t>(1, 25);
        address += std::to_string(randomInt);
    }
    return address;
}
unsigned int Generator::generateID(SexType sex) {
    auto id = 10 * generateNumber<unsigned int>(0, 999);
    if(sex == SexType::Male) {
        id += generateNumber<unsigned int>(0, 9) * 2 % 10 + 1;
    } else {
        id += generateNumber<unsigned int>(0, 9) * 2 % 10;
    }
    return id;
}
unsigned int Generator::getRandomBirthYear(bool isStudent) {
     if(isStudent) {
        return generateNumber<unsigned int>(currentYear_-40, currentYear_-18);
    } else {
        return generateNumber<unsigned int>(currentYear_-90, currentYear_-24);
    }
}
unsigned int Generator::getRandomBirthMonth() {
    return generateNumber<unsigned short int>(1, 12);
}
unsigned int Generator::getRandomBirthDay(unsigned int birthYear, unsigned int birthMonth) {
    if(birthMonth == 2) {
        if((birthYear % 4)) {
            return generateNumber<unsigned short int>(1, 28);
        } else {
            return generateNumber<unsigned short int>(1, 29);
        }
    } else if(birthMonth == 4 || birthMonth == 6 || birthMonth == 9 || birthMonth == 11) {
        return generateNumber<unsigned short int>(1, 30);
    } else {
        return generateNumber<unsigned short int>(1, 31);
    }
}

unsigned int Generator::calculateCheckDigit(std::string input) {
    std::array<unsigned int, 10> values;
    std::transform(input.begin(), input.end(), values.begin(), [](char c){return c - '0';});
    std::array<unsigned int, 10> weights = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    unsigned int sum = std::inner_product(values.begin(), values.end(), weights.begin(), 0);
    if(sum % 10 == 0) {return 0;} else {return 10 - (sum % 10);}
}

std::string Generator::getBirthdaySignature(unsigned int year, unsigned int month, unsigned int day) {
    std::string pesel;
    if(year % 100 < 10) {pesel += '0';}
    pesel += (std::to_string(year % 100));
    if(year > 1999 && year < 2100) {
        pesel += (std::to_string(20 + month));
    } else if(year > 2099 && year < 2200) {
        pesel += (std::to_string(40 + month));
    } else if(year > 2199 && year < 2300) {
        pesel += (std::to_string(60 + month));
    } else if(year < 1900) {
        pesel += (std::to_string(80 + month));
    } else {
        if(month < 10) {pesel += '0';}
        pesel += (std::to_string(month));
    }
    if(day < 10) {pesel += '0';}
    pesel += std::to_string(day);
    return pesel;
}

bool Generator::checkIfGenerated(std::string dateSignature, unsigned int id) {
    auto range = generatedIDs_.equal_range(dateSignature);
    if(range.first != generatedIDs_.end()) {
        for(auto it = range.first; it != range.second; ++it) {
            if(it->second == id) {return true;}
        }
    }
    return false;
}

unsigned long int Generator::generatePesel(SexType sex, Occupation occupation) {
    std::string pesel;
    bool isStudent;
    if(occupation == Occupation::Student) {
        isStudent = true;
    } else {
        isStudent = false;
    }
    auto birthYear = getRandomBirthYear(isStudent);
    auto birthMonth = getRandomBirthMonth();
    auto birthDay = getRandomBirthDay(birthYear, birthMonth);
    auto birthdaySignature = getBirthdaySignature(birthYear, birthMonth, birthDay);
    pesel += birthdaySignature;
    auto peselID = generateID(sex);
    while(checkIfGenerated(birthdaySignature, peselID)) {
        peselID = generateID(sex);
    }
    if(peselID < 10) {
        pesel += "000";
    } else if(peselID < 100) {
        pesel += "00";
    } else if(peselID < 1000) {
        pesel += '0';
    }
    pesel += std::to_string(peselID);
    generatedIDs_.insert(std::make_pair(birthdaySignature, peselID));

    auto lastDigit = calculateCheckDigit(pesel);
    pesel += std::to_string(lastDigit); 
    return std::stoul(pesel);
}

unsigned long int Generator::generatePesel() {
    std::string pesel;
    bool isStudent = getResultWithSetProbability(70);
    SexType sex = SexType::Other;
    (getCoinFlipResult()) ? sex = SexType::Male : sex = SexType::Female;
    auto birthYear = getRandomBirthYear(isStudent);
    auto birthMonth = getRandomBirthMonth();
    auto birthDay = getRandomBirthDay(birthYear, birthMonth);
    auto peselID = generateID(sex);
    auto birthdaySignature = getBirthdaySignature(birthYear, birthMonth, birthDay);
    pesel += birthdaySignature;
    while(checkIfGenerated(birthdaySignature, peselID)) {
        peselID = generateID(sex);
    }
    if(peselID < 10) {
        pesel += "000";
    } else if(peselID < 100) {
        pesel += "00";
    } else if(peselID < 1000) {
        pesel += '0';
    }
    pesel += std::to_string(peselID);
    generatedIDs_.insert(std::make_pair(birthdaySignature, peselID));

    auto lastDigit = calculateCheckDigit(pesel);
    pesel += std::to_string(lastDigit); 

    return std::stoul(pesel);
}

std::shared_ptr<Record> Generator::generateNewRecord() {
    Occupation occupation = Occupation::Null;
    (getResultWithSetProbability(70)) ? occupation = Occupation::Student : occupation = Occupation::Employee;
    SexType sex = SexType::Other;
    (getCoinFlipResult()) ? sex = SexType::Male : sex = SexType::Female;
    auto pesel = generatePesel(sex, occupation);
    if(getResultWithSetProbability(10)) {
        (getCoinFlipResult()) ? sex = SexType::NotStated : SexType::Other;
    }
    std::string firstName = generateFirstName(sex);
    std::string lastName = generateLastName(sex);
    std::string address = generateAddress();
    unsigned int classSpecific = 0;
    if(occupation == Occupation::Student) {
        classSpecific = generateNumber(100000, 999999);
        return std::make_shared<Student>(Student(firstName, lastName, address, pesel, sex, classSpecific));
    } else {
        classSpecific = generateNumber(3416, 20000);
        return std::make_shared<Employee>(Employee(firstName, lastName, address, pesel, sex, classSpecific));
    }
}