#ifndef OOP_L5_SCOOTEREXCEPTION_H
#define OOP_L5_SCOOTEREXCEPTION_H

#include <string>
#include <vector>
#include <exception>

using namespace std;

/**
 * Custom exception class that inherits from the public class exception and returns the custom error message
 */
namespace Exception {
    class ScooterException : public exception{
    private:
        string message;
    public:
        explicit ScooterException(const string &message);

        [[nodiscard]]const char *what() const noexcept override;
    };
}


#endif //OOP_L5_SCOOTEREXCEPTION_H
