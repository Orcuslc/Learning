## Installation through source code:
- Python v3.0+
- O365
  Notes: To install `O365`, Please install `Python3-pip` when installing python3, and use the command line in Administrator Mode
  `pip install O365`.

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

#### 2. There are two modes in controlling the title and contents
#####- The default mode

   In this mode, you should enter the detailed information of the exam:

   - Course

   - Exam

   - Time

   The title and content will be generated automatically in the format below.

   Title:

     {Exam} seat: {Building}-{Room}-{Seat}

   Content:
````
     Dear {Name}:

     Your seat for {Exam} is: {Building}-{Room}-{Seat}. It is recommended that you explore your seat a day before the exam.

     The exam is on {Time}. 
````
#####- The customized mode

