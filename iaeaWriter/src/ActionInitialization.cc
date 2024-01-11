#include "ActionInitialization.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"

ActionInitialization::ActionInitialization()
{}

ActionInitialization::~ActionInitialization()
{}

void ActionInitialization::Build() const
{
	PrimaryGeneratorAction *generator = new PrimaryGeneratorAction();
	SetUserAction(generator);

	RunAction *runAction = new RunAction();
	SetUserAction(runAction);

	SetUserAction(new RunAction);
  	SetUserAction(new EventAction);
  	SetUserAction(new SteppingAction);
	
}  

