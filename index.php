<?php
$username = null;
$password = null;

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
        $username = $_POST['username'];
		$password = $_POST['password'];
        if($username == 'admin' && $password == 'admin') {
            header('Location: main.php');
        }
        else {
            header('Location: index.php');
     }
}
else {
?>
<!doctype html>
<html>
<head>
<title>fSociety Login</title>
<link rel="icon" type="image/png" href="img/icon.png" />
</head>
<style>
	body {
		background-color:#191919;
		height: 100%;
		font-family: calibri;
}
.tblLogin {
	border: #B9081C 1px solid;
    background: #F13D24;
    border-radius: 4px;
	color: #FFF;
}
.tableheader { font-size: 24px; }
.tableheader td { padding: 20px; }
.tablerow td { text-align:center; }
.message {
	color: #FF0000;
	font-weight: bold;
	text-align: center;
	width: 100%;
}
.login-input {
	border: #CCC 1px solid;
    padding: 10px 20px;
}
.btnSubmit {
	padding: 10px 20px;
    background: #B9081C;
    border: #F13D24 1px solid;
    color: #FFF;
}
</style>
<header><br><br><br><br></header>
<body>
	<form name="frmUser" method="POST" action="">
		<table border="0" cellpadding="10" cellspacing="1" width="500" align="center" class="tblLogin">
			<tr class="tableheader">
			<td align="center" colspan="2">Login</td>
			</tr>
			<tr class="tablerow">
			<td>
			<input type="text" name="username" placeholder="User Name" class="login-input"></td>
			</tr>
			<tr class="tablerow">
			<td>
			<input type="password" name="password" placeholder="Password" class="login-input"></td>
			</tr>
			<tr class="tableheader">
			<td align="center" colspan="2"><input type="submit" name="submit" value="Submit" class="btnSubmit"></td>
			</tr>
		</table>
	</form>
</body>
</html>
<?php } ?>