<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="utf-8">
    <meta name="author" content="Ben Keane and Marco Rubens">
    <title>Connections</title>
    <meta name="description" content="This page is for a game of connections.">
    <link href="style.css" rel="stylesheet" type="text/css" media="screen" />
    <script src="buttons.js"></script>
</head>
<body>
<!--Php code for running c++ main function and reading its output from the file-->
<?php
    shell_exec('g++ -std=c++17 -o mainp main.cpp Categories.cpp');
    shell_exec('./mainp');
    $file = fopen("output.txt", "r") or die("Unable to open file!");
    $connections_items = array();
    while(!feof($file)) {
        $line = fgets($file);
        array_push($connections_items, $line);
    }
    shuffle($connections_items);
    fclose($file);
?>
<header>
    <h1>Connections Game</h1>
</header>
<!--Container for buttons, each one has unique id but same class. Name is gotten from vector.-->
<div id="container">
    <div id="buttons">
        <table>
            <tbody>
            <tr>
                <td><button id="button00" class = "connections-button"><?php echo $connections_items[0] ?></button></td>
                <td><button id="button01" class = "connections-button"><?php echo $connections_items[1] ?></button></td>
                <td><button id="button02" class = "connections-button"><?php echo $connections_items[2] ?></button></td>
                <td><button id="button03" class = "connections-button"><?php echo $connections_items[3] ?></button></td>
            </tr>
            <tr>
                <td><button id="button10" class = "connections-button"><?php echo $connections_items[4] ?></button></td>
                <td><button id="button11" class = "connections-button"><?php echo $connections_items[5] ?></button></td>
                <td><button id="button12" class = "connections-button"><?php echo $connections_items[6] ?></button></td>
                <td><button id="button13" class = "connections-button"><?php echo $connections_items[7] ?></button></td>
            </tr>
            <tr>
                <td><button id="button20" class = "connections-button"><?php echo $connections_items[8] ?></button></td>
                <td><button id="button21" class = "connections-button"><?php echo $connections_items[9] ?></button></td>
                <td><button id="button22" class = "connections-button"><?php echo $connections_items[10] ?></button></td>
                <td><button id="button23" class = "connections-button"><?php echo $connections_items[11] ?></button></td>
            </tr>
            <tr>
                <td><button id="button30" class = "connections-button"><?php echo $connections_items[12] ?></button></td>
                <td><button id="button31" class = "connections-button"><?php echo $connections_items[13] ?></button></td>
                <td><button id="button32" class = "connections-button"><?php echo $connections_items[14] ?></button></td>
                <td><button id="button33" class = "connections-button"><?php echo $connections_items[15] ?></button></td>
            </tr>
            </tbody>
        </table>
    </div>
</div>
<!--Tag to get the network response from Javascript and display it on html-->
<div id="network-response"></div>
</body>
</html>
