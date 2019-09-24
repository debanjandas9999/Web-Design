<!DOCTYPE HTML>  
<html>
<head>
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
<link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
<style>
.prob 
{
	color: #FF0000;
	
}

.header 
{
  overflow: hidden;
  background-color: black;
  text-align: center;
}

.center 
{
	text-align: center;
}

.tab_bar 
{
	overflow: auto;
    width: 100%;
    background-color: #555;
    
}

.tab_bar a 
{
    
    width: 20%;
	color: white;
    font-size: 36px;
    text-align: center;
    padding: 12px 0;
    transition: all 0.5s ease;
    float: left;
}

.tab_bar a:hover 
{
    background-color: #4CAF50;
}

.colour 
{
    background-color: #4CAF50;
}
.footer_cont
{
padding:0.01em 100px;
}

.padding-64
{
padding-top:200px;
padding-bottom:100px;
}

.black
{
color:#fff;
background-color:#000;
}

.xl
{
font-size:24px!;
}

.medium
{
font-size:14px;
}
</style>
</head>
<body>  

<div class="header">
  <a href="#default" class="logo"></a><img src="fitness_logo.jpg"> 
  </div>
  
  <div class="tab_bar">
  <a href="http://csserver.ucd.ie/~17202833/Fitness.html"><i class="fa fa-home"></i></a> 
  <a class="colour" href="http://csserver.ucd.ie/~17202833/Contactus.html"><i class="fa fa-envelope"></i></a> 
  <a href="http://csserver.ucd.ie/~17202833/News.html"><i class="fa fa-globe"></i></a>
  <a href ="http://csserver.ucd.ie/~17202833/about.html"><i class="fa fa-info-circle" style="font-size:36px"></i></a>
  <a href  ="http://csserver.ucd.ie/~17202833/careers.html"><i class="fa fa-suitcase" style="font-size:36px"></i></a>
</div>

<?php
// define variables and set to empty values
$error_name = $error_email = $error_gender = $error_website = "";
$name = $email = $gender = $comment = $website = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {

    $name = examine($_POST["name"]);
    
    $email = examine($_POST["email"]);
    
    $comment = examine($_POST["comment"]);
  }

  function examine($data) 
{
  $data = trim($data);
  $data = stripslashes($data);
  $data = htmlspecialchars($data);
  return $data;
}
?>

<?php

echo "<h2>Information you entered:</h2>";
echo $name;
echo "<br>";
echo $email;
echo "<br>";

echo $comment;
echo "<br>";

?>
<br>
<br>
<br>
<br> 
<p><font size = "4"><center> Thank you so much for contacting us! We will get back to you within 3-4 working days.</center></font> </p>
<p><font size = "4"><center>In the mean time, feel free to explore our website.</center></font> </p>
<br>
<br>
<p><font size = "3"><center> Thank You,</center></font> </p>
<p><font size = "3"><center> Fitness Freaks.</center></font> </p>
<br>
<br>
<br>
<br>
<br>
<br>
<footer class="footer_cont padding-64 black xl">
  <a href="#"><i class="fa fa-facebook-official" style="font-size:36px"></i></a>
  <a href="#"><i class="fa fa-pinterest-p" style="font-size:36px"></i></a>
  <a href="#"><i class="fa fa-twitter" style="font-size:36px"></i></a>
  
  <a href="#"><i class="fa fa-linkedin" style="font-size:36px"></i></a>
  <font size = "4">Copyright 2017 Fitness Freaks. All rights reserved.</font>
</footer>

</body>
</html>