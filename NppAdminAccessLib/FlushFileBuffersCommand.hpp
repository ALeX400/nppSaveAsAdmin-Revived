#pragma once

#include <memory>
class ICommand;
class IWinApiFunctions;

std::unique_ptr<ICommand> make_flush_file_buffers_command(
    IWinApiFunctions& original_functions);
