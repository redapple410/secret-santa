import os
from dotenv import load_dotenv
import smtplib, ssl

load_dotenv()

smtp_server = os.environ.get("SERVER_NAME")
port = os.environ.get("SERVER_PORT")
from_email = os.environ.get("EMAIL")
from_pw = os.environ.get("PW")

f = open("names.out", "r")

fl = f.readlines()
n = int(fl[0])
to_name = fl[1].split()
to_email = fl[2].split()
secret_name = fl[3].split()

context = ssl.create_default_context()

try:
    server = smtplib.SMTP(smtp_server, port)
    server.ehlo()
    server.starttls(context = context)
    server.ehlo()
    server.login(from_email, from_pw)
    for i in range(0, n):
        msg = ("Subject: Secret Santa!\n\n"
               f"Hello {to_name[i]},\n\n"
               "Thanks for participating in this secret santa gift exchange. "
               "It's going to be fun!\n\n"
               f"You are responsible for getting a gift for {secret_name[i]}.\n\n"
               "Have a wonderful day!")
        server.sendmail(from_email, to_email[i], msg)
except Exception as e:
    print(e)
finally:
    server.quit()
