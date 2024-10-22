#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ------------------------- Structure Definitions -------------------------

// Structure to represent a File
typedef struct File {
    char* filename;
    struct File* next;
} File;

// Structure to represent a Directory
typedef struct Directory {
    char* directoryName;
    struct Directory* subdirectories; // Head of subdirectories linked list
    struct Directory* next;           // Next sibling directory
    File* files;                      // Head of files linked list
    struct Directory* parent;         // Pointer to parent directory
} Directory;

// Structure to represent the File System
typedef struct FileSystem {
    Directory* rootDirectory;
} FileSystem;

// ------------------------- Function Prototypes ------------------------

Directory* getDirectSubdirectory(Directory* parent, const char* dirName);
Directory* add_subdirectory(Directory* dir, const char* directoryName);
int add_file(Directory* dir, const char* filename);
void print_directory_contents(Directory* dir);
void print_filesystem(FileSystem* fs);
Directory* create_directory(const char* directoryName, Directory* parent);
FileSystem* create_filesystem(const char* rootName);
void free_directory(Directory* dir);
void free_filesystem(FileSystem* fs);
void trim_newline(char* str);

// --------------------------- Function Implementations ------------------

// Find a direct subdirectory by name
Directory* getDirectSubdirectory(Directory* parent, const char* dirName) {
    Directory* current = parent->subdirectories;
    while (current != NULL) {
        if (strcmp(current->directoryName, dirName) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;  // Not found
}

// Create and add a subdirectory under the current directory
Directory* add_subdirectory(Directory* dir, const char* directoryName) {
    // Check if a subdirectory with the same name already exists
    if (getDirectSubdirectory(dir, directoryName) != NULL) {
        return NULL; // Directory already exists
    }

    // Create the new directory
    Directory* newDir = create_directory(directoryName, dir);

    // Insert the new directory at the head of the subdirectories list
    newDir->next = dir->subdirectories;
    dir->subdirectories = newDir;

    return newDir;
}

// Add a file to the current directory
int add_file(Directory* dir, const char* filename) {
    File* current = dir->files;
    // Check if file with the same name already exists
    while (current != NULL) {
        if (strcmp(current->filename, filename) == 0) {
            return 0;  // File already exists
        }
        current = current->next;
    }

    // Create new file
    File* newFile = (File*)malloc(sizeof(File));
    newFile->filename = strdup(filename);
    newFile->next = NULL;

    // Add file to the front of the files list
    newFile->next = dir->files;
    dir->files = newFile;

    return 1; // Success
}

// Print the contents (subdirectories and files) of a directory
void print_directory_contents(Directory* dir) {
    printf("Contents of directory '%s':\n", dir->directoryName);
    
    Directory* currentDir = dir->subdirectories;
    if (!currentDir) {
        printf("  No subdirectories.\n");
    } else {
        printf("  Subdirectories:\n");
        while (currentDir != NULL) {
            printf("    %s/\n", currentDir->directoryName);
            currentDir = currentDir->next;
        }
    }

    File* currentFile = dir->files;
    if (!currentFile) {
        printf("  No files.\n");
    } else {
        printf("  Files:\n");
        while (currentFile != NULL) {
            printf("    %s\n", currentFile->filename);
            currentFile = currentFile->next;
        }
    }
}

// Print the entire file system recursively
void print_filesystem(FileSystem* fs) {
    printf("File system structure:\n");
    print_directory_recursive(fs->rootDirectory, 0);
}

// Recursive helper to print directories and files
void print_directory_recursive(Directory* dir, int depth) {
    for (int i = 0; i < depth; i++) printf("  ");
    printf("|-- %s/\n", dir->directoryName);

    // Print files in this directory
    File* file = dir->files;
    while (file != NULL) {
        for (int i = 0; i < depth + 1; i++) printf("  ");
        printf("|-- %s\n", file->filename);
        file = file->next;
    }

    // Recurse into subdirectories
    Directory* subdir = dir->subdirectories;
    while (subdir != NULL) {
        print_directory_recursive(subdir, depth + 1);
        subdir = subdir->next;
    }
}

// Create a directory
Directory* create_directory(const char* directoryName, Directory* parent) {
    Directory* dir = (Directory*)malloc(sizeof(Directory));
    dir->directoryName = strdup(directoryName);
    dir->subdirectories = NULL;
    dir->files = NULL;
    dir->next = NULL;
    dir->parent = parent;
    return dir;
}

// Create and initialize the file system
FileSystem* create_filesystem(const char* rootName) {
    FileSystem* fs = (FileSystem*)malloc(sizeof(FileSystem));
    fs->rootDirectory = create_directory(rootName, NULL);
    return fs;
}

// Free memory used by a directory and its contents
void free_directory(Directory* dir) {
    // Free subdirectories
    Directory* currentDir = dir->subdirectories;
    while (currentDir != NULL) {
        Directory* nextDir = currentDir->next;
        free_directory(currentDir);
        currentDir = nextDir;
    }

    // Free files
    File* currentFile = dir->files;
    while (currentFile != NULL) {
        File* nextFile = currentFile->next;
        free(currentFile->filename);
        free(currentFile);
        currentFile = nextFile;
    }

    // Free directory itself
    free(dir->directoryName);
    free(dir);
}

// Free memory used by the file system
void free_filesystem(FileSystem* fs) {
    free_directory(fs->rootDirectory);
    free(fs);
}

// Trim newline character from input
void trim_newline(char* str) {
    if (!str) return;
    size_t len = strlen(str);
    if (len == 0) return;
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// ------------------------- Main Function ----------------------------

int main() {
    FileSystem* fs = create_filesystem("root");
    Directory* head = fs->rootDirectory;
    Directory* dir = NULL;

    // Variable to store user input
    char input[256];

    printf("Welcome to the In-Memory File System!\n");
    printf("Available commands:\n");
    printf("  cd <directory_name>\n");
    printf("  mkdir <directory_name>\n");
    printf("  touch <file_name>\n");
    printf("  ls\n");
    printf("  exit\n\n");

    while (1) {
        printf(">> "); // Prompt

        // Read input from the user
        if (!fgets(input, sizeof(input), stdin)) {
            printf("Error reading input. Exiting.\n");
            break;
        }

        // Remove the trailing newline character
        trim_newline(input);

        // Check for empty input
        if (strlen(input) == 0) {
            continue;
        }

        // Tokenize the input into command and argument
        char* command = strtok(input, " ");
        char* argument = strtok(NULL, " ");

        // Handle commands
        if (strcmp(command, "cd") == 0) {
            if (argument == NULL) {
                printf("Error: 'cd' command requires a directory name.\n");
                continue;
            }

            if (strcmp(argument, "..") == 0) {
                if (head != fs->rootDirectory) {
                    head = head->parent;
                    printf("Switched to parent directory %s\n", head->directoryName);
                } else {
                    printf("You are already at root directory.\n");
                }
                continue;
            }

            dir = getDirectSubdirectory(head, argument);
            if (dir) {
                printf("Switched to directory %s\n", argument);
                head = dir;
            } else {
                printf("No such subdirectory here.\n");
            }

        } else if (strcmp(command, "mkdir") == 0) {
            if (argument == NULL) {
                printf("Error: 'mkdir' command requires a directory name.\n");
                continue;
            }

            dir = add_subdirectory(head, argument);
            if (dir) {
                printf("Created SubDirectory %s\n", argument);
            } else {
                printf("SubDirectory with name %s already exists here.\n", argument);
            }

        } else if (strcmp(command, "touch") == 0) {
            if (argument == NULL) {
                printf("Error: 'touch' command requires a file name.\n");
                continue;
            }

            if (add_file(head, argument)) {
                printf("Created file %s\n", argument);
            } else {
                printf("File with name %s already exists here.\n", argument);
            }

        } else if (strcmp(command, "ls") == 0) {
            print_directory_contents(head);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Unknown command: %s\n", command);
        }
    }

    // Free memory used by the file system
    free_filesystem(fs);

    return 0;
}
