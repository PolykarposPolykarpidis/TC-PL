### **Project: File System Simulator**

**Goal**: Build a simple file system simulator that uses pointers and ownership to manage a tree-like structure of files and directories. You’ll have to carefully design the relationships between objects and deal with memory ownership.

---

### **Project Description**
Your simulator will consist of:
1. **Files**: Simple objects with a name and size.
2. **Directories**: Contain multiple files and subdirectories.
3. **File System**: A root directory that you can interact with, including creating/deleting files, creating subdirectories, and navigating the structure.

---

### **Requirements**

#### **1. Classes**
You’ll need at least three main classes:
1. **File**:
    - Represents a file with a name and size.
    - Files are not owned by any directory but are dynamically allocated (simulating real-world scenarios).
    - **Attributes**:
        - `std::string name`
        - `size_t size` (size of the file in bytes)
    - **Methods**:
        - Constructor: Initialize name and size.
        - `get_info()`: Return file details as a string (e.g., "File: name (size bytes)").

2. **Directory**:
    - Represents a directory containing files and subdirectories.
    - **Attributes**:
        - `std::string name`
        - `std::vector<File*> files` (raw pointers to dynamically allocated files)
        - `std::vector<Directory*> subdirectories` (raw pointers to dynamically allocated subdirectories)
    - **Methods**:
        - Constructor: Initialize the name.
        - Destructor: Properly delete all owned `File` and `Directory` objects.
        - `add_file(File* file)`: Add a file to the directory (ownership of the file is transferred to the directory).
        - `add_subdirectory(Directory* dir)`: Add a subdirectory (ownership of the subdirectory is transferred to the directory).
        - `list_contents()`: Print all files and subdirectories.
        - `remove_file(const std::string& name)`: Remove a file by name and delete it.
        - `remove_subdirectory(const std::string& name)`: Remove a subdirectory by name and delete it.

3. **FileSystem**:
    - Represents the entire file system with a single root directory.
    - **Attributes**:
        - `Directory* root` (pointer to the root directory)
        - `Directory* current_dir` (pointer to the current working directory)
    - **Methods**:
        - Constructor: Initialize the root directory.
        - Destructor: Delete the root directory and everything it owns.
        - `navigate_to(const std::string& name)`: Change the current working directory to a subdirectory.
        - `create_file(const std::string& name, size_t size)`: Create a new file in the current directory.
        - `create_subdirectory(const std::string& name)`: Create a new subdirectory in the current directory.
        - `list_current_directory()`: List the contents of the current directory.
        - `go_back()`: Move to the parent directory.

---

#### **2. Ownership Rules**
1. The `Directory` class owns the `File*` and `Directory*` objects it contains. When a `Directory` is deleted, it should also delete its files and subdirectories.
2. The `FileSystem` class owns the root directory. Deleting the `FileSystem` should clean up the entire file system.

---

#### **3. Example Workflow**
1. Initialize the file system:
    ```cpp
    FileSystem fs;
    ```
2. Create files and directories:
    ```cpp
    fs.create_subdirectory("Documents");
    fs.navigate_to("Documents");
    fs.create_file("Resume.pdf", 1024);
    fs.create_subdirectory("Projects");
    fs.navigate_to("Projects");
    fs.create_file("Project1.cpp", 2048);
    fs.go_back();
    fs.list_current_directory();
    ```
3. Delete files or directories:
    ```cpp
    fs.navigate_to("Projects");
    fs.remove_file("Project1.cpp");
    fs.go_back();
    fs.remove_subdirectory("Projects");
    fs.list_current_directory();
    ```
4. When the program ends, the `FileSystem` destructor will automatically clean up all dynamically allocated memory.

---

### **Implementation Steps**

#### **1. Start with the `File` Class**
- Create the `File` class with a constructor, a `get_info()` method, and proper getters for name and size.

#### **2. Implement the `Directory` Class**
- Manage a vector of raw pointers (`std::vector<File*> files` and `std::vector<Directory*> subdirectories`).
- Write the destructor to clean up all owned `File` and `Directory` objects.
- Implement the methods to add/remove files and subdirectories and list contents.

#### **3. Build the `FileSystem` Class**
- Manage navigation between directories (`current_dir` points to the current working directory).
- Create methods for creating files and directories, navigating, and listing the contents.

#### **4. Test the Workflow**
- Write test cases in `main()` to simulate creating, navigating, and deleting files and directories.

---

### **Tips**
1. **Memory Management**:
   - Pay attention to ownership and always delete dynamically allocated objects.
   - Use proper checks before deleting (e.g., make sure a file exists before deleting it).

2. **Encapsulation**:
   - Keep data members private and expose functionality through public methods.

3. **Debugging**:
   - Use `std::cout` to log actions like creating, deleting, or navigating to directories to ensure everything works as expected.

4. **Enhancements** (Optional if you have extra time):
   - Add support for file sizes in the `list_contents()` output.
   - Add error handling for invalid navigation or duplicate file/directory names.

---

### **Expected Output Example**
Given the following operations:
```cpp
fs.create_subdirectory("Documents");
fs.navigate_to("Documents");
fs.create_file("Resume.pdf", 1024);
fs.create_subdirectory("Projects");
fs.navigate_to("Projects");
fs.create_file("Project1.cpp", 2048);
fs.go_back();
fs.list_current_directory();
```

You might see:
```
Contents of Documents:
  File: Resume.pdf (1024 bytes)
  Directory: Projects
```

---

## objectives
This project will force me to think critically about
- pointers,
- ownership, and 
- object relationships,
all while giving me hands-on experience with dynamic memory.
