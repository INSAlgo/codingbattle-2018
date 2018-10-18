<?php

    function LIS($sequence){
        
        $dico = [
            'a' => 1, 'e' => 2, 'i' => 3, 'o' => 4, 'u' => 5, 'y' => 6,
            'b' => 7, 'c' => 8, 'd' => 9, 'f' => 10, 'g' => 11, 'h' => 12,
            'j' => 13, 'k' => 14, 'l' => 15, 'm' => 16, 'n' => 17, 'p' => 18,
            'q' => 19, 'r' => 20, 's' => 21, 't' => 22, 'v' => 23, 'w' => 24,
            'x' => 25, 'z' => 26
        ];
        
        
        $N = strlen($sequence);
	
    	// "dp[i]" contains the LIS of "sequence[0..i]"
    	$dp = array_fill(0, $N+1, 1);;
    	
    	// length of the LIS found so far
    	$max_length = 0;
    	
    	
    	for($i=0; $i<$N; ++$i){
    		for($j=0; $j<$i; ++$j){
    			if( $dico[$sequence[$j]] < $dico[$sequence[$i]] ){
    				$dp[$i] = max( $dp[$i], $dp[$j]+1 ); 
    			}
    			
    		}
    		
    		$max_length = max( $max_length, $dp[$i] );
    	}
        
        return $max_length;
    }

    $sequence = trim(fgets(STDIN));
    $max_length = strval(26-LIS($sequence));
    echo $max_length . "\n";

?>
