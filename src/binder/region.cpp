#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>
#include <vector>

#include "region.hpp"
#include "caster.h"

namespace py = pybind11;

PYBIND11_MODULE(molpackcpp, m) {
    auto m_region = m.def_submodule("region", "Region submodule");
    py::class_<molpack::SphericalRegion>(m_region, "SphericalRegion")
        .def(py::init<molpack::Vec3<double>, double>())
        .def("origin", &molpack::Region::origin)
        .def("size", &molpack::Region::size);
}