<h1>Web-Implemented Connections Game</h1>
<p>by Marco Rubens and Benjamin Keane</p>

**Program Summary**: Our program is adapted from the New York Times Connections, where you are given a four-by-four grid of words,
and you must find four connections of four different words. This project is currently hosted by the uvm silk server 
which displays an interactive grid of buttons, each with different text indicating the words for each connection. 
The user can then interact with the buttons by selecting them, Once four buttons are selected out program runs a check 
function to see if those words form a connection it then prints below the grid whether the connection is correct of incorrect.

**Programming languages used**: 
* C++ - original connections game framework
* HTML - for static elements of the website
* JavaScript - used to link events to each button so users are able to interact with the buttons
* PHP - used to compile c++ code, write to files, and receive information from javascript
* css - used to style the website

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
