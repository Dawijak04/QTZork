#ifndef EXCEPTION_H
#define EXCEPTION_H

class InvalidDirectionException {
public:
    const char* message() const noexcept;
};


class RestrictedAccessException {
public:
    const char* message() const noexcept;
};

class FullInventoryException {
public:
    const char* message() const noexcept;
};

#endif // EXCEPTION_H
