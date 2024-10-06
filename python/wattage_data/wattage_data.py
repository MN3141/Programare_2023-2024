## @package wattage_data

'''
The standard data format of the input file shall be:
==============================
#Name of electronic device   #
#Way in which was utilised   #
#Raw data in watts in columns#
==============================
'''

import xlsxwriter
import sys

OUTPUT_FILE_NAME='measurements.xlsx'

##System which represents the process of measuring and formating data
class MeasurementData:
    measurement_device_name=''
    measurement_device_use=''
    measurement_device_data=''

    ##Constructor
    def __init__(self,measurement_device_name,measurement_device_use,measurement_device_data):
        self.measurement_device_name=measurement_device_name
        self.measurement_device_use=measurement_device_use
        self.measurement_device_data=measurement_device_data

##Function for reading data from a text file
def get_raw_data(filename):

    ##Fetch data from file
    fin=open(filename,'r')
    file_data=fin.readlines()
    fin.close()

    ##convert raw data from string to float
    raw_data=[]
    temp=file_data[2].split()
    number_of_data=len(temp)

    for i in range(number_of_data):
        raw_data.append(float(temp[i]))
    
    return MeasurementData(file_data[0],file_data[1],raw_data)

##Function for writing the data into an excel file 
def output_data(workbook,device,device_name):
    
 #workbook = xlsxwriter.Workbook(OUTPUT_FILE_NAME)
 worksheet=workbook.add_worksheet(device_name)

 worksheet.set_column('A:A', 30)
 worksheet.set_column('B:B',len(device.measurement_device_use))
 worksheet.set_column('C:D', 30)
 cell_format = workbook.add_format()
 cell_format.set_align('center')

 worksheet.write('A1','Name',cell_format)
 worksheet.write('B1','Usage',cell_format)
 worksheet.write('C1','Measured values [W]',cell_format)
 worksheet.write('D1','Average value [W]',cell_format)

 worksheet.write('A2',device.measurement_device_name,cell_format)
 worksheet.write('B2',device.measurement_device_use,cell_format)
 worksheet.write_column('C2',device.measurement_device_data,cell_format)

 average_value=sum(device.measurement_device_data)/len(device.measurement_device_data)
 worksheet.write('D2',average_value,cell_format)

 chart = workbook.add_chart({'type': 'line'})
 chart.add_series({ 
     #[sheetname, first_row, first_col, last_row, last_col]
     'values': [device_name, 1, 2, len(device.measurement_device_data), 2],
     'line': {'color':'blue'},
     'name': device_name+' power consumption'
     })

 chart.set_x_axis({
        'name':'Time [min]'
 })
 chart.set_y_axis({
        'name':'Consumption [W]'
 })

 chart.set_size({'width': 1024, 'height': 720})

 worksheet.insert_chart('F1', chart)

 #workbook.close()
    
if len(sys.argv)==1:
    print("Error! Please select a at least a device.")
    print("Example: py ",sys.argv[0]," tv.txt")
else:
    device_number=len(sys.argv)-1 #the first element will always be the name of the script
    workbook = xlsxwriter.Workbook(OUTPUT_FILE_NAME)
    for i in range(device_number):
        device=get_raw_data(sys.argv[i+1])
        device_name=sys.argv[i+1].split('.')
        output_data(workbook,device,device_name[0])
    workbook.close()