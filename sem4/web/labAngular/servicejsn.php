<?php
// Connect to the database
header('Access-Control-Allow-Origin: *');
header('Access-Control-Allow-Methods: POST, GET, OPTIONS');
header('Access-Control-Allow-Headers: Content-Type');
$servername = "localhost"; // the MySQL server hostname
$username = "root"; // the MySQL username
$password = ""; // the MySQL password
$database = "webdb2"; // the MySQL database name
$port = 3306; // the MySQL database port

$connection = new mysqli($servername, $username, $password, $database);
if($connection->connect_error) {
    die("Connection failed: " . $connection->connect_error);
}
$authorFilter = isset($_GET['author']) ? $_GET['author'] : '';
$titleFilter = isset($_GET['title']) ? $_GET['title'] : '';

  // Build the SQL query with the WHERE clause based on the selected option
$sql = "SELECT * FROM books WHERE book_author LIKE '%$authorFilter%' AND book_title LIKE '%$titleFilter%'";

  // Execute the query and fetch the results
$result = $connection->query($sql);
$data = array();
while($row = $result->fetch_assoc()) {
    $data[] = $row;
}

  // Return the results as a JSON response
header('Content-Type: application/json');
echo json_encode($data);
  


// Close the database connection
$connection->close();

?>
