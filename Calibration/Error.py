import numpy as np

class error():
    def __init__(self, ForceData, testCal):
        self.RMSE_xyz = [self.RMSE(ForceData[:, i], testCal[:, i]) for i in range(3)]
        self.NRMSD_xyz = [self.NRMSD(ForceData[:, i], testCal[:, i]) for i in range(3)]
        self.R2_xyz = [self.R2(ForceData[:, i], testCal[:, i]) for i in range(3)]
        
        self.RMSE_total = self.RMSE(ForceData, testCal)
        self.NRMSD_total = self.NRMSD(ForceData, testCal)
        self.R2_total = self.R2(ForceData, testCal)
        
    def RMSE(self, a, b):
        return np.sqrt(np.mean((a - b) ** 2))

    def NRMSD(self, a, b):
        return (self.RMSE(a, b) / (np.max(b) - np.min(b))) * 100

    def R2(self, a, b):
        numerator = np.sum((a - b) ** 2)
        denominator = np.sum((a - np.mean(a)) ** 2)
        return 1 - numerator / denominator
    
    def print_error(self):
        axes = ['x', 'y', 'z']
        print(f"Errors:")
        for i, axis in enumerate(axes):
            print(f"  {axis}: "
                  f"RMSE: {self.RMSE_xyz[i]:.6f}, "
                  f"NRMSD: {self.NRMSD_xyz[i]:.6f}%, "
                  f"R^2: {self.R2_xyz[i]:.6f}")
        print(f"Total: "
              f"RMSE: {self.RMSE_total:.6f}, "
              f"NRMSD: {self.NRMSD_total:.6f}%, "
              f"R^2: {self.R2_total:.6f}")
        print()