<?php

$best_offer = 0;
$seller = "";

$line = trim(fgets(STDIN));
$parts = explode(" ", $line);
$g = intval($parts[0]);
$n = intval($parts[1]);

// Go through all trainers in the given order
for($i = 0; $i < $n; $i++){
    $line = trim(fgets(STDIN));
    $parts = explode(" ", $line);
    $name = $parts[0];
    $p = intval($parts[1]);
    $c = intval($parts[2]);
    
    // Compute how many parrots we can buy from this trainer
    $nb_parrots = floor(($g - $c) / $p);

    // Check if it's better than the best encountered yet
    if( $nb_parrots > $best_offer ){
        $best_offer = $nb_parrots;
        $seller = $name;
    }
}

if($best_offer>0){
    echo $best_offer . "\n";
    echo $seller . "\n";
}else{
    echo "Impossible" . "\n";
}
