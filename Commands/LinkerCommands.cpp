#include "LinkerCommands.h"

void LinkerCommands::addCommand(std::unique_ptr<Command> command)
{
    allCommands.push_back(std::move(command));
}

void LinkerCommands::executeAllCommands()
{
    foreach(auto& command, allCommands)
        command->execute();
}
