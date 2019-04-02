# WebServerPlus
Example of implementation of a WebServer in C++ using cpprestsdk

## Endpoints
 - /get (GET) Get all the colors store in the server (10x10 array, each color is in the format RRRGGGBBB)
 - /update (POST) Set a new color (body argument must be [x position];[y position];[pixel color]

## Dependencies
 - [cpprestsdk](https://github.com/Microsoft/cpprestsdk)
