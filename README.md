# NppSaveAsAdmin Revived

An unofficial, community-maintained continuation of the original [NppSaveAsAdmin](https://github.com/Hsilgos/nppsaveasadmin), by Hsilgos (Khnykin Yauheni). Not affiliated with the original author or the Notepad++ team.

**Status:** Modernization in progress. A successful compilation does not prove runtime compatibility. Privileged save behavior and UAC handling must be tested on current versions of Notepad++ before a stable release.

## Download and install

Find the x86 or x64 ZIP matching your **Notepad++ architecture** under [Releases](https://github.com/ALeX400/nppSaveAsAdmin-Revived/releases). Each ZIP contains:

- `NppSaveAsAdmin.dll`
- `NppAdminAccess.exe`
- `license.txt`
- `README.md`

Extract the contents to `<Notepad++ installation>/plugins/NppSaveAsAdmin/`. Keep the DLL and elevated helper executable in the **same directory**, then restart Notepad++. This matches the current manual plugin installation layout documented by Notepad++.

## Builds and releases

The [Build and Release workflow](.github/workflows/build-release.yml) runs MSBuild on Windows using Visual Studio 2022, compiles Win32/x86 and x64 configurations, and uploads ZIP artifacts for CI. Pushing a tag such as `v1.0.212-revived.1` creates a GitHub Release containing both ready-to-extract ZIPs if both builds pass. Tags with a prerelease suffix publish prereleases.

See [CHANGELOG.md](CHANGELOG.md) for changes.

## Attribution and license

Derived from [Hsilgos/nppsaveasadmin](https://github.com/Hsilgos/nppsaveasadmin). The upstream license and copyright notices are preserved in `NppSaveAsAdmin/license.txt` and individual source files. GPL terms apply to covered derived code.

## Security note

The inherited design intercepts Win32 file operations and communicates with an elevated helper over named pipes. Treat builds as experimental until tested for correctness, process isolation, UAC behavior and privilege boundaries.
