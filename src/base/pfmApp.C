#include "pfmApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
pfmApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

pfmApp::pfmApp(const InputParameters & parameters) : MooseApp(parameters)
{
  pfmApp::registerAll(_factory, _action_factory, _syntax);
}

pfmApp::~pfmApp() {}

void
pfmApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAllObjects<pfmApp>(f, af, syntax);
  Registry::registerObjectsTo(f, {"pfmApp"});
  Registry::registerActionsTo(af, {"pfmApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
pfmApp::registerApps()
{
  registerApp(pfmApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
pfmApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  pfmApp::registerAll(f, af, s);
}
extern "C" void
pfmApp__registerApps()
{
  pfmApp::registerApps();
}
