# Staff-Management-System

This is a complete C Programming based project, created to record and manage all of your staff/student/visitors. For more information please read the README file.

## Description: Staff Management System (SMS v1.0)

A simple **Staff Management System** built using **C Programming Language**, which allows users to manage staff profiles efficiently. For now it's a Terminal based Program.

## 🚀 Features

- 📌 **Add a New Staff**
- 📌 **View All Staff Profile**
- 🔍 **Search For a Staff Profile**
- 🗑️ **Delete a Staff Profile**
- 🚪 **Exit the Program**

## 🛠️ How It Works

1️⃣ **Start the Program**

- Displays a **Welcome Message** and the **Main Menu** options.

2️⃣ **Main Menu Options**

- `[1] Add a New Staff`
- `[2] View All Staff Profile`
- `[3] Search For a Staff Profile`
- `[4] Delete a Staff Profile`
- `[5] Exit`

3️⃣ **User Input Choice**

- The user selects an option **(1-5)**.

4️⃣ **Perform Actions Based on Choice:**

- **`1. Add a New Staff`**
  - Prompts for Name, Staff ID, Designation etc.
  - Stores the data in a database.
  - Shows a success message.
  - Returns to the main menu.
- **`2. View All Staff Profiles`**
  - Reads staff data from the database.
  - Displays all staff records in a formatted table.
  - Returns to the main menu.
- **`3. Search For a Staff Profile`**
  - Asks for a staff's Staff ID.
  - Searches the record of the staff.
  - If found, displays details; otherwise, shows an error.
  - Returns to the main menu.
- **`4. Delete a Staff Profile`**
  - Asks for the Staff ID of the staff to delete.
  - If found, removes the record from the database.
  - Shows a success message.
  - Returns to the main menu.
- **`5. Exit`**
  - Displays a **Goodbye Message** and **Exits the Program**.

## 🔩 Technology Used:

- C Programming
- CSV based Datbase Management
- File Handling in C Programming.

## ✅ Advantages:

- Minimal Design
- Easy to Record Data
- Highly Scalable & Optimised
- Small & Compressed Architecture

## 📌 Points of Improvement:

- Use a proper database system, instead using .csv file like MongoDB, MySQL ect.
- Currently optimised for storing max 5000 records, which need to be improved.
- Improve the UI/UX experience for better user interaction.

## 💻 Installation & Usage

```sh
git clone https://github.com/Soumyaghosh008/Staff-Management-System.git
cd Staff-Management-System
```

## 🔩 Compile & Run (For Mac,Linux & Windows)

```sh
gcc main.c staff_operations.c -o staff_management
./staff_management
```
