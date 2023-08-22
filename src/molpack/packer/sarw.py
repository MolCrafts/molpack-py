from molpackcpp.packer.sarw import SARW as _SARW
from molpack.region import Region
import numpy as np

class SARW(_SARW):

    def __init__(self, region: Region, step_length: float):
        super().__init__(region, step_length)

    @property
    def step_length(self) -> float:
        return super().get_step_length()
    
    @step_length.setter
    def step_length(self, step_length: float):
        super().set_step_length(step_length)

    def walk(self, num_steps: int) -> np.ndarray:
        return np.array(super().walk(num_steps))