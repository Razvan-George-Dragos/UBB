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
        <h2>Filter</h2>
        <form id="filter-form">
            <div class="mb-3">
                <label for="author-input" class="form-label">Author</label>
                <input type="text" class="form-control" id="author-input" name="author">
            </div>
            <div class="mb-3">
                <label for="title-input" class="form-label">Title</label>
                <input type="text" class="form-control" id="title-input" name="title">
            </div>
            <button type="submit" class="btn btn-primary">Filter</button>
            <button type="submit" class="btn btn-primary">button_nou</button>
        </form>
        <br>
        <h2>List of books</h2>
        <br>
        <table class="table">
            <thead>
                <tr>
                    <th>ID</th>
                    <th>Author</th>
                    <th>Title</th>
                    <th>Comment</th>
                    <th>Date</th>
                    <th>Edit/Delete</th>
                </tr>
            </thead>
            <tbody id="book-table-body">
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

                    // Set the current page and the number of results per page
                    $currentPage = isset($_GET['page']) ? $_GET['page'] : 1;
                    $resultsPerPage = 4;

                    // Calculate the starting index of the results on the current page
                    $startIndex = ($currentPage - 1) * $resultsPerPage;

                    // Get the author filter, if any
                    $authorFilter = isset($_GET['author']) ? $_GET['author'] : '';
                    $titleFilter = isset($_GET['title']) ? $_GET['title'] : '';
                    $sql = "SELECT * FROM books WHERE book_author LIKE '%$authorFilter%' AND book_title LIKE '%$titleFilter%' LIMIT $startIndex, $resultsPerPage";


                    // Build the SQL query with pagination and filtering
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
                            <td>
                            <a class='btn btn-primary' href='editBook.php?id=$row[id]' role='button'>Edit</a>
                            <a class='btn btn-danger btn-sm' href='deleteBook.php?id=$row[id]' role='button' onclick='return confirm(\"Are you sure you want to delete this book?\")'>Delete</a>
                            </td>
                        </tr>
                        ";
                    }

                    // Build the pagination links
                    $sql = "SELECT COUNT(*) AS total FROM books WHERE book_author LIKE '%$authorFilter%'";
                    $result = $connection->query($sql);
                    $row = $result->fetch_assoc();
                    $totalResults = $row['total'];
                    $totalPages = ceil($totalResults / $resultsPerPage);
                    $previousPage = $currentPage - 1;
                    $nextPage = $currentPage + 1;
                    
                    echo "<nav aria-label='book-pagination'>";
                    echo "<ul class='pagination justify-content-center'>";
                    if($currentPage > 1){
                        echo "<li class='page-item'><a class='page-link' href='admin.php?page=$previousPage&author=$authorFilter&title=$titleFilter'>Previous</a></li>";
                    }
                    for($i = 1; $i <= $totalPages; $i++){
                        echo "<li class='page-item ";
                        if($i == $currentPage){
                            echo "active";
                        }
                        echo "'><a class='page-link' href='admin.php?page=$i&author=$authorFilter&title=$titleFilter'>$i</a></li>";
                    }
                    if($currentPage < $totalPages){
                        echo "<li class='page-item'><a class='page-link' href='admin.php?page=$nextPage&author=$authorFilter&title=$titleFilter'>Next</a></li>";
                    }
                    echo "</ul>";
                    echo "</nav>";
                    $connection->close();
                ?>
            </tbody>
        </table>
        <a class="btn btn-primary" href="addBook.php" role="button">New book</a>
    </div>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha3/dist/js/bootstrap.min.js"></script>
    <script>
    $('#filter-form').submit(function(event) {
    event.preventDefault();
    var author = $('#author-input').val();
    var title = $('#title-input').val();
    $.ajax({
        url: 'filterBooks.php',
        type: 'get',
        data: { author: author, title: title },
        success: function(response) {
            $('#book-table-body').html(response);
        }
    });
});
    </script>
    </body>
</html>    


    





