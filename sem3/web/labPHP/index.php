<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial scale=1.0">
    <title>Guest book app</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha3/dist/css/bootstrap.min.css">
</head>
<body>
    <button id="hello-button">Click me!</button>
    <script>
        document.getElementById("hello-button").addEventListener("click", function() {
            alert("Choose the role below!");
        });
    </script>
    <br>
    <span>Choose the role:</span>
    <br>
    <a href="admin.php">Admin</a>
    <br>
    <a href="user.php">User</a>
    <br>
</body>
</html>