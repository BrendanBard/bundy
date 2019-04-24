<?php

if ($_SERVER['REQUEST_METHOD'] == 'GET') {
$fh = fopen('data.txt','w'); //File to write to
$fs = fopen('tester.txt', 'r'); //File to retrieve from
while ($line = fgets($fs)) {

	$decnum = intval($line);
	switch ($decnum)
	{
		case 1:
		fwrite($fh, "\nLBUTTON");
		break;
		case 2:
		fwrite($fh, "\nRBUTTON");
		break;
		case 3:
		fwrite($fh, "\nCANCEL");
		break;
		case 4:
		fwrite($fh, "\nMBUTTON");
		break;
		case 5:
		fwrite($fh, "\nXBUTTON1");
		break;
		case 6:
		fwrite($fh, "\nXBUTTON2");
		break;
		case 8:
		fwrite($fh, "\nBACKSPACE");
		break;
		case 9:
		fwrite($fh, "\nTAB");
		break;
		case 12:
		fwrite($fh, "\nCLEAR");
		break;
		case 13:
		fwrite($fh, "\n ");
		break;
		case 16:
		fwrite($fh, "\nSHIFT");
		break;
		case 17:
		fwrite($fh, "\nCTRL");
		break;
		case 18:
		fwrite($fh, "\nALT");
		break;
		case 19:
		fwrite($fh, "\nPAUSE");
		break;
		case 20:
		fwrite($fh, "\nCAPS_LOCK");
		break;
		case 21:
		fwrite($fh, "\nHangul mode");
		break;
		case 23:
		fwrite($fh, "\nJunja Mode");
		break;
		case 24:
		fwrite($fh, "\nfinal mode");
		break;
		case 25:
		fwrite($fh, "\nHanja Mode");
		break;
		case 27:
		fwrite($fh, "\nESC");
		break;
		case 28:
		fwrite($fh, "\nconvert");
		break;
		case 29:
		fwrite($fh, "\nnonconvert");
		break;
		case 30:
		fwrite($fh, "\naccept");
		break;
		case 31:
		fwrite($fh, "\nmode change");
		break;
		case 32:
		fwrite($fh, "\n ");
		break;
		case 33:
		fwrite($fh, "\nPGUP");
		break;
		case 34:
		fwrite($fh, "\nPGDN");
		break;
		case 35:
		fwrite($fh, "\nEND");
		break;
		case 36:
		fwrite($fh, "\nHOME");
		break;
		case 37:
		fwrite($fh, "\nL ARROW");
		break;
		case 38:
		fwrite($fh, "\nUP ARROW");
		break;
		case 39:
		fwrite($fh, "\nR ARROW");
		break;
		case 40:
		fwrite($fh, "\nDOWN ARROW");
		break;
		case 41:
		fwrite($fh, "\nSELECT");
		break;
		case 42:
		fwrite($fh, "\nPRINT");
		break;
		case 43:
		fwrite($fh, "\nEXECUTE");
		break;
		case 44:
		fwrite($fh, "\nPRINT SCREEN");
		break;
		case 45:
		fwrite($fh, "\nINS");
		break;
		case 46:
		fwrite($fh, "\nDELETE");
		break;
		case 47:
		fwrite($fh, "\nHELP");
		break;
		case 48:
		fwrite($fh, "\n0");
		break;
		case 49:
		fwrite($fh, "\n1");
		break;
		case 50:
		fwrite($fh, "\n2");
		break;
		case 51:
		fwrite($fh, "\n3");
		break;
		case 52:
		fwrite($fh, "\n4");
		break;
		case 53:
		fwrite($fh, "\n5");
		break;
		case 54:
		fwrite($fh, "\n6");
		break;
		case 55:
		fwrite($fh, "\n7");
		break;
		case 56:
		fwrite($fh, "\n8");
		break;
		case 57:
		fwrite($fh, "\n9");
		break;
		case 65:
		fwrite($fh, "\nA");
		break;
		case 66:
		fwrite($fh, "\nB");
		break;
		case 67:
		fwrite($fh, "\nC");
		break;
		case 68:
		fwrite($fh, "\nD");
		break;
		case 69:
		fwrite($fh, "\nE");
		break;
		case 70:
		fwrite($fh, "\nF");
		break;
		case 71:
		fwrite($fh, "\nG");
		break;
		case 72:
		fwrite($fh, "\nH");
		break;
		case 73:
		fwrite($fh, "\nI");
		break;
		case 74:
		fwrite($fh, "\nJ");
		break;
		case 75:
		fwrite($fh, "\nK");
		break;
		case 76:
		fwrite($fh, "\nL");
		break;
		case 77:
		fwrite($fh, "\nM");
		break;
		case 78:
		fwrite($fh, "\nN");
		break;
		case 79:
		fwrite($fh, "\nO");
		break;
		case 80:
		fwrite($fh, "\nP");
		break;
		case  81:
		fwrite($fh, "\nQ");
		break;
		case 82:
		fwrite($fh, "\nR");
		break;
		case 83:
		fwrite($fh, "\nS");
		break;
		case 84:
		fwrite($fh, "\nT");
		break;
		case 85:
		fwrite($fh, "\nU");
		break;
		case 86:
		fwrite($fh, "\nV");
		break;
		case 87:
		fwrite($fh, "\nW");
		break;
		case 88:
		fwrite($fh, "\nX");
		break;
		case 89:
		fwrite($fh, "\nY");
		break;
		case 90:
		fwrite($fh, "\nZ");
		break;
		case 91:
		fwrite($fh, "\nLWINDOWS KEY");
		break;
		case 92:
		fwrite($fh, "\nRWINDOWS KEY");
		break;
		case 93:
		fwrite($fh, "\nAPPS KEY");
		break;
		case 95:
		fwrite($fh, "\nSLEEP");
		break;
		case 96:
		fwrite($fh, "\n0");
		break;
		case 97:
		fwrite($fh, "\n1");
		break;
		case 98:
		fwrite($fh, "\n2");
		break;
		case 99:
		fwrite($fh, "\n3");
		break;
		case 100:
		fwrite($fh, "\n4");
		break;
		case 101:
		fwrite($fh, "\n5");
		break;
		case 102:
		fwrite($fh, "\n6");
		break;
		case 103:
		fwrite($fh, "\n7");
		break;
		case 104:
		fwrite($fh, "\n8");
		break;
		case 105:
		fwrite($fh, "\n9");
		break;
		case 106:
		fwrite($fh, "\n*");
		break;
		case 107:
		fwrite($fh, "\n+");
		break;
		case 108:
		fwrite($fh, "\nSEP");
		break;
		case 109:
		fwrite($fh, "\n-");
		break;
		case 110:
		fwrite($fh, "\n.");
		break;
		case 111:
		fwrite($fh, "\n/");
		break;
		case 112:
		fwrite($fh, "\nF1");
		break;
		case 113:
		fwrite($fh, "\nF2");
		break;
		case 114:
		fwrite($fh, "\nF3");
		break;
		case 115:
		fwrite($fh, "\nF4");
		break;
		case 116:
		fwrite($fh, "\nF5");
		break;
		case 117:
		fwrite($fh, "\nF6");
		break;
		case 118:
		fwrite($fh, "\nF7");
		break;
		case 119:
		fwrite($fh, "\nF8");
		break;
		case 120:
		fwrite($fh, "\nF9");
		break;
		case 121:
		fwrite($fh, "\nF10");
		break;
		case 122:
		fwrite($fh, "\nF11");
		break;
		case 123:
		fwrite($fh, "\nF12");
		break;
		case 124:
		fwrite($fh, "\nF13");
		break;
		case 125:
		fwrite($fh, "\nF14");
		break;
		case 126:
		fwrite($fh, "\nF15");
		break;
		case 127:
		fwrite($fh, "\nF16");
		break;
		case 128:
		fwrite($fh, "\nF17");
		break;
		case 129:
		fwrite($fh, "\nF18");
		break;
		case 130:
		fwrite($fh, "\nF19");
		break;
		case 131:
		fwrite($fh, "\nF20");
		break;
		case 132:
		fwrite($fh, "\nF21");
		break;
		case 133:
		fwrite($fh, "\nF22");
		break;
		case 134:
		fwrite($fh, "\nF23");
		break;
		case 135:
		fwrite($fh, "\nF24");
		break;
		case 144:
		fwrite($fh, "\nNUM LOCK");
		break;
		case 145:
		fwrite($fh, "\nSCROLL LOCK");
		break;
		case 160:
		fwrite($fh, "\nLSHIFT");
		break;
		case 161:
		fwrite($fh, "\nRSHIFT");
		break;
		case 162:
		fwrite($fh, "\nLCTRL");
		break;
		case 163:
		fwrite($fh, "\nRCTRL");
		break;
		case 164:
		fwrite($fh, "\nLMENU");
		break;
		case 165:
		fwrite($fh, "\nRMENU");
		break;
		default:
		fwrite($fh, $line);
	}

}
fclose($fh);
fclose($fs);
header('Location: data.php');
}

else{
?>
<!doctype html>
<html>
<style>
.btnSubmit {
	padding: 10px 20px;
    background: #B9081C;
    border: #F13D24 1px solid;
    color: #FFF;
}
</style>
<body>
<form name="frmUser" method="POST" action="">
<input type="submit" name="submit" value="Submit" class="btnSubmit">
</form>
</body>
</html><?php } ?>
