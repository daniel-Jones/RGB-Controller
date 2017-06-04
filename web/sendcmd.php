<?php
$host    = "192.168.1.13";
$port    = 3001;
$message = "red=" . $_GET['r'] . ";" . "green=" . $_GET['g'] . ";" . "blue=" . $_GET['b'];
var_dump($_GET);
//$message = "blue=0";
//echo "Message To server :".$message;
// create socket
$socket = socket_create(AF_INET, SOCK_STREAM, 0) or die("Could not create socket\n");
// connect to server
$result = socket_connect($socket, $host, $port) or die("Could not connect to server\n");  
// get server response
//Send the message to the server
if( ! socket_send ( $socket , $message , strlen($message) , 0))
{
       $errorcode = socket_last_error();
              $errormsg = socket_strerror($errorcode);
	             die("Could not send data: [$errorcode] $errormsg \n");
		     } else {
		            echo "Message send successfully \n".$message;
			    }
			    socket_close($socket);
			    ?>
