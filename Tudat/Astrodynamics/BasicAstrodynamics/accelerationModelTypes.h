/*    Copyright (c) 2010-2017, Delft University of Technology
 *    All rigths reserved
 *
 *    This file is part of the Tudat. Redistribution and use in source and
 *    binary forms, with or without modification, are permitted exclusively
 *    under the terms of the Modified BSD license. You should have received
 *    a copy of the license with this file. If not, please or visit:
 *    http://tudat.tudelft.nl/LICENSE.
 *
 */

#ifndef TUDAT_ACCELERATIONMODELTYPES_H
#define TUDAT_ACCELERATIONMODELTYPES_H

#include "Tudat/Astrodynamics/ElectroMagnetism/cannonBallRadiationPressureAcceleration.h"
#include "Tudat/Astrodynamics/Gravitation/centralGravityModel.h"
#include "Tudat/Astrodynamics/Gravitation/sphericalHarmonicsGravityModel.h"
#include "Tudat/Astrodynamics/Gravitation/mutualSphericalHarmonicGravityModel.h"
#include "Tudat/Astrodynamics/Gravitation/thirdBodyPerturbation.h"
#include "Tudat/Astrodynamics/Aerodynamics/aerodynamicAcceleration.h"
#include "Tudat/Astrodynamics/BasicAstrodynamics/massRateModel.h"
#include "Tudat/Astrodynamics/Propulsion/thrustAccelerationModel.h"
#include "Tudat/Astrodynamics/Propulsion/massRateFromThrust.h"


namespace tudat
{

namespace basic_astrodynamics
{


//! List of accelerations available in simulations
/*!
 *  List of accelerations available in simulations. Acceleration models not defined by this
 *  given enum cannot be used for automatic acceleration model setup.
 */
enum AvailableAcceleration
{
    undefined_acceleration,
    central_gravity,
    aerodynamic,
    cannon_ball_radiation_pressure,
    spherical_harmonic_gravity,
    mutual_spherical_harmonic_gravity,
    third_body_central_gravity,
    third_body_spherical_harmonic_gravity,
    third_body_mutual_spherical_harmonic_gravity,
    thrust_acceleration
};

//! Function to get a string representing a 'named identification' of an acceleration type
/*!
 * Function to get a string representing a 'named identification' of an acceleration type
 * \param accelerationType Type of acceleration model.
 * \return String with acceleration id.
 */
std::string getAccelerationModelName( const AvailableAcceleration accelerationType );

//! List of model types for body mass rates.
/*!
*  List of model types for body mass rates available in simulations. Mass rate models not defined by this
*  given enum cannot be used for automatic mass rate model setup.
*/
enum AvailableMassRateModels
{
    undefined_mass_rate_model,
    custom_mass_rate_model,
    from_thrust_mass_rate_model
};

//! Function to identify the derived class type of an acceleration model.
/*!
 *  Function to identify the derived class type of an acceleration model. The type must be defined
 *  in the AvailableAcceleration enum to be recognized by this function.
 *  \param accelerationModel Acceleration model of which the type is to be identified.
 *  \return Type of the accelerationModel, as identified by AvailableAcceleration enum.
 */
AvailableAcceleration getAccelerationModelType(
        const boost::shared_ptr< basic_astrodynamics::AccelerationModel< Eigen::Vector3d > >
        accelerationModel );

//! Function to identify the type of a mass rate model.
/*!
 *  Function to identify the type of a mass rate model. The type must be defined
 *  in the AvailableMassRateModels enum to be recognized by this function.
 *  \param massRateModel Mass rate model of which the type is to be identified.
 *  \return Type of the massRateModel, as identified by AvailableMassRateModels enum.
 */
AvailableMassRateModels getMassRateModelType(
        const boost::shared_ptr< MassRateModel > massRateModel );

//! Function to get all acceleration models of a given type from a list of models
/*!
 * Function to get all acceleration models of a given type from a list of models
 * \param fullList List of acceleration models
 * \param modelType Type for which all models are to be retrieved
 * \return Subset of fullList for which the acceleration model type is modelType
 */
std::vector< boost::shared_ptr< AccelerationModel3d > > getAccelerationModelsOfType(
        const std::vector< boost::shared_ptr< AccelerationModel3d > >& fullList,
        const AvailableAcceleration modelType );

} // namespace basic_astrodynamics

} // namespace tudat

#endif // TUDAT_ACCELERATIONMODELTYPES_H
