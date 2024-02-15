# Build stage
FROM ubuntu:latest AS builder

# Install necessary dependencies for compiling and running C++ code and for CPPUNIT
RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    libcppunit-dev \
    && rm -rf /var/lib/apt/lists/*

# Copy CMakeLists.txt and source files into the container
COPY CMakeLists.txt /app/CMakeLists.txt
COPY calculator_impl.cpp /app/calculator_impl.cpp
COPY test.cpp /app/test.cpp
COPY main.cpp /app/main.cpp
COPY calculator.h /app/calculator.h

# Set the working directory
WORKDIR /app

# Build the C++ code using CMake
RUN cmake . && make

# Final stage
FROM ubuntu:latest

# Install necessary dependencies for running the executables
RUN apt-get update && apt-get install -y \
    libcppunit-dev \
    && rm -rf /var/lib/apt/lists/*

# Copy only the built executables from the builder stage
COPY --from=builder /app/test /app/test
COPY --from=builder /app/calculator /app/calculator

# Set the working directory
WORKDIR /app

# Run the test cases by default
CMD ["./test"]
