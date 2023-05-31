<?php
header('Access-Control-Allow-Origin: *');
header('Access-Control-Allow-Methods: POST, GET, OPTIONS');
header('Access-Control-Allow-Headers: Content-Type');
header('Content-Type: application/json');

$servername = "localhost";
$username = "root";
$password = "";
$database = "webdb2";
$port = 3306;

$con = new mysqli($servername, $username, $password, $database);

if (!$con) {
    die('Could not connect: ' . mysqli_error());
}

try {
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $data = json_decode(file_get_contents("php://input"), true);

        $author = $data["book_author"];
        $title = $data["book_title"];
        $comment = $data["book_comment"];
        $date = $data["book_date"];

        $stmt = $con->prepare("INSERT INTO books (book_author, book_title, book_comment, book_date) VALUES (?, ?, ?, ?)");
        $stmt->bind_param("ssss", $author, $title, $comment, $date);

        if ($stmt->execute()) {
            $response = [
                'success' => true,
                'message' => 'The book ' . htmlspecialchars($title) . ' has been added.',
                'book' => [
                    'author' => htmlspecialchars($author),
                    'title' => htmlspecialchars($title),
                    'comment' => htmlspecialchars($comment),
                    'date' => htmlspecialchars($date)
                ]
            ];

            echo json_encode($response);
        } else {
            $response = [
                'success' => false,
                'message' => 'Failed to add the book.'
            ];

            echo json_encode($response);
        }

        $stmt->close();
        mysqli_close($con);
    }
} catch (Exception $e) {
    $response = [
        'success' => false,
        'message' => 'Caught exception: ' . $e->getMessage()
    ];

    echo json_encode($response);
}
?>
