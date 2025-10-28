[QBarcode][repo-home] is a Qt library allowing to read and generate barcodes.

> [!TIP]
> Latest development/pull requests will be committed into `main` branch.  
> Each stable release have their dedicated branch:
> - `1.0.x`: branch `dev/1.0`
> - `1.1.x`: branch `dev/1.1`
> - etc...

**Table of contents :**
- [1. Library details](#1-library-details)
  - [1.1. Features](#11-features)
  - [Supported barcodes](#supported-barcodes)
  - [1.2. Supported platforms](#12-supported-platforms)
    - [1.2.1. Status](#121-status)
    - [1.2.2. Specific behaviours](#122-specific-behaviours)
- [2. Requirements](#2-requirements)
  - [2.1. C++ Standards](#21-c-standards)
  - [2.2. Dependencies](#22-dependencies)
- [3. How to build](#3-how-to-build)
  - [3.1. CMake Usage](#31-cmake-usage)
  - [3.2. CMake options](#32-cmake-options)
- [4. How to use](#4-how-to-use)
  - [4.1. Usage](#41-usage)
  - [4.2. Library version](#42-library-version)
    - [4.2.1. Compatibility](#421-compatibility)
    - [4.2.2. Compilation time](#422-compilation-time)
    - [4.2.3. Runtime](#423-runtime)
- [5. Documentation](#5-documentation)
- [6. License](#6-license)

# 1. Library details
## 1.1. Features

- _Provide library details here_
- _Provide informations about available and unavailable features (what can be do, what can't)_

## Supported barcodes

- _Provide barcodes types details_

## 1.2. Supported platforms
### 1.2.1. Status

- _Useful if cross-platform to track current implementation status or the supported/planned/rejected backend_

### 1.2.2. Specific behaviours

- _Because sometimes you can't escape some specific platforms/versions quirks_

# 2. Requirements
## 2.1. C++ Standards

This library requires at least **C++ 17** standard

## 2.2. Dependencies

Below, list of required dependencies:

| Dependencies | VCPKG package | Comments |
|:-:|:-:|:-:|
| [Qt][qt-official] | / | Compatible with **Qt6.x**<b>Compatible with **Qt5.15.x** |
| [libqrencode][lib-qrencode-repo] | `libqrencode` | / |

> [!NOTE]
> Dependency manager [VCPKG][vcpkg-tutorial] is not mandatory, this is only a note to be able to list needed packages

# 3. How to build
## 3.1. CMake Usage

This library can be use as an _embedded library_ in a subdirectory of your project (like a _git submodule_ for example) :
1. In the **root** CMakeLists, add instructions :
```cmake
add_subdirectory(qbarcode) # Or if library is put in a folder "dependencies" : add_subdirectory(dependencies/qbarcode)
```

2. In the **application/library** CMakeLists, add instructions :
```cmake
# Link needed libraries
target_link_libraries(${PROJECT_NAME} PRIVATE qbarcode)
```

## 3.2. CMake options

This library provide some **CMake** build options:
- _add here your custom CMake library options, for each, add: the name, the default value, when to use and what consequences_

# 4. How to use
## 4.1. Usage

_An "usage" section example_

Please refer to `myns::MyClass` class documentation for more details.

## 4.2. Library version
### 4.2.1. Compatibility

This library use the [PImpl Idiom][pimpl-doc-cpp] in order to preserve _ABI compatibility_ (_Qt wiki_ also have a [great tutorial on the PImpl idiom][pimpl-doc-qt]).  
So only **major** release (this project use the [semantic versioning][semver-home]) _should_ break the ABI.

### 4.2.2. Compilation time

In order to easily check at compilation time library version (to manage compatibility between multiple versions for example), macro `QBAR_VERSION_ENCODE` (defined inside _library_global.h_ file) can be used:
```cpp
#if QBAR_VERSION >= QBAR_VERSION_ENCODE(2,0,0)
    // Do stuff for version 2.0.0 or higher
#else
    // Do stuff for earlier versions
#endif
```

### 4.2.3. Runtime

Since library header used during final application build could differ from the actual library version, it is recommended to use the method:
```cpp
#include "libraryname/someheader.h"

const QVersionNumber libSemver = qwm::getLibraryVersion();
```

# 5. Documentation

All classes/methods has been documented with [Doxygen][doxygen-official] utility and automatically generated at [online website documentation][repo-doc-web].

> [!NOTE]
> This repository contains two kinds of documentation:
> - **Public API:** Available via [online website documentation][repo-doc-web] or locally via Doxyfile `docs/fragments/Doxyfile-public-api.in`
> - **Internal:** Available locally only via `docs/fragments/Doxyfile-internal.in`

To generate documentation locally, we can use:
```shell
doxygen ./docs/fragments/Doxyfile-name
```
> [!TIP]
> You can also load the _Doxyfile_ into _Doxywizard_ (Doxygen GUI) and run generation.

# 6. License

This library is licensed under [MIT license][repo-license-url].

<!-- Anchor of this page -->
[anchor-platforms]: #12-supported-platforms
[anchor-cmake-opts]: #32-cmake-options

<!-- Links of this repository -->
[repo-home]: https://github.com/legerch/QBarcode
[repo-doc-web]: https://legerch.github.io/QBarcode/
[repo-license]: LICENSE.md
[repo-license-url]: https://github.com/legerch/QBarcode/LICENSE.md

<!-- External links -->
[doxygen-official]: https://www.doxygen.nl/index.html

[gtest-repo]: https://github.com/google/googletest
[lib-qrencode-repo]: https://github.com/fukuchi/libqrencode
[qt-official]: https://www.qt.io/

[vcpkg-tutorial]: https://github.com/legerch/develop-memo/tree/master/Toolchains/Build%20systems/VCPKG

[semver-home]: https://semver.org
[pimpl-doc-cpp]: https://en.cppreference.com/w/cpp/language/pimpl
[pimpl-doc-qt]: https://wiki.qt.io/D-Pointer