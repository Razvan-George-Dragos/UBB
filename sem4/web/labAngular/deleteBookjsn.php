<?php
header('Access-Control-Allow-Origin: *');
header('Access-Control-Allow-Methods: POST, GET, OPTIONS, DELETE');
header('Access-Control-Allow-Headers: Content-Type');
$servername = "localhost"; // the MySQL server hostname
$username = "root"; // the MySQL username
$password = ""; // the MySQL password
$database = "webdb2"; // the MySQL database name
$port = 3306; // the MySQL database port

$connection = new mysqli($servername, $username, $password, $database);
if ($connection->connect_error) {
    die("Connection failed: " . $connection->connect_error);
}
try {
    if ($_SERVER["REQUEST_METHOD"] == "DELETE") {
        $nameToDelete = $_GET["book_title"];
        
        if ($nameToDelete) {
            $sql = "DELETE FROM books WHERE book_title = '$nameToDelete'";
            $result = $connection->query($sql);
            
            if ($result) {
                $response = array(
                    "message" => "Row deleted successfully."
                );
                echo json_encode($response);
            } else {
                $response = array(
                    "error" => "Failed to delete row."
                );
                echo json_encode($response);
            }
        } else {
            $response = array(
                "error" => "book_title parameter is missing."
            );
            echo json_encode($response);
        }

        mysqli_close($connection);
    }
} catch(Exception $e) {
    $response = array(
        "error" => "Caught exception: " . $e->getMessage()
    );
    echo json_encode($response);
}
?>