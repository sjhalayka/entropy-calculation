<!DOCTYPE html>

<html>
<body>

<form method="post" action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']);?>">
Input string: <input type="text" name="input_string">
<input type="submit" value="Get String Entropy">
</form>

<?php

$str = $_REQUEST['input_string'];
$len = strlen($str);

if($len > 0)
{
	$entropy = 0.0;

	echo "<br>";
	echo "String: \"" . $str . "\"<br>";
	echo "String length: " . $len . "<br><br>";

	for($i=0; $i < $len; $i++)
		$counts[$str[$i]]++;

	foreach($counts as $char => $char_value)
	{
		$probability = $char_value / $len;

		echo "Character: '" . $char . "', Count: " . $char_value . ", Probability: " . $probability;
		echo "<br>";

		$entropy += $probability * log($probability);
	}

	$entropy = -$entropy;

	echo "<br>Entropy: " . $entropy;
	echo "<br>";
}

?>

</body>
</html>