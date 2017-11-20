ALLOWED FUNCTIONS

write() - fcntl.h
  A system call used to write data out of a buffer

  Function definition
  ssize_t write(int fildes, const void *buf, size_t nbytes);
    int fildes
      The file descriptor of where to write the output. You can either use a file descriptor obtained from the open system call, or you can use 0, 1, or 2, to refer to standard input, standard output, or standard error, respectively.
    const void *buf
      A pointer to a buffer of at least nbytes bytes, which will be written to the file.
    size_t nbytes
      The number of bytes to write. If smaller than the provided buffer, the output is truncated.
      return value	Returns the number of bytes that were written. If value is negative, then the system call returned an error.


opendir - dirent.h
  Opens a directory

  Function definition
  DIR *opendir(const char *dirname);

  dirname
    The name of the directory to be opened
