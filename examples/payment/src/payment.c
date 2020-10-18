int payment(float value, char status[20])
{ 
	char estudante[20] = "estudante";
	char vip[20] = "vip";
	char regular[20] = "regular";
	char aposentado[20] = "aposentado";
	int isValid = 0;

	if(value < 0.01f || value > 99999.00f){
		return 1;
	}

	if(!strcmp(status,estudante)){		isValid = 1;
	}else if(!strcmp(status,vip)){		isValid = 1;
	}else if(!strcmp(status,regular)){	isValid = 1;
	}else if(!strcmp(status,aposentado)){	isValid = 1;
	}
	
	if(!isValid){
		return 2;
	}

	return 0;
}
