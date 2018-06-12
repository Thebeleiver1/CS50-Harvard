


<table>
    <thead>
        <tr class = "head">
            <th>Symbol</th>
            <th>Name</th>
            <th>Shares</th>
            <th>Price</th>
            <th>TOTAL</th>
        </tr>
    </thead>
    <tbody>
    <?php 
        foreach ($positions as $position) {
            $total = number_format($position["price"]*$position["shares"], 2);
            print("<tr>"); 
            print("<td>{$position["symbol"]}</td>"); 
            print("<td>{$position["name"]}</td>"); 
            print("<td>{$position["shares"]}</td>");
            print("<td>$"); 
            print("{$position["price"]}</td>");
            print("<td>$"); 
            print("$total</td>");
            print("</tr>");
            
    }
    ?>
    
    </tbody>
</table>
