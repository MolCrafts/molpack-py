#include <pybind11/pybind11.h>
#include "vec3.hpp"


namespace pybind11 {
namespace detail {

template <> struct type_caster<molpack::Vec3<double>> {
    public:
        PYBIND11_TYPE_CASTER(molpack::Vec3<double>, _("molpack.Vec3"));

        bool load(handle src, bool) {
            PyObject *source = src.ptr();
            value = molpack::Vec3<double>(
                PyFloat_AsDouble(PyTuple_GetItem(source, 0)),
                PyFloat_AsDouble(PyTuple_GetItem(source, 1)),
                PyFloat_AsDouble(PyTuple_GetItem(source, 2))
            );
            return !PyErr_Occurred();
        }

        static handle cast(molpack::Vec3<double> src, return_value_policy /* policy */, handle /* parent */) {
            return Py_BuildValue("(ddd)", src.getX(), src.getY(), src.getZ());
        }
};
}
}