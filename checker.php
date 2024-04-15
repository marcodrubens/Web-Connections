<?php
      $guess = $_POST['arrayString'] ?? '';
      if (!empty($guess)) {
          file_put_contents("check.txt", "");
          $file = fopen("check.txt", "a") or die("Unable to open file!");
          fwrite($file, $guess);
          fclose($file);

          shell_exec('g++ -std=c++17 -o check checker.cpp');
          $result = shell_exec('./check');
          echo $result;
      } else {
          echo 'error';
      }
  ?>