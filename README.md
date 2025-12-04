# Team B Platform Control Board

A sample embedded firmware repository demonstrating platform connectivity capabilities for STM32MP1xx-based control boards with dual-core architecture (Cortex-A7 and Cortex-M4).

## Project Description

This project showcases a modern embedded systems platform with the following features:

- **Dual-Core Architecture**: Support for both ARM Cortex-A7 (application processor) and Cortex-M4 (real-time processor) cores on STM32MP1xx SoC
- **MQTT Connectivity**: Platform integration with MQTT protocol for IoT communication
- **FreeRTOS Integration**: Real-time operating system support for the Cortex-M4 core
- **Comprehensive Testing**: Unit testing with CppUTest, memory leak detection with Valgrind
- **Quality Assurance**: Static analysis with Cppcheck, code style checking with Cpplint, and code metrics with Metrix++
- **CI/CD Pipeline**: Automated build, test, and quality checks using GitHub Actions
- **Docker-based Development**: Containerized build environment for consistent development experience

### Key Components

- **Board Support Package (BSP)**: Startup code, linker scripts, and system initialization for STM32MP15
- **Application Layer**: MQTT-based connectivity application running on Cortex-A7
- **RTOS Layer**: FreeRTOS configuration for real-time tasks on Cortex-M4
- **Platform Commons**: Shared libraries and utilities (included as git submodule)
- **Third-party Libraries**: FreeRTOS kernel and CMSIS support

## Getting Started

### Prerequisites

To build and develop this project, you need one of the following:

**Option 1: Docker (Recommended)**
- Docker Engine 20.10 or later
- Git with submodule support

**Option 2: Native Development**
- CMake 3.13 or later
- Ninja build system
- ARM GCC toolchain (`gcc-arm-none-eabi` and `gcc-arm-linux-gnueabihf`)
- Python 3.x with pip
- Cppcheck, Cpplint, Metrix++
- CppUTest framework
- Valgrind (for memory leak detection)
- lcov/gcovr (for code coverage)

### Setup

1. **Clone the repository with submodules:**

   ```bash
   git clone --recursive https://github.com/HennyPenny-Ned/teamb-platform-connectivity.git
   cd teamb-platform-connectivity
   ```

   If you already cloned without `--recursive`, initialize submodules:

   ```bash
   git submodule update --init --recursive
   ```

2. **Build the Docker image:**

   ```bash
   docker build -t platform-builder .
   ```

   This creates a containerized development environment with all necessary tools.

### Building the Firmware

**Using Docker (Recommended):**

```bash
docker run --rm -v $PWD:/workspace platform-builder bash -c "scripts/build/run_build.sh"
```

Build artifacts (ELF, BIN, HEX, MAP files) will be available in the `build/images/` directory.

**Native Build:**

```bash
./scripts/build/run_build.sh
```

### Running Tests

**Unit Tests:**

```bash
docker run --rm -v $PWD:/workspace platform-builder bash -c "scripts/build/run_test.sh"
```

**Memory Leak Detection:**

```bash
docker run --rm -v $PWD:/workspace platform-builder bash -c "cd tests/mqtt/build && valgrind --leak-check=full ./mqtt_tests"
```

### Code Quality Checks

**Static Analysis (Cppcheck):**

```bash
docker run --rm -v $PWD:/workspace platform-builder bash -c "scripts/build/run_cppcheck.sh"
```

**Code Style (Cpplint):**

```bash
docker run --rm -v $PWD:/workspace platform-builder bash -c "scripts/build/run_cpplint.sh"
```

**Code Metrics (Metrix++):**

```bash
docker run --rm -v $PWD:/workspace platform-builder bash -c "scripts/build/run_metrix++.sh"
```

## Usage

### Project Structure

```
teamb-platform-connectivity/
├── board/              # BSP: startup code, linker scripts, system files
├── docs/               # Documentation and diagrams
├── project/            # Application entry points (main.c for each core)
│   └── stm32mp1xx/     # STM32MP1xx-specific projects
│       ├── ca7/        # Cortex-A7 application
│       └── cm4/        # Cortex-M4 real-time application
├── source/             # Source code
│   ├── app/            # Application layer (MQTT, connectivity)
│   └── cfg/            # Configuration files (FreeRTOS config)
├── scripts/            # Build and utility scripts
│   └── build/          # Build automation scripts
├── tests/              # Unit tests
│   └── mqtt/           # MQTT component tests
├── vendors/            # Third-party dependencies (submodules)
│   ├── platform-commons/   # Platform shared libraries
│   └── third-party/        # External libraries (FreeRTOS, CMSIS)
├── CMakeLists.txt      # Main CMake build configuration
├── CMakePresets.json   # CMake presets for different targets
└── Dockerfile          # Development environment container
```

### Target Cores

The project supports two build targets:

- **Cortex-A7 (ca7)**: Application processor running Linux-based applications with MQTT connectivity
- **Cortex-M4 (cm4)**: Real-time coprocessor running FreeRTOS for time-critical tasks

Configure the target core using the `TARGET_CORE` CMake variable.

### Continuous Integration

The project includes a comprehensive CI pipeline (`.github/workflows/connectivity-ci.yml`) that automatically:

1. Builds firmware for all target cores
2. Runs unit tests with coverage reporting
3. Performs memory leak detection with Valgrind
4. Runs static analysis (Cppcheck)
5. Checks code style (Cpplint)
6. Generates code metrics (Metrix++)
7. Archives build artifacts

The CI pipeline triggers on:
- Push to `main`, `develop`, `feature/**`, and `custom/**` branches
- Pull requests to `main`, `develop`, and `feature/**` branches
- Manual workflow dispatch

## Contributing

We welcome contributions to improve the platform! Please follow these guidelines:

### Development Workflow

1. **Fork the repository** and create a new branch from `develop`:
   ```bash
   git checkout -b feature/your-feature-name develop
   ```

2. **Make your changes** following the project coding standards:
   - Follow the existing code style
   - Ensure Cpplint checks pass
   - Maintain or improve test coverage
   - Add unit tests for new functionality

3. **Test your changes**:
   ```bash
   # Run all tests
   ./scripts/build/run_test.sh
   
   # Run code quality checks
   ./scripts/build/run_cppcheck.sh
   ./scripts/build/run_cpplint.sh
   ```

4. **Commit your changes** with descriptive commit messages:
   ```bash
   git commit -m "feat: add new MQTT handler for sensor data"
   ```

5. **Push to your fork** and create a Pull Request:
   ```bash
   git push origin feature/your-feature-name
   ```

### Code Standards

- **C Standard**: C11 (as defined in CMakeLists.txt)
- **Code Style**: Follow Cpplint guidelines
- **Static Analysis**: Code must pass Cppcheck without errors
- **Testing**: Maintain minimum code coverage levels
- **Memory Safety**: No memory leaks (verified by Valgrind)

### Pull Request Process

1. Ensure all CI checks pass
2. Update documentation if needed
3. Request review from maintainers
4. Address review feedback
5. Squash commits if requested

## License

This project is provided as a sample repository for demonstration purposes.

**License**: To be determined (TBD)

Please contact the project maintainers for licensing information if you wish to use this code in production environments.

## Authors

**Team B Platform Development Team**

### Maintainers
- TBD

### Contributors
- See [GitHub Contributors](https://github.com/HennyPenny-Ned/teamb-platform-connectivity/graphs/contributors) for a full list

---

## Additional Resources

- **Documentation**: See the `docs/` directory for architecture diagrams and detailed documentation
- **Issue Tracker**: [GitHub Issues](https://github.com/HennyPenny-Ned/teamb-platform-connectivity/issues)
- **CI/CD Status**: Check the [Actions tab](https://github.com/HennyPenny-Ned/teamb-platform-connectivity/actions) for build status

## Support

For questions, issues, or contributions, please:
1. Check existing [GitHub Issues](https://github.com/HennyPenny-Ned/teamb-platform-connectivity/issues)
2. Create a new issue with detailed information
3. Contact the maintainers

---

**Note**: This is a sample repository created to demonstrate platform connectivity capabilities. It serves as a reference implementation for embedded IoT projects using STM32MP1xx dual-core architecture.
