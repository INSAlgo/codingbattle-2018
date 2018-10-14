<?php
$N = trim(fgets(STDIN));

if ($N < 42)
	echo "More\n";
else if ($N > 42)
	echo "Less\n";
else
	echo "Bingo!\n";
