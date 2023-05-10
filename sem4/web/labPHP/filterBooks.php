<?php
$servername = "localhost"; // the MySQL server hostname
$username = "root"; // the MySQL username
$password = ""; // the MySQL password
$database = "webdb2"; // the MySQL database name
$port = 3306; // the MySQL database port

// Create connection
$conn = new mysqli($servername, $username, $password, $database, $port);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Get the author parameter from the request
$author = $_GET["author"];
$title = $_GET["title"];
// Generate the SQL query with the author filter
$sql = "SELECT * FROM books WHERE book_author LIKE '%$author%' AND book_title LIKE '%$title%'";

// Execute the query
$result = $conn->query($sql);

// Generate the HTML table with the results
if ($result->num_rows > 0) {
    echo "<table class='table'>
            <tbody>";
    // output data of each row
    while($row = $result->fetch_assoc()) {
        echo "<tr>
                <td>" . $row["id"] . "</td>
                <td>" . $row["book_author"] . "</td>
                <td>" . $row["book_title"] . "</td>
                <td>" . $row["book_comment"] . "</td>
                <td>" . $row["book_date"] . "</td>
                <td>
                    <a class='btn btn-primary' href='editBook.php?id=" . $row["id"] . "' role='button'>Edit</a>
                    <a class='btn btn-danger btn-sm' href='deleteBook.php?id=" . $row["id"] . "' role='button'>Delete</a>
                </td>
            </tr>";
    }
    echo "</tbody></table>";
} else {
    echo "No results found";
}

// Close the database connection
$conn->close();
?>

