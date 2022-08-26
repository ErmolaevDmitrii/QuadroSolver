/// @file
/// @brief Header file containing errors enumeration

#ifndef SS_ERRORS_H
#define SS_ERRORS_H

/// Enumeration containing error codes
enum SS_ERROR {
    /// constant for error accused by bad file opening
    SS_ERROR_FILE_NOT_OPENED =  -2,
    /// constant for error accused by bad file input
    SS_ERROR_FILE_WRONG_INPUT = -3,
    /// constant for error accused by unexpected end of file
    SS_ERROR_UNEXPECTED_EOF =   -4,
    /// constant for error accused by bad double number
    SS_ERROR_BAD_VALUE =        -5,
    /// constant for error accused by accesing attempt to NULL
    SS_ERROR_NULL_PTR =         -6,
    /// constant for error accused by bad file closing
    SS_ERROR_FILE_NOT_CLOSED =  -7,
    /// constant for no errors
    SS_ERROR_OK =                0,
};

#endif
