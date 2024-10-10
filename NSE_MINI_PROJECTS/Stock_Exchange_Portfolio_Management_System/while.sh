#!/bin/bash

# Infinite loop
while true
do
    # Clear the screen
    clear

    # Execute web_search and a.out
    ./web_search
    ./nifty50

    # Wait for 5 seconds before the next iteration (optional)
    sleep 10
done
