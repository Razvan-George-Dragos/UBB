<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial scale=1.0">
    <title>Admin page</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha3/dist/css/bootstrap.min.css">
</head>
<body>
    <div class="container my-5">
        <h2>List of books</h2>
        <a class="btn btn-primary" href="addBookUser.php" role="button">New Book</a>
        <br>
        <table class="table">
            <thread>
                <tr>
                    <th>ID</th>
                    <th>Author</th>
                    <th>Title</th>
                    <th>Comment</th>
                    <th>Date</th>
                </tr>
            </thread>
            <tbody>
                <?php
                    $servername = "localhost"; // the MySQL server hostname
                    $username = "root"; // the MySQL username
                    $password = ""; // the MySQL password
                    $database = "webdb2"; // the MySQL database name
                    $port = 3306; // the MySQL database port

                    $connection = new mysqli($servername, $username, $password, $database);
                    if($connection->connect_error) {
                        die("Connection failed: " . $connection->connect_error);
                    }
                    $sql = "SELECT * FROM books";
                    $result = $connection->query($sql);
                    if(!$result){
                        die("Invalid query: " . $connection->connection_error);
                    }
                    while($row = $result->fetch_assoc()){
                        echo"
                        <tr>
                            <td>$row[id]</td>
                            <td>$row[book_author]</td>
                            <td>$row[book_title]</td>
                            <td>$row[book_comment]</td>
                            <td>$row[book_date]</td>
                        </tr>
                        ";
                    }
                ?>
            </tbody>
        </table>
    </div>  
</body>
</html>