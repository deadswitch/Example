char *get_string()
{
	size_t size = 2; // размер буффера
	const unsigned char num = size; // максимальное количество символов помещаемых в буффер
	unsigned int len = 0; // длина от начала строки
	char *buffer = (char*)malloc(size*sizeof(char)); // выделяем память под буффер
	if(!buffer) return NULL;
	char *string = buffer;
	char *temp = string; // для проверки результата функции realloc
	while(fgets(buffer,num,stdin))
	{
		len+=strlen(buffer);
		if(string[len-1]=='\n')
		{
			string[len-1] = '\0'; // \n нам ни к чему
			return string;
		}
		size+=num;
		temp = (char*)realloc(string,sizeof(char)*size); // перераспределяем блок памяти
		if(!temp) break;
		string = temp; // так как фукция realloc может нам вернуть указатель на другой блок памяти
		buffer = string+len; // смещаем указатель буффера
	}
	free(string);
	return NULL;
}
