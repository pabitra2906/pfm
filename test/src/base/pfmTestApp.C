//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "pfmTestApp.h"
#include "pfmApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
pfmTestApp::validParams()
{
  InputParameters params = pfmApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

pfmTestApp::pfmTestApp(const InputParameters & parameters) : MooseApp(parameters)
{
  pfmTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

pfmTestApp::~pfmTestApp() {}

void
pfmTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  pfmApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"pfmTestApp"});
    Registry::registerActionsTo(af, {"pfmTestApp"});
  }
}

void
pfmTestApp::registerApps()
{
  registerApp(pfmApp);
  registerApp(pfmTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
pfmTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  pfmTestApp::registerAll(f, af, s);
}
extern "C" void
pfmTestApp__registerApps()
{
  pfmTestApp::registerApps();
}
