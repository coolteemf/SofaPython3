/******************************************************************************
*                 SOFA, Simulation Open-Framework Architecture                *
*                    (c) 2021 INRIA, USTL, UJF, CNRS, MGH                     *
*                                                                             *
* This program is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU Lesser General Public License as published by    *
* the Free Software Foundation; either version 2.1 of the License, or (at     *
* your option) any later version.                                             *
*                                                                             *
* This program is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License *
* for more details.                                                           *
*                                                                             *
* You should have received a copy of the GNU Lesser General Public License    *
* along with this program. If not, see <http://www.gnu.org/licenses/>.        *
*******************************************************************************
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/

#pragma once

#include <pybind11/pybind11.h>
#include <SofaPython3/Sofa/Core/Binding_Base.h>
#include <SofaBaseVisual/BaseCamera.h>

namespace sofapython3 {


void moduleAddBaseCamera(pybind11::module &m);

} /// namespace sofapython3

// The class instanciation of the following binding is explicit here
// to force its linkage into external projects/plugins (see PR #130)
extern template class pybind11::class_<
	sofa::component::visualmodel::BaseCamera,
	sofa::core::objectmodel::BaseObject,
	sofapython3::py_shared_ptr<sofa::component::visualmodel::BaseCamera>>;

