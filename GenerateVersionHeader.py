import sys

version_str = sys.argv[1].removeprefix("v")
base = version_str.split("-", 1)[0].split("+", 1)[0]
parts = base.split(".")
if not (1 <= len(parts) <= 4 and all(part.isdecimal() for part in parts)):
    raise SystemExit("Expected a numeric version with an optional suffix (e.g. 1.0.212-revived.1)")
numbers = [int(part) for part in parts] + [0] * (4 - len(parts))
if any(n > 65535 for n in numbers):
    raise SystemExit("Version fields must be within 0..65535")
print('#define SAVE_AS_ADMIN_VERSION "' + version_str + '"')
print('#define SAVE_AS_ADMIN_VERSION_UNICODE L"' + version_str + '"')
print('#define SAVE_AS_ADMIN_VERSION_DIGITAL ' + ', '.join(map(str, numbers)))
