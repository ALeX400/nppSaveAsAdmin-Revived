# Changelog

All changes to NppSaveAsAdmin Revived are documented here.

## [Unreleased]

- Modernized the Visual Studio C++ projects to the VS2022 v143 toolset and Windows 10 SDK.
- Added x86 and x64 GitHub Actions compilation, ZIP packaging and tag-based GitHub Releases.
- Preserved the original DLL and elevated helper executable names and license.
- Fixed the save-state reset implementation (`cancel_process_file()`).
- Deferred Win32 import hook initialization until Notepad++ sends `NPPN_READY`, and unhooked at `NPPN_SHUTDOWN`.
- Improved import search to work when the relevant API is imported from a module other than Kernel32.
- Added version header generation that supports prerelease suffixes.
- **Pending:** Windows CI compilation, real Notepad++ integration testing and UAC/security review.

## Upstream [1.0.211] - 2021-02-20

Original author Hsilgos: removed "Save As..." support and fixed a crash. Upstream: https://github.com/Hsilgos/nppsaveasadmin/releases/tag/1.0.211
