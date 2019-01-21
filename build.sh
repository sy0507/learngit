#!/usr/bin/env bash
mvn clean package -Dmaven.test.skip=true
cp target/app.jar docker/java/app.jar
docker-compose build