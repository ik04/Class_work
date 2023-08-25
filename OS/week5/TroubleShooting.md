# Fixing "undefined function" errors with pthread_create and pthread_join in C programs

## Issue

During the execution of C code, particularly in Week-5 exercises, you might encounter errors related to undefined functions or missing references for `pthread_create` or `pthread_join`. This situation often arises due to incomplete linking of the pthread library during compilation.

## Solution

To resolve these "undefined function" errors and successfully compile your code, you can follow these steps:

1. **Compile Command:** When using the gcc compiler, include the `-pthread` flag in the compilation command. This flag ensures that the pthread library is correctly linked with your program. The command should look like this:

    ```bash
    gcc -o your_program_name your_source_code.c -pthread
    ```


