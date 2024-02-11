FROM ubuntu:latest

# Install necessary dependencies for compiling and running C++ code and for CPPUNIT
RUN apt-get update && apt-get install -y \
    g++ \
    libcppunit-dev \
    && rm -rf /var/lib/apt/lists/*

# Copy calculator implementation and test files into the container
COPY calculator_impl.cpp /app/calculator_impl.cpp
COPY test.cpp /app/test.cpp
COPY calculator.h /app/calculator.h

# Set the working directory
WORKDIR /app

# Compile the calculator implementation and test files
RUN g++ -o tests test.cpp calculator_impl.cpp -lcppunit

# Run the test cases
CMD ["./tests"]
