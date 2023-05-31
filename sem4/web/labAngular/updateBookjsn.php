<?php
header('Access-Control-Allow-Origin: *');
header('Access-Control-Allow-Methods: POST, GET, OPTIONS, PUT');
header('Access-Control-Allow-Headers: Content-Type');
$servername = "localhost";
$username = "root";
$password = "";
$database = "webdb2";
$port = 3306;

$con = new mysqli($servername, $username, $password, $database);


if (!$con){
    die('Could not connect: ' . mysqli_error());
}

try {
    if ($_SERVER["REQUEST_METHOD"] == "PUT") {
        $data = json_decode(file_get_contents("php://input"), true);
        $bookToUpdate = mysqli_real_escape_string($con, $data["book_title"]);
        $author = mysqli_real_escape_string($con, $data["book_author"]);
        $title = mysqli_real_escape_string($con, $data["book_title"]);
        $comment = mysqli_real_escape_string($con, $data["book_comment"]);
        $date = mysqli_real_escape_string($con, $data["book_date"]);

        if ($bookToUpdate) {
            $sql = "UPDATE books SET book_author='$author', book_title='$title', book_comment='$comment', book_date='$date' WHERE (book_title = '$bookToUpdate')";
            $con->query($sql);

            $response = array(
                'message' => 'Row updated successfully.',
                'Book' => $title,
                'Author' => $author,
                'Comment' => $comment,
                'Date' => $date
            );
            echo json_encode($response);
        }

        mysqli_close($con);
    }
} catch (Exception $e) {
    echo 'Caught exception: ', $e->getMessage(), "\n";
}
?>