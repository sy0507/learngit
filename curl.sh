#!/usr/bin/env bash
root_url="http://localhost"

echo "等待容器启动完成。。。"
while ! curl "${root_url}"; do sleep 3; done
echo ""

echo ----------------------------------Reuqest 1--------------------------------------
curl -d "name=MARY&password=SMITH" "${root_url}/customers/login"
echo ""
echo ----------------------------------Reuqest 2--------------------------------------
curl "${root_url}/films?page=0&pageSize=5"
echo ""

echo ----------------------------------Reuqest 3--------------------------------------
customer_id=`curl -X PUT -d "firstName=DEBRA&lastName=NELSON&email=DEBRA.NELSON@sakilacustomer.org&address=306 Antofagasta Place" "${root_url}/customers"`
echo ""
echo "new create customer id =====> ${customer_id}"
echo ""

echo ----------------------------------Reuqest 4--------------------------------------
curl -X POST -d "firstName=JORDAN&lastName=ARCHULETA&email=JORDAN.ARCHULETA@sakilacustomer.org&address=1229 Varanasi (Benares) Manor" "${root_url}/customers/${customer_id}"
echo ""

echo ----------------------------------Reuqest 5--------------------------------------
curl -X DELETE --cookie "customerId=${customer_id}" "${root_url}/customers"
echo ""