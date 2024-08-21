from calculator import BasicCalculator

def test0_calculator():

    ti=BasicCalculator()
    ti.add(-1)
    ti.add(1)
    assert ti.get_result()==0

def test1_calculator():

    ti=BasicCalculator()
    assert ti.divide(0) < 0
