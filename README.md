# nihitha_1831


# 🚐 Transport Management System (C Program)

A simple, menu-driven **Hospital Transport Management System** written in C.

This program helps hospital staff record and manage transport services such as ambulance allocation, patient transfer details, driver information, trip timings, and service status—all stored in a binary file.

---

## 👉 Abstract

The **Transport Management System** is a lightweight, command-line C application designed to help hospitals manage and track vehicle-based patient transport operations. The system lets users register transport requests, assign ambulances, record driver details, update trip status, search trips by ID, and view all transport logs.

All transport data is stored persistently in a binary `.dat` file, ensuring the system maintains records even when closed.

This project demonstrates essential C programming concepts such as structures, arrays, file operations (`fread`, `fwrite`), loops, conditional statements, and user-friendly menu-driven interfaces.
It provides a practical, beginner-friendly tool for hospitals to systematically manage their transport and ambulance services.

---

# 👉 Features of the Program

### ✔ Add New Transport Entry

* Enter Trip/Transport ID
* Patient Name
* Ambulance Number
* Driver Name
* Pickup Location
* Drop Location
* Trip Status (Ongoing / Completed / Scheduled)
* Save to binary file `transport.dat`

### ✔ View All Transport Records

Displays:

* Trip ID
* Patient Name
* Ambulance No.
* Driver Name
* From → To
* Status

### ✔ Search Transport by Trip ID

* Find specific transport entry
* Show complete details
* Displays **Not Found** if ID doesn’t exist

### ✔ Update Transport Details

* Load all records into an array
* Modify:

  * Status
  * Driver name
  * Locations
* Rewrite updated record list back to file

### ✔ Delete Transport Record

* Confirm deletion
* Remove entry from storage
* Save rewritten list back to `transport.dat`

### ✔ Persistent Storage

* Records saved in `transport.dat`
* File auto-created if missing
* Uses binary read/write for reliability

### ✔ User-Friendly Menu System

* Clean terminal-based UI
* Input safety using `fgets()`
* Loop continues until Exit

---

# 👉 Technical Requirements

### System Requirements

* Windows / Linux / macOS
* Command-line terminal
* Minimum RAM: 4 MB
* Tiny disk space for `transport.dat`

### Software Requirements

* C compiler (GCC / Clang / MSVC)
* Any code editor (VS Code, CodeBlocks, Dev-C++, etc.)

### Programming Standards

* C89 / C99 / C11 compatible
* Uses only standard libraries

### Header Files Used

```c
#include <stdio.h>   // I/O + file handling
#include <string.h>  // String functions (fgets, strcpy, strcmp)
```

(No need for `<stdlib.h>`)

---

# 👉 File Handling Requirements

* Data stored in **binary file** → `transport.dat`
* Structure stored using:

  * `fwrite()` → writing
  * `fread()` → reading
* File created if not found
* Delete/Update operations use array-based rewrite technique

---

# 👉 Functional Requirements

### 🔹 User Interface

* Text-based
* Clear options
* Looped menu
* Error handling for invalid input

---

## 🔹 Transport Operations

### ✔ Add Transport Record

* Input trip ID
* Check for duplicates
* Enter patient/driver/location details
* Save to file

### ✔ View All Records

Display:

* Trip ID
* Patient
* Ambulance
* Driver
* Pickup → Drop
* Status

### ✔ Search Transport

* Input trip ID
* If exists → show details
* Else → “Record Not Found”

### ✔ Update Transport

* Load all data into array
* Modify:

  * Status
  * Driver
  * Route
* Save updated list back

### ✔ Delete Transport Entry

* Confirm user choice
* Remove entry
* Rewrite remaining records to `transport.dat`

---

# 👉 Data Management

* Permanent storage
* File auto-created
* Safe reading/writing
* Uses sequential storage of structures

---

# 👉 Program Flow

1. Display menu
2. User selects an option
3. Perform action
4. Display result
5. Return to menu
6. Exit when selected

---

screenshots
<img width="677" height="502" alt="Screenshot 2025-11-25 190223" src="https://github.com/user-attachments/assets/166f3a44-607d-438c-9f4f-812ec0a559f2" />
<img width="1009" height="316" alt="Screenshot 2025-11-25 190235" src="https://github.com/user-attachments/assets/763621fa-02ff-4db8-a587-e4d3869095e5" />
<img width="462" height="484" alt="Screenshot 2025-11-25 190246" src="https://github.com/user-attachments/assets/16957914-62b7-462e-82b6-9bbea3a54bfc" />
<img width="550" height="506" alt="Screenshot 2025-11-25 190309" src="https://github.com/user-attachments/assets/486a9f14-91d1-4cec-8d2c-6a5c3b9a88e5" />
<img width="439" height="347" alt="Screenshot 2025-11-25 190256" src="https://github.com/user-attachments/assets/dd34b314-8da3-4d1d-aa3c-6d08e0d431cf" />



# 👉 How to Run the Program

### Step 1 — Compile

```
gcc transport_management.c -o transport_management
```

### Step 2 — Run

Linux/macOS:

```
./transport_management
```

Windows:

```
transport_management.exe
```

### Step 3 — Data File

Automatically created:

```
transport.dat
```

All transport records are saved here permanently.

---
