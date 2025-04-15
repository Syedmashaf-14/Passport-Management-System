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

![image](https://github.com/user-attachments/assets/da421458-88c4-4e22-803c-2dd8ff438f1c)

![image](https://github.com/user-attachments/assets/6bb205e6-f2ee-4f8d-af37-06f539ca07f8)

![image](https://github.com/user-attachments/assets/fb79b689-62b8-4bce-8912-4ba4399340cc)
![image](https://github.com/user-attachments/assets/27f646c9-6322-4478-bb2a-fa3b3799827e)




Applications will be processed in priority order, with up to 4 running in parallel.
