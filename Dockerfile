# hallo
FROM  gcc:15.2.0 AS build
WORKDIR /src
COPY ./Main.cpp /src/
RUN g++ Main.cpp -o Hello_World

FROM ubuntu:24.04
COPY --from=build /src/Hello_World /Hello_World
CMD [ "/Hello_World" ]
