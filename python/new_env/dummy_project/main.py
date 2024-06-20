'''
OBS:
    fisierul old_list.txt enumera modulele instalate in mediul principal(cel standard)
    fisierul new_list.txt enumera modulele prezente in noul venv(new_venv)
    noile module vor fi instalate in new_venv/Lib
    codul sursa nu trebuie sa se afle neaparat in acelasi director cu venv
'''
import requests
req=requests.get('https://stackoverflow.com/questions/7696924/how-do-i-create-multiline-comments-in-python')
print(req.status_code)

