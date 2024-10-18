FROM gcc:latest as build
WORKDIR /docker_build
COPY . .
RUN apt-get update && apt-get install -y cmake
RUN mkdir -p build && cd build && cmake -DCMAKE_BUILD_TYPE=Release .. && cmake --build .
# WORKDIR /docker_build
# COPY --from=build /docker_build/build/lab_2_tests ./
CMD ["./lab_2_tests"]
