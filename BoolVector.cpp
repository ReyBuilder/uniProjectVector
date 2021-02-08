//
// Created by ReyBuilder on 008 08.02.21.
//

#include <cstring>
#include "BoolVector.h"

BoolVector::BoolVector() {
    size_ = 0;
    memory_ = 0;
    vector_ = nullptr;
}

BoolVector::BoolVector(const size_t size) {
    size_ = size;
    memory_ = size / 8 + 1;

    vector_ = new char[memory_];
    for (size_t i = 0; i < memory_; ++i) {
        vector_[i] = 0;
    }
}

BoolVector::BoolVector(const char *value) {
    size_ = strlen(value);
    memory_ = size_ / 8 + 1;

    vector_ = new char[memory_];
    for (size_t i = 0; i < memory_; ++i) {
        vector_[i] = 0;
    }

    for (size_t i = 0; i < size_; ++i) {
        if (value[i] == '1') {
            vector_[i / 8] |= 1 << i % 8;
        } else if(value[i] != '0' && value[i] != '\0') {
            throw std::invalid_argument("Value must contain only 1 or 0");
        }
    }
}

BoolVector::BoolVector(const size_t size, const char *value) {
    size_ = size;
    memory_ = size / 8 + 1;

    vector_ = new char[memory_];
    for (size_t i = 0; i < memory_; ++i) {
        vector_[i] = 0;
    }

    for (size_t i = 0; i < size_; ++i) {
        if (value[i] == '1') {
            vector_[i / 8] |= 1 << i % 8;
        } else if(value[i] != '0' && value[i] != '\0') {
            throw std::invalid_argument("Value must contain only 1 or 0");
        }
    }
}

BoolVector::~BoolVector() {
    delete [] vector_;
}

BoolVector::BoolVector(const BoolVector& vector) {
    size_ = vector.size_;
    memory_ = vector.memory_;
    vector_ = new char[memory_];

    for (size_t i = 0; i < memory_; ++i) {
        vector_[i] = vector.vector_[i];
    }
}

void BoolVector::inversion() {
    for (size_t i = 0; i < size_; ++i) {
        inversion(i);
    }
}

void BoolVector::inversion(const size_t index) {
    char mask = 1 << (index % 8);
    if((vector_[index / 8] & mask) == 0) {
        vector_[index / 8] |= mask;
    }
    else {
        vector_[index / 8] &= ~mask;
    }
}

bool BoolVector::operator[](const size_t index) const {
    return (vector_[index / 8] & (1 << (index % 8))) == 1;
}

BoolVector& BoolVector::operator&=(const BoolVector & vector) {
    for (size_t i = 0; i < std::min(size_, vector.size_); ++i) {
        char mask = 1 << (i % 8);
        if(((vector.vector_[i / 8] & mask) & (vector_[i / 8] & mask)) == 0) {
            vector_[i / 8] &= ~mask;
        }
        else {
            vector_[i / 8] |= mask;
        }
    }

    return *this;
}

BoolVector& BoolVector::operator|=(const BoolVector & vector) {

    for (size_t i = 0; i < std::min(size_, vector.size_); ++i) {
        char mask = 1 << (i % 8);
        if(((vector.vector_[i / 8] & mask) | (vector_[i / 8] & mask)) == 0) {
            vector_[i / 8] &= ~mask;
        }
        else {
            vector_[i / 8] |= mask;
        }
    }

    return *this;
}

BoolVector& BoolVector::operator^=(const BoolVector & vector) {

    for (size_t i = 0; i < std::min(size_, vector.size_); ++i) {
        char mask = 1 << (i % 8);
        if(((vector.vector_[i / 8] & mask) ^ (vector_[i / 8] & mask)) == 0) {
            vector_[i / 8] &= ~mask;
        }
        else {
            vector_[i / 8] |= mask;
        }
    }

    return *this;
}

std::ostream &operator<<(std::ostream &os, const BoolVector boolVector) {
    for (size_t i = 0; i < boolVector.size_; ++i) {
        char mask = 1 << (i % 8);
        os << ((boolVector.vector_[i / 8] & mask) ? 1 : 0);
    }
    return os;
}

BoolVector BoolVector::operator&(const BoolVector& vector) const {
    return BoolVector(*this) &= vector;
}

BoolVector BoolVector::operator|(const BoolVector& vector) const {
    return BoolVector(*this) |= vector;
}

BoolVector BoolVector::operator^(const BoolVector& vector) const {
    return BoolVector(*this) ^= vector;
}
