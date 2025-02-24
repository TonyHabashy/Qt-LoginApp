# Qt Login Application

## Overview

This is a simple Qt-based login application that validates user credentials. The application features a login window with basic authentication and includes a unit test suite using Google Test.

## Features

- User authentication with predefined credentials.
- UI built with Qt.
- Unit testing using Google Test framework.
- CMake-based build system.
- GitHub Actions for CI/CD.

## Requirements

To build and run this project, you need the following dependencies:

### Development Environment

- **Qt 6** (qt6-base-dev)
- **CMake** (minimum version 3.10)
- **Google Test** (as a Git submodule)
- **A C++ Compiler** (e.g., `g++` or `clang++`)

### Installation on Ubuntu

Run the following commands to install dependencies:

```sh
sudo apt-get update
sudo apt-get install -y qt6-base-dev cmake g++
```

## Building the Application

### Clone the Repository

Clone the repository and initialize submodules:

```sh
git clone --recurse-submodules https://github.com/yourusername/yourrepository.git
cd yourrepository
```

### Build Instructions

1. Create a build directory and navigate to it:
   ```sh
   mkdir build && cd build
   ```
2. Configure the CMake project:
   ```sh
   cmake .. -DCMAKE_PREFIX_PATH=/usr/lib/qt6
   ```
3. Build the project:
   ```sh
   cmake --build .
   ```

## Running the Application

After a successful build, run the application with:

```sh
./LoginApp
```

## Running Tests

The project includes a unit test suite. To execute the tests, run:

```sh
./tests/LoginAppTests
```

## Continuous Integration

The project uses **GitHub Actions** for CI/CD. The workflow file is located at `.github/workflows/cmake.yml` and is triggered on `push` and `pull_request` events to the `main` branch.

### CI Pipeline Steps

1. Checkout repository.
2. Install dependencies (CMake, Qt 6).
3. Configure and build the project.
4. Run tests.

## Git Submodules

This project includes Google Test as a submodule. If not cloned with `--recurse-submodules`, initialize it manually:

```sh
git submodule update --init --recursive
```

## License

This project is licensed under the **MIT License**. See [LICENSE](LICENSE) for details.

## Author

Tony Habashy

