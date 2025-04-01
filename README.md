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

![image](https://github.com/user-attachments/assets/af6cd86b-d1a6-4852-b1eb-6a8fa897de55)
![image](https://github.com/user-attachments/assets/be224a49-d11c-4db5-b815-9681fe7c3efe)



Applications will be processed in priority order, with up to 4 running in parallel.
