import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from cal_data import calData
from Error import error

# '''
# methods for HGP calibration
# '''
# def RMSE(a, b):
#     return np.sqrt(np.mean((a - b) ** 2))

# def NRMSD(a, b):
#     return (RMSE(a, b) / (np.max(b) - np.min(b))) * 100

# def prepare_data(path):
#     load = load_data('test/' + path)
#     param = calData(load)
#     return param

# def plot_hgp_cal(time, actualForce, predForce, idx = 0):
#     titles = ['x', 'y', 'z']
    
#     plt.figure(figsize=(15,10))
#     plt.plot(time, actualForce, color='k', linewidth=1, label='Actual force')
#     plt.plot(time, predForce, color='r', linewidth=1, label='Predicted force', linestyle='--')
#     plt.xlabel('Time')
#     # plt.ylabel('Force')
#     plt.ylabel(f'Force in {titles[idx]} axis')
#     plt.legend()
#     plt.show

'''
methods for regular calibration
'''

# load file
def load_data(file_path):
    return pd.read_csv(file_path, header=None, sep=r'\s+', skiprows=0, converters={i: lambda x: x.replace(',', '') for i in range(100)})

def process_data(path):
    data = []
    cal_data = []
    cal_mat = []
    
    for data_path in path:
        # load data from path
        loaded_data = load_data('test/' + data_path)
        data.append(loaded_data)
        # split data for calibration
        cal_param = calData(loaded_data)
        cal_data.append(cal_param)
        # get calibration matrices
        cal_mat.append(cal_param.perform_cal())
    
    return cal_data, cal_mat

def testCalibration(cal_data, cal_mat, mode=None):
    test_cal = []
    if mode == 'multi':
        for cd in cal_data:
            for cm in cal_mat:
                cal_instance = np.dot(cd.SensorData, cm)
                test_cal.append(cal_instance)
    elif mode == 'single':
        for idx, cd in enumerate(cal_data):
            cal_instance = np.dot(cd.SensorData, cal_mat[idx])
            test_cal.append(cal_instance)
    else:
        raise ValueError("Invalid data.")
    return test_cal

# print errors
def print_error(caltest, data, mode='multi', index=None):
    if mode == 'multi':
        i = 1
        for idx, test in enumerate(caltest):
            # if not index == None and idx in index:
            data_row = 0 if idx < 3 else 1 if idx < 6 else 2
            print(f"Sensor data #{data_row} with Cal Mat #{idx-data_row*3}:")
            err = error(data[data_row].ForceData, test)
            err.print_error()
            i += 1
    elif mode == 'single':
        # for idx, test in enumerate(caltest):
        #     test_label = 'Test: ' if idx == 0 else 'Test(zeroed): '
        #     print(test_label)
        #     err = error(data[idx].ForceData, test)
        #     err.print_error()
        err = error(data[1].ForceData, caltest[1])
        err.print_error()
    else:
        raise ValueError("Invalid data.")

# plot graphs
def plot_calibration(cal_data, test_cal, cal_mat, mode=None):
    color = ['k', 'b', 'r', 'g']
    titles = ['x', 'y', 'z']

    if mode == 'multi':
        fig, axes = plt.subplots(3, 3, figsize=(15, 10))
        for i in range(len(cal_data)):
            for j in range(3):
                ax = axes[i, j]
                ax.plot(cal_data[i].Time, cal_data[i].ForceData[:, j], color=color[0], label='Actual' + titles[j], linewidth=2)
                for k in range(len(cal_mat)):
                    ax.plot(cal_data[i].Time, test_cal[k + 3*i][:, j], color=color[k + 1], label='Pred ' + titles[j] + ' from CalMat ' + str(k+1), linestyle='--')
                ax.set_title(f'Cal{i+1}_{titles[j]}')
                ax.set_xlabel('Time')
                ax.set_ylabel('Force')
                ax.legend()
    
    elif mode == 'single':
        fig, axes = plt.subplots(1, 3, figsize=(15, 5))
        for i in range(3):
            ax = axes[i]
            ax.plot(cal_data[1].Time, cal_data[1].ForceData[:, i], color=color[0], label='Actual' + titles[i], linewidth=2)
            ax.plot(cal_data[1].Time, test_cal[1][:, i], color=color[1], label='Predicted' + titles[i], linestyle='--')
            ax.set_title(f'Cal{i+1}_{titles[i]}')
            ax.set_xlabel('Time')
            ax.set_ylabel('Force')
            ax.legend()
    else:
        raise ValueError("Invalid data.")

    plt.tight_layout()
    plt.show()