
EMpower (Employee Management System) 
This is a simple Employee Management System implemented in C++. The system provides a menu-based interface for users to perform various operations related to employee records.

Features
User Authentication
Users can register their credentials (name and password) or login with existing credentials to access the system.

Add Record
Users can add new employee records by providing details such as name, ID, designation, age, CTC (Cost To Company), and experience.

Display Record
Users can view all employee records stored in the system.

Modify Record
Users can modify existing employee records by providing the employee ID and updating the necessary details.

Search Record
Users can search for a specific employee record by entering the employee ID.

Delete Record
Users can delete employee records by providing the employee ID.

How to Use
Compilation: Compile the source code using a C++ compiler.

bash
Copy code
g++ main.cpp -o employee_management_system
Execution: Run the compiled executable.

bash
Copy code
./employee_management_system
Login/Register: Follow the prompts to either register as a new user or login with existing credentials.

Menu Options: After successful authentication, users can choose from various menu options to perform desired operations.

Dependencies
iostream: Standard Input/Output stream for user interaction.
fstream: File stream for reading from and writing to files.
windows.h: Header file for Windows API functions (for system-specific operations).
unistd.h: Header file for Unix standard functions (for system-specific operations).
conio.h: Header file for console input/output functions (for password masking).
cstdlib, ctime: Standard Library headers for general-purpose functions and time functions.
cstdio: Standard Input/Output functions.
cstring: String manipulation functions.
