from .molpackcpp.region import SphericalRegion as _SphericalRegion
# from molpackcpp import CubicRegion as _CubicRegion

class Region:
    ...

class SphericalRegion(_SphericalRegion):
    
    def __init__(self, center, radius):
        super().__init__(tuple(center), radius)