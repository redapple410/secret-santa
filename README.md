# Secret Santa

A simple program to randomly "draw" names for a secret santa gift exchange. I   
wrote this program so that me and my friends could continue our secret santa  
tradition during the COVID-19 pandemic.

## Instructions:

1. Create a file called `names.in`.
2. In `names.in`:
  a. The first line should be an integer *n* (4 ≤ *n* ≤ 20), the number of  
  people participating.
  b. The next *n* lines should each contain a person's name and their email,  
  separated by a space. (The names and emails cannot contain spaces.)
3. Run the command  
`g++ randomize-ppl.cpp && ./a.out`  
This will produce a file `names.out`.
4. Verify that the randomization worked by running the command  
`head -n 1 names.out`  
This should output the number *n*.
5. Create a `.env` file with variables `SERVER_NAME` (SMTP server address),  
`SERVER_PORT` (SMTP server port), `EMAIL` (the email adress that all the emails  
will be sent from), and `PW` (the password for this email).
6. Run the command  
`python3 email-ppl.py`  
This will send the emails to everyone.
