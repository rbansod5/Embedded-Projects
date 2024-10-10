#!/bin/bash

# Infinite loop
while true
do
    # Run web_search and a.out and capture their output
    web_search_output=$(./web_search)
    a_out_output=$(./a.out)

    # Combine the outputs and add color using HTML formatting
    combined_output="<span foreground='blue'>Web Search Output:</span>\n\n<tt>$web_search_output</tt>\n\n"
    combined_output+="<span foreground='green'>Program Output (a.out):</span>\n\n<tt>$a_out_output</tt>"

    # Display the output with options to Refresh or Exit
    zenity --question --title="Program Output" \
    --text="$combined_output" \
    --ok-label="Refresh" --cancel-label="Exit" --width=500 --height=400 \
    --no-wrap --html

    # Check if the user clicked "Exit"
    if [[ $? -ne 0 ]]; then
        break
    fi

    # Wait for 1 second before refreshing (optional)
    sleep 1
done
