<?php
// configuration
require("../includes/config.php");
// if form was submitted 
if($_SERVER["REQUEST_METHOD"] == "POST")
{
	 if(empty($_POST["stock"]) || empty($_POST["shares"]) || !preg_match("/^\d+$/", $_POST["shares"]) ||
	  								($_POST["shares"] < 0 ))
	 {
	 	if(empty($_POST["stock"]))
	 	{
	 		apologize("You need to specify a stock to buy");
	 	}
	 	else if(empty($_POST["shares"]) || !preg_match("/^\d+$/", $_POST["shares"]) || 
	 								($_POST["shares"] < 0 ))
	 	{
	 		apologize("You need to specify whole amounts of shares.");
	 	}
	 }else
	 {
	 	$symbol = strtoupper($_POST["stock"]);
	 		 	
	 	// If the cost is more then the balanc of the user, an error message is displayed
 		if($stock = lookup($symbol) === false)
 		{
 			apologize("This stock doesn't exist.");
 		}else
 		{
 			$stock = lookup($symbol);
 			$id = $_SESSION["id"];
	 		$shares = $_POST["shares"];
	 		$price = $stock["price"];
	 		$cash = cs50::query("SELECT cash FROM users WHERE id = $id");
	 		//$check = cs50::query("SELECT symbol FROM portfolio WHERE id = $id");
	 		$cost = $price*$_POST["shares"];
	 		//echo $check[0]["symbol"];
	 		
 			if($cost > $cash[0]["cash"])
		 	{
		 		apologize("You don't have enough money to buy ". $shares . " shares from " . $stock["name"] . ".");
		 	}else
		 	{
		 		//
		 		cs50::query("INSERT INTO portfolio (id, symbol, shares) VALUES($id, '$symbol', $shares) 
		 		 ON DUPLICATE KEY UPDATE shares = shares + $shares");
		 		cs50::query("UPDATE users SET cash = cash - $cost WHERE id = $id");
		 		cs50::query("INSERT INTO history (id, symbol, status, shares, price) VALUES($id, '$symbol', 'BUY', $shares, $price)");
		 		render("buy_disp.php", ["title" => "Buy", "stock" => $stock, "cost" => $cost, "shares" => $shares]);
		 		
						
		 	}
	 	}
	 }
} 
else
{
  // else render form
  render("buy_form.php", ["title" => "Buy"]);
}
?>