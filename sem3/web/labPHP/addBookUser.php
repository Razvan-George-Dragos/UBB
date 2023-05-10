<?php
$servername = "localhost"; // the MySQL server hostname
$username = "root"; // the MySQL username
$password = ""; // the MySQL password
$database = "webdb2"; // the MySQL database name
$port = 3306; // the MySQL database port

$connection = new mysqli($servername, $username, $password, $database);

$author = "";
$title = "";
$comment = "";
$date = "";

$errorMessage = "";
$succesMessage = "";
if($_SERVER['REQUEST_METHOD'] == 'POST'){
    $author = $_POST["book_author"];
    $title = $_POST["book_title"];
    $comment = $_POST["book_comment"];
    $date = $_POST["book_date"];

    do{
        if( empty($author) || empty($title) || empty($comment) || empty($date)){
            $errorMessage = "All the fields are required";
            break;
        }

        //add to database
        $sql = "INSERT INTO books (book_author, book_title, book_comment, book_date)" .
                "VALUES ('$author', '$title', '$comment', '$date')";
        $result = $connection->query($sql);
        if(!$result){
            $errorMessage = "Invalid query: " . $connection->error;
            break;
        }
        $author = "";
        $title = "";
        $comment = "";
        $date = "";
        $succesMessage = "Book added successfully";

        header("location: user.php");
        exit;

    }while(false);
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Guest book app</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha3/dist/css/bootstrap.min.css">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha3/dist/js/bootstrap.bundle.min.js"></script>
</head>
<body>
    <div class="container my-5">
        <h2>New Book</h2>
        <?php
            if(!empty($errorMessage)){
                echo "
                <div class='alert alert-warning alert-dismissible fade show' role='alert'>
                    <strong>$errorMessage</strong>
                    <button type='button' class='btn-close' data-bs-dismiss='alert' aria-label='Close'></button>
                </div>
                ";
            }
        ?>
        <form method="post">
            <div class="row mb-3">
                <label class="col-sm-3 col-form-label">Author</label>
                <div class="col-sm-6">
                    <input type="text" class="form-control" name="book_author" value="<?php echo $author; ?>">
                </div>
            </div>
            <div class="row mb-3">
                <label class="col-sm-3 col-form-label">Title</label>
                <div class="col-sm-6">
                    <input type="text" class="form-control" name="book_title" value="<?php echo $title; ?>">
                </div>
            </div>
            <div class="row mb-3">
                <label class="col-sm-3 col-form-label">Comment</label>
                <div class="col-sm-6">
                    <input type="text" class="form-control" name="book_comment" value="<?php echo $comment; ?>">
                </div>
            </div>
            <div class="row mb-3">
                <label class="col-sm-3 col-form-label">Date</label>
                <div class="col-sm-6">
                    <input type="text" class="form-control" name="book_date" value="<?php echo $date; ?>">
                </div>
            </div>
            <?php
            if(!empty($succesMessage)){
                echo"
                <div class='row mb-3'>
                    <div class='offset-sm-3 col-sm-6'>
                        <div class='alert alert-success alert-dismissible fade show' role='alert'>
                            <strong>$succesMessage</strong>
                            <button type='button' class='btn-close' data-bs-dismiss='alert' aria-label='Close'></button>
                        </div>
                    </div>
                </div>
                ";
            }
            ?>
            <div class="row mb-3">
                <div class="offset-sm-3 col-sm-3 d-grid">
                    <button type="submit" class="btn btn-primary">Submit</button>
                </div>
                <div class="col-sm-3 d-grid">
                    <a class="btn btn-outline-primary" href="admin.php" role="button">Cancel</a>
                </div>
            </div>
        </form>
    </div>
</body>
</html>