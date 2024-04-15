**Names:** 
Ben Keane & Marco Rubens

**Necessary Installations:**
N/A

**Program Summary:**
Our program is adapted from the New York Times Connections, where you are given a four-by-four grid of words, and you must 
find four connections of four different words. This module we created a website hosted by the uvm silk server which displays 
an interactive grid of buttons, each with different text indicating the words for each connection. The user can then interact 
with the buttons by selecting them, Once four buttons are selected out program runs a check function to see if those words form a connection
it then prints below the grid whether the connection is correct of incorrect.

**Languages:**
C++, HTML, JavaScript, PHP, css 

**Why Each Language Was Used:**
C++ was used for the original connections game
HTML was used to create the static elements of the website
JavaScript was used to link events to each button so users are able to interact with the buttons 
PHP was used to compile c++ code, write to files, and receive information from javascript.
css was used to style our website, by adding color to the buttons and background, as well as editing the size and font of the text and buttons

**How The Languages Are Connected:**
JavaScript is connected to the buttons that we're created in HTML.
JavaScript also sends information to PHP which compiles and calls C++, and C++ sends information back to PHP via file handling, then back to JavaScript, then finally back to HTML where it is displayed on the website.


**Known Bugs:**
No currently known bugs

**Future work:**
Since we only implemented the default connections game, we could add implementation to work with custom connections games. We could add a new menu when you go onto the website that would prompt the user, with options to either
play the "daily" connections game, play a custom connections game, or create a custom connections game. We could also change the color of the buttons that you've already gotten correct and display the category, so that 
it's easier for the user to see what they've already gotten correct and what the specific category was. Another addition would be adding a life mechanic, that would track how many more guesses you have until you lose.

**Citations:**

| Concept               | How it was used                                                                       | Source                                                                                     |
|-----------------------|---------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------|
| XMLHttpRequest        | Send arrays from buttons.js to checker.php (lines 29-31 in buttons.js)                | https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest                            |
| Splice                | Remove items from an array in javascript                                              | https://www.w3schools.com/jsref/jsref_splice.asp                                           |
| addEventListener      | Attach events to elements in javascript, primarily buttons (lines 1, 10 buttons.js)   | https://www.w3schools.com/jsref/met_element_addeventlistener.asp                           |
| DOMContentLoaded      | Check if the HTML completely loaded (line 1 buttons.js)                               | https://developer.mozilla.org/en-US/docs/Web/API/Document/DOMContentLoaded_event           |
| Array.prototype.map() | To get the text content of each button in an array (line 23 buttons.js)               | https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/map |
| file_put_contents     | Write data to check.txt from checker.php (line 2 checker.php)                         | https://www.php.net/manual/en/function.file-put-contents.php                               |
| feof                  | Checks if we're at the end of output.txt in connections.php (line 17 connections.php) | https://www.php.net/manual/en/function.feof.php                                            |
| querySelectorAll      | Get a list of buttons with the element 'connections-button' (line 5 buttons.js)       | https://developer.mozilla.org/en-US/docs/Web/API/Document/querySelectorAll                 |


**Grade:**
Main Program: 40 Points, We use plenty of different languages to create our interactive website.
Use of Multiple Languages: 20 Points, We used 5 different languages in conjunction to allow our website to work properly.
Choice of Languages: 20 Points, each language that we chose was used for what it is primarily good at. HTML and PHP for creating a website, JavaScript to allow for interaction, css for styling, and C++ for core game functionality.
Command line argument(s) (or file I/O for larger data) between languages: 20 Points, we used plenty of command line arguments to compile and run out C++ code, as well as file I/O for communication between other languages.
Style & Documentation: 0 Points, Comments and documentation used throughout code, code is well organized.
Video: 0 Points, video demonstrates core website functionality.
Lifespan: 0 Points, repository created over 7 days ago, large commits within the last 3 days.
TOTAL: 100