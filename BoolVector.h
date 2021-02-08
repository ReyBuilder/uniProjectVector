//
// Created by ReyBuilder on 008 08.02.21.
//

#ifndef UNIPROJECTVECTOR_BOOLVECTOR_H
#define UNIPROJECTVECTOR_BOOLVECTOR_H

#include <iostream>
#include <ctime>

class BoolVector {

private:

    size_t size_;

    size_t memory_;
    char* vector_;

public:

    BoolVector();

    BoolVector(const size_t size);

    BoolVector(const char *value);

    BoolVector(const size_t size, const char *value);

    BoolVector(const BoolVector& vector);

    ~BoolVector();

    friend std::ostream &operator<<(std::ostream &os, const BoolVector boolVector);

    void inversion();

    void inversion(const size_t index);

    bool operator[](const size_t index) const;

    BoolVector& operator&=(const BoolVector & vector);

    BoolVector& operator|=(const BoolVector& vector);

    BoolVector& operator^=(const BoolVector& vector);

    BoolVector operator&(const BoolVector& vector) const;

    BoolVector operator|(const BoolVector& vector) const;

    BoolVector operator^(const BoolVector& vector) const;


};


#endif //UNIPROJECTVECTOR_BOOLVECTOR_H
