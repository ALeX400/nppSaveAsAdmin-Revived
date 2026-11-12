#include "FlushFileBuffersCommand.hpp"

#include "ICommand.hpp"
#include "IWinApiFunctions.hpp"

class FlushFileBuffersCommand : public ICommand {
 public:
  using ICommand::ICommand;

 private:
  bool execute(const std::vector<char>& data,
               std::vector<char>& ret_data) override {
    const FlushFileBuffersData* request =
        get_command_data_from_vector<FlushFileBuffersData>(data);
    if (!request)
      return false;

    FlushFileBuffersResult* result =
        prepare_vector_to_store_data<FlushFileBuffersResult>(ret_data);
    const BOOL success = m_winapi.flush_file_buffers(request->handle);
    result->success = (success == TRUE);
    result->last_error = success ? ERROR_SUCCESS : GetLastError();
    return true;
  }
};

std::unique_ptr<ICommand> make_flush_file_buffers_command(
    IWinApiFunctions& original_functions) {
  return std::make_unique<FlushFileBuffersCommand>(original_functions);
}
