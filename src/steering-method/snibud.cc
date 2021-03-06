// Copyright (c) 2017, CNRS
// Authors: Florent Lamiraux
//
// This file is part of hpp-core.
// hpp-core is free software: you can redistribute it
// and/or modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation, either version
// 3 of the License, or (at your option) any later version.
//
// hpp-core is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even the implied warranty
// of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Lesser Public License for more details.  You should have
// received a copy of the GNU Lesser General Public License along with
// hpp-core. If not, see <http://www.gnu.org/licenses/>.

# include <hpp/core/steering-method/snibud.hh>

# include <hpp/pinocchio/device.hh>
# include <hpp/pinocchio/joint.hh>

# include <hpp/core/problem.hh>
# include <hpp/core/dubins-path.hh>

namespace hpp {
  namespace core {
    namespace steeringMethod {
      PathPtr_t Snibud::impl_compute (ConfigurationIn_t q1,
          ConfigurationIn_t q2) const
      {
        DubinsPathPtr_t path =
          DubinsPath::create (device_.lock (), q2, q1,
			      rho_ , xyId_, rzId_, wheels_, constraints ());
	
        return path->reverse ();
      }

      Snibud::Snibud (const Problem& problem) :
        CarLike (problem), weak_ ()
      {
      }

      Snibud::Snibud  (const Problem& problem,
          const value_type turningRadius,
          JointPtr_t xyJoint, JointPtr_t rzJoint,
          std::vector <JointPtr_t> wheels) :
	CarLike (problem, turningRadius, xyJoint, rzJoint, wheels)
      {
      }

      /// Copy constructor
      Snibud::Snibud  (const Snibud& other) :
        CarLike (other)
      {
      }

    } // namespace steeringMethod
  } // namespace core
} // namespace hpp
