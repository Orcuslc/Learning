## Dependents:
- Python v3.0+
- O365
Notes: To install `O365`, Please install `Python3-pip` when installing python3, and use the command line in Administrator Mode
`pip install O365`.

## Usage:
1. fill the `configuration` part in `seats.py` with `hawkid@uiowa.edu` and your password.
2. Requirements to the CSV file:
	- No headers
	- Three columns, `name`, `hawkid`, 'seat'
3. Use the command line `python seats.py *path-to-file*` to send emails.