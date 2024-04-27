import pandas as pd
manufacturers=["IPRS","Pravets","Inter-Konnekt","RobCo"]
data=pd.DataFrame(manufacturers)
data.to_excel("output.xlsx",sheet_name="pg 0",header=False)