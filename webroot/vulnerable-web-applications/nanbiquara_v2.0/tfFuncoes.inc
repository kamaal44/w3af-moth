<?php

//------------------------------------------------------------------------------
function vogal($v)
{
	if (in_array($v, array('a','�','�','�','�','�','A','�','�','�','�','�'))) return 'A';
	if (in_array($v, array('e','�','�','�','�','E','�','�','�','�'))) return 'E';
	if (in_array($v, array('i','�','�','�','�','I','�','�','�','�'))) return 'I';
	if (in_array($v, array('o','�','�','�','�','�','O','�','�','�','�','�'))) return 'O';
	if (in_array($v, array('u','�','�','�','�','U','�','�','�','�'))) return 'U';
}
//------------------------------------------------------------------------------
function eh_vogal($caracter)
{
	$vogais = array (
		'a','e','i','o','u',
		'�','�','�','�','�',
		'�','�','�','�','�',
		'�','�','�','�','�',
		'�','�','�','�','�',
		'�','�',
		'A','E','I','O','U',
		'�','�','�','�','�',
		'�','�','�','�','�',
		'�','�','�','�','�',
		'�','�','�','�','�',
		'�','�');
	return in_array($caracter, $vogais);
}
//------------------------------------------------------------------------------
function eh_consoante($caracter)
{
	return (!eh_vogal($caracter) && !is_numeric($caracter));
}
//------------------------------------------------------------------------------
function eh_maior($f, $s)
{
	if ((vogal($f) == 'I') && (vogal($s) == 'U')) return true;
	if ((vogal($f) == 'I') || (vogal($f) == 'U')) return false;
	if ((vogal($s) == 'I') || (vogal($s) == 'U')) return true;
	if (vogal($f) == 'A') return true;
	if (vogal($s) == 'A') return false;
	return ((vogal($f) == 'O') && (vogal($s) == 'E'));
}
//------------------------------------------------------------------------------
function eh_letra($caractere)
{
	$letras = array(
		'a','�','�','�','�','e','�','�','i','�','o','�','�','�','u','�','b','c',
		'd','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z');
	return(in_array($caractere, $letras));
}
//------------------------------------------------------------------------------
function eh_nasal($caractere)
{
	return(in_array($caractere, array('�','�')));
}
//------------------------------------------------------------------------------
function eh_pontuacao($caractere)
{
	return(in_array($caractere, array('.','?','!')));
}
//------------------------------------------------------------------------------
function converte($vogal, $array_de_conversao)
{
	while (list($indice, $valor) = each($array_de_conversao))
		if(is_array($valor))
		{
			while (list($sub_indice, $sub_valor) = each($valor))
				if($sub_valor == $vogal)
					return($indice);
		}
		else
			if($valor == $vogal)
				return($indice);
	return('_');
}
//------------------------------------------------------------------------------
function tem_acento($s)
{
	$tem_acento = false;
	$tamanho_silaba = strlen($s);
	for ($j = 0; $j < $tamanho_silaba; $j++)
	{
		if (in_array($s[$j], array(
			'�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�',
			'�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�')))
		{
			$tem_acento = true;
		}
	}
	return $tem_acento;
}
//------------------------------------------------------------------------------
function eh_oxitona($s)
{
	$tam = strlen($s);
	if (in_array(strtoupper($s[$tam-1]), array('L')) && eh_vogal($s[$tam-2]))
		return true;
	return (in_array(strtoupper($s[$tam-1]), array('U','I')) && eh_consoante($s[$tam-2]));
}
?>