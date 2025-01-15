#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cerrno>
#include <cstring>

// ///////////////////////////////////// //
// @function movePointer
// Moves the file pointer to a specified offset
// Returns the new position of the pointer or -1 if an error occurs
// ///////////////////////////////////// //
off_t movePointer(int fd, off_t offset, int whence) {
    off_t newPos = lseek(fd, offset, whence);
    if (newPos < 0) {
        std::cerr << "Error moving pointer: " << strerror(errno) << std::endl;
    }
    return newPos;
}

// ///////////////////////////////////// //
// @function openFile
// Opens file for read and write operations
// Returns -1 if the file failed to open
// ///////////////////////////////////// //
int openFile(const char *filename) {
    int fd = open(filename, O_RDWR | O_CREAT, 0644);
    if (fd < 0) {
        std::cerr << "Error opening file: " << strerror(errno) << std::endl;
    }
    return fd;
}

// ///////////////////////////////////// //
// @function closeFile
// Closes the file associated with the file descriptor
// Prints an error message if the file fails to close
// ///////////////////////////////////// //
void closeFile(int fd) {
    if (close(fd) < 0) {
        std::cerr << "Error closing file: " << strerror(errno) << std::endl;
    }
}

// ///////////////////////////////////// //
// @function readFile
// Reads data from the file between start and end positions
// Returns the number of bytes read or -1 if an error occurs
// ///////////////////////////////////// //
ssize_t readFile(int fd, off_t start, off_t end, char *buffer) {
    if (start > end) {
        std::cerr << "Invalid range: start position is greater than end position." << std::endl;
        return -1;
    }

    size_t numBytes = end - start;
    if (movePointer(fd, start, SEEK_SET) < 0) {
        return -1;
    }

    ssize_t bytesRead = read(fd, buffer, numBytes);
    if (bytesRead < 0) {
        std::cerr << "Error reading file: " << strerror(errno) << std::endl;
    }
    return bytesRead;
}

// ///////////////////////////////////// //
// @function writeFile
// Writes data to the file starting at the specified position
// Returns the number of bytes written or -1 if an error occurs
// ///////////////////////////////////// //
ssize_t writeFile(int fd, const char *data, off_t position) {
    size_t numBytes = strlen(data);
    if (movePointer(fd, position, SEEK_SET) < 0) {
        return -1;
    }

    ssize_t bytesWritten = write(fd, data, numBytes);
    if (bytesWritten < 0) {
        std::cerr << "Error writing file: " << strerror(errno) << std::endl;
    }
    return bytesWritten;
}

// ///////////////////////////////////// //
// @function main
// Tests file operations: opening, writing, reading, and closing
// ///////////////////////////////////// //
int main() {
    const char *filename = "example.txt";
    int fd = openFile(filename);

    if (fd < 0) {
        return 1;
    }
		
    writeFile(fd, "Hello, POSIX!", 13);
		
    char buffer[20] = {0};
    readFile(fd, 5, 13, buffer);
    std::cout << "Data read: " << buffer << std::endl;
		
    closeFile(fd);

    return 0;
}
