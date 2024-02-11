FROM ubuntu:latest

# Install necessary dependencies for compiling and running C++ code and for CPPUNIT
RUN apt-get update && apt-get install -y \
    g++ \
    libcppunit-dev \
    && rm -rf /var/lib/apt/lists/*

# Copy calculator implementation and test files into the container
COPY calculator_impl.cpp /app/calculator_impl.cpp
COPY test.cpp /app/test.cpp
COPY main.cpp /app/main.cpp
COPY calculator.h /app/calculator.h

# Set the working directory
WORKDIR /app

# Compile the calculator implementation, main, and test files
RUN g++ -o tests test.cpp calculator_impl.cpp -lcppunit
RUN g++ -o calculator main.cpp calculator_impl.cpp

# Run the test cases by default
CMD ["./tests"]
