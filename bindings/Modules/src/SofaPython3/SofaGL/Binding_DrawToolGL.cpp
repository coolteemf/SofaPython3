/******************************************************************************
*                              SofaPython3 plugin                             *
*                  (c) 2021 CNRS, University of Lille, INRIA                  *
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

#include <pybind11/pybind11.h>

#include <sofa/simulation/Node.h>
using sofa::simulation::Node;

#include <sofa/core/visual/VisualParams.h>

#include <sofa/simulation/Simulation.h>
#include <sofa/gl/DrawToolGL.h>

#include <SofaPython3/SofaGL/Binding_DrawToolGL.h>
#include <SofaPython3/SofaGL/Binding_DrawToolGL_doc.h>


namespace sofapython3 {

using DrawToolGL = sofa::gl::DrawToolGL;


namespace py { using namespace pybind11; }

void moduleAddDrawToolGL(pybind11::module& m) {
    m.def("draw", [](Node* node){
      auto* vparam = sofa::core::visual::VisualParams::defaultInstance();
      vparam->drawTool() = new sofa::gl::DrawToolGL();
      vparam->setSupported(sofa::core::visual::API_OpenGL);
      sofa::simulation::getSimulation()->draw(vparam, node);
    }, doc::SofaGL::draw);

    m.def("glewInit", [](){
      glewInit();
    }, doc::SofaGL::glewInit);
}

} // namespace sofapython3
