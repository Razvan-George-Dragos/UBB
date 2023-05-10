<?php
if (isset($_GET["id"])) {
    $id = $_GET["id"];
    $servername = "localhost"; // the MySQL server hostname
    $username = "root"; // the MySQL username
    $password = ""; // the MySQL password
    $database = "webdb2"; // the MySQL database name
    $port = 3306; // the MySQL database port

    $connection = new mysqli($servername, $username, $password, $database);
    if ($connection->connect_error) {
        die("Connection failed: " . $connection->connect_error);
    }
    $sql = "DELETE FROM books WHERE id=$id";
    if ($connection->query($sql) === TRUE) {
        echo "Record deleted successfully";
    } else {
        echo "Error deleting record: " . $connection->error;
    }
}
header("location: admin.php");
exit;
?>


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial scale=1.0">
    <title>Delete Book</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha3/dist/css/bootstrap.min.css">
</head>
<body>
    <div class="container my-5">
        <h2>Delete Book</h2>
        <p>Are you sure you want to delete the following book?</p>
        <p><strong>Author:</strong> <?php echo $book['book_author']; ?></p>
        <p><strong>Title:</strong> <?php echo $book['book_title']; ?></p>
        <form method="POST">
            <input type="hidden" name="confirm_delete" value="1">
            <button type="submit" class="btn btn-danger">Delete</button>
            <a class='btn btn-secondary' href='admin.php' role='button'>Cancel</a>
        </form>
    </div>
</body>
</html>
