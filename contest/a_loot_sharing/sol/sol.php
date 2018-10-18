<?php


$line = trim(fgets(STDIN));
$b = intval($line);
$line = trim(fgets(STDIN));
$t = intval($line);
$line = trim(fgets(STDIN));
$n = intval($line);



if(2*$b+3*$t <= $n){
    echo "LOOT!" . "\n";
}else{
    echo "RHUM!" . "\n";
}

