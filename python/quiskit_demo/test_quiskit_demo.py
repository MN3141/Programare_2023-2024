from quiskit_demo import *

def test0_kyiv_backend():
    service = QiskitRuntimeService(instance="ibm-q/open/main")
    computer=service.backend('ibm_kyiv')
    assert computer.num_qubits > 0 
