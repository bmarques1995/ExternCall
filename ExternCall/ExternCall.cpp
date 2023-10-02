// ExternCall.cpp: define o ponto de entrada para o aplicativo.
//

#include "ExternCall.h"

using namespace std;

int main(int argc, char** argv)
{
    const char* pathVariable = getenv("PATH");

    if (pathVariable != nullptr) {
        std::cout << "PATH variable: " << pathVariable << std::endl;
    }
    else {
        std::cout << "PATH variable not found." << std::endl;
    }

	cout << "Hello CMake, lets call you from this program" << endl;
    
    // Command to execute CMake: cmake <path_to_source_directory>
    const char* command = " --help";

    // CreateProcessA parameters
    char* cmd = _strdup(command);
    
    STARTUPINFOA si = { sizeof(si) };
    PROCESS_INFORMATION pi;

    // Create the process
    if (CreateProcessA("C:/Program Files\\CMake\\bin/cmake.exe",   // No module name (use command line)
        cmd,    // Command line
        NULL,   // Process handle not inheritable
        NULL,   // Thread handle not inheritable
        FALSE,  // Set handle inheritance to FALSE
        0,      // No creation flags
        NULL,   // Use parent's environment block
        NULL,   // Use parent's starting directory 
        &si,    // Pointer to STARTUPINFO structure
        &pi))   // Pointer to PROCESS_INFORMATION structure
    {
        // Wait until child process exits
        WaitForSingleObject(pi.hProcess, INFINITE);

        // Close process and thread handles
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    else {
        printf("CreateProcess failed (%d)\n", GetLastError());
    }

    // Free allocated memory
    free(cmd);
	return 0;
}
