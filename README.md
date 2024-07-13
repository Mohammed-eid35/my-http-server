# HTTP Server

A multi-threaded HTTP server implemented in C++ with middleware support.

## Table of Contents

- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Endpoints](#endpoints)
- [Testing](#testing)
- [Contributing](#contributing)

## Features

- Multi-threaded request handling
- Middleware support
- Static file serving
- JSON handling
- Route handling

## Requirements

- CMake
- Build-essential tools

## Installation

### 1. Install Required Packages

```bash
sudo apt update
sudo apt install -y build-essential cmake
```

### 2. Clone the Repository

```bash
git clone https://github.com/yourusername/http_server.git
cd http_server
```

### 3. Build the Project

```bash
mkdir build
cd build
cmake ..
make
```

## Usage

### Run the Server

```bash
./http_server
```

### Access the Server

Open your browser and navigate to http://localhost:8080/


### Endpoints

`GET /` : Serves the index.html file.

`POST /echo` : Echoes the request body.

`POST /json` : Responds with a JSON message.

## Testing

### Access the Root Route

Open a web browser and go to http://localhost:8080/.

### Echo Route

```bash
curl -X POST -d "Hello Server" http://localhost:8080/echo
```

### JSON Route
```bash
curl -X POST -d '{"key": "value"}' http://localhost:8080/json
```

## Contributing
Contributions are welcome! Please open an issue or submit a pull request for any changes.
