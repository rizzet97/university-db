#include "record.hpp"

std::string Record::getSexString() const {
    if (sex_ == 0) {
        return "male";
    } else if (sex_ == 1) {
        return "female";
    } else if (sex_ == 2) {
        return "intersex";
    } else {
        return "not stated";
    }
}