#ifndef EXITCODE_H
#define EXITCODE_H

enum class Exitcode : int {
    Ok = 0,
    Exit = -1,
    InvalidCommand = 10,
    MissingFile = 1,
    FileNotFound = 7,
    FilesystemError = 2
};

#endif