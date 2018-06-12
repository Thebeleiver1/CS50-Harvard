<?php
// configuration
require("../includes/config.php");
// if form was submitted
if($_SERVER["REQUEST_METHOD"] == "POST")
{	
	// Check if the userinputted anything
	if(empty($_POST["stock"]))
	{
		apologize("Type which Stock you want to sell");
	}else{
		$id = $_SESSION["id"];
		$stock = strtoupper($_POST["stock"]);
	// If the user doesn't own any of the stock, error message is displayed
        	if(!$shares = cs50::query("SELECT shares FROM portfolio WHERE id = $id AND symbol = '$stock'")){
        		apologize("You don't own any shares of this stock");
        	}
        	else{
        	 	$value = lookup("$stock");
        	 	$shares = $shares[0]["shares"];
        	 	$price = $value["price"];
        	 	$profit = $shares*$price;
        	 	
        	 	// Delete the stock from the users portfolio and update the balance
        	 	cs50::query("DELETE FROM portfolio WHERE id = $id AND symbol = '$stock'");
        	 	cs50::query("UPDATE users SET cash = cash + $profit WHERE id = $id");
        	 	cs50::query("INSERT INTO history (id, symbol, status, shares, price) 
        	 	VALUES($id, '$stock', 'SELL', $shares, $price)");
        	 	render("sell1.php", ["title" => "Sell", "value" => $value , "profit" => $profit]);
        	 }
	}
}
else
{
  // else render form
  render("sell_form.php", ["title" => "Sell"]);
}
?>