#pip install coverage
#documentatie:https://coverage.readthedocs.io/en/7.5.3
#coverage run ceva.py-creare fisier .coverage
#coverage html ceva.py-creare pagina web cu raportul
#coverage report ceva.py-afisare raport pe consola
#coverage json ceva.py-afiasare raport intr-un fiser json
def dummy_funct(x):
    print(x)
x=10
if x > 1:
    print("MSG0")
if 2 > 1:
    print("Dumb test")
else:
    print("Dead code")
dummy_funct(2)
dummy_funct("IPRS")