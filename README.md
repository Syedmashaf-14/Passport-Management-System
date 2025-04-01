## Passport Management System
This C++ program implements a Passport Management System using a Priority Queue. The system allows users to manage passport applications based on priority levels and process them using multithreading.

# Features
Add Applicants – Store applicant ID and priority level.
Display All Applicants – View the list of applications in priority order.
Clear All Applications – Remove all stored applications.
Process Applications – Handle up to 4 applications simultaneously using threads.
File Storage – Save applicant data in a text file (data.txt).

# Implementation Details
Priority Queue: Implemented using a linked list, ensuring higher-priority applications are processed first.

Multithreading: Uses C++ threads to process applications concurrently.

# File Handling:
Saves applicant details in a file for record-keeping.

# How to Run
Compile the code using a C++ compiler (g++ or MSVC).

Run the executable and follow the on-screen menu.

Applications will be processed in priority order, with up to 4 running in parallel.
