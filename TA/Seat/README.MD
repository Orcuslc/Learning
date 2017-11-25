## Installation through source code:
- Python v3.0+
- O365
  Notes: To install `O365`, Please install `Python3-pip` when installing python3, and use the command line in Administrator Mode
  `pip install O365`.
- PyQt5
- Qt5.0+

## Format of the seat file:
- Shoule be `.csv` file, with seperation being the comma `,`.
- Each line represent a record with five columns, and the format shoule be like

  | Name    | Hawk ID | Building | Room | Seat |
  | ------- | ------- | -------- | ---- | ---- |
  | Foo Bar | foobar  | PBB      | W101 | A21  |

## Usage:

#### 1. Enter the information needed for sending emails.

- Hawk ID
- Password
- Choose the seat file by pressing the `Seat File` button.

#### 2. There are two modes in controlling the title and contents
#####- The default mode

   In this mode, you should enter the detailed information of the exam, while keep the states of `Enter title` and `Enter content` as `False`.

   - Course

   - Exam

   - Time

   The title and content will be generated automatically in the format below.

   Title:

     {Exam} seat: {Building}-{Room}-{Seat}

   Content:

````
Dear {Name}:
Your seat for {Exam} is: Building {Building}, Room {Room}, Seat {Seat}. It is recommended that you explore your seat a day before the exam.
The exam is on {Time}. 
````
#####- The customized mode

  In this mode, you have full control of the title and content. In order to enter this mode, just check the state of `Enter title` and `Enter content` as `True`, and enter what you want in the editing area right to the checkbox.


If you want to add additional info into the title and content, like:

- name
- building
- room
- seat
- exam
- time

you need to use `{}` to wrap these parameters, which need to be in `UPPERCASE` letters. For example,

````
Dear {NAME}:
The {EXAM} will be held on {TIME}, and your seat is {BUILDING}, {ROOM}, {SEAT}. Wish you good luck in the exam!
````

#### 3. Use the configuration file

​	There is an easy way to keep memory of your information, which is to use the config file. There is a default config file `config.txt` in the same path of the executable file, and in order to generate a blank config file, just press the `Save Config` button when running the program. After entering all the information in the program, you can dump the configuration into a local config file using the `Save Config` button, and the file by default is `config.txt` in the same path.

​	The config file has a format of `json`, which means it consists of a list of `key:value` pairs. It is a better way to edit the config file using some local file editor, and load it into the program with the `Load Config` button.