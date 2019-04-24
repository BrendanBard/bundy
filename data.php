<html>
<head>
<title>fSociety</title>
<link rel="icon" type="image/png" href="img/icon.png" />
<html>
<head>
<title>fSociety</title>
<link rel="icon" type="image/png" href="img/icon.png" />
</head>
<style>
body {
		background-color:#191919;
		height: 100%;
		font-family: calibri;
}
.topnav {
  background-color: #333;
  overflow: hidden;
}
/* Style the links inside the navigation bar */
.topnav a {
  float: left;
  color: #f2f2f2;
  text-align: center;
  padding: 14px 16px;
  text-decoration: none;
  font-size: 17px;
}

/* Change the color of links on hover */
.topnav a:hover {
  background-color: #ddd;
  color: black;
}

/* Add a color to the active/current link */
.topnav a.active {
  background-color: #B9081C;
  color: white;
}
</style>
<header><br><br><br><br></header>
<body>
 <div class="topnav">
	<a href="main.php">Home</a>
	<a class="active" href="#">Data</a>
</div> 
<style>
    iframe {
padding: 10px;
background-color: white;
border: 2px red solid;
position:relative; 
top: 50px; 
left: 0px;
    } 
	.btnSubmit {
	padding: 10px 20px;
    background: #B9081C;
    border: #F13D24 1px solid;
    color: #FFF;
}
</style> 
<div style="padding-top: 25px">
<center>
<form name="frmUser" method="GET" action="convert.php">
<input type="submit" name="submit" value="Update" class="btnSubmit">
</form>
</center>
</div>
<div>
<center>
<iframe 
	src="data.txt" 
	width=500 
	height="500">
</iframe>
</center>
</div>
<br><br>
</p>
</body>
</html>
	
