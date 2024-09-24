from qiskit_ibm_runtime import QiskitRuntimeService
from qiskit import QuantumCircuit

def computer_setup():

    #in order to run quantum programs a quantum computer is needed
    #luckily, IBM offer some of theis for use
    #see https://quantum.ibm.com/services/resources for a list of available computers
    print("Connecting to a quantum computer...")
    service = QiskitRuntimeService(instance="ibm-q/open/main")
    backend=service.backend(name = "ibm_kyiv")

def circuit0():
    
    print("Defining a one qubit quantum circuit...")
    qc=QuantumCircuit(1) #a quantum circuit with 1 qubit is declared
    qc.x(0)

    qc.draw(output='mpl',filename='circuit0.png')

computer_setup()
circuit0()
print("Sample program finished.")
