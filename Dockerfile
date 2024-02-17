# Build stage
FROM ubuntu:latest AS builder

# Install necessary dependencies for compiling and running C++ code and for CPPUNIT
RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    libcppunit-dev \
    && rm -rf /var/lib/apt/lists/*

# Copy only the necessary source files into the container
COPY CMakeLists.txt /app/CMakeLists.txt
COPY calculator_impl.cpp /app/calculator_impl.cpp
COPY test.cpp /app/test.cpp
COPY main.cpp /app/main.cpp
COPY calculator.h /app/calculator.h

# Set the working directory
WORKDIR /app

# Build the C++ code using CMake
RUN mkdir build && cd build && cmake .. && make

# Run tests during the build process
RUN ./build/calculator_test

# Final stage
FROM ubuntu:latest

# Install necessary dependencies for running the executables
RUN apt-get update && apt-get install -y \
    libcppunit-dev \
    && rm -rf /var/lib/apt/lists/*

# Copy only the built executables from the builder stage
COPY --from=builder /app/build/calculator_main /app/calculator_main
COPY --from=builder /app/build/calculator_test /app/calculator_test

# Set execute permission for the calculator_test and calculator_main executables
RUN chmod a+x /app/calculator_test /app/calculator_main

# Set the working directory
WORKDIR /app

# Start the container with the specified command
CMD ["./calculator_test"]
